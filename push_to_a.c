#include "push_swap.h"

void    step_one(t_stack *s, int bot)
{
   ft_push(s, "pa");
   bot++;
   if (s->size_a > 1)
        ft_rotate(s->a, s->size_a, "rot", "ra");
}
void    search(t_stack *s)
{    
    if (max_ind(s->b, s->size_b) <=  s->size_b / 2)
    {
        while(max_ind(s->b, s->size_b) > 0)
        {
            if (s->b[0] > s->a[s->size_a-1])
            {
                ft_push(s, "pa");
                ft_rotate(s->a, s->size_a, "rot", "ra");
            }
            else
                ft_rotate(s->b, s->size_b, "rot", "rb");
        }
        ft_push(s, "pa");
    }
    else 
    {
        while(max_ind(s->b, s->size_b) > 0)
        {
            ft_rotate(s->b, s->size_b, "rrot", "rrb");
            if (s->b[0] > s->a[s->size_a-1])
            {
                ft_push(s, "pa");
                ft_rotate(s->a, s->size_a, "rot", "ra");
            }
        }
        ft_push(s, "pa");
    }
}
void general_step(t_stack *s, int bot)
{
    while (bot >= 0 &&  s->size_a - bot > 0 && s->a[0] == s->a[s->size_a-1] + 1)
        ft_rotate(s->a, s->size_a, "rot", "ra");
    if (max_ind(s->b, s->size_b) == 0)
        ft_push(s, "pa");
    else    
        search(s);
}
void push_to_a(t_stack *s)
{
    int i;
    int n;
    int d;
    int bot;

    d = s->size_a;
    n = get_g_s(d);
    i = init_step(s, n);
    bot = 0;
    while (s->b[0] == s->size_b)
        ft_push(s, "pa");
    if (s->size_b == 0)
        exit_with_message(s,  NULL);
    step_one(s, bot);
    while (s->size_b >0)
        general_step(s, bot);
}
