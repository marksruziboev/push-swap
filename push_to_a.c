/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:16:51 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/17 12:09:15 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_a(t_stack *s)
{
	if (s->bot == 0 && s->size_a == 0 && s->size_b > 0) 
	{
		ft_push(s, "pa");
		s->bot++;
	}
	else if (s->bot == 0 && s->size_a > 0 && s->size_b > 0) 	
	{
		ft_push(s, "pa");
		if (s->a[0] < s->a[1] - 1)
		{
			ft_rotate(s->a, s->size_a, "rot", "ra");
			s->bot++;
		}
	}
	else if (s->bot > 0 && s->size_a > 0 && s->size_b > 0 && 
				s->b[0] > s->a[s->size_a - 1])
	{
		ft_push(s, "pa");
		ft_rotate(s->a, s->size_a, "rot", "ra");
		s->bot++;
	}
	else if (s->size_b > 1)
		ft_rotate(s->b, s->size_b, "rot", "rb");
}
void	ft_push_to_ar(t_stack *s)
{
	if (s->bot == 0 && s->size_a == 0 && s->size_b > 0) 
	{
		ft_push(s, "pa");
		s->bot++;
	}
	else if (s->bot == 0 && s->size_a > 0 && s->size_b > 0) 	
	{
		ft_push(s, "pa");
		if (s->a[0] < s->a[1] - 1)
		{
			ft_rotate(s->a, s->size_a, "rot", "ra");
			s->bot++;
		}
	}
	else if (s->bot > 0 && s->size_a > 0 && s->size_b > 0 && 
				s->b[0] > s->a[s->size_a - 1])
	{
		ft_push(s, "pa");
		ft_rotate(s->a, s->size_a, "rot", "ra");
		s->bot++;
	}
}
void	search(t_stack *s)
{
	int i;
	if (s->size_b>0)
	{
		i = max_ind(s->b, s->size_b);	
		if (i > 0 && i <= s->size_b / 2)
			ft_push_to_a(s);
		else if(i > 0 && i > s->size_b / 2)
		{
			ft_rotate(s->b, s->size_b, "rrot", "rrb");
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
		ft_rotate(s->a, s->size_a, "rrot", "rra");
		s->bot--;
	}
	else if (max_ind(s->b, s->size_b) == 0)
		ft_push(s, "pa");
	else if (max_ind(s->b, s->size_b) == 1)
	{
		ft_swap(s->b, "sb");
		ft_push(s, "pa");	
	}
	else
		search(s);
}

void	push_to_a(t_stack *s)
{
	int	n;
	int	d;
	//int i = 0;


	d = s->size_a;
	n = get_g_s(d);
	init_step(s, n);
	
	while (s->b[0] == s->size_b)
		ft_push(s, "pa");
	if (s->size_b == 0)
		exit_with_message(s, NULL);
	s->bot = 0;
	
	while (s->size_a < d && s->size_b > 0)
		general_step(s);
}
