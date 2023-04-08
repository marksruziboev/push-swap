/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:45:40 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/13 19:45:38 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		*(a++) = c;
		i++;
	}
	return (str);
}
