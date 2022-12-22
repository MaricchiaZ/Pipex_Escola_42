/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:39:01 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/21 22:20:17 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*my_path_join(char const *s1, char const *s2)
{
	char	*s;
	int		count;
	int		count2;

	count = 0; 
	count2 = 0;
	s = malloc ((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (s1[count] != '\0')
	{
		s[count] = s1[count];
		count++;
	}
	s[count++] = '/';
	while (s2[count2] != '\0')
		s[count++] = s2[count2++];
	s[count] = '\0';
	return (s);
}

char    *get_path(char **env, char *cmd)
{
    int        i;
    char    *line;
    char    **check;
    char    *path;

    i = 0;
    while (env[i][0] != 'P' || env[i][1] != 'A'
            || env[i][2] != 'T' || env[i][3] != 'H'|| env[i][4] != '=')
        i++;
    line = env[i] + 5;
    check = ft_split(line, ':');
    i = 0;
    while (check[i] != NULL)
    {
		// /usr/local/sbin
		// /usr/local/bin
		// /usr/sbin
		// /usr/bin
		// /sbin
		// /bin/
        path = my_path_join(check[i], ft_split(cmd, ' ')[0]);
        if (access(path, F_OK | X_OK) == 0)
            return (path);
        free(path);
        i++;
    }
    exit (127);
}

static int	get_cmd_count(char *s)
{
	int		i;
	int		n;
	char	c;

	n = 0;
	i = 0;
	while (s[i] != '\0') //     "   tr 'c' e"
	{
		while (s[i] == ' ')
			i++;
		if ((s[i] == '\'' || s[i] == '\"') && s[i + 1] != '\0')
		{
			c = s[i];
			i++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
			n++;
		}
		else if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

static void	my_cmd_split(char	*s, char **matriz, int n, int strcount)
{
	int	start;

	start = 0;
	while (s[n] != '\0')
	{
		while (s[n] == ' ')
			n++;
		start = n;
		if (s[n] == '\'' || s[n] == '\"') //  "   tr 'c' e"
		{
			n++;
			start++;
			while (s[n] != s[start - 1] && s[n] != '\0')
				n++;
			matriz[strcount++] = ft_substr(s, start, n - start);
			if (s[n] == s[start - 1])
				n++;
		}
		else
		{
			while (s[n] != ' ' && s[n] != '\0')
				n++;
			matriz[strcount++] = ft_substr(s, start, n - start);
		}
	}
}

char	**get_cmd(char *s)
{
	char	**ret;
	int		n;
	int		strcount;

	ret = (char **) malloc (sizeof(char *) * (get_cmd_count(s) + 1));
	if (ret == NULL)
		return (NULL);
	n = 0;
	strcount = 0;
	my_cmd_split(s, ret, n, strcount);
	ret[get_cmd_count(s)] = NULL;
	return (ret);
}

void	child_cmd(t_px pipex, char **env)
{
	char *path;
	
	close(pipex.pipefd[0]);
	dup2(pipex.pipefd[1], 1);
	pipex.mtx_cmd = get_cmd(pipex.args.cmd1); // ls -l | wc
	path = get_path(env, pipex.args.cmd1);
	execve(path, pipex.mtx_cmd, env); // 	execve(pipex->path, pipex->mtx_cmd, env);
}

void	parent_cmd(t_px pipex, char **env)
{
	char *path;
	
	close(pipex.pipefd[1]);
	pipex.mtx_cmd = get_cmd(pipex.args.cmd2);
	dup2(pipex.pipefd[0], 0);
	path = get_path(env, pipex.args.cmd2);
	execve(path, pipex.mtx_cmd, env); // 	execve(pipex->path, pipex->mtx_cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	t_px	pipex;
	int		process_id;
	
	if (check_arguments(argc) == 0)
		return (-1);
	if (save_arguments(argv, &pipex) == 0)
		return (-1);
	open_file(&pipex);
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

/*

void	child_cmd(t_px pipex, char **env)
{
	char	**split;

	split = ft_split(pipex.args.cmd1, ' ');
	close(pipex.s_fd[0]);
	dup2(pipex.s_fd[1], 1);
//	pipex->cmd = FUNC PEGA COMANDO(pipex->args.cmd1);
//	pipex->path = FUNC PEGA CAMINHO(pipex, env)
	execve(PATH, split, env); // 	execve(pipex->path, pipex->cmd, env);
}

void	parent_cmd(t_px pipex, char **env)
{
	char	**split;

	split = ft_split(pipex.args.cmd2, ' ');
	close(pipex.s_fd[1]);
	dup2(pipex.s_fd[0], 0);
//	pipex->cmd = FUNC PEGA COMANDO(pipex->args.cmd2);
//	pipex->path = FUNC PEGA CAMINHO(pipex, env)
	execve(PATH, split, env); // 	execve(pipex->path, pipex->cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	t_px	pipex;
	int		process_id;
	
	if (check_arguments(argc) == 0)
		return (-1);
	if (save_arguments(argv, &pipex) == 0)
		return (-1);
	open_file(&pipex);
	dup2(pipex.fd_out, 1);
	dup2(pipex.fd_in, 0);
	if (pipe(pipex.s_fd) == -1)
		return (-1);
	process_id = fork();
	if (process_id == 0)
		child_cmd(pipex, env);
	else
		parent_cmd(pipex, env);
	return (0);
}
*/

/*
#include <stdlib.h> 

    int main (int argc, char* argv[]) 
    { 
       system("mkdir NomePasta");
       return 0;
    }
*/