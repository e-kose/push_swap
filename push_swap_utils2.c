/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:18:53 by ekose             #+#    #+#             */
/*   Updated: 2024/02/29 00:09:30 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_fill_index(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while(tmp != NULL)
	{
		tmp ->index = -1;
		tmp = tmp->next;
	}
}

void	ft_find_index(t_stack **stack)
{
	t_stack *top;
	int		index;

	index = 0;
	ft_fill_index(stack);
	top = ft_min_node(stack);
	while(top != NULL)
	{
		top->index = index++;
		top = ft_min_node(stack);
	}
}

char **ft_arg(char **argv ,int ac)
{
	int	i;
	char	*tmp;
	char	**f_arg;
	int		check;

	check = 0;
	tmp = argv[0];
	i = 1;
	while(argv[i])
	{
		printf("aa\n");
		tmp = ft_strjoin(tmp, " ");
		tmp = ft_strjoin(tmp, argv[i]);
		check = 1;
		i++;
	}
	f_arg = ft_split(tmp, ' ');
	if(check == 1)
		free(tmp);
	return(f_arg);
}
