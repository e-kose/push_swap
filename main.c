/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:30:54 by ekose             #+#    #+#             */
/*   Updated: 2024/02/13 22:35:08 by ekose            ###   ########.fr       */
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
	// if(ft_check_stack_sorted(&stack_a))
	// {
	// 	if(ft_stack_size(&stack_a) == 2)
	// 		ft_swap_a(&stack_a);
	// 	else if(ft_stack_size(&stack_a) == 3)
	// 		ft_three_node_sort(&stack_a);
	// }
	// ft_reverse_rotate_a(&stack_a);
	// ft_rotate_a(&stack_a);
	// // ft_swap(&stack_a);
	// ft_push_b(&stack_a,&stack_b);
	// // ft_push(&stack_b,&stack_a);
	// ft_push_b(&stack_a,&stack_b);
	// ft_swap_a(&stack_a);
	// ft_swap_b(&stack_b);
	while(stack_a!=NULL)
	{
		printf("%d\n",stack_a->data);
		stack_a=stack_a->next;
	}
	printf("--------------\n");
	while (stack_b != NULL)
	{
		printf("%d\n",stack_b->data);
		stack_b=stack_b->next;
	}

	// printf("%ld\n",stack_a.data);
}
