/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:38:44 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/23 13:44:43 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

// função que une a string com o caminho, na string que tem o comando
char	*my_path_join(char const *path, char const *cmd)
{
	char	*p_c; // string que recebe o caminho + comando
	int		i; // índice que percorre o path e a strig p_c
	int		i2; // índice que percorre o comando 

	i = 0; 
	i2 = 0;
	p_c = malloc ((ft_strlen(path) + ft_strlen(cmd) + 2) * sizeof(char)); // maloca-se o tamanho do path + / + cmd, caminho, barra, comando
	if (p_c == NULL) // se o malloc der errado
		return (NULL);
	while (path[i] != '\0') // enquanto não acabar de ver o caminho
	{
		p_c[i] = path[i]; // copia-se o caminho para a string final
		i++;
	}
	p_c[i++] = '/'; // adiciona-se a barra
	while (cmd[i2] != '\0') // enquanto não acabar de ver o caminho
		p_c[i++] = cmd[i2++]; // copia-se o caminho para a string final
	p_c[i] = '\0'; // finaliza-se a string com um byte nulo
	return (p_c); // retornamos o comando já com o caminho
}

// checa a validade/ EFETIVIDADE dos possíveis caminhos para o executável, dentro da função get_path
static char *check_path (char **check, char **cmd_name, int i)
{
	char *path; // string com o caminho

	while (check[i] != NULL) // enquanto houver ponteiros usados na matriz chekck
    {
        path = my_path_join(check[i], cmd_name[0]); // path recebe o caminho presente em check + o comando de cmd_name[0]
        if (access(path, F_OK | X_OK) == 0) // a função access confere se o caminho é válido, e se é possível acessar aquele comando (no fundo confere se o comando é válido)
		{
			free_matrix(cmd_name); // limpamos as matrizes auxiliares
			free_matrix(check); // limpamos as matrizes auxiliares
            return (path); // retornamos o caminho para o executável do comando
		}
        free(path); // se não foi encontrando um caminho válido para o executável
        i++; // testamos o próximo caminho
    }
	return (NULL); // se não foi encontrando um caminho para o executável válido
}

// função que encontra dentro do env o caminho EFETIVO para o executável
char    *get_path(char **env, char *cmd)
{
    int        i; // índice pra percorrer as variáveis de ambiente
    char    *line; // rebebe a string do env $PATH=
    char    **check; // matriz com os caminhos a serem testados 
    char    *path; // string com o caminho certo
	char	**cmd_name; //matriz com as parte do comando
	
    i = 0;
    while (env[i][0] != 'P' || env[i][1] != 'A'
            || env[i][2] != 'T' || env[i][3] != 'H'|| env[i][4] != '=') // dentre todas as variáveis de ambiente env procuramos o caminho que comeca com PATH=
        i++;
    line = env[i] + 5; // line recebe a string do path, mas só oo que tiver depois do =
    check = ft_split(line, ':'); // separamos o caminho para as pastas
	// os caminhos retornados pelo env antes da split :
	// "/usr/local/sbin/::/usr/local/bin/:/usr/sbin/:/usr/bin/:/sbin:/bin/"
	// depois da split, cada caminho estará dentro de uma string:
	//	/usr/local/sbin/
	//	/usr/local/bin/
	//	/usr/sbin/
	//	/usr/bin/
	//	/sbin:/bin/
	cmd_name = ft_split(cmd, ' '); // o nome do comando é a primeira parte dele, então passamos a split dividindo o comando em seus espaços
    i = 0;
	path = check_path (check, cmd_name, i); //path recebe o caminho para o executável do comando
	if (path) // se path for diferente de null, isto é, se for um comando válido
		return (path); // retornamos esse caminho
	free_matrix(cmd_name); // senão limpamos a matriz auxiliar do comando 
	free_matrix(check); // e a matriz auxiliar dos caminhos possíveis
	return (NULL); // e o caminho é null
}
