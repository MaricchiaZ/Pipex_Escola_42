/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:38:13 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/23 12:01:04 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//man strlen:
// A função strlen() calcula o comprimento da corda apontada por s, excluindo o byte 
//nulo terminante ('\0').

//essa função mede o tamanho da string passada
int	ft_strlen(const char *s)
{
	int	i; // criamos um índice

	i = 0; // i índice inicia em zero
	while (s[i] != '\0') // enquanto o conteúdo da string s na posição i for diferente de nulo
	{
		i++; // nosso índice ganha uma unidade
	}
	return (i); //retornamos o valor do índice que corresponte a quantos bytes da string estão preenchidos
}