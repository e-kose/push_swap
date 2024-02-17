/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:45:05 by ekose             #+#    #+#             */
/*   Updated: 2024/02/13 13:13:15 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_filling(t_stack **stack_a, char **argv)
{
	t_stack	*top;

	ft_limit_check(argv);
	top = NULL;
	int	i;
	i = -1;
	while (argv[++i])
	{
		if (top == NULL)
		{
			*stack_a = malloc(sizeof(t_stack));
			(*stack_a)->data = (int)ft_atoi(argv[i]);
			(*stack_a)->next = NULL;
			top = *stack_a;
		}
		else
		{
			*stack_a = malloc(sizeof(t_stack));
			(*stack_a)->data = (int)ft_atoi(argv[i]);
			(*stack_a)->next = top;
			top = *stack_a;
		}

	}
	ft_difference_check(stack_a);
}

t_stack	*ft_last_node(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp == NULL)
		return (0);
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

	min = *stack;
	if (min == NULL)
		return (0);
	tmp = min->next;
	while (tmp != NULL)
	{
		if (tmp->data < min->data)
		{
			min = tmp;
			tmp = min->next;
		}
		else
			tmp = tmp->next;
	}
	return (min);
}
