/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kostili.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:12:33 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/03/27 15:06:52 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_back_copy(char *num, int p, char sign)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	if (!(res = (char*)ft_memalloc(sizeof(char) * (p + 2))))
		return (NULL);
	if (sign == '-')
	{
		res[0] = '-';
		i = 1;
	}
	while (i <= p)
		res[i++] = '0';
	len = (int)ft_strlen(num) - 1;
	while (len >= 0)
	{
		if (len == 0 && sign == '-')
			break ;
		res[p--] = num[len--];
	}
	return (res);
}

void	ft_add_2(char *num, char **res, t_struct ds, int l)
{
	int tmp;
	int len;

	len = ft_strlen(num);
	tmp = l;
	if (ds.f[1] == '-' && num[len - 1] == ' ' && num[len - 2] != ' '
	&& (ds.type == 'x' || ds.type == 'X'))
		len++;
	while (tmp < len)
	{
		if (ds.f[1] == '-')
			(ds.type == 'x' || ds.type == 'X') ? ((*res)[tmp] = num[tmp - 2])
			: ((*res)[tmp] = num[tmp - 1]);
		else
			((*res)[tmp] = num[tmp]);
		tmp++;
	}
}

char	*ft_add(char *num, char *str, t_struct ds)
{
	char	*res;
	int		len;
	int		tmp;
	int		l;

	len = ft_strlen(num);
	l = ft_strlen(str);
	tmp = len;
	if (!(res = ft_strnew(len + 2)))
		return (NULL);
	res[0] = *str;
	str++;
	if (ds.type == 'x' || ds.type == 'X')
	{
		tmp++;
		res[1] = *str;
	}
	if ((ds.f[1] == '-' && ds.width)
	|| (ds.f[0] == '0' && ds.width && ds.type == 'f'))
		ft_add_2(num, &res, ds, l);
	else
		while (len > 0)
			res[tmp--] = num[(len--) - 1];
	return (res);
}

void	ft_kostil_2(char **str, int i)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*str);
	tmp = *str;
	*str = ft_strnew(len);
	(*str)[--i] = '.';
	while (len - 1 > 0)
		(*str)[--i] = tmp[--len];
	ft_strdel(&tmp);
}

void	ft_kostil(int kostil, char **str, t_struct ds)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(*str);
	if (kostil == 1)
	{
		while (((*str)[i] <= '0' || (*str)[i] >= '9') && (*str)[i] != '\0')
			i++;
		while ((*str)[i] >= '0' && (*str)[i] <= '9' && (*str)[i] != '\0')
			i++;
		if ((*str)[i] == '\0' && !ds.width)
		{
			tmp = *str;
			*str = ft_strjoin(tmp, ".");
			ft_strdel(&tmp);
		}
		else if ((*str)[i] == '\0' && ds.width)
			ft_kostil_2(str, i);
		else
			(*str)[i] = '.';
	}
}
