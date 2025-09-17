/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:03:44 by phofer            #+#    #+#             */
/*   Updated: 2025/09/17 17:06:14 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i] == 0) || str[i] != '+' || str[i] != '-')
			return (0);
		else
			++i;
	}
	return (1);
}

int	ps_init_stack(t_node *stack_a, t_node *stack_b)
{
	if (!stack_a)
	{
		stack_a->content = NULL;
		stack_a->index = NULL;
		stack_a->next = NULL;
	}
	if (!stack_b)
	{
		stack_b->content = NULL;
		stack_b->index = NULL;
		stack_b->next = NULL;
	}
}

int	ps_parse(char **argv, t_node *stack_a)
{
	int	i;
	int	tmp;

	i = 0;
	while (argv[i])
	{
		if (ps_is_valid(argv[i]) == 0)
			tmp = ft_atoi(argv[i]);
		else
		{
			ft_putstr_fd("Error, Input must be digits only\n", 1);
			exit(1);
		}
		ft_lstadd_back(stack_a, ft_lstnew(tmp));
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_node	stack_a;
	t_node	stack_b;

	ps_init_stack(&stack_a, &stack_b);
	if (argc == 2)
		argv = ft_split(argv[1], " ");
	ps_parse(argv, &stack_a);
	return (0);
}
