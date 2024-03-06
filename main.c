/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:30:54 by ekose             #+#    #+#             */
/*   Updated: 2024/03/06 13:18:01 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

int	main(int ac, char **argv)
{
	t_data	*arg;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	argv++;
	if (ac > 1)
	{
		arg = malloc(sizeof(t_data));
		arg->argv = argv;
		arg->ac = ac;
		if (ac == 2)
			ft_arg_check(arg, argv);
		ft_value_check(arg);
		ft_stack_filling(&stack_a, arg);
		ft_find_index(&stack_a);
		if (ft_check_stack_sorted(&stack_a))
			ft_sort(&stack_a, &stack_b);
		ft_free(&stack_a, arg);
	}
	return (0);
}
