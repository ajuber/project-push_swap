/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:46:26 by ajubert           #+#    #+#             */
/*   Updated: 2016/05/10 15:11:36 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int		test_revswap_a(t_e *e, t_list_cir *tmp, int comp)
{
	tmp = e->l_a->previous;
	comp = tmp->n;
	tmp = tmp->previous;
	if (comp > tmp->n)
		return (0);
	tmp = tmp->previous;
	while (tmp != e->l_a && comp > tmp->n)
	{
		comp = tmp->n;
		tmp = tmp->previous;
	}
	if (tmp == e->l_a)
	{
		rra(e);
		if_display(e, 1);
		rra(e);
		if_display(e, 1);
		sa(e);
		if_display(e, 1);
		ra(e);
		if_display(e, 1);
		ra(e);
		if_display(e, 1);
		e->str = ft_strjoin_free(e->str, e->str, "rra rra sa ra ra");
		return (1);
	}
	return (0);
}

int		test_swap_a(t_e *e)
{
	t_list_cir	*tmp;
	int			comp;

	tmp = e->l_a->next;
	comp = tmp->n;
	tmp = tmp->next;
	if (comp < tmp->n)
	{
		if (test_revswap_a(e, tmp, comp))
			return (1);
		else
			return (0);
	}
	tmp = tmp->next;
	while (tmp != e->l_a && comp < tmp->n)
	{
		comp = tmp->n;
		tmp = tmp->next;
	}
	if (tmp == e->l_a)
	{
		sa(e);
		e->str = ft_strjoin_free(e->str, e->str, "sa");
		if_display(e, 1);
		return (1);
	}
	return (0);
}
