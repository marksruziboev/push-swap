/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:46:38 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/21 18:58:43 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ss1;
	size_t	slen;

	if (!s1 || !set)
		return (ft_strdup(""));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	slen = ft_strlen(s1);
	while (slen && ft_strchr(set, s1[slen]))
		slen--;
	ss1 = ft_substr((char *)s1, 0, (slen + 1));
	return (ss1);
}
