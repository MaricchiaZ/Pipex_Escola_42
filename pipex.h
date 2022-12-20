/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:39:36 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/20 16:13:29 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> // RETIRAR * RETIRAR * RETIRAR * RETIRAR * RETIRAR * RETIRAR * 

typedef struct s_arguments
{
	char	*file_in;
	char	*cmd1;
	char	*cmd2;
	char	*file_out;
}	t_arg;

typedef struct s_pipex
{
	t_arg	args;
}	t_px;

// utils.c
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *s);

// check.c
int		check_arguments(int argc);
int		save_arguments(char **argv, t_px *pipex);

// init.c
void	init_struct_args(t_arg *args);

#endif