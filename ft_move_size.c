/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_size_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 21:45:17 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/03/27 15:05:34 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_struct		ft_null_detector(t_struct ds, char *str)
{
	if (str[0] == '0' && str[1] == '\0')
		ds.isnull = 1;
	return (ds);
}

t_struct		ft_pointer_move(t_struct ds)
{
	int i;

	i = ft_strlen(ds.f);
	if (ds.f[i - 1] == 'l' || ds.f[i - 1] == 'h' || ds.f[i - 1] == 'j')
		ds.p = (ds.f[i - 2] == 'l' || ds.f[i - 2] == 'h') ? (i - 3) : (i - 2);
	else if (ds.f[i - 1] == 'L')
		ds.p = i - 2;
	else
		ds.p = i - 1;
	return (ds);
}

long long int	ft_size_2(t_struct ds, va_list ap, int i)
{
	if ((ds.f[i - 1] == 'l' && ds.f[i - 2] == 'l') || ds.f[i - 1] == 'j')
		return (va_arg(ap, long long int));
	else if (ds.f[i - 1] == 'h' && ds.f[i - 2] == 'h')
		return ((ds.dp >= 5 && ds.dp <= 8) ?
				(unsigned char)va_arg(ap, long long int)
				: (char)va_arg(ap, long long int));
	else if (ds.f[i - 1] == 'l')
		return ((ds.dp >= 5 && ds.dp <= 8) ?
				(unsigned long int)va_arg(ap, long long int)
				: (long int)va_arg(ap, long long int));
	else if (ds.f[i - 1] == 'h')
		return ((ds.dp >= 5 && ds.dp <= 8) ?
				(unsigned short int)va_arg(ap, long long int) :
				(short int)va_arg(ap, long long int));
	else
		return (va_arg(ap, int));
}

long long int	ft_size(t_struct ds, va_list ap)
{
	int i;

	i = ft_strlen(ds.f);
	if (*ds.f)
		if (ds.f[i - 1] == 'l' || ds.f[i - 1] == 'h')
			return (ft_size_2(ds, ap, i));
	if (ds.dp >= 5 && ds.dp <= 8)
		return (va_arg(ap, unsigned int));
	return (va_arg(ap, int));
}
