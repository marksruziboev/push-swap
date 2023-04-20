/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mess.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:41:58 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/20 13:22:57 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_message(t_stack *s, char *msg)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	if (s != NULL)
	{
		if (s->z != NULL)
		{
			free(s->z);
			s->z = NULL;
		}
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
	s->bot = 0;
	s->a = NULL;
	s->b = NULL;
	s->z = NULL;
}

void	update_z(t_stack *s, char *new)
{
	if (ft_strncmp(s->z, " ", 1) && s->z != NULL && ft_strlen(s->z) > 0)
		ft_putendl_fd(s->z, 1);
	ft_strlcpy(s->z, new, ft_strlen(new) + 1);
}

void	printcom(char *new, t_stack *s)
{
	if (s->z == NULL || !ft_strncmp(s->z, " ", 1))
		ft_strlcpy(s->z, new, ft_strlen(new) + 1);
	else if ((!ft_strncmp(s->z, "ra", 2) && !ft_strncmp(new, "rb", 2))
		|| (!ft_strncmp(s->z, "rb", 2) && !ft_strncmp(new, "ra", 2)))
	{
		ft_putendl_fd("rr", 1);
		ft_strlcpy(s->z, " ", 2);
	}
	else if ((!ft_strncmp(s->z, "sa", 2) && !ft_strncmp(new, "sb", 2))
		|| (!ft_strncmp(s->z, "sb", 2) && !ft_strncmp(new, "sa", 2)))
	{
		ft_putendl_fd("ss", 1);
		ft_strlcpy(s->z, " ", 2);
	}
	else if ((!ft_strncmp(s->z, "rrb", 3) && !ft_strncmp(new, "rra", 3))
		|| (!ft_strncmp(s->z, "rra", 3) && !ft_strncmp(new, "rrb", 3)))
	{
		ft_putendl_fd("rrr", 1);
		ft_strlcpy(s->z, " ", 2);
	}
	else
		update_z(s, new);
}
