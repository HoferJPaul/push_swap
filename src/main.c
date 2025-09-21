/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:03:44 by phofer            #+#    #+#             */
/*   Updated: 2025/09/21 17:34:03 by phofer           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;
	int		must_free;

	must_free = 0;
	stack_a = NULL;
	stack_b = NULL;
	args = NULL;
	if (argc < 2)
		return (ft_putstr_fd("error, no input", 2), 0);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		must_free = 1;
	}
	else
		args = argv + 1;
	ps_parse(args, &stack_a, must_free);
	if (has_duplicates(stack_a))
	{
		if (must_free)
			free_split(args);
		return (free_stack(&stack_a),
			ft_putstr_fd("Error, duplicates detected\n", 2), 0);
	}
	ps_index(stack_a);
	//print_stack(stack_a);
	sort_dispatch(&stack_a, &stack_b);
	//print_stack(stack_a);
	free_stack(&stack_a);
	if (must_free)
		free_split(args);
	return (0);
}
