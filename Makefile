# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 18:01:09 by yel-mrab          #+#    #+#              #
#    Updated: 2022/05/23 18:21:25 by yel-mrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
INC = -I ./inc

FILES = main utils
BDIR = build
OBJS = $(addprefix $(BDIR)/, $(FILES:=.o))

NAME = snake

all : $(NAME)
	
$(NAME) : $(OBJS)
	$(CC) $(MLXFLAGS) $(OBJS) -o $(NAME)

$(BDIR)/%.o : src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean :
	rm -rf $(BDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : re fclean clean all