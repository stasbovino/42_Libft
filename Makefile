# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 17:48:56 by gwyman-m          #+#    #+#              #
#    Updated: 2019/08/19 22:36:59 by gwyman-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

FLAGS = -Wall -Wextra -Werror -c -I.

PRINTFSRC_DIR=ft_printf/src/

LIBFTSRC_DIR=libsrc/

CLIBFT=ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
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

CPRINTF= ft_printf.c parse.c prepare_opt.c print_type.c \
		print_c.c print_s.c print_p.c print_d.c print_u.c \
		print_o.c print_x.c print_f.c print_lf.c \
		itoa.c ftoa.c signfp_func.c create_dig_output.c apply_len_mod.c \
		float_signfp_func.c double_arithmetics.c create_float_output.c \
		atoi_binary.c optstrrejoin.c create_fnum.c def_inf.c make_str_upper.c \
		rounding.c \

LIBFTSRC = $(addprefix $(LIBFTSRC_DIR),$(CFILES))

PRINTFSRC = $(addprefix $(PRINTFSRC_DIR),$(CPRINTF))

OLIBFT=$(LIBFTSRC:%.c=%.o)

OPRINTF=$(PRINTFSRC:%.c=%.o)

VPATH := libftsrc:ft_printf/srs

all: $(NAME)

$(NAME): $(OLIBFT) $(OPRINTF)
	ar rc libft.a $(OLIBFT) $(OPRINTF)
	ranlib libft.a

$(PRINTFSRC_DIR)/%.o: %.c ft_printf.h
	gcc $(FLAGS) $< -o $@

$(LIBSRC)/%.o: %.c libft.h
	gcc $(FLAGS) $< -o $@

clean:
	rm -fv $(OLIBFT) $(OPRINTF)

fclean: clean
	rm -fv libft.a

re: fclean all
