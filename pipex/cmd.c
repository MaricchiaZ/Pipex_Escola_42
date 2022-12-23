/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:37:13 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/23 11:55:20 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_cmd_count(char *s)
{
	int		i;
	int		n;
	char	c;

	n = 0;
	i = 0;
	while (s[i] != '\0') //     "   tr 'c' e"
	{
		while (s[i] == ' ')
			i++;
		if ((s[i] == '\'' || s[i] == '\"') && s[i + 1] != '\0')
		{
			c = s[i];
			i++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
			n++;
		}
		else if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

//função que separa as partes do comando em uma matriz, tira os espaços e ignora as aspas simples e duplas ex: "tr 'c' e", *pt[1] = tr, *pt[2] = c, *pt[3] = 3, 
static void	my_cmd_split(char	*s, char **matriz, int i, int strcount)
{
	int	start; //salva a posição onde se inicia o comando

	start = 0;
	while (s[i] != '\0') // enquanto ainda tiver caracter na string para olhar
	{
		while (s[i] == ' ') // pula os espaços iniciais "        tr 'c' e"
			i++;
		start = i; // salva a posição do primeiro caracter não espaço
		if (!(s[i] == '\'' || s[i] == '\"')) // se não for aspas simples nem dupla
		{
			while (s[i] != ' ' && s[i] != '\0') // se não for espaço e nem tiver acabado a string
				i++; // anda até achar o espaço ou fim da string
			matriz[strcount++] = ft_substr(s, start, i - start); // esse trecho é guardado na matriz
		}
		else // se for aspas simples ou dupla "tr 'c' e"
		{
			i++; // vai para o 1o caracter depois da aspa
			start++; // salva a posição do 1o caracter depois da aspa
			while (s[i] != s[start - 1] && s[i] != '\0') // enquanto tiver percorrendo dentro das aspas, só para de andar se achar a aspa que fecha a anterior
				i++; // anda, 
			matriz[strcount++] = ft_substr(s, start, i - start); // esse trecho é guardado na matriz
			if (s[i] == s[start - 1]) // se for duas aspas iguais seguidas
				i++; // anda novamente
		}
	}
}

// função que pegará o comando já sem espaços e limpo de aspas simples e aspas duplas
char	**get_cmd(char *s)
{
	char	**cmd_n_spc; // recebe as partes do comando em uma matriz, tira os espaços e ignora as aspas simples e duplas ex: "tr 'c' e", *pt[1] = tr, *pt[2] = c, *pt[3] = 3, 
	int		i; // índice pra percorrer a string na função my_cmd_split
	int		strcount; // conta quantas partes/ subcomandos compõe o comando

	cmd_n_spc = (char **) malloc (sizeof(char *) * (get_cmd_count(s) + 1)); // a matriz é malocada de acordo com quantos subcomandos ela tem
	if (cmd_n_spc == NULL) // se o maloc der errado
		return (NULL);
	i = 0; // índice inicia em zero
	strcount = 0; // partes começa em zero
	my_cmd_split(s, cmd_n_spc, i, strcount);  //separa as partes do comando em uma matriz, tira os espaços e ignora as aspas simples e duplas ex: "tr 'c' e", *pt[1] = tr, *pt[2] = c, *pt[3] = 3, 
	cmd_n_spc[get_cmd_count(s)] = NULL; // *pt[final] = reebe NULL
	return (cmd_n_spc); // retornamos a matriz do comando. Isso é importante porque acharemos o caminho para o comando principal, e não com seus complementos, ex: para o comando "tr 'c' e", acharemos o caminho /usr/bin/tr 
}
