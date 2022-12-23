/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:39:01 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/23 14:15:33 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_cmd(t_px pipex, char **env)
{
	char	*path;

	pipex.fd_in = open(pipex.args.file_in, O_RDONLY);
	if (pipex.fd_in == -1)
	{
		write(2, pipex.args.file_in, ft_strlen(pipex.args.file_in));
		write(2, ": No such file or directory\n", 28);
		free_pipex(&pipex);
		exit(0);
	}
	dup2(pipex.fd_in, 0);
	close(pipex.pipefd[0]);
	dup2(pipex.pipefd[1], 1);
	pipex.mtx_cmd = get_cmd(pipex.args.cmd1);
	path = get_path(env, pipex.args.cmd1);
	if (path)
		execve(path, pipex.mtx_cmd, env);
	free(path);
	free_matrix(pipex.mtx_cmd);
	free_pipex(&pipex);
	exit(127);
}

void	parent_cmd(t_px pipex, char **env)
{
	char	*path;

	close(pipex.pipefd[1]);
	pipex.mtx_cmd = get_cmd(pipex.args.cmd2);
	dup2(pipex.pipefd[0], 0);
	path = get_path(env, pipex.args.cmd2);
	if (path)
		execve(path, pipex.mtx_cmd, env);
	free_matrix(pipex.mtx_cmd);
	free_pipex(&pipex);
	exit(127);
}

int	main(int argc, char **argv, char **env)
{
	t_px	pipex;
	int		process_id;

	if (check_arguments(argc) == 0)
		return (0);
	if (save_arguments(argv, &pipex) == 0)
		return (-1);
	pipex.fd_out = open(pipex.args.file_out, \
	O_CREAT | O_WRONLY | O_TRUNC, 0777);
	dup2(pipex.fd_out, 1);
	if (pipe(pipex.pipefd) == -1)
		return (-1);
	process_id = fork();
	if (process_id == 0)
		child_cmd(pipex, env);
	else
		parent_cmd(pipex, env);
	return (0);
}
