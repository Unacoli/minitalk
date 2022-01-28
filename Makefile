# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nargouse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 14:54:05 by nargouse          #+#    #+#              #
#    Updated: 2022/01/28 14:36:36 by nargouse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
INCLUDE = ./include
LIBFT	= ./libft/libft.a
LIB	= $(LIBFT)
CFLAGS	+= -Wall -Werror -Wextra -DLINUX

SRCS	= $(addprefix ./srcs/, main.c free.c pa.c pb.c ra.c rb.c rra.c rrb.c\
	  	rr.c rrr.c sa.c sb.c ss.c error.c stack.c sort.c sort_3.c\
		sort_under_5.c sort_over_5.c index.c)

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $@

srcs/%.o: srcs/%.c
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) --no-print-directory -C ./libft 

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

norm:
	norminette ./**/*.c ./**/*.h && echo Norm OK || echo /!\\ Norm KO /!\\

re:	fclean all

.PHONY:	all clean fclean test norm re
