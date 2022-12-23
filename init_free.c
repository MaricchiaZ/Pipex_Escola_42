/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:46:08 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/22 19:50:50 by maclara-         ###   ########.fr       */
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

void	free_matrix(char **mtx)
{
	int	i;

	i = 0;
	if (mtx == NULL)
		return ;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}

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
}
