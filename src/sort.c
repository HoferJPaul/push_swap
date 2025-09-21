/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:24:53 by phofer            #+#    #+#             */
/*   Updated: 2025/09/19 16:52:39 by phofer           ###   ########.fr       */
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
	int	a;
	int	b;
	int	c;

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

void	four_sort(t_node **a, t_node **b)
{
	int	min_index;

	if (!a || !*a || ps_lstsize(*a) != 4)
		return ;
	min_index = find_min_index(*a);
	bring_index_to_top(a, min_index);
	pb(a, b);
	three_sort(a);
	pa(a, b);
}

void	five_sort(t_node **a, t_node **b)
{
	int	first_min;
	int	second_min;

	if (!a || !*a || ps_lstsize(*a) != 5)
		return ;
	first_min = find_min_index(*a);
	bring_index_to_top(a, first_min);
	pb(a, b);
	second_min = find_min_index(*a);
	bring_index_to_top(a, second_min);
	pb(a, b);
	three_sort(a);
	if ((*b)->index < (*b)->next->index)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	sort_dispatch(t_node **a, t_node **b)
{
	int	size;

	if (!a || !*a)
		return ;
	if (is_sorted(*a))
		return ;
	size = ps_lstsize(*a);
	if (size == 2)
		two_sort(a);
	else if (size == 3)
		three_sort(a);
	else if (size == 4)
		four_sort(a, b);
	else if (size == 5)
		five_sort(a, b);
	// else
	// 	big_sort(a, b);
}
