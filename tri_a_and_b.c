/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a_and_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:10:51 by ajubert           #+#    #+#             */
/*   Updated: 2016/05/11 17:00:00 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_a_and_b_next(t_e *e, t_list_cir *tmp, int comp, int comp1)
{
	if (comp > comp1 && comp1 > tmp->n)
	{
		sa(e);
		if_display(e, 1);
		rra(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "sa rra");
	}
	if (comp > comp1 && tmp->n > comp)
	{
		sa(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "sa");
	}
	if (comp1 > tmp->n && tmp->n > comp)
	{
		rra(e);
		if_display(e, 1);
		sa(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "rra sa");
	}
}

int		tri_a_and_b(t_e *e)
{
	t_list_cir	*tmp;
	int			comp;
	int			comp1;

	tmp = e->l_a->next;
	comp = tmp->n;
	tmp = tmp->next;
	comp1 = tmp->n;
	tmp = tmp->next;
	if (tmp->n > comp1 && comp1 > comp)
		return (0);
	if (comp1 > comp && comp > tmp->n)
	{
		rra(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "rra");
	}
	if (comp > tmp->n && tmp->n > comp1)
	{
		ra(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "ra");
	}
	tri_a_and_b_next(e, tmp, comp, comp1);
	return (1);
}

void	tri_b_and_a_next(t_e *e, t_list_cir *tmp, int comp, int comp1)
{
	if (comp > comp1 && comp1 > tmp->n)
	{
		sb(e);
		if_display(e, 1);
		rrb(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "sb rrb ");
	}
	if (comp > comp1 && tmp->n > comp)
	{
		sb(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "sb ");
	}
	if (comp > tmp->n && tmp->n > comp1)
	{
		rb(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "rb ");
	}
}

void	tri_b_and_a(t_e *e)
{
	t_list_cir	*tmp;
	int			comp;
	int			comp1;

	tmp = e->l_b->next;
	comp = tmp->n;
	tmp = tmp->next;
	comp1 = tmp->n;
	tmp = tmp->next;
	if (comp1 > comp && comp > tmp->n)
	{
		rrb(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "rrb ");
	}
	if (comp1 > tmp->n && tmp->n > comp)
	{
		rrb(e);
		if_display(e, 1);
		sb(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "rrb sb ");
	}
	tri_b_and_a_next(e, tmp, comp, comp1);
}
