NAME	= pipex

CC	= cc
INCLUDE		= -I ./
CFLAGS		= -g -Wall -Wextra -Werror $(INCLUDE)

RM	= rm -rf

PATH_SRCS	= ./
PATH_UTILS	= $(PATH_SRCS)utils/
PATH_OBJS	= ./objs/

SRCS	= ./main.c \
		./check.c \
		./init.c \
		$(PATH_UTILS)ft_strdup.c \
		$(PATH_UTILS)ft_strjoin.c \
		$(PATH_UTILS)ft_strlen.c \

OBJS	= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) $(MLXFLAGS)

$(PATH_OBJS)%.o:	$(PATH_SRCS)%.c
		@mkdir -p $(PATH_OBJS)
		@mkdir -p $(PATH_OBJS)gnl/
		@mkdir -p $(PATH_OBJS)utils/
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./objs

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all $(PATH_OBJS) clean fclean re