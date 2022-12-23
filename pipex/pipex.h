/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:39:36 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/23 13:20:52 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> // para usar a função fork, read, close
# include <stdlib.h> // malloc, free
# include <fcntl.h> // open, pipe

// armazena os argumentos passados por parâmetros
typedef struct s_arguments
{
	char	*file_in; // 2o arg
	char	*cmd1; // 3o arg
	char	*cmd2; // 4o arg
	char	*file_out; // 5o arg
}	t_arg;

typedef struct s_pipex
{
	int		fd_in; //fd para o arquivo de entrada/ file_in ou file1
	int		fd_out; //fd para o arquivo de saída/ file_out ou file2
	char	**mtx_cmd; // vai receber o comando já passado pela split
	int		pipefd[2]; // fd temporário usado pela função pipe que conecta dos dois processos criados pela função fork
	char	*path_cmd; // vai receber o caminho passado por parâmetro env
	t_arg	args; // struct args
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

// init_free.c
void	init_struct_args(t_arg *args);
void	free_matrix(char **mtx);
void	free_pipex(t_px *pipex);

// path.c
char	*my_path_join(char const *s1, char const *s2);
char    *get_path(char **env, char *cmd);

// cmd.c
char	**get_cmd(char *s);

// main.c
void	child_cmd(t_px pipex, char **env);
void	parent_cmd(t_px pipex, char **env);

#endif