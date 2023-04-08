/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:59:50 by maruzibo          #+#    #+#             */
/*   Updated: 2023/03/25 15:19:41 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcnt(char *s, char c)
{
	int	result;
	int	counter;

	result = 0;
	counter = 0;
	while (s[counter])
	{
		while (s[counter] == c)
			counter++;
		if (s[counter] != '\0')
			result++;
		while (s[counter] && s[counter] != c)
			counter++;
	}
	return (result);
}

static void	ft_gtwrds(char **res, const char *s, char c)
{
	size_t	k;
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			k = 0;
			while (s[i + k] != c && s[i + k] != '\0')
				k++;
			res[cnt] = ft_substr((char *)s, i, k);
			cnt++;
			i = i + k;
		}
		else
			i++;
	}
	res[cnt] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc((ft_wcnt((char *)s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	ft_gtwrds(res, s, c);
	return (res);
}
