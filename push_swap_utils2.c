/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:18:53 by ekose             #+#    #+#             */
/*   Updated: 2024/02/13 17:31:22 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

void	ft_indexing(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int		median;

	tmp = *stack;
	median = ft_stack_size(stack) / 2;
	i = 0;
	while(tmp != NULL)
	{
		tmp->index = i;
		if(i <= median)
			tmp->above_median = 1;
		else
			tmp->above_median = 0;
		i++;
		tmp = tmp->next;
	}
}
