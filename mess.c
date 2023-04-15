/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mess.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:41:58 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/15 17:36:55 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_huseyin(t_stack *s)
{
	ft_putendl_fd("Husseyin insert at least 2(two) numbers!", 2);
	ft_putendl_fd("Only integrs separated with spaces are allowed.", 2);
	ft_putendl_fd("No repeated numbers! For example:", 1);
	ft_putendl_fd("./push_swap 6 5 4 3 2   or ./push_swap \"6 5 4 3 2 1\"", 2);
	free(s);
	exit(1);
}
void	exit_with_message(t_stack *s, char *msg)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	if (s != NULL)
	{
		if (s->a != NULL)
		{
			free(s->a);
			s->a = NULL;
		}
		if (s->b != NULL)
		{
			free(s->b);
			s->b = NULL;
		}
		if (s != NULL)
			free(s);
	}
	exit(1);
}

void	initials(t_stack *s)
{
	s->size_a = 0;
	s->size_b = 0;
	s->a = NULL;
	s->b = NULL;
}
