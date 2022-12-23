/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:41:08 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/01 16:41:08 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//man substr:
//Retorna a substring da string s, iniciada no byte start (posição inicial dada) e
//com o len (comprimento dado) (ou menor se o comprimento da string original for 
//menor do que início + comprimento, ou se comprimento for maior do que MAXSTRINGLEN).

// essa função cria uma substring de s, de s[start] até s[start + len]
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s; // criamos uma variável que irá receber o tamanho da string s
	char	*dest; // criamos um ponteiro para a string que vammos criar 

	if (!s) // se a string s falsa, isto é for nula 
		return (NULL); // retornamos NULL
	len_s = ft_strlen(s); // len_s recebe o tamanho da string s medido pela função ft_strlen
	if (len_s <= len) // se a string s for menor que o len passado por parâmetro
		len = len_s - start; // len recebe o tamanho da string s - menos os bytes que deverão
	// estar avançados representados pelo start; com isso temos o comprimento da substring a ser criada
	if (start > len_s) //se a posição de start estiver para além do comprimento...
		return (ft_strdup("")); // retornamos um ponteiro nulo, criado pela função strdup quando recebe
		// uma string vazia ""
	dest = (char *)malloc(sizeof(char) * (len + 1)); // dest recebe a reserva da memória de len bytes mais um (do nulo)
	if (!dest) // se depois do malloc dest for igual a NUll, o malloc deu errado
		return (NULL); // então retornamaos null
	ft_strlcpy(dest, (char *) s + start, len + 1); // casp esteja tudo certo a função ft_strlcpy copia a string s
	// para a dest, comecando pelo ponteiro s na posição start (já convertido para um ponteiro char), e prossegue
	// a cópia até len + 1 bytes
	return (dest); // dest está pronta para ser retornada :) FIM
}