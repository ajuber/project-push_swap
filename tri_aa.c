/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 05:50:31 by ajubert           #+#    #+#             */
/*   Updated: 2016/05/10 16:04:01 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_aa_else(t_e *e)
{
	ra(e);
	if (e->v)
		display_list(e, 1);
	e->str = ft_strjoin_free(e->str, e->str, " ra");
}

void	tri_aa(t_e *e)
{
	t_list_cir *tmp_b;
	t_list_cir *tmp_a_next;
	t_list_cir *tmp_a_previous;

	tmp_b = e->l_b->next;
	while (tmp_b != e->l_b)
	{
		tmp_a_next = e->l_a->next;
		tmp_a_previous = e->l_a->previous;
		if ((tmp_b->n < tmp_a_next->n && tmp_b->n > tmp_a_previous->n) ||
				(tmp_b->n > tmp_a_next->n && tmp_b->n > tmp_a_previous->n
				&& tmp_a_next->n < tmp_a_previous->n) ||
				(tmp_b->n < tmp_a_next->n && tmp_b < tmp_a_previous
				&& tmp_a_next->n < tmp_a_previous->n))
		{
			pa(e);
			if_display(e, 1);
			e->str = ft_strjoin_free(e->str, e->str, " pa");
			tmp_b = e->l_b->next;
		}
		else
			tri_aa_else(e);
	}
}

void	after_tri_aa(t_e *e)
{
	t_list_cir	*tmp_a_next;
	t_list_cir	*tmp_a_previous;

	tmp_a_next = e->l_a->next;
	tmp_a_previous = e->l_a->previous;
	while (tmp_a_next->n > tmp_a_previous->n)
	{
		ra(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, " ra");
		tmp_a_next = e->l_a->next;
		tmp_a_previous = e->l_a->previous;
	}
}
