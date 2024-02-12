/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:45:05 by ekose             #+#    #+#             */
/*   Updated: 2024/02/11 15:12:43 by ekose            ###   ########.fr       */
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
	while(argv[++i])
	{
		if(top == NULL)
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

