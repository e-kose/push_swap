/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:45:53 by ekose             #+#    #+#             */
/*   Updated: 2024/02/10 13:25:03 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while(argv[i])
		free(argv[i++]);
	free(argv);
}
void	ft_free(t_stack **stack_a, char *s)
{
	t_stack	*iter;

	while((*stack_a)!= NULL)
	{
		iter = (*stack_a)->next;
		free(*stack_a);
		*stack_a = iter;
	}
	ft_error(s);
}
