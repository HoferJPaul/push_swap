/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:59:01 by phofer            #+#    #+#             */
/*   Updated: 2025/09/19 16:20:32 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **from, t_node **to)
{
	t_node	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}

