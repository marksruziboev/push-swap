/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:45:41 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/21 14:50:14 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dup;
	char	*ss2;
	char	*ss1;

	ss2 = (char *)s2;
	ss1 = (char *)s1;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, ss1, (int)ft_strlen(s1) + 1);
	ft_strlcat(dup + ft_strlen(s1), ss2, ft_strlen(s2) + 1);
	return (dup);
}
