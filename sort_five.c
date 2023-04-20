/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:19:29 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/20 13:48:17 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_write(t_stack *s, char *str1, char *str2)
{
	ft_rotate(s->a, s->size_a, str1);
	ft_putendl_fd(str2, 1);
	ft_rotate(s->a, s->size_a, str1);
	ft_putendl_fd(str2, 1);
}

void	ft_writepush(t_stack *s, char *str)
{
	ft_push(s, str);
	ft_putendl_fd(str, 1);
}

void	five(t_stack *s)
{
	int	i;

	i = 1;
	if (s->a[1] == 1)
	{
		ft_rotate(s->a, s->size_a, "rot");
		ft_putendl_fd("ra", 1);
	}
	else if (s->a[2] == 1)
		ft_write(s, "rot", "ra");
	else if (s->a[3] == 1)
		ft_write(s, "rrot", "rra");
	else if (s->a[4] == 1)
	{
		ft_rotate(s->a, s->size_a, "rrot");
		ft_putendl_fd("rra", 1);
	}
	if (is_sorted(s) == 0)
		ft_writepush(s, "pb");
	if (is_sorted(s) == 0)
		four(s);
	ft_writepush(s, "pa");
}
