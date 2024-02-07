/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:30:54 by ekose             #+#    #+#             */
/*   Updated: 2024/02/06 23:08:48 by ekose            ###   ########.fr       */
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
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*top;

	stack_b = NULL;
	top = NULL;
	if(ac == 1)
		return (0);
	ft_value_check(argv);
	stack_a = ft_stack_filling(stack_a,argv);
	top = stack_a;
	  while(top !=NULL)
     {
         printf("%d\n",top->data);
         top = top->next;
    }
	stack_b = ft_push(stack_b,stack_a);
	printf("%d\n",stack_a->data);
	ft_free(stack_a,"Bitti");

}
