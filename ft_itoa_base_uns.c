/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:38:46 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/03/25 14:28:37 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int	ft_count(unsigned long long int nb, int base)
{
	int		res;

	res = 0;
	while (nb > 0)
	{
		nb /= base;
		res++;
	}
	return (res);
}

char		*ft_itoa_base_unsigned(unsigned long long int nb, int base, char x)
{
	int		len;
	char	*res;
	char	*abc;
	char	*abc_up;

	abc_up = "0123456789ABCDEF";
	abc = "0123456789abcdef";
	if (nb == 0)
	{
		res = ft_strdup("0");
		return (res);
	}
	len = ft_count(nb, base);
	if (!(res = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	len--;
	while (len >= 0 && nb)
	{
		if (x == 'X')
			res[len--] = abc_up[nb % base];
		else
			res[len--] = abc[nb % base];
		nb = nb / base;
	}
	return (res);
}
