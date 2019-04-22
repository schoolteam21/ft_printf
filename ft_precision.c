/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:11:28 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/03/25 20:32:09 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_struct	ft_precision_float_2(t_struct ds, int *p, int i)
{
	char *flag;

	if (ft_strrchr(ds.f, '.'))
	{
		while (ds.f[i] != '.')
			i--;
		if (i == ds.p || ft_atoi(ft_strrchr(ds.f, '.') + 1) == 0)
			ds.pres = 0;
		flag = ft_strsub(ds.f, i + 1, (ds.p - i));
		*p = ft_atoi(flag);
		ft_strdel(&flag);
		ds.p = i - 1;
	}
	else
		*p = 6;
	return (ds);
}

t_struct	ft_precision_float(t_struct ds, long double *num)
{
	int i;
	int p;

	i = ds.p;
	ds.width = 0;
	if ((ds.f[i] >= '0' && ds.f[i] <= '9' && !ds.width) || ds.f[i] == '.')
		ds = ft_precision_float_2(ds, &p, i);
	else
		p = 6;
	ds.pres = p;
	(p == 0) ? (ds.kostil = 1)
	: (ds.kostil = 0);
	i = 0;
	while (i <= p + 1 && *num * 10 <= 9223372036854775807)
	{
		*num *= 10;
		i++;
	}
	if (*num - (long long int)(*num) > 0.5)
		(*num)++;
	*num = ft_round(*num);
	*num /= 100;
	return (ds);
}

t_struct	ft_precision_s(t_struct ds, char **str, int p, int i)
{
	char *flag;

	if ((size_t)p < ft_strlen(*str))
	{
		flag = *str;
		*str = ft_strsub(flag, 0, p);
		ft_strdel(&flag);
	}
	ds.p = i - 1;
	return (ds);
}

t_struct	ft_precision_num(t_struct ds, char **str, int p, int i)
{
	char *flag;

	if (*str[0] == '-')
	{
		if ((size_t)p >= ft_strlen(*str))
		{
			flag = *str;
			*str = ft_back_copy(flag, p, '-');
			ft_strdel(&flag);
		}
	}
	else if ((size_t)p > ft_strlen(*str))
	{
		p--;
		flag = *str;
		*str = ft_back_copy(flag, p, '+');
		ft_strdel(&flag);
	}
	ds.p = i - 1;
	return (ds);
}

t_struct	ft_precision(t_struct ds, char **str)
{
	int		p;
	int		i;
	char	*flag;

	i = ds.p;
	if ((ft_atoi(*str) == 0) && (ft_atoi((ft_strrchr(ds.f, '.') + 1)) == 0)
	&& (ds.type != '%'))
		(*str)[0] = '\0';
	while (ds.f[i] != '.')
		i--;
	if (ft_strlen(ds.f) > 1)
	{
		flag = ft_strsub(ds.f, i + 1, (ds.p - i));
		p = ft_atoi(flag);
		ft_strdel(&flag);
	}
	else
		p = 0;
	if (ds.type == 's')
		ds = ft_precision_s(ds, str, p, i);
	else if (ds.type == 'p' || ds.type == 'c' || ds.type == '%')
		ds.p = i - 1;
	else if (ds.dp > 2 && ds.dp <= 8)
		ds = ft_precision_num(ds, str, p, i);
	return (ds);
}
