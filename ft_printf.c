/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:41:50 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/03/25 19:44:57 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_struct	ft_print_args(t_struct ds, va_list ap)
{
	if (!(ft_check_err(ds)))
	{
		ds.type = '0';
		ft_strdel(&(ds.f));
		return (ds);
	}
	if (ds.dp == 0)
		ds = ft_print_char(ds, ap);
	else if (ds.dp <= 2)
		ds = ft_print_pointer(ds, ap);
	else if (ds.dp <= 8)
		ds = ft_print_numbers(ds, ap);
	else if (ds.dp == 9)
		ds = ft_print_float(ds, ap);
	else if (ds.dp == 10)
		ds = ft_print_procent(ds);
	return (ds);
}

t_struct	ft_struct_null(t_struct ds)
{
	ds.f = NULL;
	ds.pres = 0;
	ds.width = 0;
	ds.ret = 0;
	ds.type = '0';
	ds.dp = 0;
	ds.p = 0;
	ds.sign = '+';
	ds.kostil = 0;
	ds.isnull = 0;
	return (ds);
}

t_struct	ft_definer(char *str, int i)
{
	t_struct	ds;
	int			j;
	int			temp;

	temp = i;
	j = 0;
	ds.type = '0';
	ds = ft_struct_null(ds);
	while (str[i])
	{
		while (str[i] != DEFINE[j] && DEFINE[j])
			j++;
		if (str[i] == DEFINE[j])
		{
			ds.type = DEFINE[j];
			ds.dp = j;
			ds.f = ft_strsub(str, temp, i - temp);
			ds.p = i;
			return (ds);
		}
		j = 0;
		i++;
	}
	return (ds);
}

int			ft_read_format(char *str, va_list ap)
{
	int			i;
	t_struct	ds;
	int			ret;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			ret++;
			i++;
			continue ;
		}
		ds = ft_definer(str, i + 1);
		i = ds.p;
		(ds.type != '0') ? ds = ft_print_args(ds, ap) : ds;
		if (ds.type == '0')
			return (-1);
		ft_strdel(&(ds.f));
		ret += ds.ret;
		i++;
	}
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_read_format((char*)format, ap);
	va_end(ap);
	return (ret);
}
