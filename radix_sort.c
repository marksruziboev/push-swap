/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:52:57 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/16 19:00:40 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort_stack_b(t_stack *s, int bit_size, int j)
{
    int size;

    size = s->size_b;
	while (size-- && j <= bit_size && !is_sorted(s))
	{
		if (((s->b[0] >> j) & 1) == 0)
			ft_rotate(s->b, s->size_b, "rot", "rb");
		else
			ft_push(s, "pa");
	}
	if (is_sorted(s))
		while (s->size_b != 0)
			ft_push(s, "pa");
}

void	radix_sort(t_stack *s)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = s->size_a;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = s->size_a;
		while (size-- && !is_sorted(s))
		{
			if (((s->a[0] >> j) & 1) == 0)
				ft_push(s, "pb");
			else
				ft_rotate(s->a, s->size_a, "rot", "ra");
		}
		radix_sort_stack_b(s, bit_size, j + 1);
	}
	while (s->size_b != 0)
		ft_push(s, "pa");
}