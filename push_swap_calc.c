/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 05:50:31 by ajubert           #+#    #+#             */
/*   Updated: 2016/05/12 00:03:11 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_to_min(t_e *e)
{
	if (e->rot < e->rev_rot)
	{
		while (e->rot > 0)
		{
			e->rot--;
			ra(e);
			if_display(e, 1);
			e->str = ft_strjoin_free(e->str, e->str, "ra ");
		}
	}
	else
	{
		while (e->rev_rot > 0)
		{
			e->rev_rot--;
			rra(e);
			if_display(e, 1);
			e->str = ft_strjoin_free(e->str, e->str, "rra ");
		}
	}
}

void	search_min(t_e *e)
{
	t_list_cir	*tmp;
	t_list_cir	*tmp_min;
	int			i;

	e->rot = 0;
	i = 0;
	tmp = e->l_a->next;
	tmp_min = tmp;
	while (tmp != e->l_a)
	{
		if (tmp->n < tmp_min->n)
		{
			tmp_min = tmp;
			e->rot = i;
		}
		tmp = tmp->next;
		i++;
	}
	e->rev_rot = e->size_l - e->rot;
	rot_to_min(e);
}

void	push_swap_calc(t_e *e)
{
	t_list_cir *tmp;

	if (test_small_list(e))
		return ;
	while (e->size_l > 0)
	{
		search_min(e);
		pb(e);
		e->size_l--;
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "pb ");
	}
	tmp = e->l_b->next;
	while (tmp != e->l_b)
	{
		pa(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "pa ");
		tmp = e->l_b->next;
	}
	e->str[ft_strlen(e->str) - 1] = '\0';
}
