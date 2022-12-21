/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:46:08 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/20 23:37:39 by maclara-         ###   ########.fr       */
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

void	free_matrix(t_px *pipex)
{
	int	i;

	i = 0;
	if (pipex->exv == NULL)
		return ;
	while (pipex->exv[i])
	{
		free(pipex->exv[i]);
		i++;
	}
	free(pipex->exv);
}

void	free_pipex(t_px *pipex)
{
	free(pipex->args.file_in);
	free(pipex->args.cmd1);
	free(pipex->args.cmd2);
	free(pipex->args.file_out);
	free_matrix(pipex);
}
