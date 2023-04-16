/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_push_tob.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:15:51 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/15 18:34:46 by maruzibo         ###   ########.fr       */
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
/*
This function pushes elements of jth group to b.
each group have n ~ sqrt(size_a)  elements
*/

int	push_jthgroup(t_stack *s, int j, int n)
{
	int	k ;
	//int	c;
	int	num;
	int count; 

	//c = s->size_a;
	k = -1;
	num = 0;
	count = 0; 
	while (++k < s->size_a && count <= n) // c was here insted of s->size_a
	{
		if (s->a[0] > j * n && s-> a[0] <= (j + 1) * n)
		{
			ft_push(s, "pb");
			if (s->b[0] > n / 2 + j * n && s->size_b > 1 && s->b[0] > s->b[1])
			{
				ft_rotate(s->b, s->size_b, "rot", "rb");
				num++;
			}
			count++;// this counts number of elements pushed to b.
		}
		else
			ft_rotate(s->a, s->size_a, "rot", "ra");
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
			ft_rotate(s->b, s->size_b, "rrot", "rrb");
			i--;
		}
		j++;
	}
	return (j);
}

int	max_ind(int *arr, int k)
{
	int	j;
	int	m;

	j = 0;
	m = 0;
	while (++j < k)
	{
		if (arr[m] < arr[j])
			m = j;
	}
	return (m);
}

int	min_ind(int *arr, int k, int m)
{
	int	j;

	j = 0;
	while (++j < k)
	{
		if (arr[j] == m)
			return (j);
	}
	return (-1);
}
