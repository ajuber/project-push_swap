#include "push_swap.h"

void	tri_a_and_b(t_e *e)
{
	t_list_cir	*tmp;
	int			comp;
	int			comp1;

	tmp = e->l_a->next;
	comp = tmp->n;
	tmp = tmp->next;
	comp1 = tmp->n;
	tmp = tmp->next;
	if (comp1 >tmp->n && tmp->n > comp)
	{
		sa(e);
		if (e->v)
			display_list(e, 1);
		ra(e);
		if (e->v)
			display_list(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "sa ra");
	}
	if (comp > comp1 && tmp->n > comp)
	{
		sa(e);
		if (e->v)
			display_list(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "sa");
	}
	if (comp > comp1 && comp1 > tmp->n)
	{
		sa(e);
		if (e->v)
			display_list(e, 1);
		rra(e);
		if (e->v)
			display_list(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "sa rra");
	}
}
