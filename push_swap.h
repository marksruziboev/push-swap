/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:03:20 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/19 12:06:27 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	bot;
	char	*z;
}	t_stack;

void	chinsert(int argc, char **argv, t_stack *s);
void	initials(t_stack *s);
void	no_rep(t_stack *s);
void	fill_a(int argc, char **argv, t_stack *s);
void	exit_with_message(t_stack *s, char *msg);

void	ft_swap(t_stack *s, char *str);
void	ft_push(t_stack *s, char str[2]);
void	ft_rotate(int *arr, int n, char *str);
void	printcom(char *new, t_stack *s);

void	get_size(int argc, char **argv, t_stack *s);
void	ft_free(char **d);
void	ft_index(t_stack *s);
void	ft_reset(t_stack *s);

void	ft_sort3(t_stack *s);
void	four(t_stack *s);
void	five(t_stack *s);
void	push_to_a(t_stack *s);

int		init_step(t_stack *s, int n);
int		is_sorted(t_stack *s);
int		get_g_s(int k);
int		max_ind(int *arr, int k);


#endif
