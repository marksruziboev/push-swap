/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:25:54 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/20 13:02:20 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	k;
	size_t	m;

	if (ft_strlen(lit) == 0)
		return ((char *) big);
	k = 0;
	while (k < len && big[k] != '\0')
	{
		m = 0;
		while (lit[m] != '\0' && lit[m] == big[k + m] && k + m < len)
		{
			m++;
			if (lit[m] == '\0')
				return ((char *) &big[k]);
		}
		k++;
	}
	return (0);
}
