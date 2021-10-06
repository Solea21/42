# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakorchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 06:22:42 by nakorchi          #+#    #+#              #
#    Updated: 2019/12/15 00:19:17 by nakorchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memalloc.c \
	ft_putchar.c ft_putstr.c ft_strcat.c \
	ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	ft_strdup.c ft_strjoin.c ft_memchr.c ft_memdel.c\
	ft_strlen.c ft_memcpy.c ft_memmove.c ft_strnstr.c\
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnew.c \
	ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strtrim.c \
	ft_toupper.c ft_tolower.c ft_memset.c ft_strdel.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_putchar_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c  \
	ft_putendl.c ft_memcmp.c ft_memccpy.c ft_itoa.c \
	ft_strlcat.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_putnbr.c
HDR = libft.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

AR = ar -rc

OBJ = $(SRC:.c=.o) 

debug:
	make all DEBUG=1

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@ 

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
