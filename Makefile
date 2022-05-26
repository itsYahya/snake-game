# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 18:01:09 by yel-mrab          #+#    #+#              #
#    Updated: 2022/05/26 13:41:20 by yel-mrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
INC = -I ./inc

FILES = main utils events moves \
		list/lstaddback list/lstaddfront list/lstlast list/lstnew list/lstsize
BDIR = build
OBJS = $(addprefix $(BDIR)/, $(FILES:=.o))

NAME = snake

all : $(NAME)
	
$(NAME) : $(OBJS)
	$(CC) $(MLXFLAGS) $(OBJS) -o $(NAME)

$(BDIR)/%.o : src/%.c inc/snake.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean :
	rm -rf $(BDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : re fclean clean all