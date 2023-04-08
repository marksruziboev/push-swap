/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:36:45 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/20 16:16:44 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	slen;
	char	*dup;

	slen = ft_strlen(str);
	dup = (char *) malloc(sizeof(char) * slen + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, slen + 1);
	return (dup);
}
