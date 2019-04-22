/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:48:55 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/03/27 15:08:06 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_hash_maker_3(t_struct ds, char **str)
{
	char *tmp;

	if (ds.isnull && (ds.type == 'x' || ds.type == 'X'))
		return ;
	tmp = *str;
	if (ds.type == 'x' || ds.type == 'X')
		(ds.type == 'X') ? (*str = ft_add(tmp, "0X", ds))
		: (*str = ft_add(tmp, "0x", ds));
	else if (ds.type == 'o')
		*str = ft_add(tmp, "0", ds);
	ft_strdel(&tmp);
}

void	ft_hash_maker_2(t_struct ds, char **str, int len)
{
	if (!ds.width)
		(*str)[0] = '\0';
	else
	{
		(*str)[len - 1] = ' ';
		(*str)[len - 2] = ' ';
	}
}

int		ft_hash_kostil(t_struct ds, char **str)
{
	int		i;
	char	*tmp;
	int		check;

	i = 0;
	check = 0;
	if ((*str)[i] == '0' || (*str)[i] == ' ')
	{
		if ((*str)[i] == '0')
			while ((*str)[i] == '0')
				i++;
		else
			while ((*str)[i] == ' ')
				i++;
	}
	if (i == 1)
	{
		tmp = *str;
		(ds.type == 'x') ? (*str = ft_strjoin("0x", tmp + 1))
		: (*str = ft_strjoin("0X", tmp + 1));
		ft_strdel(&tmp);
		check = 1;
	}
	return (check);
}

void	ft_hash_maker_1(t_struct ds, char **str, int i)
{
	int check;

	check = 0;
	if (ft_atoi(*str) == 0 && (ds.type == 'o'))
		return ;
	if (ds.isnull && (ds.type == 'x' || ds.type == 'X'))
		return ;
	if ((ds.type == 'x' || ds.type == 'X')
	&& ((*str)[0] == '0' && (*str)[1] == '\0'))
		ds.pres ? ((*str)[0] = '\0')
		: ((*str)[0] = '0');
	if ((ds.f[0] == '0' || (*str[0] == ' '))
	&& (ds.type == 'x' || ds.type == 'X'))
		check = ft_hash_kostil(ds, str);
	if (((ds.type == 'x' || ds.type == 'X') && !check)
	|| ((*str)[0] != 0 && (*str)[1] == '\0'))
	{
		(ds.type == 'X') ? ((*str)[i - 1] = 'X')
		: ((*str)[i - 1] = 'x');
		((*str)[i - 2] = '0');
	}
	if (ds.type == 'o')
		((*str)[i - 1] = '0');
}

void	ft_hash_maker(t_struct ds, char **str)
{
	int		i;
	int		len;

	i = 0;
	if (ds.type != 'x' && ds.type != 'X' && ds.type != 'f' && ds.type != 'o')
		return ;
	if (ds.type == 'f')
	{
		(ds.kostil == 1) ? ft_kostil(1, str, ds) : ft_kostil(0, str, ds);
		return ;
	}
	len = ft_strlen(*str);
	while ((*str)[i] == ' ')
		i++;
	(i == 0 && !ds.pres) ? i++ : i;
	((*str)[i] == '0' && ds.pres && (ds.type == 'o')) ? i++ : i;
	(ds.f[0] == '0') ? i++ : i;
	((i > 0 && ds.width && ds.f[1] == '*')
	|| ((*str)[0] == '0' && (*str)[1] == '\0')
	|| (ds.type == 'o' && i > 0 && (*str)[0] == '0')) ?
	ft_hash_maker_1(ds, str, i) : ft_hash_maker_3(ds, str);
	if ((ds.type == 'x' || ds.type == 'X') && (((*str)[len - 1] == 'x'
	|| ((*str)[len - 1] == 'X')) && (*str)[len - 2] == '0') && ds.isnull)
		ft_hash_maker_2(ds, str, len);
}
