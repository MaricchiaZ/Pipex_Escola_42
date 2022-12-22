/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:39:36 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/21 22:19:57 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> // para usar a função fork, read, close
# include <stdlib.h>
# include <fcntl.h> // open, pipe
# include <stdio.h> // RETIRAR * RETIRAR * RETIRAR * RETIRAR * RETIRAR * RETIRAR * 

# define PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin/"
/usr/local/sbin
/usr/local/bin
/usr/sbin
/usr/bin
/sbin
/bin/

typedef struct s_arguments
{
	char	*file_in;
	char	*cmd1;
	char	*cmd2;
	char	*file_out;
}	t_arg;

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	char	**mtx_cmd;
	int		pipefd[2];
	char	*path_cmd;
	char	*cmd;
	t_arg	args;
}	t_px;

// utils.c
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

// check.c
int		check_arguments(int argc);
int		save_arguments(char **argv, t_px *pipex);

// init.c
void	init_struct_args(t_arg *args);

// open.c
void	open_file(t_px *pipex);
void	free_matrix(t_px *pipex);
void	free_pipex(t_px *pipex);


#endif