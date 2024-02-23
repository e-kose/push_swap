/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:05:24 by ekose             #+#    #+#             */
/*   Updated: 2024/02/22 21:39:29 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack *tmp;

	tmp = *(stack);
	top = (*stack)->next;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->next = NULL;
	*stack= top;
}

void	ft_rotate_a(t_stack **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 4);
}

void	ft_rotate_b(t_stack **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 4);
}

void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 4);
}
