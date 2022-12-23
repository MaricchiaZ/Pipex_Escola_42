/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:39:54 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/01 16:39:54 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//man strdup
//A função strdup() retorna um ponteiro para uma nova string que é uma duplicata 
//da string s. A memória para a nova string é obtida com malloc(3), e pode ser liberada com free(3).
// Se tudo ocorrer bem, a função strdup() retorna um ponteiro para a string duplicada.  E ela retorna NULL 
//se a memória for insuficiente. 

//essa função duplica alocando uma string
char	*ft_strdup(const char *src)
{
	int		i; // criamos um índíce para percorrer a string
	int		len_src; //criamos uma variável que armazenará o tamanho da sring recebida
	char	*cpy; // criamos um ponteiro que receberá a cópia da string passada

	i = 0; // o índice inicia zerado
	if (!src) // se a src for falsa, isto é não existir
		return ((void *)0); // retornamos um ponteiro vazio
	len_src = ft_strlen(src); //len_src recebe o tamanho da src, obtido pela função ft_strlen() 
	cpy = (char *) malloc (sizeof (char) * (len_src + 1)); // a nova string cpy recebe o malloc (a reserva)
	// dos bytes referentes a char do tamanho da src + 1 byte (o byte nulo)
	if (cpy == NULL) // se cpy for NULL o Malloc deu errado..
		return (NULL); // então retornamos null
	while (src[i]) // enquanto a src existir, isto é não for nula
	{
		cpy[i] = src[i]; // a string nova na posição i recebe o valor da src na posição i
		i++; // vamos para a próxima posição
	}	
	cpy[i] = '\0'; // a posição final da nossa string nova recebe o byte nulo
	return (cpy); // retornamos nossa nova string
}