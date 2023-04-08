/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruzibo <maruzibo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:32:27 by maruzibo          #+#    #+#             */
/*   Updated: 2023/04/07 16:44:46 by maruzibo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *arr, char *str)  
{
	int tmp;
    
    if (sizeof(*arr)/sizeof(arr[0]) <= 0)
        return ;
    tmp = arr[0];
	arr[0] = arr[1],
	arr[1] = tmp;
    if (str != NULL)
        ft_putendl_fd(str, 1);
}

void    ft_push(t_stack *s, char str[2]) //pa or pb push to a pa
{    
    if (str[1] == 'a')
    {
        if (s->size_b <= 0)
            return ;
        ft_memmove(s->a+1, s->a, sizeof(int)*(size_t)s->size_a);
        s->size_a++;
        s->a[0] = s->b[0];
        //s->b[s->size_b-1]= 0;
        s->size_b--;
        ft_memmove(s->b, s->b+1, sizeof(int)*(size_t)s->size_b);
    }
    else if (str[1] == 'b')
    {
        if (s->size_a <= 0)
            return ;
        ft_memmove(s->b+1, s->b, sizeof(int)*(size_t)s->size_b);
        s->size_b++;
        s->b[0] = s->a[0];
        //s->a[s->size_a-1] = 0;
        s->size_a--;
        ft_memmove(s->a, s->a+1, sizeof(int)*(size_t)s->size_a);
    }
    ft_putendl_fd(str, 1);
}

void    ft_rotate(int *arr, int n, char *str, char *str2) // str = rota or rrota str 2 ra or rb or rr
{
    int tmp;
    
    if( !ft_strncmp(str, "rot", 3))
    {
        tmp = arr[0];
        ft_memmove(arr, arr+1, sizeof(int)*((size_t)n-1));
        arr[n-1] = tmp;
        
    }
    else if (!ft_strncmp(str, "rrot", 4))
    {
        tmp = arr[n-1];
        ft_memmove(arr+1, arr, sizeof(int)*((size_t)n-1));
        arr[0] = tmp;
    }
   // ft_putstr_fd(str, 1);
    ft_putendl_fd(str2, 1);
}