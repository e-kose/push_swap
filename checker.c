/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:22:27 by ekose             #+#    #+#             */
/*   Updated: 2024/02/18 15:15:22 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_limit_check(char **argv)
{
	long	tmp;
	while (*argv)
	{
		tmp = ft_atoi(*argv);
		if(tmp > 2147483647 || tmp < -2147483648)
			ft_error("Error\nInvalid value range\n");
		argv++;
	}

}
void	ft_arg_check(t_data *arg, char **argv)
{
	
	if(ft_strchr(argv[1],' ') != 0)
			arg->argv = ft_split(argv[1],' ');
	else
		exit(0);
}

void	ft_value_check(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while(argv[++i])
	{
		j = -1;
		while(argv[i][++j])
		{
			if(ft_isdigit(argv[i][j]) == 0)
			{
				if((argv[i][j + 1] != '\0' && j == 0) && (argv[i][j + 1] != '0')
					&& (argv[i][j] == '-' || argv[i][j] == '+'))
					continue;
				else
					ft_error("Error\nArg not integer\n");
			}
		}
	}
}

void	ft_difference_check(t_stack **stack_a)
{
	t_stack	*root;
	t_stack	*iter;
	long		tmp;

	root = *stack_a;
	while(root != NULL)
	{
		tmp = root->data;
		iter = root->next;
		while(iter != NULL)
		{
			if(tmp == iter->data)
				ft_free(stack_a, "Error\nSame values\n");
			iter = iter->next;
		}
		root = root->next;
	}
}
