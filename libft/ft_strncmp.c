/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:59:09 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/16 16:59:47 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	k;

	k = 0;
	while ((str1[k] != '\0' || str2[k] != '\0') && k < n)
	{
		if ((unsigned char)str1[k] > (unsigned char)str2[k])
			return (1);
		else if ((unsigned char)str1[k] < (unsigned char) str2[k])
			return (-1);
		else
			k++;
	}
	return (0);
}
