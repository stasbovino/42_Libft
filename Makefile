# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 17:48:56 by gwyman-m          #+#    #+#              #
#    Updated: 2019/04/04 14:32:20 by gwyman-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

FLAGS = -Wall -Wextra -Werror -c -Iincludes

CFILES=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memrevcpy.c ft_memset.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
ft_lstsplit.c ft_numlen.c ft_countwords.c ft_itoa_base.c ft_strrejoin.c \
ft_strcpy_whilech.c get_next_line.c ft_countchars.c ft_strchrpos.c ft_sqrt.c \
ft_get_coords.c ft_isupper.c ft_islower.c ft_create_coords.c ft_strtrim_all.c \
ft_strchr_replace.c ft_strchr_swap.c

OFILES=$(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rc libft.a $(OFILES)
	ranlib libft.a

$(OFILES): $(CFILES) includes/libft.h
	gcc $(FLAGS) $(CFILES)

clean:
	rm -fv $(OFILES)

fclean: clean
	rm -fv libft.a

re: fclean all
