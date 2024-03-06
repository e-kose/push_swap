/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:18:53 by ekose             #+#    #+#             */
/*   Updated: 2024/03/06 13:59:00 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_index(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		tmp ->index = -1;
		tmp = tmp->next;
	}
}

void	ft_find_index(t_stack **stack)
{
	t_stack	*top;
	int		index;

	index = 0;
	ft_fill_index(stack);
	top = ft_min_node(stack);
	while (top != NULL)
	{
		top->index = index++;
		top = ft_min_node(stack);
	}
}
