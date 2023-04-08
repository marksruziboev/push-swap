/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:23:25 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/16 16:48:23 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	k;
	size_t	ind;
	size_t	slen;

	ind = 0;
	slen = (size_t) ft_strlen((char *) src);
	if (n == 0)
		return (slen);
	while (dest[ind] != '\0' && ind < n)
		ind++;
	k = 0;
	while (k + ind + 1 < n && src[k] != '\0')
	{
		dest[ind + k] = src[k];
		k++;
	}
	if (ind < n)
		dest[ind + k] = '\0';
	return (ind + slen);
}
