/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:43:25 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/20 12:28:59 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushnrot(t_stack *s)
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

void	pushrot(t_stack *s)
{
	ft_push(s, "pa");
	printcom("pa", s);
	ft_rotate(s->a, s->size_a, "rot");
	printcom("ra", s);
	s->bot++;
}

int	max_d(int *d, int e)
{
	int	y;
	int	a;

	y = -1;
	a = d[0];
	while (++y < e)
	{
		if (a < d[y])
			a = d[y];
	}
	return (a);
}

int	min_d(int *d, int e)
{
	int	y;
	int	a;

	y = -1;
	a = d[0];
	while (++y < e)
	{
		if (a > d[y])
			a = d[y];
	}
	return (a);
}
