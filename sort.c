/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:56:08 by ekose             #+#    #+#             */
/*   Updated: 2024/02/13 13:14:55 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_stack_sorted(t_stack **stack)
{
	t_stack	*tmp;
	int		check;
	if (stack == NULL)
		return (1);
	tmp = *stack;
	check = 0;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			check++;
		tmp = tmp->next;
	}
	if (check == ft_stack_size(stack) - 1)
		return (0);
	return (1);
}

void	ft_three_node_sort(t_stack **stack_a)
{
	t_stack *max;

	max = ft_max_node(stack_a);
	if (max == *stack_a)
		ft_rotate_a(stack_a);
	else if ((*stack_a)->next == max)
		ft_reverse_rotate_a(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_swap_a(stack_a);
}
