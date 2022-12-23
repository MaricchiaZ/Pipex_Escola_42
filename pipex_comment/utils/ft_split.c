/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 23:06:23 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/23 11:56:45 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


//descrição da função nas diretrizes da tarefa:
// Aloca (com malloc(3)) e retorna uma matriz de strings obtidas através da divisão de "s" 
//usando o o caractere "c" como delimitador. A matriz deve terminar com um ponteiro NULL. 
//Essa função retorma o conjunto de novas strings resultantes da divisão ou NULL se a alocação falhar.



//função auxiliar - COMEÇE LENDO PELA OUTRA FUNÇÂO

//essa função é static; funções estáticas são funções que só são visíveis para outras funções neste mesmo arquivo 
//ou (mais precisamente a mesma unidade de tradução)

//essa função conta quantas strings devem ser alocadas
static int	count_to_malloc(char const *s, char c)
{
	int	count; // contador pra ver quantas strings devem ser alocadas
	int	i; // índice pra andar nas casas de s

	count = 0; // contador começa no 0
	i = 0; // inicio a leitura da string na posição 0

	// se a posição inicial da string s já for o '\0', ela está vazia
	// e eu não tenho o que alocar
	if (s[i] == '\0')
	// e eu não tenho o que alocar
	//ela retorna zero e será alocada uma única string, que receberá um NULL
	//ao final da função split
		return (0);

	//se a minha string s não está vazia, entraremos nesse while
	while (s[i])
	{
		// caso a primeira posição da string já seja o caracter de corte
		// isso não será alocado então devemos ir para a próxima posição da
		// string s
		if (i == 0 && s[i] == c)
			i++;
		// caso s[i] seja algo diferente de c, e a próxima posição
		// seja um c, isso indica que eu acabei de passar por uma 'palavra'
		// ou uma string interessante para alocar
		// então o contador aumenta em 1
		if (s[i] != c && s[i + 1] == c)
			count++;
		// e se, em ultimo caso, eu tiver em uma 'palavra' mas a posição seguinte
		// for o '\0', isso também deve ser alocado, então o contador aumenta em 1
		if (s[i] != c && s[i + 1] == '\0')
			count++;
		// e se não for nada disso, eu estou no meio da 'palavra' ou 'string'
		// eu devo seguir para a próxima posição da string s
		i++;
	}
	//acabada a verificação, retorno o meu contador
	return (count);
}


//função principal - COMEÇE LENDO POR AQUI

// essa função cria um array de strings que foram criadas pela subdivisão da string
// s passada como argumento, cada vez que o caracter c é encontrado
char	**ft_split(char const *s, char c)
{
	int		to_cpy; //posição /localização do que dever ser copiado
	int		i; // índice / contador
	int		i_tab; // índice da tabela
	char	**tab; // tabela de strings

	i = 0; //contador inicia no 0
	to_cpy = 0; // posição se inicia no 0
	i_tab = 0; // índice da tabela inicia no 0

	// aloca-se a quantidade de c + 1 (da string nula)
	// para saber a quantidade de c, uso uma função que conta esses c's
	tab = (char **) malloc (sizeof(char *) * (count_to_malloc(s, c) + 1));

	// enquando a string S existir, ou não acabar e houver o que copiar, isto é
	// count_to_malloc retornar > 0
	while (s[i] && count_to_malloc(s, c) > 0)
	{
		// s[i] && s[i] == c, eu só ando pra próxima casa, pois não me interessa 
		// copiar o c
		while (s[i] && s[i] == c)
			i++;
		// quando ele parar de ser igual ao c, essa é a primeira posição
		//que devo copiar, por isso o to_cpy recebe o valor de i
		to_cpy = i;
		// agora veremos até quando s[i] != c, e essas posições correspondem a i
		while (s[i] && s[i] != c)
			i++;
		// se o i avançar, ele será maior que a primeira posição pra copiar (to_cpy)
		if (i > to_cpy)
		{
			// aí nesse caso, a posição 1(i) da tabela recebe a sub.string de s
			// começando no 1o caracter interessante, e com o tamanho indo
			// de to_cpy até i
			tab[i_tab] = ft_substr(s, to_cpy, i - to_cpy);
			// aí avanço pra próxima posição da tabela
			i_tab++;
		}
	}
	//a posição final recebe uma string NULA
	tab[i_tab] = NULL;
	//e eu retorno minha tabela de strings criada
	return (tab); // retorno minha tabela, ou array de strings criado
}