/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:24:41 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/17 17:25:10 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	k;
	size_t	i;
	char	*ptr;

	k = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			k++;
			ptr = (char *)&str[i];
		}
		i++;
	}
	if (k > 0)
		return (ptr);
	else if ((char)c == '\0')
		return ((char *)&str[i]);
	else
		return ((char *) NULL);
}
