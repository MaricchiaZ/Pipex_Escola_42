/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:46:08 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/19 20:00:33 by maclara-         ###   ########.fr       */
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
