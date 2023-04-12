void    search_head(t_stack *s, int bot) //we have not plased the biggest element yet
{
    int m;
    int u;

    m = max_ind(s->b, s->size_b); 
    u = s->b[m];
    if (m < s->size_b / 2 + 1)
    {
        while (s->b[0] != u) 
        {
            if (s->b[0] > s->a[s->size_a -1])
            {
                ft_push(s, "pa");
                ft_rotate(s->a, s->size_a, "rot", "ra");
                bot++;                    
            }
            else 
                ft_rotate(s->b, s->size_b, "rot", "rb");
        }
        ft_push(s, "pa");
    }
    else    
    {
        while (s->b[0] != u) 
        {
            ft_rotate(s->b, s->size_b, "rrot", "rrb");
            if (s->b[0] > s->a[s->size_a -1])
            {
                ft_push(s, "pa");
                ft_rotate(s->a, s->size_a, "rot", "ra");
                bot++;                    
            }
        }
        ft_push(s, "pa");
    }
}

//If we have found the maximum element


void cheap_cases(t_stack *s, int bot)
{
    if (bot > 0 && s->a[s->size_a-1] == s->a[0] - 1)
    {
        ft_rotate(s->a, s->size_a, "rrot", "rra");
        bot--;
    }
       
}  

void search_tail(t_stack *s, int bot) //we have not plased the biggest element yet
{
    int m;
    int u;

    m = max_ind(s->b, s->size_b); 
    u = s->b[m];

    if (s->b[0] == s->a[0] - 1)
        ft_push(s, "pa");
    if (s->b[s->size_b -1] == s->a[0] - 1)
    {
        ft_push(s, "pa");
        ft_rotate(s->b, s->size_b, "rrot", "rrb");
    }
    if (m < s->size_b / 2 + 1)
    {
        while (s->b[0] != u) 
        {
            if (s->b[0] > s->a[s->size_a -1])
            {
                ft_push(s, "pa");
                ft_rotate(s->a, s->size_a, "rot", "ra");
                bot++;                    
            }
            else 
                ft_rotate(s->b, s->size_b, "rot", "rb");
        }
        ft_push(s, "pa");
    }
    else    
    {
        while (s->b[0] != u) 
        {
            ft_rotate(s->b, s->size_b, "rrot", "rrb");
            if (s->b[0] > s->a[s->size_a -1])
            {
                ft_push(s, "pa");
                ft_rotate(s->a, s->size_a, "rot", "ra");
                bot++;                    
            }
        }
        ft_push(s, "pa");
    }
}
