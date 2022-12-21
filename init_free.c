/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:46:08 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/21 01:27:00 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct_args(t_arg *args)
{

	args->file_in = ft_strdup("");
	args->cmd1 = ft_strdup("");
	args->cmd2 = ft_strdup("");
	args->file_out = ft_strdup("");
}

// void	free_matrix(char **exv)
// {
// 	int	i;

// 	i = 0;
// 	if (exv == NULL)
// 		return ;
// 	while (exv[i])
// 	{
// 		free(exv[i]);
// 		i++;
// 	}
// 	free(exv);
// }

void	free_pipex(t_px *pipex)
{
	if (pipex->args.file_in)
		free(pipex->args.file_in);
	if (pipex->args.cmd1)
		free(pipex->args.cmd1);
	if (pipex->args.cmd2)
		free(pipex->args.cmd2);
	if (pipex->args.file_out)
		free(pipex->args.file_out);
//	if (pipex->exv)
//		free_matrix(pipex->exv);
	if (pipex->path_cmd)
		free(pipex->path_cmd);
	if (pipex->cmd)
		free(pipex->cmd);
}
