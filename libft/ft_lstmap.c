/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:07:03 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/29 20:38:51 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*val;

	if (lst)
	{
		new = NULL;
		while (lst)
		{
			val = ft_lstnew(f(lst->content));
			if (!val)
			{
				ft_lstclear(&val, (del));
				return (NULL);
			}
			ft_lstadd_back(&new, val);
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
