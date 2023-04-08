/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:43:23 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/21 19:00:13 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	char	*sf;
	size_t	vsize;

	sf = (char *)s;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	vsize = 0;
	while (sf[vsize + start] != '\0' && vsize < len)
		vsize++;
	subs = (char *)malloc(sizeof(char) * (vsize + 1));
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, sf + start, vsize + 1);
	return (subs);
}
