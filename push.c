/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:52:51 by ekose             #+#    #+#             */
/*   Updated: 2024/02/11 15:27:52 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **stack_d, t_stack **stack_s)
{
	t_stack	*head;

	if(*stack_s == NULL)
		return ;
	if(*stack_d == NULL)
	{
		head = (*stack_s)->next;
		(*stack_s) ->next = NULL;
		*stack_d = *stack_s;
		*stack_s = head;
	}
	else
	{
		head = (*stack_s)->next;
		(*stack_s)->next = *stack_d;
		*stack_d = *stack_s;
		*stack_s = head;
	}
}

void	ft_push_a(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_a, stack_b);
	write(1,"pa\n",3);
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1,"pb\n",3);
}
