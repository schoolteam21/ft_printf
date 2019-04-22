/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:58:37 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/08 18:42:09 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_plusmin(long long int n)
{
	int plusmin;

	plusmin = 0;
	if (n < 0)
	{
		plusmin = 1;
	}
	return (plusmin);
}

static int	ft_len(long long int n, int pm)
{
	int l;

	l = 1;
	while ((n = n / 10))
		l++;
	l = l + pm;
	return (l);
}

char		*ft_itoa(long long int n)
{
	char	*res;
	int		pm;
	int		l;

	if ((unsigned long long)n == -9223372036854775808U)
		return (ft_strdup("-9223372036854775808"));
	if ((pm = ft_plusmin(n)))
		n = n * -1;
	l = ft_len(n, pm);
	if (!(res = ft_memalloc(sizeof(char) * (l + 1))))
		return (NULL);
	l--;
	while (l > 0)
	{
		res[l] = n % 10 + '0';
		n = n / 10;
		l--;
	}
	if (pm == 0)
		res[l] = n % 10 + '0';
	else
		res[l] = '-';
	return (res);
}
