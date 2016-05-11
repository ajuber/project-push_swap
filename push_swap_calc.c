/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 05:50:31 by ajubert           #+#    #+#             */
/*   Updated: 2016/05/11 18:16:20 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_b_else(t_e *e, t_list_cir *tmp_a, t_list_cir *tmp_b_next,
		t_list_cir *tmp_b_previous)
{
	int		rot;
	int		rev_rot;
	int		test;

	test = 1;
	rot = what_ratation(tmp_a, tmp_b_next, tmp_b_previous);
	rev_rot = e->size_lb - rot;
	if (rot <= rev_rot)
		while (rot > 0 || test)
		{
			test = 0;
			rot--;
			rb(e);
			if_display(e, 1);
			e->str = ft_strjoin_free(e->str, e->str, " rb");
		}
	else
		while (rev_rot > 0 || test)
		{
			test = 0;
			rev_rot--;
			rrb(e);
			if_display(e, 1);
			e->str = ft_strjoin_free(e->str, e->str, " rrb");
		}
}

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
				(tmp_a->n > tmp_b_next->n && tmp_a->n > tmp_b_previous->n
				&& tmp_b_next->n > tmp_b_previous->n))
		{
			pb(e);
			e->size_lb++;
			if_display(e, 1);
			e->str = ft_strjoin_free(e->str, e->str, " pb");
			tmp_a = e->l_a->next;
		}
		else
			tri_b_else(e, tmp_a, tmp_b_next, tmp_b_previous);
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
		if_display(e, 1);
		e->size_lb++;
		e->str = ft_strjoin_free(e->str, e->str, " pb");
	}
	else
	{
		pb(e);
		e->size_lb++;
		if_display(e, 1);
		rb(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, " pb rb");
	}
}

void	after_tri_b(t_e *e, t_list_cir *tmp_b_next, t_list_cir *tmp_b_previous)
{
	e->rot = what_ratation2b(e, tmp_b_next, tmp_b_previous);
	while (tmp_b_next->n < tmp_b_previous->n)
	{
		if (e->rot <= e->rev_rot)
		{
			rb(e);
			if_display(e, 1);
			e->str = ft_strjoin_free(e->str, e->str, " rb");
		}
		else
		{
			rrb(e);
			if_display(e, 1);
			e->str = ft_strjoin_free(e->str, e->str, " rrb");
		}
		tmp_b_next = e->l_b->next;
		tmp_b_previous = e->l_b->previous;
	}
	while (tmp_b_next != e->l_b)
	{
		pa(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, " pa");
		tmp_b_next = e->l_b->next;
	}
}

void	push_swap_calc(t_e *e)
{
	t_list_cir *tmp_b_next;
	t_list_cir *tmp_b_previous;

	if (test_small_list(e))
		return ;
	pb(e);
	e->size_lb = 1;
	if_display(e, 1);
	e->str = ft_strjoin_free(e->str, e->str, "pb");
	push_swap_calc_under(e);
	tri_b(e);
	tmp_b_next = e->l_b->next;
	tmp_b_previous = e->l_b->previous;
	after_tri_b(e, tmp_b_next, tmp_b_previous);
}
