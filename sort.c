/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:56:08 by ekose             #+#    #+#             */
/*   Updated: 2024/02/23 18:37:27 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_sort_iter(t_stack **stack_a, t_stack **stack_b)
{
	int		rotate;
	t_stack	*end;

	rotate = 0;
	while((*stack_b)->data > (*stack_a)->data)
	{
		ft_rotate_a(stack_a);
		rotate++;
	}
	ft_push_a(stack_b, stack_a);
	while(rotate > 0)
	{
		end = ft_find_end(stack_a);
		if(end->data < (*stack_b)->data && (*stack_a)->data > (*stack_b)->data)
		{
			ft_push_a(stack_b,stack_a);
			continue ;
		}
		ft_reverse_rotate_a(stack_a);
		rotate--;
	}
}

void	ft_sort_first(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		mid;
	int		i;

	i = 0;
	size = ft_stack_size(stack_a);
	mid = ft_cp_stack(stack_a);
	if(size == 3)
	{
		ft_three_node_sort_a(stack_a);
		return ;
	}
	while(i < size  && ft_stack_size(stack_a) > 3)
	{
		if((*stack_a)->data <= mid)
			ft_push_b(stack_a, stack_b);
		else
			ft_rotate_a(stack_a);
		i++;
	}
	ft_sort_first(stack_a,stack_b);
}

void	ft_sort_second(t_stack **stack_a, t_stack **stack_b)
{
	int		mid;
	int		i;
	int		size;

	i = 0;
	size = ft_stack_size(stack_b);
	mid = ft_cp_stack(stack_b);
	if(size == 3)
	{
		ft_three_node_sort_b(stack_b);
		return ;
	}
	while(i < size && ft_stack_size(stack_b) > 3)
	{
		if((*stack_b)->data >= mid)
			ft_sort_iter(stack_a, stack_b);
		else
			ft_rotate_b(stack_b);
		i++;
	}
	ft_sort_second(stack_a, stack_b);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int rotate = 0;
	ft_sort_first(stack_a, stack_b);
	ft_sort_second(stack_a, stack_b);
	while(*stack_b != NULL)
	{
			while((*stack_b)->data > (*stack_a)->data && (*stack_b)->data < (*stack_a)->next->data)
			{
				ft_rotate_a(stack_a);
				rotate++;
			}
			ft_push_a(stack_b, stack_a);
			while(rotate >0)
			{
				ft_reverse_rotate_a(stack_a);
				rotate--;
			}
		rotate =0;
	}

}
