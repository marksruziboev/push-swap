/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:43:32 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/08 12:20:34 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a(int argc, char **argv, t_stack *s)
{
	int		i;
	int		j;
	int		k;
	char	**b;

	k = 0; //s->size_a;
	i = 0;
	while (++i < argc)
	{
		j = 0;
		b = ft_split(argv[i], ' ');
		while (b[j])
		{
			if (ft_atoi(b[j]) < -2147483648 || ft_atoi(b[j]) > 2147483647)
			{
				ft_free(b);
				exit_with_message(s, "Husseyin are out of int range!!!\n");
			}
			s->a[k] = (int)ft_atoi(b[j]);
			//printf("%d,", s->a[k]);
			j++;
			k++;
		}
		ft_free(b);
	}
}
void	no_rep(t_stack *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < s->size_a - 1)
	{
		j = i;
		while (++j < s->size_a)
		{
			if (s->a[i] == s->a[j])
				printf("%d", s -> a[i]);
				//exit_with_message(s, "No repeatitions Husseyin!");
		}
	}
}
int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s-> size_a - 1)
	{
		if (s->a[i] > s->a[i+1])
			return (0);
		i++;
	}
	return (1);
}
void ft_index(t_stack *s)
{
	int	i;
	int	j;
	int	c;


	i = -1;
	while(++i < s->size_a)
	{
		c = 1;
		j = -1;
		while(++j < s->size_a)
		{
			if (s->a[i] > s->a[j])
				c++;
		}
		s->b[i] = c;
	}
}
void	ft_reset(t_stack *s)
{
	int	i;

	i = -1;
	while(++i < s->size_a)
	{
		s->a[i] = s-> b[i];
		s-> b[i] = 0;
	}
}

