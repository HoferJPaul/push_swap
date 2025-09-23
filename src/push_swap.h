/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:57:26 by phofer            #+#    #+#             */
/*   Updated: 2025/09/23 15:01:34 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

# define BIG_SORT radix_sort

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	int				index;
}	t_node;

typedef struct s_args
{
	char	**args;
	int		must_free;
}	t_args;

/* ==== ps_lst.c ==== */
void	ps_lstadd_back(t_node **lst, t_node *new);
t_node	*ps_lstnew(int value);
int		ps_lstsize(t_node *lst);

/* ==== parse.c ==== */
int		has_duplicates(t_node *stack);
int		ps_is_valid_digits(char *str, int i, int sign, long num);
int		ps_is_valid(char *str);
int		ps_index(t_node *stack_a);

/* ==== helpers.c ==== */
void	print_stack(t_node *stack);
void	free_stack(t_node **stack);
void	free_split(char **args);

/* ==== sort.c ==== */
void	two_sort(t_node **stack);
void	three_sort(t_node **stack);
void	four_sort(t_node **a, t_node **b);
void	five_sort(t_node **a, t_node **b);
void	sort_dispatch(t_node **a, t_node **b);

void	radix_sort(t_node **stack_a, t_node **stack_b);
void	greedy_sort(t_node **stcak_a, t_node **stack_b);

/* ==== utils.c ==== */
int		find_min_index(t_node *stack);
int		find_max_index(t_node *stack);
int		get_position(t_node *stack, int index);
void	bring_index_to_top(t_node **stack, int index);
int		is_sorted(t_node *stack);

/* ==== algorithms ==== */
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif
