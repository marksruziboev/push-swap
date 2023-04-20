/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:16:51 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/20 13:28:23 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_a(t_stack *s)
{
	if (s->bot == 0 && s->size_a == 0 && s->size_b > 0)
	{
		ft_push(s, "pa");
		printcom("pa", s);
		s->bot++;
	}
	else if (s->bot == 0 && s->size_a > 0 && s->size_b > 0)
		pushnrot(s);
	else if (s->bot > 0 && s->size_a > 0 && s->size_b > 0
		&& s->b[0] > s->a[s->size_a - 1])
		pushrot(s);
	else if (s->size_b > 1)
	{
		ft_rotate(s->b, s->size_b, "rot");
		printcom("rb", s);
	}
}

void	ft_push_to_ar(t_stack *s)
{
	if (s->bot == 0 && s->size_a == 0 && s->size_b > 0)
	{
		ft_push(s, "pa");
		printcom("pa", s);
		s->bot++;
	}
	else if (s->bot == 0 && s->size_a > 0 && s->size_b > 0)
		pushnrot(s);
	else if (s->bot > 0 && s->size_a > 0 && s->size_b > 0
		&& s->b[0] > s->a[s->size_a - 1])
		pushrot(s);
}

void	search(t_stack *s)
{
	int	i;

	if (s->size_b > 0)
	{
		i = max_ind(s->b, s->size_b);
		if (i > 0 && i <= s->size_b / 2)
			ft_push_to_a(s);
		else if (i > 0 && i > s->size_b / 2)
		{
			ft_rotate(s->b, s->size_b, "rrot");
			printcom("rrb", s);
			ft_push_to_ar(s);
		}
	}
}

void	general_step(t_stack *s)
{
	if (is_sorted(s) && s->size_b == 0)
		exit_with_message(s, NULL);
	if (s->bot > 0 && s->a[0] - 1 == s->a[s->size_a - 1])
	{
		ft_rotate(s->a, s->size_a, "rrot");
		printcom("rra", s);
		s->bot--;
	}
	else if (max_ind(s->b, s->size_b) == 0)
	{
		ft_push(s, "pa");
		printcom("pa", s);
	}
	else if (max_ind(s->b, s->size_b) == 1)
	{
		ft_swap(s, "sb");
		printcom("sb", s);
		ft_push(s, "pa");
		printcom("pa", s);
	}
	else
		search(s);
}

void	push_to_a(t_stack *s)
{
	int	n;
	int	d;

	d = s->size_a;
	n = get_g_s(d);
	init_step(s, n);
	while (s->b[0] == s->size_b)
	{
		ft_push(s, "pa");
		printcom("pa", s);
	}
	if (s->size_b == 0)
		exit_with_message(s, NULL);
	s->bot = 0;
	while (s->size_a < d && s->size_b > 0)
		general_step(s);
	if (s->size_b == 0 && (s->z != NULL || !ft_strncmp(s->z, " ", 1)))
		ft_putendl_fd(s->z, 1);
	while (!is_sorted(s))
	{
		ft_rotate(s->a, s->size_a, "rrot");
		ft_putendl_fd("rra", 1);
	}
}
