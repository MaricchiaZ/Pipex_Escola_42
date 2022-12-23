/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 01:58:14 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/23 12:00:14 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//man strlcpy
//As funções strlcpy() copiam as cordas. Ao contrário dessas funções, strlcpy() toma 
//o tamanho completo do buffer (não apenas o comprimento) e garante a terminação NUL (desde 
//que o tamanho seja maior que 0. Note que um byte para o NUL deve ser incluído no tamanho.
//Observe também que strlcpy() opera somente as strings passadas forem verdadeiras strings da 
//linguagem ''C'''. Isto significa que para strlcpy() src deve ser terminada NUL.  A função 
//strlcpy() copia até o tamanho - 1 caracter da string terminada NUL src para dst, 
//terminando NUL o resultado.

//essa função copia a string src na dest até o size passado
//essa função faz a cópia e retorna o valor de src
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i; // criamos um índice i;
	size_t	len_src; // criamos uma variável para armazenar o tamanho de src

	i = 0; // o índice inicia em zero
	len_src = 0; // inicia em zero
	while (src[len_src] != '\0') // enquanto o conteúdo desrc[len_src] for diferente de nulo
		len_src++; // avançamos no len_src, por fim essa variável terá o valor do tamanho de src
	if (size != 0) // se o size passado não for zero
	{
		while (src[i] != '\0' && i < (size - 1)) //enquanto src[i] não for nulo e
		// o índice da cópia forem menor do que o size total passado -1 byte (que está reservado pro byte nulo)
		{
			dest[i] = src[i]; // dest na posição i recebe o valor de src na posição i
			i++; // e seguimos para o próximo byte
		}
		dest[i] = '\0'; // o byte final da dest, que corresponde ao size passado recebe o '\0'
	}
	return (len_src); // retornamos o tamanho de src
}
