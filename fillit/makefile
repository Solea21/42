# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 16:39:43 by nakorchi          #+#    #+#              #
#    Updated: 2019/12/14 23:01:10 by nakorchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror

#ifeq 
#endif

LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a
LIB_LINK = -L $(LIB_PATH)

INC_DIR = includes
INC = fillit.h
INC_FLAG = -I $(INC_DIR) -lft

OBJ_DIR = obj

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

SRC_DIR = src
SRC = main.c parsing.c bw_translation_32.c tool_box_0.c tool_box_1.c \
tool_box_2.c solve.c init_masta.c display.c bw_translation_3.c\

all: $(NAME)

$(NAME): obj $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(INC_FLAG) $(LIB_LINK) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(LIB_PATH) -I $(INC_DIR) -c $< -o $@

$(LIB):
	make -C $(LIB_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(LIB_PATH) -I $(INC_DIR) -c $< -o $@

obj:
	mkdir -pv obj

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJS)
	rm -Rf obj

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
