/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:56:56 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/03/25 21:42:51 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int	ft_round(long long int num)
{
	char			*str;
	long long int	rest;
	long long int	test;
	int				round;

	str = ft_itoa(num);
	str[ft_strlen(str) - 1] = '0';
	str[ft_strlen(str) - 2] = '0';
	round = str[ft_strlen(str) - 3] - '0';
	test = ft_atoi(str);
	rest = num - test;
	ft_strdel(&str);
	if (rest == 50)
		(round % 2 != 0 && round != 1) ? num += 100 : num;
	else if (rest > 50)
		num += 100;
	ft_strdel(&str);
	return (num);
}

void			ft_print_float_no_pres(long double num, char **str)
{
	int		i;

	num *= 100;
	i = (*str)[ft_strlen(*str) - 1] - '0';
	if ((int)num == 50)
		(i % 2) ? i++ : i;
	else if ((int)num > 50)
		i++;
	(*str)[ft_strlen(*str) - 1] = i + '0';
}

char			*ft_print_float_pres(t_struct ds, long double num, char **str)
{
	char *str2;
	char *str3;
	char *res;

	if (num < 0)
		res = ft_itoa((unsigned long long)num * -1);
	else
		res = ft_itoa((long long int)num);
	if ((size_t)ds.pres > ft_strlen(res))
	{
		str2 = ft_strnew(ds.pres - ft_strlen(res));
		ft_memset(str2, '0', ds.pres - ft_strlen(res));
		str3 = ft_strjoin(".", str2);
		ft_strdel(&str2);
		str2 = ft_strjoin(str3, res);
	}
	else
		str2 = ft_strjoin(".", res);
	ft_strdel(&res);
	res = ft_strjoin(*str, str2);
	ft_strdel(str);
	ft_strdel(&str2);
	return (res);
}

t_struct		ft_print_float(t_struct ds, va_list ap)
{
	char		*str;
	char		*res;
	long double	num;

	str = NULL;
	res = NULL;
	num = ft_float_size(ds, ap);
	str = ft_itoa((long long)num);
	(num < 0) ? (num *= -1) : (num);
	num = num - (long)num;
	ds = ft_pointer_move(ds);
	ds = ft_precision_float(ds, &num);
	if (ds.pres != 0)
		res = ft_print_float_pres(ds, num, &str);
	else
	{
		ft_print_float_no_pres(num, &str);
		res = str;
	}
	ft_flags(ds, &res);
	ds.ret = ft_strlen(res);
	ft_putstr(res);
	ft_strdel(&res);
	return (ds);
}

long double		ft_float_size(t_struct ds, va_list ap)
{
	int i;

	i = ft_strlen(ds.f);
	if (*ds.f)
	{
		if (ds.f[i - 1] == 'l')
			return ((double)va_arg(ap, double));
		else if (ds.f[i - 1] == 'L')
			return ((double)va_arg(ap, long double));
	}
	return ((double)va_arg(ap, double));
}
