/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhelly <dhelly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:01:30 by dhelly            #+#    #+#             */
/*   Updated: 2019/03/27 15:27:44 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"
# define DEFINE "cspdiouxXf%"
# define FLAGS "0-+ #"

typedef struct	s_struct
{
	char		type;
	char		*f;
	int			dp;
	int			p;
	int			pres;
	int			width;
	char		sign;
	int			kostil;
	int			ret;
	int			isnull;
}				t_struct;

int				ft_printf(const char *format, ...);
t_struct		ft_definer(char *str, int i);
int				ft_read_format(char *str, va_list ap);
t_struct		ft_print_char(t_struct ds, va_list ap);
t_struct		ft_print_pointer(t_struct ds, va_list ap);
t_struct		ft_print_numbers(t_struct ds, va_list ap);
t_struct		ft_print_args(t_struct ds, va_list ap);
char			*ft_itoa_base_unsigned(unsigned long long int nb,
				int base, char x);
long long int	ft_size(t_struct ds, va_list ap);
t_struct		ft_flags(t_struct ds, char **str);
t_struct		ft_wp(t_struct ds, char **str);
t_struct		ft_precision(t_struct ds, char **str);
t_struct		ft_pointer_move(t_struct ds);
char			*ft_back_copy(char *num, int p, char sign);
char			*ft_copy_width(char *num, t_struct ds);
t_struct		ft_width(t_struct ds, char **str);
void			ft_last_flags(t_struct ds, char **str);
void			ft_minus_maker(t_struct ds, char **str);
void			ft_plus_space_maker(t_struct ds, char **str);
void			ft_hash_maker(t_struct ds, char **str);
void			ft_null_maker(t_struct ds, char **str);
t_struct		ft_new_flags(t_struct ds, char **str);
char			*ft_add(char *num, char *str, t_struct ds);
t_struct		ft_print_float(t_struct ds, va_list ap);
long double		ft_float_size(t_struct ds, va_list ap);
long long int	ft_round(long long int num);
t_struct		ft_precision_float(t_struct ds, long double *num);
void			ft_kostil(int kostil, char **str, t_struct ds);
t_struct		ft_print_procent(t_struct ds);
t_struct		ft_struct_null(t_struct ds);
void			ft_add_2(char *num, char **res, t_struct ds, int l);
void			ft_kostil_2(char **str, int i);
void			ft_hash_maker_1(t_struct ds, char **str, int i);
void			ft_hash_maker_2(t_struct ds, char **str, int len);
void			ft_hash_maker_3(t_struct ds, char **str);
t_struct		ft_width_2(t_struct ds, char **str, int i);
t_struct		ft_precision_float_2(t_struct ds, int *p, int i);
t_struct		ft_precision_num(t_struct ds, char **str, int p, int i);
t_struct		ft_char_0(char adr, t_struct ds);
char			*ft_print_float_pres(t_struct ds, long double num, char **str);
void			ft_print_float_no_pres(long double num, char **str);
long long int	ft_size_2(t_struct ds, va_list ap, int i);
t_struct		ft_null_detector(t_struct ds, char *str);
int				ft_hash_kostil(t_struct ds, char **str);
int				ft_check_err(t_struct ds);

#endif
