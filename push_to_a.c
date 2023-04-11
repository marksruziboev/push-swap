#include "push_swap.h"

int max_found(t_stack *s)
{
    int bul;
    
    bul = 0;
    if (s->a[s->size_a-1] == s->a[0] - 1)
        ft_rotate(s->a, s->size_a, "rrot", "rra");
    if (s->b[0] == s->a[0] - 1)
    {
        ft_push(s, "pb");
        bul = 1;
    }
    else if (s->b[0] > s->a[s->size_a-1])
    {
        ft_push(s, "pb");
        ft_rotate(s->a, s->size_a, "rot", "ra");
        bul = 1;
    }
    return (bul);
}

int max_not_found(t_stack *s, int d)
{
    int bul;

    bul = 0;
    if (s->b[0] == d)
    {
        ft_push(s, "pb");
        bul = 1;
    }
    else if (s->b[0] > s->a[s->size_a-1])
    {   
        ft_push(s, "pb");
        ft_rotate(s->a, s->size_a, "rot", "ra");
        bul = 1;
    }
    return (bul);
}
/*
This function takes the pointer to stack s, d- the size of original stack a, n-number of elements in each block, jth block
path: push_to_a.c
*/
void push_jthgroup_toa1(t_stack *s, int n, int d, int j) 
{
	int	maxind;
    
    maxind = max_ind(s->a, s->size_a);

	while (s->b[0] > j * n && s-> b[0] <= (j+1) * n)
	{
		if (s->a[maxind] != d)
        {
            max_not_found(s, d);
            if (max_not_found(s, d) == 0)
                ft_rotate(s->a, s->size_a, "rot", "rb");
        }
        else 
        {
            max_found(s);
            if (max_found(s) == 0)
                ft_rotate(s->a, s->size_a, "rot", "rb");
        }

    }
}
void push_jthgroup_toa2(t_stack *s, int n, int d, int j) 
{
	int	maxind;
    
    maxind = max_ind(s->a, s->size_a);
    while (s->b[s->size_b-1] > j * n && s-> b[s->size_b-1] <= (j+1) * n)
    {
        ft_rotate(s->b, s->size_b, "rrot", "rrb");
        if (s->a[maxind] != d)
            max_not_found(s, d);
        else
            max_found(s);
    }
}

/*
In principle, after the inital sorting the top stack b might be already sortred in decreasing order
the following  function takes care of this situation
path: push_to_a.c
*/
void push_to_a(t_stack *s)
{
    int i;
    int n;
    int d;

    d = s->size_a;
    n = get_g_s(d);
    i = init_step(s, n);
    while (s->b[0] == s->size_b)
        ft_push(s, "pa");
    if (s->size_b == 0)
        exit_with_message(s, NULL);
    else if (s->size_b > 0 && s->size_a > 0)
    {
        ft_push(s, "pa");
        ft_rotate(s->a, s->size_a, "rot", "ra");
    }
    else if (s->size_a == 0)
        ft_push(s, "pa");
    printf("|size_a = %d, a[size_a-1] = %d, %d|", s->size_a, s->a[0], s->a[s->size_a-1]);
  /*  while(i >= 0)
    {
        while (s->b[0] > i * n && s-> b[0] <= (i+1) * n)
        {
            push_jthgroup_toa1(s, n, d, i);
           // push_jthgroup_toa2(s, n, d, i);
        }
        i--;
    }*/
}