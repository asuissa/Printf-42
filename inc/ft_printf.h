/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:27:23 by tvisenti          #+#    #+#             */
/*   Updated: 2018/02/15 11:21:39 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>

/*
** Code Couleur
*/

# define BLACK "\x1B[30m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define EOC "\033[0m"

char			g_buf[4096];
int				g_i;

typedef struct	s_flag
{
	int			ret;
	char		*frmt;
	int			ndx;
	char		spe;
	char		*arg;
	wchar_t		*warg;

	char		sign;
	va_list		ap;
	int			fla[13];
}				t_flag;

typedef struct	s_spec
{
	char		c;
	int			(*ptr)();
}				t_spec;

/*
** ft_PRINTF
*/

int				ft_printf(const char *format, ...);
void			pf_ft_end(t_flag *f);

/*
** CHECKS
*/

int				pf_ft_check(t_flag *f);
void			pf_ft_check_initialize(t_flag *f);
void			pf_ft_check_flag(t_flag *f);
void			pf_ft_check_width(t_flag *f);
void			pf_ft_check_precision(t_flag *f);
void			pf_ft_check_modifier(t_flag *f);

/*
** UTILS
*/

int				pf_ft_isdigit(int c);
char			*pf_ft_strsub(char const *s, unsigned int start, size_t len);
char			*pf_ft_itoa_base(uintmax_t nbr, int base);
uintmax_t		pf_ft_sign(t_flag *f, intmax_t nbr);
size_t			pf_ft_strlen(const char *str);
long			pf_ft_atoi(const char *str);
char			*pf_ft_strlwr(char *s1);
void			ft_bzero(void *s, size_t n);
char			*ft_itoa_base(long long nb, char *base);
void			*ft_memalloc(size_t size);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strrev(char *str);
char			*ft_itoa(long long n);
long			ft_atoi_base(char *str, char *base);
size_t			ft_strclen(const char *s, char c);
char			*ft_strchr(const char *s, int c);

/*
** Les Wchars
*/

void			pf_ft_putwchar(wchar_t wchar, t_flag *f);
int				pf_ft_wcharlen(wchar_t wchar);
size_t			pf_ft_wbytelen(wchar_t *ws);
size_t			pf_ft_wstrlen(wchar_t *ws);
char			*pf_ft_wstrsub(wchar_t *ws, unsigned int start, size_t len);
char			*pf_ft_strsub_with_free(char const *s, unsigned int start,
		size_t len);
char			*pf_ft_transform_wchar_in_char(wchar_t *ws);
int				pf_ft_putwchar_in_char(wchar_t wchar, char *fresh, int i);

/*
** DISPATCHER
*/

void			pf_ft_initialize_specs(t_spec *specs);
int				pf_ft_dispatcher(t_flag *f, va_list *ap);

/*
** HANDLERS
*/

void			pf_ft_apply_mask(t_flag *f, int *mask);
int				pf_ft_handler_char(t_flag *f);
int				pf_ft_handler_numb(t_flag *f);
int				pf_ft_handler_bonus(t_flag *f);

int				pf_ft_handler_c(t_flag *f, va_list *ap);
int				pf_ft_handler_wc(t_flag *f, va_list *ap);
int				pf_ft_modifier_wc(t_flag *f, va_list *ap);

int				pf_ft_handler_s(t_flag *f, va_list *ap);
int				pf_ft_handler_ws(t_flag *f, va_list *ap);

int				pf_ft_handler_d(t_flag *f, va_list *ap);
int				pf_ft_handler_wd(t_flag *f, va_list *ap);
char			*pf_ft_modifier_d(t_flag *f, va_list *ap);

int				pf_ft_handler_o(t_flag *f, va_list *ap);
int				pf_ft_handler_u(t_flag *f, va_list *ap);
char			*pf_ft_modifier_u_o(t_flag *f, va_list *ap);

int				pf_ft_handler_wo(t_flag *f, va_list *ap);
int				pf_ft_handler_wu(t_flag *f, va_list *ap);
char			*pf_ft_modifier_wu_wo(t_flag *f, va_list *ap);

int				pf_ft_handler_x(t_flag *f, va_list *ap);
int				pf_ft_handler_wx(t_flag *f, va_list *ap);
char			*pf_ft_modifier_x(t_flag *f, va_list *ap);

int				pf_ft_handler_p(t_flag *f, va_list *ap);
int				pf_ft_handler_undefined(t_flag *f);

/*
** Bonus
*/

int				pf_ft_handler_b(t_flag *f, va_list *ap);
int				pf_ft_handler_w(t_flag *f, va_list *ap);
int				pf_ft_handler_m(t_flag *f, va_list *ap);
int				pf_ft_handler_n(t_flag *f, va_list *ap);

/*
** ft_apply_flags.c
*/

void			pf_ft_space_plus_sharp(t_flag *f);
void			pf_ft_sharp(t_flag *f);
void			pf_ft_precision_string(t_flag *f);

/*
** ft_display_numb.c
*/

void			pf_ft_precision_without_width(t_flag *f);
void			pf_ft_precision_numb(t_flag *f, int len);
void			pf_ft_zero_numb(t_flag *f);
void			pf_ft_minus_numb(t_flag *f);
void			pf_ft_width_numb(t_flag *f);

/*
** ft_display_numb.c
*/

void			pf_ft_display_arg(t_flag *f);
void			pf_ft_width_char(t_flag *f);
void			pf_ft_minus_char(t_flag *f);
void			pf_ft_zero_char(t_flag *f);

/*
** ft_buff.c
*/

void			pf_ft_buf(char c, t_flag *f);
void			pf_ft_buf_null(t_flag *f);
void			pf_ft_display(t_flag *f);
void			pf_ft_bufset(void);

#endif
