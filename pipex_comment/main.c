/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:39:01 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/26 18:53:20 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// processo filho, abre o file1(file_in) e depois de achar o caminho e o comando adequado, roda o comando sobre o file_in, mas direciona sua saída para o pipefd[1], em vez do terminal;
void	child_cmd(t_px pipex, char **env)
{
	char *path; //string que receberá o caminho
	
	pipex.fd_in = open(pipex.args.file_in, O_RDONLY); // abre-se o file_in para a leitura, e guarda-se seu conteúdo no fd_in
	if(pipex.fd_in == -1) // se a função open falhar
	{
		write(2, pipex.args.file_in, ft_strlen(pipex.args.file_in)); //escrevemos o nome do file_in
		write(2, ": No such file or directory\n", 28); // seguida da mensagem de não encontrado
		free_pipex(&pipex); // limpamos a struct usada
		exit(0); // finalizamos o processo com a mensagem êxito/sucesso/ok
	}
	dup2(pipex.fd_in, 0); // troca a entrada padrão pelo fd_in 
	close(pipex.pipefd[0]); //pipefd[0] - read // sempre feche a extremidade do pipe que voce não usa, se ficar aberta a outra extremidade ficará aguardando algum tipo de entrada e o processo não se finalizará
	dup2(pipex.pipefd[1], 1); // pipefd[1] - write // dup2 - int dup2(int fd1, int fd2) pode trocar os fds para stdin/stdout (essa func fecha o fd2, e duplica o conteúdo dele para o fd1, ou seja redireciona o fd1 para o fd2, limpando o fd1 sem deixar vazar os leaks)
	// a dup2 fecha o stdout (1) saída pro terminal, e o pipefd[1] torna-se o novo stdout, recebendo a saída
	pipex.mtx_cmd = get_cmd(pipex.args.cmd1); // extrai o comando do argumento 3
	path = get_path(env, pipex.args.cmd1); // pegamos o caminho necessário para rodar o comando
	//	execve(path, pipex.mtx_cmd, env); // executamos o comando, no caminho, sobre o fd_in e o resultado vai para o fd_out
	if (path)
		execve(path, pipex.mtx_cmd, env); // executamos o comando, no caminho, sobre o fd_in e o resultado vai para o fd_out
	free(path); // limpa o ponteiro do caminho
	free_matrix(pipex.mtx_cmd); // limpa a matriz dos comandos
	free_pipex(&pipex); // limpa a struct pipex
	exit(127); // saída de erro
}

// processo pai, abre o fd_id, pega o comando 2 e depois de achar o caminho, roda o comando sobre o pipefd[0], e direciona sua saída para o terminal stdout(1);
void	parent_cmd(t_px pipex, char **env)
{
	char *path;
	
	close(pipex.pipefd[1]); // pipefd[1] - write // sempre feche a extremidade do pipe que voce não usa, se ficar aberta a outra extremidade ficará aguardando algum tipo de entrada e o processo não se finalizará
	pipex.mtx_cmd = get_cmd(pipex.args.cmd2);
	dup2(pipex.pipefd[0], 0); //pipefd[0] - read // a dup2 - int dup2(int fd1, int fd2) pode trocar os fds para stdin/stdout (essa func fecha o fd2, e duplica o conteúdo dele para o fd1, ou seja redireciona o fd1 para o fd2, limpando o fd1 sem deixar vazar os leaks)
	// a dup2 fecha o stdin (0), e o pipefd[0] torna-se o novo stdin, agora essa função vai receber os valores do arquivo 1 e não do terminal
	path = get_path(env, pipex.args.cmd2); // path recebe o caminho para a execussão do comando
	if (path) // se o caminho existir
		execve(path, pipex.mtx_cmd, env); // executamos o programa referenciado pelo path. Essa função faz a execução de um programa externo ao processo. Não existe a criação efetiva de um novo processo, mas simplesmente uma substituição do programa de execução., de modo que ela executa o comando no caminho 
	free(path); //limpamos a string path
	free_matrix(pipex.mtx_cmd); // limpamos o ponteiro de ponteiri (matriz) dos comandos
	free_pipex(&pipex); // limpamos a struct pipex
	exit(127); // mensagem de erro “command not found”
}

//checa-se os argumentos, inicia-se o pipe, e usa-se o fork para duplicar os processos
int	main(int argc, char **argv, char **env)
{
	t_px	pipex; // struct com as variáveis necessárias
	int		process_id; //recebe o retorno da função fork
	
	if (check_arguments(argc) == 0) // checa se o número de args é 5
		return (1); // avisa o erro
	if (save_arguments(argv, &pipex) == 0) // salva os argumentos numa struct
		return (-1); // avisa o erro
	pipex.fd_out = open(pipex.args.file_out, O_CREAT | O_WRONLY | O_TRUNC, 0777); // usa a func open para criar o file_out com permissão de escrita O_WRONLY, se ele não existir préviamente, e se ele existir remove todo o seu conteúdo (Truncate) 
	dup2(pipex.fd_out, 1);//fecha a saída do terminal e converte-a para o fd_out
	if (pipe(pipex.pipefd) == -1) // se a função pipe não funcionar
		return (-1); // retornamos erro
	process_id = fork(); // fork duplica todos os processos a partir daqui, retornando 0 para o processo filho, e > 0 para o processo pai
	if (process_id == 0) // no processo filho
		child_cmd(pipex, env); // roda-se o comando 1
	else // no processo pai
		parent_cmd(pipex, env); // roda-se o comando 2
	return (0); // retorno ok
}
