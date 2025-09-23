/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:06:44 by phofer            #+#    #+#             */
/*   Updated: 2025/09/23 14:25:41 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_node **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
