/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:30:36 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/03/25 14:58:54 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_plus_space_maker(t_struct ds, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ds.type != 'd' && ds.type != 'i' && ds.type != 'f')
		return ;
	while ((*str)[i] == ' ')
		i++;
	if (i == 0 && !ds.pres && ds.type != 'f' && ds.width && ds.f[0] == '0')
		i++;
	if (ds.sign == '-')
		return ;
	if (i > 0)
		(ds.f[2] == '+') ? ((*str)[i - 1] = '+')
		: ((*str)[i - 1] = ' ');
	else
	{
		tmp = *str;
		(ds.f[2] == '+') ? (*str = ft_add(tmp, "+", ds))
		: (*str = ft_add(tmp, " ", ds));
		ft_strdel(&tmp);
	}
}

void	ft_minus_maker(t_struct ds, char **str)
{
	int		i;
	int		p;
	char	*tmp;

	tmp = *str;
	i = 0;
	p = 0;
	if (!ds.width)
		return ;
	while ((*str)[i] == ' ')
		i++;
	*str = ft_strnew(ft_strlen(tmp));
	while (tmp[i] != '\0')
	{
		(*str)[p] = tmp[i];
		p++;
		i++;
	}
	while ((size_t)p < ft_strlen(tmp))
	{
		(*str)[p] = ' ';
		p++;
	}
	ft_strdel(&tmp);
}

void	ft_null_maker(t_struct ds, char **str)
{
	int i;

	i = 0;
	if (!ds.width)
		return ;
	if (ds.sign == '-')
	{
		(*str)[i++] = '-';
		while ((*str)[i] == ' ' || (*str)[i] == '-')
			(*str)[i++] = '0';
	}
	else
	{
		while ((*str)[i] == ' ')
			(*str)[i++] = '0';
	}
}
