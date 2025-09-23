/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:03:44 by phofer            #+#    #+#             */
/*   Updated: 2025/09/23 15:06:53 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_parse(char **args, t_node **stack_a, int must_free)
{
	int	i;
	int	tmp;

	i = 0;
	while (args[i])
	{
		if (!ps_is_valid(args[i]))
		{
			if (must_free)
				free_split(args);
			free_stack(stack_a);
			exit(1);
		}
		tmp = ft_atoi(args[i]);
		ps_lstadd_back(stack_a, ps_lstnew(tmp));
		++i;
	}
	return (1);
}

t_args	arg_check(int argc, char **argv)
{
	t_args	result;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	if (argc == 2)
	{
		result.args = ft_split(argv[1], ' ');
		if (!result.args || !result.args[0])
		{
			ft_putstr_fd("Error\n", 2);
			free_split(result.args);
			exit (1);
		}
		result.must_free = 1;
	}
	else
	{
		result.args = argv + 1;
		result.must_free = 0;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_args	args;

	stack_a = NULL;
	stack_b = NULL;
	args = arg_check(argc, argv);
	ps_parse(args.args, &stack_a, args.must_free);
	if (has_duplicates(stack_a))
	{
		if (args.must_free)
			free_split(args.args);
		return (free_stack(&stack_a),
			ft_putstr_fd("Error\n", 2), 1);
	}
	ps_index(stack_a);
	sort_dispatch(&stack_a, &stack_b);
	free_stack(&stack_a);
	if (args.must_free)
		free_split(args.args);
	return (0);
}
