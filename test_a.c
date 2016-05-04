/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 15:15:08 by ajubert           #+#    #+#             */
/*   Updated: 2016/05/04 16:30:10 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_a(t_e *e, int nb_rot, int nb_rot_rev, int comp)
{
	if (nb_rot <= nb_rot_rev)
	{
		comp = nb_rot;
		while (nb_rot-- > 0)
		{
			ra(e);
			display_list(e, 1);
			if (nb_rot + 1 != comp)
				e->str = ft_strjoin_free(e->str, e->str, " ");
			e->str = ft_strjoin_free(e->str, e->str, "ra");
		}
	}
	else
	{
		comp = nb_rot_rev;
		while (nb_rot_rev-- > 0)
		{
			rra(e);
			display_list(e, 1);
			if (nb_rot_rev + 1 != comp)
				e->str = ft_strjoin_free(e->str, e->str, " ");
			e->str = ft_strjoin_free(e->str, e->str, "rra");
		}
	}
}

void	test_to_tri_a(t_e *e, int *nb_rot_rev, int comp, t_list_cir **tmp)
{
	int max;

	*nb_rot_rev = 1;
	max = comp;
	comp = tmp[0]->n;
	*tmp = tmp[0]->next;
	while (tmp[0] != e->l_a && comp < tmp[0]->n && tmp[0]->n < max)
	{
		comp = tmp[0]->n;
		tmp[0] = tmp[0]->next;
		*nb_rot_rev += 1;
	}
}

int		test_a(t_e *e)
{
	t_list_cir	*tmp;
	int			comp;
	int			nb_rot;
	int			nb_rot_rev;

	nb_rot = 1;
	tmp = e->l_a->next;
	comp = tmp->n;
	tmp = tmp->next;
	while (tmp != e->l_a && comp < tmp->n)
	{
		nb_rot++;
		comp = tmp->n;
		tmp = tmp->next;
	}
	if (tmp == e->l_a)
		return (1);
	test_to_tri_a(e, &nb_rot_rev, comp, &tmp);
	if (tmp == e->l_a)
	{
		tri_a(e, nb_rot, nb_rot_rev, comp);
		return (1);
	}
	return (0);
}
