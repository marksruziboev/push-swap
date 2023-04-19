/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:43:25 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/19 13:49:53 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pushnrot(t_stack *s)
{
    ft_push(s, "pa");
	printcom("pa", s);
	if (s->a[0] < s->a[1] - 1)
	{
		ft_rotate(s->a, s->size_a, "rot");
		printcom("ra", s);
		s->bot++;
	}
}

void    pushrot(t_stack *s)
{
	ft_push(s, "pa");
	printcom("pa", s);
	ft_rotate(s->a, s->size_a, "rot");
	printcom("ra", s);
	s->bot++;
}