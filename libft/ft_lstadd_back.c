/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:46:18 by maruzibo          #+#    #+#             */
/*   Updated: 2022/10/29 20:37:05 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tlst;

	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			tlst = *lst;
			ft_lstlast(tlst)->next = new;
		}
	}
}
