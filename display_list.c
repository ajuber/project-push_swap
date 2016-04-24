/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 07:01:21 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/24 07:28:43 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_list(t_e *e)
{
	t_list_cir *tmp_a;
	t_list_cir *tmp_b;

	tmp_a = e->l_a->previous;
	while (tmp_a != e->l_a)
	{
		ft_putnbr(tmp_a->n);
		ft_putchar(' ');
		tmp_a = tmp_a->previous;
	}
	tmp_b = e->l_b->previous;
	ft_putchar('\n');
	while (tmp_b != e->l_b)
	{
		ft_putnbr(tmp_b->n);
		ft_putchar(' ');
		tmp_b = tmp_b->previous;
	}
}
