/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:27:25 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/03/27 15:09:27 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_copy_width(char *num, t_struct ds)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	(ds.type == 'p') ? (len = ft_strlen(num) + 2) :
			(len = ft_strlen(num));
	if ((ds.type == 'p')
	&& (!(res = (char*)ft_memalloc(sizeof(char) * (ds.width + 3)))))
		return (NULL);
	else if (!(res = (char*)ft_memalloc(sizeof(char) * (ds.width + 1))))
		return (NULL);
	while (i < (ds.width - len))
		res[i++] = ' ';
	if (ds.type == 'p')
	{
		res[i++] = '0';
		res[i++] = 'x';
	}
	while (i < ds.width)
	{
		res[i++] = *num;
		num++;
	}
	return (res);
}

t_struct		ft_width_2(t_struct ds, char **str, int i)
{
	char *flag;

	flag = ft_strsub(ds.f, i, ds.p - i + 1);
	ds.width = ft_atoi(flag);
	ft_strdel(&flag);
	if (((size_t)ds.width > ft_strlen(*str) && ds.type != 'p') ||
	((size_t)ds.width > (ft_strlen(*str) + 2) && ds.type == 'p'))
	{
		flag = *str;
		*str = ft_copy_width(flag, ds);
		ft_strdel(&flag);
	}
	else
		ds.width = 0;
	return (ds);
}

t_struct		ft_width(t_struct ds, char **str)
{
	int p;
	int i;

	i = ds.p;
	while (ds.f[i] >= '0' && ds.f[i] <= '9')
		i--;
	p = i++;
	while (ds.f[i] == '0')
	{
		if (i == ds.p)
		{
			ds.p = p;
			return (ds);
		}
		i++;
	}
	ds = ft_width_2(ds, str, i);
	ds.p = i - 1;
	return (ds);
}
