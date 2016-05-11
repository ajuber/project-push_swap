/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_small_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:09:36 by ajubert           #+#    #+#             */
/*   Updated: 2016/05/11 18:15:06 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		test_small_list(t_e *e)
{
	if (test_a(e))
		return (1);
	if (e->size_l == 3)
	{
		tri_a_and_b(e);
		return (1);
	}
	if (test_swap_a(e))
		return (1);
	if (e->size_l <= 6)
	{
		tri_small_list(e);
		return (1);
	}
	return (0);
}

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
	if (tri_a_and_b(e))
		e->str = ft_strjoin_free(e->str, e->str, " ");
	e->size_l = 3;
	tri_aa(e);
	after_tri_aa(e);
	e->str[ft_strlen(e->str) - 1] = '\0';
}
