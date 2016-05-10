#include "push_swap.h"

void	tri_small_list(t_e *e)
{
	int		i;

	i = 0;
	while (i < e->size_l - 3)
	{
		pb(e);
		if_display(e, 1);
		i++;
		e->str = ft_strjoin_free(e->str, e->str, "pb ");
	}
	if (e->size_l == 6)
		tri_b_and_a(e);
	tri_a_and_b(e);
	tri_aa(e);
	after_tri_aa(e);
}
