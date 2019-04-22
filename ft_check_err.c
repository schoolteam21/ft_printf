/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:05:07 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/03/27 15:05:31 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_check_err_2(t_struct ds, int i)
{
	if (ft_strrchr(ds.f, '.'))
	{
		if (ds.f[i] == '.' && i >= 0)
		{
			i--;
			while ((ds.f[i] >= '0' && ds.f[i] <= '9') && i >= 0)
				i--;
		}
		else
		{
			while ((ds.f[i] >= '0' && ds.f[i] <= '9') && i >= 0)
				i--;
			if (ds.f[i] == '.' && i >= 0)
				i--;
			while ((ds.f[i] >= '0' && ds.f[i] <= '9') && i >= 0)
				i--;
		}
	}
	else
		while ((ds.f[i] >= '0' && ds.f[i] <= '9') && i >= 0)
			i--;
	return (i);
}

int		ft_check_err(t_struct ds)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(ds.f) - 1;
	if ((((ds.f[i] == 'l' && ds.f[i - 1] == 'l') ||
	(ds.f[i] == 'h' && ds.f[i - 1] == 'h')) && ds.type != 'f') && i >= 0)
		i -= 2;
	else if ((ds.f[i] == 'l' || (ds.f[i] == 'h' && ds.type != 'f')
	|| (ds.f[i] == 'L' && ds.type == 'f')) && i >= 0)
		i -= 1;
	i = ft_check_err_2(ds, i);
	while (FLAGS[j] != '\0' && i >= 0)
	{
		while (ds.f[i] != FLAGS[j] && FLAGS[j] && i >= 0)
			j++;
		if (FLAGS[j] == '\0')
			break ;
		j = 0;
		i--;
	}
	if (i != -1)
		return (0);
	return (1);
}
