/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:40:51 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 20:41:10 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int save_arguments(char **argv, t_px *pipex)
{
	init_struct_args(&pipex->args);
	pipex->args.file_in = ft_strjoin(pipex->args.file_in, argv[1]);
	pipex->args.cmd1 = ft_strjoin(pipex->args.cmd1, argv[2]);
	pipex->args.cmd2 = ft_strjoin(pipex->args.cmd2, argv[3]);
	pipex->args.file_out = ft_strjoin(pipex->args.file_out, argv[4]);

	printf("file_in: %s\n", pipex->args.file_in);
	printf("cmd1: %s\n", pipex->args.cmd1);
	printf("cmd2: %s\n", pipex->args.cmd2);
	printf("file_out: %s\n", pipex->args.file_out);
	
	if (!pipex->args.file_in || pipex->args.file_out || \
	pipex->args.cmd1 || pipex->args.cmd2)
		return (0);
	return (1);
}

int	check_arguments(int argc)
{
	if(argc != 5)
	{
		write(1, "Error\n invalid number of arguments\n", 36);
		return (0);
	}
	return (1);
}