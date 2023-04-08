/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:03:20 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/07 16:09:56 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
}			t_stack;



void    	chinsert(int argc, char **argv, t_stack *s);
void    	initials(t_stack *s);
//void		init_c(t_stack *s, t_cnst *c);
void     	exit_huseyin(t_stack *s);
void 		fill_a(int argc, char **argv, t_stack *s);
void		exit_with_message(t_stack *s, char *msg);


void	ft_swap(int *arr, char *str);
void    ft_push(t_stack *s, char str[2]);
void	ft_rotate(int *arr, int n, char *str, char *str2);
void	get_size(int argc, char **argv, t_stack *s);
void 	ft_free(char **d);
void	ft_index(t_stack *s);
void	ft_reset(t_stack *s);

void	ft_sort3(t_stack *s);
void    four(t_stack *s);
void	init_step(t_stack *s);


void 	no_rep(t_stack *s);
int 		is_sorted(t_stack *s);
int 		get_ch_n(t_stack *s);

#endif
