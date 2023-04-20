/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_short_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:16:53 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/20 12:48:06 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort2(t_stack *s)
{
	if (s->size_a == 2)
	{
		ft_swap(s, "sa");
		ft_putendl_fd("sa", 1);
	}
}

void	ft_sort3(t_stack *s)
{
	while (is_sorted(s) == 0)
	{
		if (s->a[2] == max_d(s->a, s->size_a))
		{
			ft_swap(s, "sa");
			ft_putendl_fd("sa", 1);
		}
		else if (s->a[1] == max_d(s->a, s->size_a))
		{
			ft_rotate(s->a, s->size_a, "rrot");
			ft_putendl_fd("rra", 1);
		}
		else if (s->a[0] == max_d(s->a, s->size_a))
		{
			ft_rotate(s->a, s->size_a, "rot");
			ft_putendl_fd("ra", 1);
		}
	}
}

void	fourone(t_stack *s, int a)
{
	if (s->a[1] == a)
	{
		ft_rotate(s->a, s->size_a, "rot");
		ft_putendl_fd("ra", 1);
	}
	else if (s->a[2] == a)
	{
		ft_rotate(s->a, s->size_a, "rot");
		ft_rotate(s->a, s->size_a, "rot");
		ft_putendl_fd("ra", 1);
		ft_putendl_fd("ra", 1);
	}
	else if (s->a[3] == a)
	{
		ft_rotate(s->a, s->size_a, "rrot");
		ft_putendl_fd("rra", 1);
	}
}

void	four(t_stack *s)
{
	int	a;

	a = min_d(s->a, s->size_a);
	fourone(s, a);
	if (is_sorted(s) == 0)
	{
		ft_push(s, "pb");
		ft_putendl_fd("pb", 1);
		ft_sort3(s);
		ft_push(s, "pa");
		ft_putendl_fd("pa", 1);
	}
}
