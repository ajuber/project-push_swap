/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 23:26:40 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/24 10:08:55 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_cir		*ft_create_list(char **argv, t_e *e, int argc)
{
	int		i;
	long	nb;
	int		j;

	i = 1;
	if (!(e->l_a = ft_create_racine()))
		return (NULL);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				return (NULL);
			j++;
		}
		nb = ft_atoi_long(argv[i]);
		if (nb < -2147483648 || nb > 2147483647)
			return (NULL);
		push_back_list(e->l_a, nb);
		i++;
	}
	return (e->l_a);
}

int				ft_check_doublon(t_e *e)
{
	t_list_cir *tmp;
	t_list_cir *tmp1;

	tmp = e->l_a->next;
	while (tmp != e->l_a)
	{
		tmp1 = tmp->next;
		while (tmp1 != e->l_a)
		{
			if (tmp->n == tmp1->n)
				return (0);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_e		e;

	if (argc == 1)
	{
		ft_putendl_fd("pas de pile a trier", 2);
		return (-1);
	}
	e.l_a = ft_create_list(argv, &e, argc);
	e.l_b = ft_create_racine();
	if (e.l_a == NULL || (!(ft_check_doublon(&e))))
	{
		ft_putendl_fd("error", 2);
		return (-1);
	}
	e.str = ft_strdup("\0");
	push_swap_calc(&e);
	ft_putendl(e.str);
	display_list(&e);
	ft_free_list_cir(e.l_a);
	ft_free_list_cir(e.l_b);
	ft_memdel((void **)&e.str);
	return (0);
}
