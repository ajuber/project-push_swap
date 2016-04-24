/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 05:50:31 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/24 10:26:13 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_b(t_e *e)
{
	t_list_cir *tmp_a;
	t_list_cir *tmp_b_next;
	t_list_cir *tmp_b_previous;

	tmp_a = e->l_a->next;
	while (tmp_a != e->l_a)
	{
		tmp_b_next = e->l_b->next;
		tmp_b_previous = e->l_b->previous;
		if ((tmp_a->n > tmp_b_next->n && tmp_a->n < tmp_b_previous->n) ||
				(tmp_a->n < tmp_b_next->n && tmp_a->n < tmp_b_previous->n
				&& tmp_b_next->n > tmp_b_previous->n) ||
				(tmp_a->n > tmp_b_next->n && tmp_a > tmp_b_previous
				&& tmp_b_next->n > tmp_b_previous->n))
		{
			pb(e);
			e->str = ft_strjoin_free(e->str, e->str, " pb");
			tmp_a = e->l_a->next;
		}
		else
		{
			rb(e);
			e->str = ft_strjoin_free(e->str, e->str, " rb");
		}
	}
}

void	push_swap_calc_under(t_e *e)
{
	t_list_cir *tmp_a;
	t_list_cir *tmp_b_next;

	tmp_a = e->l_a->next;
	tmp_b_next = e->l_b->next;
	if (tmp_a->n > tmp_b_next->n)
	{
		pb(e);
		e->str = ft_strjoin_free(e->str, e->str, " pb");
	}
	else
	{
		pb(e);
		rb(e);
		e->str = ft_strjoin_free(e->str, e->str, " pb rb");
	}
}

void	push_swap_calc(t_e *e)
{
	t_list_cir *tmp_b_next;
	t_list_cir *tmp_b_previous;

	pb(e);
	e->str = ft_strjoin_free(e->str, e->str, "pb");
	push_swap_calc_under(e);
	tri_b(e);
	tmp_b_next = e->l_b->next;
	tmp_b_previous = e->l_b->previous;
	while (tmp_b_next->n < tmp_b_previous->n)
	{
		rb(e);
		e->str = ft_strjoin_free(e->str, e->str, " rb");
		tmp_b_next = e->l_b->next;
		tmp_b_previous = e->l_b->previous;
	}
	while (tmp_b_next != e->l_b)
	{
		pa(e);
		e->str = ft_strjoin_free(e->str, e->str, " pa");
		tmp_b_next = e->l_b->next;
	}
}
