/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:01:30 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/15 18:16:12 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*s;

	s = ft_calloc(1, sizeof(t_stack));
	initials(s);
	get_size(argc, argv, s);
	chinsert(argc, argv, s);
	s->a = ft_calloc(sizeof(int), (size_t)s->size_a);
	s->b = ft_calloc(sizeof(int), (size_t)s->size_a);
	fill_a(argc, argv, s);
	no_rep(s);
	if (is_sorted(s))
		exit_with_message(s, "Husseyin your string is sorted\n");
	ft_index(s);
	ft_reset(s);
	if (s->size_a == 2 || s->size_a == 3)
		ft_sort3(s);
	else if (s->size_a == 4)
		four(s);
	else
		push_to_a(s);
	exit_with_message(s, NULL);
	return (0);
}
