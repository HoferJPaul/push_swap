/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:57:26 by phofer            #+#    #+#             */
/*   Updated: 2025/09/18 20:13:37 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	int				index;
}	t_node;

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

#endif
