/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_short_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:16:53 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/15 17:22:03 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max_d(int *d, int e)
{
    int y;
    int a;
    
    y = -1;
    a = 0;
    while (++y < e)
    {
        if(a < d[y])
           a = d[y];
    }
    return(a);
    
}
void    ft_sort3(t_stack *s)
{
    while (is_sorted(s) == 0)
    {
        if (s->size_a == 2)
            ft_swap(s->a, "sa");
        else if(s->size_a == 3)
        {
            if (s->a[2] == max_d(s->a, s->size_a))
                ft_swap(s->a, "sa");
            else if  (s->a[1] == max_d(s->a, s->size_a))
                ft_rotate(s->a, s->size_a, "rrot", "rra"); 
            else if (s->a[0] == max_d(s->a, s->size_a))
                ft_rotate(s->a, s->size_a, "rot", "ra");       
        }
    }
}

void    four(t_stack *s)
{   
    if (s->a[1] == 1)
        ft_rotate(s->a, s->size_a, "rot", "ra");
     else if (s->a[2] == 1)
    {
        ft_rotate(s->a, s->size_a, "rot", "ra");
        ft_rotate(s->a, s->size_a, "rot", "ra");
    }  
    else if (s->a[3] == 1)
        ft_rotate(s->a, s->size_a, "rrot", "rra"); 
    if (is_sorted(s) == 0)
    {
        ft_push(s, "pb");
        ft_sort3(s);
        ft_push(s, "pa");
    }
}
/*void    five(t_stack *s)
{
    
}*/
