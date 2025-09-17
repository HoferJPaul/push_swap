/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phofer <phofer@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:57:26 by phofer            #+#    #+#             */
/*   Updated: 2025/09/17 16:09:50 by phofer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	int				index;
}	t_node;

#endif
