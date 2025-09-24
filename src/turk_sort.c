/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:00:00 by phofer            #+#    #+#             */
/*   Updated: 2025/09/24 12:00:00 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find where an element from stack_b should be inserted in stack_a
static int	find_target_position(t_node *stack_a, int b_index)
{
	t_node	*current;
	int		min_greater;
	int		min_index;
	int		max_index;

	if (!stack_a)
		return (-1);

	min_index = find_min_index(stack_a);
	max_index = find_max_index(stack_a);
	
	// If b_index should go at the end (larger than max) or beginning (smaller than min)
	if (b_index > max_index || b_index < min_index)
		return (min_index);  // Place before minimum to maintain order
	
	// Find the smallest number in stack_a that is greater than b_index
	min_greater = INT_MAX;
	current = stack_a;
	while (current)
	{
		if (current->index > b_index && current->index < min_greater)
			min_greater = current->index;
		current = current->next;
	}
	
	return (min_greater);
}

// Calculate cost to bring target to top of stack
static int	calculate_rotation_cost(t_node *stack, int target_index)
{
	int	position;
	int	size;

	position = get_position(stack, target_index);
	if (position == -1)
		return (INT_MAX);
		
	size = ps_lstsize(stack);
	
	// Forward rotation cost
	if (position <= size / 2)
		return (position);
	// Reverse rotation cost  
	else
		return (size - position);
}

// Calculate total cost to move element from B to its correct position in A
static int	calculate_total_cost(t_node *stack_a, t_node *stack_b, int b_index)
{
	int	cost_b;
	int	cost_a;
	int	target_index;

	// Cost to bring element to top of stack B
	cost_b = calculate_rotation_cost(stack_b, b_index);
	
	// Find where this element should go in stack A
	target_index = find_target_position(stack_a, b_index);
	if (target_index == -1)
		return (INT_MAX);
		
	// Cost to prepare the position in stack A
	cost_a = calculate_rotation_cost(stack_a, target_index);
	
	return (cost_a + cost_b);
}

// Find the cheapest element in stack_b to move to stack_a
static int	find_cheapest_element(t_node *stack_a, t_node *stack_b)
{
	t_node	*current;
	int		min_cost;
	int		cheapest_index;
	int		current_cost;

	if (!stack_b)
		return (-1);
		
	current = stack_b;
	min_cost = INT_MAX;
	cheapest_index = current->index;
	
	while (current)
	{
		current_cost = calculate_total_cost(stack_a, stack_b, current->index);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest_index = current->index;
		}
		current = current->next;
	}
	
	return (cheapest_index);
}

// Execute the move: bring element from B to correct position in A
static void	execute_cheapest_move(t_node **stack_a, t_node **stack_b, int b_index)
{
	int	target_index;

	// Find where this element belongs in stack A
	target_index = find_target_position(*stack_a, b_index);
	
	// Prepare stack A: bring target position to top
	bring_index_to_top(stack_a, target_index);
	
	// Prepare stack B: bring element to top
	bring_index_to_top(stack_b, b_index);
	
	// Move element from B to A
	pa(stack_a, stack_b);
}

// Push all elements except the 3 best ones to stack B
static void	push_to_stack_b(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	pushed;

	size = ps_lstsize(*stack_a);
	pushed = 0;
	
	// Push elements to B, but keep the 3 that will be easiest to sort
	while (ps_lstsize(*stack_a) > 3 && pushed < size - 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

// Main Turk algorithm
void	turk_sort(t_node **stack_a, t_node **stack_b)
{
	int	cheapest_index;

	// Handle small cases
	if (ps_lstsize(*stack_a) <= 3)
	{
		three_sort(stack_a);
		return;
	}
	
	// Step 1: Push all but 3 elements to stack B
	push_to_stack_b(stack_a, stack_b);
	
	// Step 2: Sort remaining 3 elements in stack A
	three_sort(stack_a);
	
	// Step 3: Move elements from B back to A using greedy approach
	while (*stack_b)
	{
		cheapest_index = find_cheapest_element(*stack_a, *stack_b);
		if (cheapest_index == -1)
		{
			// Fallback: just move top element if calculation fails
			pa(stack_a, stack_b);
		}
		else
		{
			execute_cheapest_move(stack_a, stack_b, cheapest_index);
		}
	}
	
	// Step 4: Final adjustment - ensure minimum is at top
	if (!is_sorted(*stack_a))
	{
		bring_index_to_top(stack_a, find_min_index(*stack_a));
	}
}