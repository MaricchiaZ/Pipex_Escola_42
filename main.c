/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:39:01 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/20 16:27:48 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_px	pipex;
	
	if (check_arguments(argc) == 0)
		return (-1);
	if (save_arguments(argv, &pipex) == 0)
		return (-1);
	return (0);
}

/*
#include <stdlib.h> 

    int main (int argc, char* argv[]) 
    { 
       system("mkdir NomePasta");
       return 0;
    }
*/