# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 14:54:05 by nargouse          #+#    #+#              #
#    Updated: 2022/02/01 14:35:58 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= server
NAME_C	= client
INCLUDE = ./include/
LIBFT	= ./libft/libft.a
LIB	= $(LIBFT)
CFLAGS	+= -Wall -Werror -Wextra -DLINUX

FILES	= main_server.c utils.c
SRCS	= $(addprefix ./srcs/, $(FILES))
OBJS	= $(addprefix ./objs/, $(FILES:.c=.o))  

FILES_C	= main_client.c utils.c
SRCS_C	= $(addprefix ./srcs/, $(FILES_C))
OBJS_C	= $(addprefix ./objs/, $(FILES_C:.c=.o))  

all: $(NAME) $(NAME_C)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $@

$(NAME_C): $(LIBFT) $(OBJS_C)
	$(CC) $(OBJS_C) $(LIB) $(CFLAGS) -o $@

objs/%.o: srcs/%.c
	mkdir -p ./objs/
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) --no-print-directory -C ./libft 

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS) $(OBJS_C)

fclean:	clean
	$(RM) $(NAME) $(NAME_C)
	$(RM) $(LIBFT)

norm:
	norminette ./**/*.c ./**/*.h && echo Norm OK || echo /!\\ Norm KO /!\\

re:	fclean all

.PHONY:	all clean fclean test norm re
