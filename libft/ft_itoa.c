/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:49:21 by maruzibo          #+#    #+#             */
/*   Updated: 2023/03/25 16:40:54 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pos_dec_dig(int n)
{
	int	cond;

	cond = 0;
	if (n == 0)
		return (1);
	else
	{
		while (n > 0)
		{
			n = n / 10;
			cond++;
		}
		return (cond);
	}
}

static int	dec_dig(int n)
{
	if (n >= 0)
		return (pos_dec_dig(n));
	else if (n == -2147483648)
		return (10);
	else
		return (pos_dec_dig((-1 * n)));
}

static void	*pos_itoa(int n, char *ss)
{
	int	len;
	int	tlen;

	len = dec_dig(n);
	tlen = len;
	while (tlen > 0)
	{
		ss[tlen - 1] = n % 10 + '0';
		n = n / 10;
		tlen--;
	}
	ss[len] = '\0';
	return (ss);
}

char	*ft_itoa(int n)
{
	char	*ss;
	int		len;

	if (n >= 0)
		len = dec_dig(n);
	else
		len = dec_dig(n) + 1;
	ss = (char *)malloc(sizeof(char) * (len + 1));
	if (!ss)
		return (NULL);
	if (n >= 0)
		pos_itoa(n, ss);
	else if (n == -2147483648)
	{
		ss[0] = '-';
		ss[1] = 2 + '0';
		pos_itoa(147483648, ss + 2);
	}
	else
	{
		n = (-1) * n;
		ss[0] = '-';
		pos_itoa(n, ss + 1);
	}
	return (ss);
}
