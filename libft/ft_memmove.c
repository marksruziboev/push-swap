/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:05:55 by maruzibo          #+#    #+#             */
/*   Updated: 2023/03/27 16:28:13 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	k;
	char	*d;
	char	*s;

	if ((!dst && !src) || n == 0)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	k = 0;
	if (dst < src)
	{
		while (k < n)
		{
			d[k] = s[k];
			k++;
		}
	}
	else
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return (dst);
}
