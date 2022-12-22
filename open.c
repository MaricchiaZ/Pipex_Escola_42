/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:49:13 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/22 18:43:53 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(t_px *pipex)
{
	if (access(pipex->args.file_out, F_OK) == -1) // se não encontrar o file_out
        pipex->fd_out = open(pipex->args.file_out, O_CREAT | O_WRONLY); // usa a func open para criar o file_out com permissão de escrita O_WRONLY
    else // mas se encontrar o arquivo
        pipex->fd_out = open(pipex->args.file_out, O_WRONLY | O_TRUNC); // usa a func open para abrir o arquivo e remove todo o seu conteúdo (Truncate) 
    if (access(pipex->args.file_in, F_OK | R_OK) == -1) // se o acesso ao file_in estiver ok (F)
    {
        write (2, pipex->args.file_in, ft_strlen(pipex->args.file_in));
        write (2, ": No such file or directory\n", 28);
        free_pipex(pipex);
        exit(1);
    }
    else
	{
        pipex->fd_in = open(pipex->args.file_in, O_RDONLY);		
	}
}
