/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:30:54 by ekose             #+#    #+#             */
/*   Updated: 2024/02/23 15:13:16 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *s)
{
	write(2,s,ft_strlen(s));
	exit(1);
}

int	main(int ac, char **argv)
{
	t_data	arg;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	arg.argv = argv + 1;
	if (ac == 1)
		return (0);
	else if(ac == 2)
		ft_arg_check(&arg,argv);
	argv = arg.argv;
	ft_value_check(argv);
	ft_stack_filling(&stack_a,argv);
	ft_indexing(&stack_a);
	ft_cp_stack(&stack_a);
	if(ft_check_stack_sorted(&stack_a))
	{
		if(ft_stack_size(&stack_a) == 2)
			ft_swap_a(&stack_a);
		else if(ft_stack_size(&stack_a) == 3)
			ft_three_node_sort_a(&stack_a);
		else
			ft_sort(&stack_a, &stack_b);
	}
	// while(stack_a!=NULL)
	// {
	// 	printf("%d\n",stack_a->data);
	// 	stack_a=stack_a->next;
	// }
	return (0);
}
