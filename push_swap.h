/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:31:07 by ekose             #+#    #+#             */
/*   Updated: 2024/02/06 20:23:06 by ekose            ###   ########.fr       */
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
	long				data;
	struct s_stack	*next;
} t_stack;


void	ft_error(char *s);
void	ft_free(t_stack *stack_a, char *s);
void	ft_value_check(char **argv);
t_stack	*ft_stack_filling(t_stack *stack_a, char **argv);
void	ft_difference_check(t_stack *stack_a);
t_stack	*ft_swap(t_stack *stack);
t_stack *ft_push(t_stack *stack_d, t_stack *stack_s);
#endif
