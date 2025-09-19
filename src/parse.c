/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:03:44 by phofer            #+#    #+#             */
/*   Updated: 2025/09/19 14:57:03 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_node *stack)
{
	t_node	*i;
	t_node	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->content == j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	ps_is_valid_digits(char *str, int i, int sign, long num)
{

	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (ft_putstr_fd("Error, Input must be digits only\n", 2), 0);
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX)
			|| (sign == -1 && (num * -1) < INT_MIN))
			return (ft_putstr_fd("Error, Outside of INT scope\n", 2), 0);
		++i;
	}
	return (1);
}

int	ps_is_valid(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	if (!str || !str[0])
		return (ft_putstr_fd("Error: Empty string\n", 2), 0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	if (!str[i])
		return (ft_putstr_fd("Error: No digits after sign\n", 2), 0);
	if (!ps_is_valid_digits(str, i, sign, num))
		return (0);
	return (1);
}

static void	assign_index(t_node *current, int *sorted, int size)
{
	int	i;

	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->content == sorted[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

int	ps_index(t_node *stack_a)
{
	int		size;
	int		*sorted;
	int		i;
	t_node	*current;

	size = ps_lstsize(stack_a);
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (0);
	i = 0;
	current = stack_a;
	while (current)
	{
		sorted[i] = current->content;
		current = current->next;
		++i;
	}
	ft_bubble_sort(sorted, size);
	current = stack_a;
	assign_index(current, sorted, size);
	free(sorted);
	return (1);
}
