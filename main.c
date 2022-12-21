/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:39:01 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/21 00:54:16 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

/*
#include <stdlib.h> 

    int main (int argc, char* argv[]) 
    { 
       system("mkdir NomePasta");
       return 0;
    }
*/