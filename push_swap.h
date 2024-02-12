/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:31:07 by ekose             #+#    #+#             */
/*   Updated: 2024/02/11 15:20:16 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_data
{
	int		ac;
	char	**argv;

} t_data;

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
} t_stack;

void	ft_push_a(t_stack **stack_b, t_stack **stack_a);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b);

void	ft_swap_a(t_stack **stack_a);
void	ft_swap_b(t_stack **stack_b);
void	ft_swap_ss(t_stack **stack_a,t_stack **stack_b);

void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_rr(t_stack **stack_a, t_stack **stack_b);

void	ft_reverse_rotate_a(t_stack **stack_a);
void	ft_reverse_rotate_b(t_stack **stack_b);
void	ft_reverse_rotate_rr(t_stack **stack_a, t_stack **stack_b);

void	ft_limit_check(char **argv);
void	ft_error(char *s);
void	ft_free_argv(char **argv);
void	ft_arg_check(t_data *arg, char **argv);
void	ft_free(t_stack **stack_a, char *s);
void	ft_value_check(char **argv);
void	ft_stack_filling(t_stack **stack_a, char **argv);
void	ft_difference_check(t_stack **stack_a);
#endif
