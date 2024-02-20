/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:56:08 by ekose             #+#    #+#             */
/*   Updated: 2024/02/20 12:38:32 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_stack_sorted(t_stack **stack)
{
	t_stack	*tmp;
	int		check;
	if (stack == NULL)
		return (0);
	tmp = *stack;
	check = 0;
	while (tmp->next != NULL)
	{
		if (tmp->data < tmp->next->data)
			check++;
		tmp = tmp->next;
	}
	if (check == ft_stack_size(stack) - 1)
		return (0);
	return (1);
}

void	ft_three_node_sort_a(t_stack **stack_a)
{
	t_stack *max;

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
	t_stack *min;

	min = ft_min_node(stack_b);
	if (min == *stack_b)
		ft_rotate_b(stack_b);
	else if ((*stack_b)->next == min)
		ft_reverse_rotate_b(stack_b);
	if ((*stack_b)->data < (*stack_b)->next->data)
		ft_swap_b(stack_b);
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
	int	mid;
	int	i;
	int	size;
	int rotate;

	i = 0;
	rotate = 0;
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
		{
			// if((*stack_b)->data > (*stack_a)->data )
			// 	ft_push_a(stack_b, stack_a);
			// else
			// 	ft_rotate_rr(stack_a,stack_b);
			while((*stack_b)->data > (*stack_a)->data)
			{
				ft_rotate_a(stack_a);
				rotate++;
			}
			ft_push_a(stack_b, stack_a);
			while(rotate > 0)
			{
				ft_reverse_rotate_a(stack_a);
				rotate--;
			}
		}
		else
			ft_rotate_b(stack_b);
		i++;
		rotate = 0;
	}
	// if(ft_stack_size(stack_b) == 3)
	// 	ft_three_node_sort_b(stack_b);
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
