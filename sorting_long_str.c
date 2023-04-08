#include "push_swap.h"

//inital push to b
int	get_ch_n(t_stack *s)
{
	int	i;

	i = 0;
	while (i * i < s->size_a && i <= 46340)
		i++;
	if (i % 2 == 0)
		return (i);
	else
		return (i + 1);
}

/*void init_c(t_stack *s)
{
	get_ch_n(s, c); 
	c->ch_size = s->size_a/c->ch_n;
	c->ch_b  = 0;
	if (c->ch_size > 2)
		c->ch_e  = c->ch_size;
	else 
		c->ch_e = 2;
	c->ch_m = c->ch_size/2;
	c->count = s->size_a;
}*/

void	init_step(t_stack *s)
{
	int	i;
	int j;
	int c;
	int n;
	int nrotb;
	int	init_s;

	init_s = get_ch_n(s);
	n = s->size_a / init_s;
	j = -1;
	nrotb = 0;
	while (++j < init_s)
	{
		c = s->size_a;
		i = -1;
		while (++i < c)
		{
			if (j + 1 < init_s && s->a[0] > (j + 1) * n)
				ft_rotate(s->a, s->size_a, "rot", "ra");
			else if (j + 1 < init_s && s->a[0] > j * n && s->a[0] <= (j + 1) * n)
			{
				ft_push(s, "pb");
				if (s->b[0] > n / 2 + j * n)
				{
					ft_rotate(s->b, s->size_b, "rot", "rb");
					nrotb++;
				}
			}
			else if (j + 1 == init_s && s->a[0] > j * n)
			{	
				ft_push(s, "pb");
				if (s->b[0] > n / 2 + j * n)
				{
						ft_rotate(s->b, s->size_b, "rot", "rb");
						nrotb++;
				}
			}		
		}
		while (nrotb--)
		{
			ft_rotate(s->b, s->size_b, "rrot", "rb");
		}
	}
}

//printf("chunks =%d, end =%d , c = %d\n", get_ch_n(s), end, c);
	
