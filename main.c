/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:39:01 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/22 18:28:36 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_cmd(t_px pipex, char **env)
{
	char *path;
	
	close(pipex.pipefd[0]); // sempre feche a extremidade do pipe que voce não usa, se ficar aberta a outra extremidade ficará aguardando algum tipo de entrada e o processo não se finalizará
	dup2(pipex.pipefd[1], 1); // a dup2 - int dup2(int fd1, int fd2) pode trocar os fds para stdin/stdout (essa func fecha o fd2, e duplica o conteúdo dele para o fd1, ou seja redireciona o fd1 para o fd2, limpando o fd1 sem deixar vazar os leaks)
	// a dup2 fecha o stdout (1), e o pipefd[1] torna-se o novo stdin
	pipex.mtx_cmd = get_cmd(pipex.args.cmd1); // ls -l | wc
	path = get_path(env, pipex.args.cmd1); // pegamos o caminho 
	execve(path, pipex.mtx_cmd, env); // executamos o comando, no caminho, sobre o fd_in e o resultado vai para o fd_out\
}

void	parent_cmd(t_px pipex, char **env)
{
	char *path;
	
	close(pipex.pipefd[1]); // sempre feche a extremidade do pipe que voce não usa, se ficar aberta a outra extremidade ficará aguardando algum tipo de entrada e o processo não se finalizará
	pipex.mtx_cmd = get_cmd(pipex.args.cmd2);
	dup2(pipex.pipefd[0], 0); // a dup2 - int dup2(int fd1, int fd2) pode trocar os fds para stdin/stdout (essa func fecha o fd2, e duplica o conteúdo dele para o fd1, ou seja redireciona o fd1 para o fd2, limpando o fd1 sem deixar vazar os leaks)
	// a dup2 fecha o stdin (0), e o pipefd[0] torna-se o novo stdin, agora essa função vai receber os valores do arquivo 1 e não do terminal
	path = get_path(env, pipex.args.cmd2);
	execve(path, pipex.mtx_cmd, env); // 	execve(pipex->path, pipex->mtx_cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	t_px	pipex;
	int		process_id;
	
	if (check_arguments(argc) == 0) // checa se o número de args é 5
		return (-1);
	if (save_arguments(argv, &pipex) == 0) // salva os argumentos numa struct
		return (-1);
	open_file(&pipex); //
	dup2(pipex.fd_out, 1);
	dup2(pipex.fd_in, 0);
	if (pipe(pipex.pipefd) == -1)
		return (-1);
	process_id = fork();
	if (process_id == 0)
		child_cmd(pipex, env);
	else
		parent_cmd(pipex, env);
	return (0);
}
