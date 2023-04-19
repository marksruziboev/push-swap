/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:01:30 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/19 14:11:19 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void allocate(int argc, char **argv, t_stack *s)
{

	get_size(argc, argv, s);
	chinsert(argc, argv, s);
	s->a = ft_calloc(sizeof(int), (size_t)s->size_a);
	if (s->a == NULL)
		exit_with_message(s, NULL);
	s->b = ft_calloc(sizeof(int), (size_t)s->size_a);
	if (s->b == NULL)
		exit_with_message(s, NULL);
	s->z = ft_calloc(sizeof(char), 4);
	if (s->z == NULL)
		exit_with_message(s, NULL);
	fill_a(argc, argv, s);
	no_rep(s);
}

int	main(int argc, char **argv)
{
	t_stack	*s;
	
	if (argc == 1) 
		return (0);
	s = ft_calloc(1, sizeof(t_stack));
	if (s == NULL)
		exit_with_message(NULL, NULL);
	initials(s);
	allocate(argc, argv, s);
	if (is_sorted(s))
		exit_with_message(s, NULL);
	ft_index(s);
	ft_reset(s);
	if (s->size_a == 2)
		ft_sort3(s);
	else if (s->size_a == 3)
		ft_sort3(s);
	else if (s->size_a == 4)
		four(s);
	else if (s->size_a == 5)
		five(s);
	push_to_a(s);
	exit_with_message(s, NULL);
	return (0);
}
