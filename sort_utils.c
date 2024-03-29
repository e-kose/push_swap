/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:37:56 by ekose             #+#    #+#             */
/*   Updated: 2024/03/06 12:26:22 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_node_sort_a(t_stack **stack_a)
{
	t_stack	*max;

	max = ft_max_node(stack_a);
	if (max == *stack_a)
		ft_rotate_a(stack_a);
	else if ((*stack_a)->next == max)
		ft_reverse_rotate_a(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_swap_a(stack_a);
}

void	ft_three_node_sort_b(t_stack **stack_b)
{
	t_stack	*min;

	min = ft_min_node(stack_b);
	if (min == *stack_b)
		ft_rotate_b(stack_b);
	else if ((*stack_b)->next == min)
		ft_reverse_rotate_b(stack_b);
	if ((*stack_b)->data < (*stack_b)->next->data)
		ft_swap_b(stack_b);
}

void	ft_five_node_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_stack_size(stack_a);
	while (len--)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			ft_push_b(stack_a, stack_b);
		else
			ft_rotate_a(stack_a);
	}
	ft_three_node_sort_a(stack_a);
	ft_push_a(stack_b, stack_a);
	ft_push_a(stack_b, stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_swap_a(stack_a);
}
