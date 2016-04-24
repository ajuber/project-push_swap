/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 23:16:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/24 08:00:24 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct			s_list_cir
{
	int					n;
	struct s_list_cir	*previous;
	struct s_list_cir	*next;
}						t_list_cir;

typedef struct			s_e
{
	t_list_cir			*l_a;
	t_list_cir			*l_b;
	char				*str;
}						t_e;

t_list_cir				*ft_create_racine(void);
t_list_cir				*push_back_list(t_list_cir *begin_list, int nb);
void					ft_free_list_cir(t_list_cir *begin_list);
void					pa(t_e *e);
void					pb(t_e *e);
void					sa(t_e *e);
void					sb(t_e *e);
void					ss(t_e *e);
void					ra(t_e *e);
void					rb(t_e *e);
void					rr(t_e *e);
void					rra(t_e *e);
void					rrb(t_e *e);
void					rrr(t_e *e);
void					push_swap_calc(t_e *e);
void					display_list(t_e *e);

#endif
