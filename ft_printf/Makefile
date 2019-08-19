NAME= ../libft.a

SRC_DIR = src/

FLAGS = -g -Wall -Wextra -Werror -I..

CFILES= ft_printf.c parse.c prepare_opt.c print_type.c \
		print_c.c print_s.c print_p.c print_d.c print_u.c \
		print_o.c print_x.c print_f.c print_lf.c \
		itoa.c ftoa.c signfp_func.c create_dig_output.c apply_len_mod.c \
		float_signfp_func.c double_arithmetics.c create_float_output.c \
		atoi_binary.c optstrrejoin.c create_fnum.c def_inf.c make_str_upper.c \
		rounding.c \

OFILES=$(CFILES:%.c=%.o)

SRC = $(addprefix $(SRC_DIR),$(CFILES))

OBJ = $(addprefix $(SRC_DIR),$(OFILES))

VPATH := src

all: $(NAME)

$(NAME): $(OBJ)

src/%.o: %.c ../ft_printf.h
	gcc -c $(FLAGS) $< -o $@

clean:
	rm -fv $(OBJ)

fclean: clean
	rm -fv libftprintf.a

re: fclean all
