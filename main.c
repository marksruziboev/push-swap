/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:01:30 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/08 12:08:42 by maruzibo         ###   ########.fr       */
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
	if (s-> size_a == 2 || s-> size_a == 3)
		ft_sort3(s);
	else if (s-> size_a == 4)
		four(s);
	/*else 
	{
		init_step(s);
	}
	for (int i = 0;  i < 10; i++)
	{
		printf("%d \t %d\n", s->a[i], s->b[i]);

	}*/
	
	

	//printf("%d \t %d\n", s->size_a, s->size_b);
			
	
	//printf("%d\n", s->size_a);
	//ft_sort3(s);
	//printf("%d\n", s->size_a);
	
	//s->b = ft_calloc(sizeof(int), s->size_a);
	/*ft_push(s, "pb");
	printf("%d", s->size_a);
	ft_swap(s->a, "sa", s->size_a, 0, 1); //swaps i to j
	printf("\nsize_b=%d\n", s->size_b);
	ft_rotate(s->a, s->size_a, "rrot", "a");
	
		for (int i = 0;  i<3; i++)
			printf("%d ", s->tbs[i]);*/
	exit_with_message(s, NULL);
	//free(s);
	return (0);
}
