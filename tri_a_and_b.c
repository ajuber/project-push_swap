/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a_and_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:10:51 by ajubert           #+#    #+#             */
/*   Updated: 2016/05/10 16:18:22 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_a_and_b_next(t_e *e, t_list_cir *tmp, int comp, int comp1)
{
	if (comp1 > comp && comp > tmp->n)
	{
		rra(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "rra");
	}
	if (comp > comp1 && tmp->n > comp)
	{
		sa(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "sa");
	}
	if (comp > comp1 && comp1 > tmp->n)
	{
		sa(e);
		if_display(e, 1);
		rra(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "sa rra");
	}
	if (comp1 > comp && comp > tmp->n)
	{

	}
}

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
	tri_a_and_b_next(e, tmp, comp, comp1);
}
