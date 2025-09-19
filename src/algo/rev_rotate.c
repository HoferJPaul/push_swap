/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:13:55 by phofer            #+#    #+#             */
/*   Updated: 2025/09/19 16:20:38 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;

	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
