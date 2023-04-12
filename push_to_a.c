#include "push_swap.h"



void push_to_a(t_stack *s)
{
    int i;
    int n;
    int d;
    int bot;
   // int z = 0;

    d = s->size_a;
    n = get_g_s(d);
    i = init_step(s, n);
    bot = 0;
    while (s->b[0] == s->size_b)
        ft_push(s, "pa");
    if (s->size_b == 0)
        exit_with_message(s,  NULL);
    else if (s->size_a == 0)
    {
        ft_push(s, "pa");
        bot++;
    }
}
