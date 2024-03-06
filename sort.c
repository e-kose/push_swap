/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:56:08 by ekose             #+#    #+#             */
/*   Updated: 2024/03/06 12:23:03 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_bits(t_stack **stack)
{
	int	max_bit;
	int	max_index;

	max_index = ft_max_node(stack)->index;
	max_bit = 0;
	while (max_index >> max_bit)
		max_bit++;
	return (max_bit);
}

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top;
	int		i;
	int		j;
	int		size;
	int		max_bit;

	max_bit = ft_max_bits(stack_a);
	size = ft_stack_size(stack_a);
	i = -1;
	while (++i < max_bit)
	{
		j = -1;
		while (++j < size)
		{
			top = *stack_a;
			if ((top->index >> i) & 1)
				ft_rotate_a(stack_a);
			else
				ft_push_b(stack_a, stack_b);
		}
		while (ft_stack_size(stack_b))
			ft_push_a(stack_b, stack_a);
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(stack_a) == 2)
		ft_swap_a(stack_a);
	else if (ft_stack_size(stack_a) == 3)
		ft_three_node_sort_a(stack_a);
	else if (ft_stack_size(stack_a) == 5)
		ft_five_node_sort(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
}
