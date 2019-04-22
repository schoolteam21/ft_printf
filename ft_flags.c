/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:24:49 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/03/25 20:51:06 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_last_flags(t_struct ds, char **str)
{
	if (ds.f[0] == '0')
		ft_null_maker(ds, str);
	if (ds.f[1] == '-')
		ft_minus_maker(ds, str);
	if (ds.f[3] == ' ' || ds.f[2] == '+')
		ft_plus_space_maker(ds, str);
	if (ds.f[4] == '#')
		ft_hash_maker(ds, str);
}

t_struct	ft_new_flags(t_struct ds, char **str)
{
	int		i;
	int		j;
	char	flags[6];

	if (*str)
		j = 0;
	i = ds.p;
	j = 0;
	ft_memset(flags, '*', 6);
	flags[5] = '\0';
	while (i >= 0)
	{
		while (ds.f[i] != FLAGS[j] && i >= 0)
			j++;
		flags[j] = FLAGS[j];
		j = 0;
		i--;
	}
	ft_memset(ds.f, 0, ft_strlen(ds.f));
	ft_strcpy(ds.f, flags);
	ds.p = 4;
	return (ds);
}

t_struct	ft_wp(t_struct ds, char **str)
{
	int i;

	ds.pres = 0;
	i = ds.p;
	if ((ds.f[i] >= '0' && ds.f[i] <= '9' && !ds.width) || ds.f[i] == '.')
	{
		if (ft_strrchr(ds.f, '.') && ds.type != 'f')
		{
			ds = ft_precision(ds, str);
			ds.pres = 1;
		}
		ds = ft_width(ds, str);
	}
	return (ds);
}

t_struct	ft_flags(t_struct ds, char **str)
{
	ds.width = 0;
	if ((*str)[0] == '-')
		ds.sign = '-';
	if (ds.p >= 0)
	{
		if ((ds.f[ds.p] >= '0' && ds.f[ds.p] <= '9' && !ds.width)
		|| ds.f[ds.p] == '.')
			ds = ft_wp(ds, str);
		if (ds.p >= 0)
			ds = ft_new_flags(ds, str);
	}
	if (ds.p < 0)
		return (ds);
	if ((ds.f[0] == '0' && ds.f[1] == '-')
	|| (ds.f[0] == '0' && ds.pres) || (ds.f[0] == '0' && !ds.width))
		ds.f[0] = '*';
	if ((ds.f[0] == '0' && ds.f[4] == '#' && ds.type == 'o'))
		ds.f[4] = '*';
	if (ds.f[3] == ' ' && ds.f[2] == '+')
		ds.f[3] = '*';
	if ((ds.f[2] == '+' || ds.f[3] == ' ') && ds.f[4] == '#'
	&& (ds.type == 'd' || ds.type == 'i'))
		ds.f[4] = '*';
	ft_last_flags(ds, str);
	return (ds);
}
