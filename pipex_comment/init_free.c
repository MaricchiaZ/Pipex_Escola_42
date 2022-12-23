/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:46:08 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/23 12:07:23 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// função que inicializa as strings da struct args
void	init_struct_args(t_arg *args)
{
	args->file_in = ft_strdup(""); // inicializa as strings pela função ft_strdup mallocando e colocando um \0 na primeira posição da string
	args->cmd1 = ft_strdup("");
	args->cmd2 = ft_strdup("");
	args->file_out = ft_strdup("");
}

// função para dar free em uma matriz (ponteiro de ponteiro). Primeiro dá free em cada ponteiro interno e depois dá free no ponteiro de ponteiro
void	free_matrix(char **mtx)
{
	int	i; // índice que percorre os ponteiros

	i = 0;
	if (mtx == NULL) // se a matriz já estiver vazia
		return ;
	while (mtx[i]) // se houver algum ponteiro ainda utilizado na matriz
	{
		free(mtx[i]);  // damos free no ponteiro
		i++; // partimos para o próximo
	}
	free(mtx); // free no ponteiro de ponteiro
}

//  função que dá free nas strings alocadas da struct principal (ts_px pipex)
void	free_pipex(t_px *pipex)
{
	if (pipex->args.file_in) // se o ponteiro não for null
		free(pipex->args.file_in); // damos free no ponteiro
	if (pipex->args.cmd1)
		free(pipex->args.cmd1);
	if (pipex->args.cmd2)
		free(pipex->args.cmd2);
	if (pipex->args.file_out)
		free(pipex->args.file_out);
}
