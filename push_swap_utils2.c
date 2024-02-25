/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:18:53 by ekose             #+#    #+#             */
/*   Updated: 2024/02/25 17:52:01 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < size - 1; ++step) {
    int swapped = 0;

    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {

      // compare two array elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {

        // swapping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;

        swapped = 1;
      }
    }

    // no swapping means the array is already sorted
    // so no need for further comparison
    if (swapped == 0) {
      break;
    }

  }
}

int	ft_sum(t_stack **stack)
{
	int		sum;
	t_stack	*tmp;

	tmp = *stack;
	sum = 0;
	while(tmp != NULL)
	{
		sum += tmp->data;
		tmp = tmp->next;
	}
	return (sum);
}

int	ft_cp_stack(t_stack **stack)
{
	int		*arr;
	int		mid;
	int		size;
	t_stack	*tmp;

	arr = (int *) malloc(sizeof(int) * ft_stack_size(stack));
	if (arr == NULL)
		ft_error("Arr not allocated");
	size = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		arr[size] = tmp->data;
		tmp = tmp->next;
		size++;
	}
	bubbleSort(arr,size);
	int temp = 0;
	while(temp < size)
	{
		printf("arr=%d\n",arr[temp++]);
	}
	if (size % 2 == 0)
		mid = (arr[size / 2] + arr[(size / 2) -1]) / 2;
	else
		mid = arr[size / 2];
	free(arr);
	return (mid);
}

t_stack	*ft_find_end(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
