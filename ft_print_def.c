/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:57:35 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/03/25 21:57:11 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_struct	ft_print_procent(t_struct ds)
{
	char *adr;

	ds.p = ft_strlen(ds.f) - 1;
	if (ds.type == '%')
	{
		adr = ft_strnew(1);
		adr[0] = '%';
		ft_flags(ds, &adr);
		ds.ret = ft_strlen(adr);
		ft_putstr(adr);
		ft_strdel(&adr);
	}
	return (ds);
}

t_struct	ft_char_0(char adr, t_struct ds)
{
	int check;

	check = 0;
	ds.width = ft_atoi(ds.f);
	if (ds.width < 0)
	{
		ds.width *= -1;
		ft_putchar(adr);
		check = 1;
	}
	if (ds.width > 1)
		ds.ret = ds.width;
	while (ds.width > 1)
	{
		ft_putchar(' ');
		ds.width--;
	}
	if (!check)
		ft_putchar(adr);
	return (ds);
}

t_struct	ft_print_char(t_struct ds, va_list ap)
{
	char *adr;

	ds.ret = 0;
	ds.p = ft_strlen(ds.f) - 1;
	if (ds.type == 'c')
	{
		adr = ft_strnew(1);
		adr[0] = va_arg(ap, int);
		if (adr[0] == 0)
		{
			ds.ret = 1;
			adr[0] = '\x00';
			ds = ft_char_0(adr[0], ds);
		}
		else
		{
			ft_flags(ds, &adr);
			ds.ret += ft_strlen(adr);
			ft_putstr(adr);
		}
		ft_strdel(&adr);
	}
	return (ds);
}

t_struct	ft_print_pointer(t_struct ds, va_list ap)
{
	char *adr;

	ds.p = ft_strlen(ds.f) - 1;
	ds.ret = 0;
	adr = NULL;
	if (ds.type == 's')
		adr = ft_strdup(va_arg(ap, char *));
	else if (ds.type == 'p')
		adr = ft_itoa_base_unsigned((long long int)va_arg(ap, char *), 16, 'x');
	if (!adr)
		adr = ft_strdup("(null)");
	ds = ft_flags(ds, &adr);
	ds.ret += ft_strlen(adr);
	if (!ds.width && ds.type == 'p')
	{
		ft_putstr("0x");
		ds.ret += 2;
	}
	ft_putstr(adr);
	ft_strdel(&adr);
	return (ds);
}

t_struct	ft_print_numbers(t_struct ds, va_list ap)
{
	char *str;

	str = NULL;
	if (ds.type == 'd' || ds.type == 'i')
		str = ft_itoa(ft_size(ds, ap));
	else if (ds.type == 'u')
		str = ft_itoa_base_unsigned(ft_size(ds, ap), 10, 'u');
	else if (ds.type == 'o')
		str = ft_itoa_base_unsigned(ft_size(ds, ap), 8, 'x');
	else if (ds.type == 'x')
		str = ft_itoa_base_unsigned(ft_size(ds, ap), 16, 'x');
	else if (ds.type == 'X')
		str = ft_itoa_base_unsigned(ft_size(ds, ap), 16, 'X');
	if (ds.type == 'x' || ds.type == 'X')
		ds = ft_null_detector(ds, str);
	ds = ft_pointer_move(ds);
	ft_flags(ds, &str);
	ds.ret = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (ds);
}
