/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_push_tob.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:15:51 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/19 12:07:55 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_g_s(int k)
{
	int	i;

	i = 0;
	while (i * i < k && i <= 46340)
		i++;
	if (i % 2 == 0)
		return (i);
	else
		return (i + 1);
}

/*This function pushes elements of jth group to b.
each group have n ~ sqrt(size_a)  elements*/

int	push_jthgroup(t_stack *s, int j, int n)
{
	int	c;
	int	num;
	int	count;

	c = s->size_a;
	num = 0;
	count = 0;
	while (--c >= 0 && count <= 2 * n)
	{
		if (s->a[0] > j * n && s-> a[0] <= (j + 1) * n)
		{
			ft_push(s, "pb");
			printcom("pb", s);
			count++;
		}
		else if (s->a[0] > (j + 1) * n && s-> a[0] <= (j + 2) * n)
		{
			ft_push(s, "pb");
			printcom("pb", s);
			ft_rotate(s->b, s->size_b, "rot");
			printcom("rb", s);
			num++;
			count++;
		}
		else
		{
			ft_rotate(s->a, s->size_a, "rot");
			printcom("ra", s);
		}
	}
	return (num);
}

/*
This function parses through the stack a several times to push from a to b
elements of each gruop of numbers 
*/
int	init_step(t_stack *s, int n)
{
	int	i;
	int	j;

	j = 0;
	while (s->size_a > 0)
	{
		i = push_jthgroup(s, j, n);
		while (i > 0)
		{
			ft_rotate(s->b, s->size_b, "rrot");
			printcom("rrb", s);
			i--;
		}
		j = j + 2;
	}
	return (j);
}

int	max_ind(int *arr, int k)
{
	int	j;
	int	m;

	if (k <= 0)
		return (-1);
	j = 0;
	m = 0;
	while (++j < k)
	{
		if (arr[m] < arr[j])
			m = j;
	}
	return (m);
}
