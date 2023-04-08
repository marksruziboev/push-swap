/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:51:42 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/25 16:18:47 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	k;

	if (!s || !f)
		return (NULL);
	res = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	k = 0;
	while (s[k])
	{
		res[k] = f(k, s[k]);
		k++;
	}
	res[k] = '\0';
	return (res);
}
