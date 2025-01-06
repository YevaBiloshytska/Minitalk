# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybiloshy <ybiloshy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 19:58:06 by ybiloshy          #+#    #+#              #
#    Updated: 2025/01/04 14:04:32 by ybiloshy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT			=		client
NAME_SERVER			=		server

LIBFT				=		./libraries/Libft/libft.a
FT_PRINTF			=		./libraries/ft_printf/libftprintf.a
LIB_DIRS			=		-L./libraries/Libft -L./libraries/ft_printf
LIBS				=		-lft -lftprintf

CC					=		cc
CFLAGS				=		-Wall -Werror -Wextra -g -I./libraries/Libft -I./libraries/ft_printf
RM					=		rm -f

SRC_CLIENT			=		client.c
SRC_SERVER			=		server.c

OBJ_CLIENT			=		${SRC_CLIENT:.c=.o}
OBJ_SERVER			=		${SRC_SERVER:.c=.o}

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIB_DIRS) $(LIBS)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(LIB_DIRS) $(LIBS)
			
$(LIBFT):
	make -C libraries/Libft

$(FT_PRINTF):
	make -C libraries/ft_printf
					
clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	make clean -C libraries/Libft
	make clean -C libraries/ft_printf			

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	make fclean -C libraries/Libft
	make fclean -C libraries/ft_printf

re: fclean all

.PHONY: all clean fclean re