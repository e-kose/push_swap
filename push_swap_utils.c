/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:45:05 by ekose             #+#    #+#             */
/*   Updated: 2024/03/02 14:57:39 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_filling(t_stack **stack_a, t_data *arg)
{
	t_stack	*top;
	int		i;

	top = NULL;
	i = -1;
	while (arg->argv[++i])
	{
		if (top == NULL)
		{
			*stack_a = malloc(sizeof(t_stack));
			(*stack_a)->data = (int)ft_atoi(arg->argv[i]);
			(*stack_a)->next = NULL;
			(*stack_a)->prev = NULL;
			top = *stack_a;
		}
		else
		{
			top->next = malloc(sizeof(t_stack));
			top->next->data = (int)ft_atoi(arg->argv[i]);
			top->next->prev = top;
			top = top->next;
			top->next = NULL;
		}
	}
	ft_difference_check(stack_a, arg);
}

t_stack	*ft_find_end(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	ft_stack_size(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	if (stack == NULL)
		return (0);
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*ft_max_node(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*max;

	max = *stack;
	if (max == NULL)
		return (0);
	tmp = max->next;
	while (tmp != NULL)
	{
		if (tmp->data > max->data)
		{
			max = tmp;
			tmp = max->next;
		}
		else
			tmp = tmp->next;
	}
	return (max);
}

t_stack	*ft_min_node(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *stack;
	if (tmp == NULL)
		return (0);
	min = NULL;
	while (tmp != NULL)
	{
		if ((min == NULL || tmp->data < min->data) && tmp->index == -1)
		{
			min = tmp;
			tmp = min->next;
		}
		else
			tmp = tmp->next;
	}
	return (min);
}
