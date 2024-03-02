/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:22:27 by ekose             #+#    #+#             */
/*   Updated: 2024/03/02 15:21:26 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_limit_check(t_data *arg)
{
	long	tmp;
	char	**argv;

	argv = arg->argv;
	while (*argv)
	{
		tmp = ft_atoi(*argv);
		if(tmp > 2147483647 || tmp < -2147483648)
			ft_free_argv(arg,"Error\n");
		argv++;
	}
}

void	ft_arg_check(t_data *arg, char **argv)
{
	if(ft_strchr(argv[0],' ') != 0)
			arg->argv = ft_split(argv[0],' ');
	else
	{
		free(arg);
		exit (0);
	}
}

void	ft_value_check(t_data *arg)
{
	int		i;
	int		j;
	char	**argv;

	i = -1;
	argv = arg->argv;
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
					ft_free_argv(arg, "Error\n");
			}
		}
	}
	ft_limit_check(arg);
}

void	ft_difference_check(t_stack **stack_a, t_data *arg)
{
	t_stack	*root;
	t_stack	*iter;
	long	tmp;

	root = *stack_a;
	while(root != NULL)
	{
		tmp = root->data;
		iter = root->next;
		while(iter != NULL)
		{
			if(tmp == iter->data)
				ft_full_free(stack_a, arg,"Error\n");
			iter = iter->next;
		}
		root = root->next;
	}
}
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
