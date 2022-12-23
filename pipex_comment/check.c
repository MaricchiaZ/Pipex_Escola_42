/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:40:51 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/23 10:49:35 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// salvamos os argumentos na struct args
int save_arguments(char **argv, t_px *pipex)
{
	init_struct_args(&pipex->args); // inicimos a structs
	pipex->args.file_in = ft_strjoin(pipex->args.file_in, argv[1]); // salvamos os valores dos arg2, 3, 4 e 5 nas strings da struct args
	pipex->args.cmd1 = ft_strjoin(pipex->args.cmd1, argv[2]);
	pipex->args.cmd2 = ft_strjoin(pipex->args.cmd2, argv[3]);
	pipex->args.file_out = ft_strjoin(pipex->args.file_out, argv[4]);
	if (!pipex->args.file_in || !pipex->args.file_out || \
	!pipex->args.cmd1 || !pipex->args.cmd2) // se algum dos argumentos não for salvo, 
		return (0); // retornamos erro
	return (1); // retornamos ok
}

// checando o número de args passados
int	check_arguments(int argc)
{
	if(argc != 5) // diferente de 5 - (a.out file_in cmd1 cmd2 file_out) está errado
	{
		write(1, "Error\n invalid number of arguments\n", 36); // mensagem avisando o erro
		return (0); // erro
	}
	return (1); // ok
}
