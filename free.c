/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:53 by ekose             #+#    #+#             */
/*   Updated: 2024/03/06 12:20:36 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_free(t_stack **stack_a, char *s)
{
	t_stack	*iter;

	while (*stack_a != NULL)
	{
		iter = (*stack_a)->next;
		free(*stack_a);
		*stack_a = iter;
	}
	ft_error(s);
}

void	ft_free_argv(t_data *arg, char *s)
{
	int	i;

	i = 0;
	if (arg->ac == 2)
	{
		while (arg->argv[i])
		{
			free(arg->argv[i]);
			i++;
		}
		free(arg->argv);
	}
	free(arg);
	ft_error(s);
}

void	ft_free(t_stack **stack_a, t_data *arg)
{
	t_stack	*iter;
	int		i;

	i = 0;
	if (arg->ac == 2)
	{
		while (arg->argv[i])
			free(arg->argv[i++]);
		free(arg->argv);
	}
	free(arg);
	while ((*stack_a) != NULL)
	{
		iter = (*stack_a)->next;
		free(*stack_a);
		*stack_a = iter;
	}
}

void	ft_full_free(t_stack **stack_a, t_data *arg, char *s)
{
	int		i;
	t_stack	*iter;

	iter = *stack_a;
	i = 0;
	if (arg->ac == 2)
	{
		while (arg->argv[i])
			free(arg->argv[i++]);
		free(arg->argv);
	}
	free(arg);
	while ((*stack_a) != NULL)
	{
		iter = (*stack_a)->next;
		free(*stack_a);
		*stack_a = iter;
	}
	ft_error(s);
}
