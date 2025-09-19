/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:24:53 by phofer            #+#    #+#             */
/*   Updated: 2025/09/19 16:10:49 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_node **stack)
{

	if (!stack || !*stack || !(*stack)->next)
		return ;
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
}

void	three_sort(t_node **stack)
{
	int		a;
	int		b;
	int		c;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}
