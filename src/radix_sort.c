/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:32:37 by phofer            #+#    #+#             */
/*   Updated: 2025/09/21 16:47:50 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		bit_max;

	size = ps_lstsize(*stack_a);
	bit_max = max_bits(size);
	i = 0;
	while (i < bit_max)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa (stack_a, stack_b);
		i++;
	}
}
