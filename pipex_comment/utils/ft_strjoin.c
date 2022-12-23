/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:58:00 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/01 16:58:00 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//descrição da função nas diretrizes da tarefa:
// Aloca (com malloc(3)) e retorna uma nova string, que é o resultado da concatenação 
//de 's1' e 's2'.

//essa função cria e malloca uma nova string que é a união de s1 e s2
char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dest; // criamos um ponteiro para a nova string que será criada
	int		len; // criamos um int len para armazenar o tam das strins s1 e s2
	int		i; // criamos um índice para percorrer a string para a cópia

	len = ft_strlen(s1) + ft_strlen(s2); // len recebe o tamanhoda s1 + o tamanho da s2
	dest = (char *) malloc (sizeof (char) * (len + 1)); //o ponteiro dest recebe a memória reservada para
	// o comprimento das duas strings + 1 byte que é o '\0'
	if (dest == NULL) // se dest for NULL o Malloc deu errado..
		return (NULL); // então retornamos null
	i = 0; // o índice é zerado e ele percorrerá s1
	len = 0; // o len é zerado e será o índice de preenchimento (tamanho) da dest
	while (s1[i] != '\0') // enquanto a s1[i] for diferente do byte nulo
	{
		dest[len++] = s1[i++];  //dest[len] recebe o valor de s1[i], e em seguida
		//fazemos len++ e i++, para avançarmos para as próximas posições
	}
	i = 0; // o índice é zerado novamente, e agora percorrerá s2
	// o len não foi zerado, então a dest continuará ser preenchida, agora com o
	// conteúdo de s2
	while (s2[i] != '\0') // enquanto a s2[i] for diferente do byte nulo
	{
		dest[len] = s2[i]; //dest[len] recebe o valor de s2[i]
		i++; // i ganha uma unidade
		len++; // len ganha uma unidade
	}
	dest[len] = '\0'; //a posição final da dest recebe o byte nulo
	free(s1);
	return (dest); // retornamos a dest
}