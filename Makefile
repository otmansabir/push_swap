# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osabir <osabir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 13:04:12 by osabir            #+#    #+#              #
#    Updated: 2023/04/29 15:49:38 by osabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 

FLAGS = -Wall -Wextra -Werror

SRC = mandatory/push_swap.c mandatory/ab.c mandatory/needed_1.c \
		mandatory/needed_2.c mandatory/needed_3.c mandatory/needed_4.c \
		mandatory/needed_5.c mandatory/rr.c \
		mandatory/ss.c mandatory/rrr.c mandatory/para_1.c \
		mandatory/sort_100.c mandatory/sort_100_2.c \
		mandatory/sort_500.c mandatory/sort_500_2.c 

LIBFT_SRC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
		libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c \
		libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c \
		libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
		libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/libft.h

OBJ = $(SRC:.c=.o)

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
NAME = push_swap
LIBFT = libft/libft.a

HD = ./mandatory/push_swap.h

all : $(LIBFT) $(NAME)

$(LIBFT) : $(LIBFT_OBJ) 
	make -C  libft/

$(NAME) : $(OBJ) $(LIBFT) 
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o : %.c $(HD) 
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)
	make clean -C libft/

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft/

re : fclean all