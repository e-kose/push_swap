/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:59:45 by ekose             #+#    #+#             */
/*   Updated: 2024/03/06 13:36:47 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **stack)
{
	t_stack	*head;

	if ((*stack)->next == NULL || *stack == NULL)
		return ;
	head = (*stack)->next;
	head->prev->prev = head;
	head->prev->next = head->next;
	if (head->next != NULL)
		head->next->prev = head->prev;
	head->next = head->prev;
	head->prev = NULL;
	(*stack) = head;
}

void	ft_swap_a(t_stack **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ft_swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
