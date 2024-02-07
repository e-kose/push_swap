/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:45:05 by ekose             #+#    #+#             */
/*   Updated: 2024/02/06 23:07:56 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_filling(t_stack *stack_a, char **argv)
{
	t_stack	*top;

	top = NULL;
	int	i;
	i = 0;
	while(argv[++i])
	{
		if(top == NULL)
		{
			stack_a = (t_stack *)malloc(sizeof(t_stack));
			stack_a->data = ft_atoi(argv[i]);
			stack_a->next = NULL;
			top = stack_a;
		}
		else
		{
			stack_a = (t_stack *)malloc(sizeof(t_stack));
			stack_a->data = ft_atoi(argv[i]);
			stack_a->next = top;
			top = stack_a;
		}
	}
	ft_difference_check(stack_a);
	return (stack_a);
}

t_stack	*ft_swap(t_stack *stack)
{
	t_stack	*top;

	if(stack->next == NULL || stack == NULL)
		return (stack);
	top = stack->next;
	stack->next = top->next;
	top->next =stack;
	return (top);
}

t_stack *ft_push(t_stack *stack_d, t_stack *stack_s)
{
	t_stack	*top;

	if(stack_s == NULL)
		return (stack_d);
	if(stack_d == NULL)
	{
		top = stack_s->next;
		stack_s->next = NULL;
		stack_d = stack_s;
		stack_s = top;
	}
	else
	{
		top = stack_s->next;
		stack_s->next = stack_d;
	}
	return(stack_d);
}
