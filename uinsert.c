/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinsert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:00:15 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/15 17:37:23 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **d)
{
	size_t	i;

	i = 0;
	while (d[i])
	{
		free(d[i]);
		i++;
	}
	free(d);
}
int	alldig(int argc, char **argv)
{
	size_t	i;

	while (--argc > 0)
	{
		i = 0;
		if (argv[argc] && argv[argc][0] == '\0')
			return (0);
		while (argv[argc][i])
		{
			if (!ft_isdigit(argv[argc][i]) && argv[argc][i] != '-'
				&& argv[argc][i] != ' ' && argv[argc][i] != '+')
				return (0);
			if (i + 1 <= ft_strlen(argv[argc]) && (argv[argc][i] == '-'
					|| argv[argc][i] == '+') && !ft_isdigit(argv[argc][i + 1]))
				return (0);
			if (i > 0 && !ft_isspace(argv[argc][i - 1]) &&
				(argv[argc][i] == '-' || argv[argc][i] == '+'))
				return (0);
			i++;
		}
	}
	return (1);
}
void	chinsert(int argc, char **argv, t_stack *s)
{
	if (argc == 1)
		exit_with_message(s, "Error\n");
	else if (!alldig(argc, argv))
		exit_with_message(s, "Error\n");
}
void	get_size(int argc, char **argv, t_stack *s)
{
	int	i;

	i = 0;
	while (++i < argc)
		s->size_a += ft_wcnt(argv[i], ' ');
	if (s->size_a > 2147483647)
		exit_with_message(s, "OOO Husseyin I can't count up to that number!\n");
}
