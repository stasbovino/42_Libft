/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:07:02 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/19 22:19:33 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct	s_options
{
	int		left_side;
	int		sign;
	int		space;
	int		alt_out;
	int		zeros;
	int		width;
	int		prec;
	char	*len_mod;
	char	type;
}				t_options;

int				ft_printf(const char *format, ...);
int				prepare_opt(char *format, size_t *begin, va_list *args);
int				print_type(t_options *opt, va_list *args);

/*
**		func for 's' conv
*/

void			define_width(char *format, int *width, size_t *i);
void			define_prec(char *format, int *prec, size_t *i);
int				flags(t_options *opt, char c);
int				parse_type(t_options *opt, char c);
void			parse_len_mod(t_options *opt, char *format);

/*
**		func for 'd' conv
*/

int				count_and_free(char *buff);
int				length(size_t n, size_t base);
char			*ft_itoa_sizet(size_t nb, size_t base, int uppercase);
void			set_sign(char *s, int *signfp, int *i, int side);
void			apply_len_mod(intmax_t *n, char *len_mod);
void			create_signfp(int *signfp, t_options *opt, intmax_t n);
char			*create_buff(t_options *opt, int lennum, int signfp);
void			left_side_output(char *buff, int signfp,
		t_options *opt, char *num);
void			right_side_output(char *buff, int signfp,
		t_options *opt, char *num);
char			*create_dig_output(char *num, t_options *opt, int signfp);

/*
**		func for 'uoxX' conv
*/

void			create_signfp_u(int *signfp, t_options *opt, uintmax_t n);
void			apply_len_mod_u(uintmax_t *n, char *len_mod);
char			set_sign_u(int signfp);
void			set_len_from_signfp(int *len, int signfp);

/*
**		func for 'fF' conv
*/

char			*mant_double(char *mant, char *num, int denorm, int dcase);
char			*rounding(char *num, t_options *opt, int i, int j);
char			*create_fnum(char *mant, int exp, int denorm, int dcase);
char			*bits_div(char *bits, t_options *opt, int dcase);
char			*ft_itoa_double(double *n, t_options *opt, int *signfp);
void			overf(char *buf, int i);
void			summ(char *t, char **buf, int i);
void			divis(char **buf, int i);
char			*ft_itoa_longdouble(long double *n,
		t_options *opt, int *signfp);
void			set_fsignfp(char *num, int *signfp, int i);
void			create_fsignfp(int *signfp, t_options *opt, char *bits);
char			*create_float_output(char *num, t_options *opt, int signfp);
char			*is_inf(char *bits, t_options *opt);

/*
**		types
*/

int				print_f(double n, t_options *opt);
int				print_lf(long double n, t_options *opt);
int				print_p(void *p, t_options *opt);
int				print_s(char *s, t_options *opt);
int				print_c(char c, t_options *opt);
int				print_d(intmax_t n, t_options *opt);
int				print_u(uintmax_t u, t_options *opt);
int				print_o(uintmax_t o, t_options *opt);
int				print_x(uintmax_t u, t_options *opt);

/*
**		libft func
*/

char			*ft_optstrrejoin(char *s1, char *s2, int opt);
int				ft_atoi_binary(char *s);
void			make_str_upper(char *s);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dest, const char *src);
int				ft_atoi(const char *str);
char			*ft_strnew(size_t size);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strrejoin(char *s1, char *s2);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
void			ft_bzero(void *s, size_t n);
int				ft_isdigit(int c);
char			*ft_itoa_base(long n, int osn, int opt);
int				ft_strcmp(const char *s1, const char *s2);

#endif
