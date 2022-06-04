/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:21:16 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/31 20:24:07 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort_3(t_list **stack)
{
	t_data	data;
	t_list	*temp;

	temp = *stack;
	data.min = get_min(*stack);
	data.max = get_max(*stack);
	data.first = temp->content;
	data.middle = temp->next->content;
	data.last = ft_lstlast(temp)->content;
	if (data.middle == data.min && data.last == data.max)
		swap(*stack, 'a');
	else if (data.first == data.max && data.last == data.min)
	{
		swap(*stack, 'a');
		reverse_rotate(stack, 'a');
		ft_lstclear(stack);
	}
	else if (data.first == data.max && data.middle == data.min)
	{
		rotate(stack, 'a');
		ft_lstclear(stack);
	}
	else if (data.first == data.min && data.middle == data.max)
	{
		swap(*stack, 'a');
		rotate(stack, 'a');
		ft_lstclear(stack);
	}
	else if (data.middle == data.max && data.last == data.min)
	{
		reverse_rotate(stack, 'a');
		ft_lstclear(stack);
	}
}

void	sort_4(t_list *stack_a, t_list *stack_b)
{
	t_data	data;

	data.min = get_min_index(stack_a);
	data.size = ft_lstsize(stack_a);
	data.i = 1;
	if (data.min > data.size / 2)
		while (data.min++ <= data.size)
			reverse_rotate(&stack_a, 'a');
	else
	{
		while (data.i++ < ft_lstsize(stack_a))
		{
			swap(stack_a, 'a');
			if (get_min_index(stack_a) == 1)
				break ;
		}
	}
	push(&stack_a, &stack_b, 'b');
	sort_4_half(stack_a, stack_b, data);
}

void	sort_5(t_list *stack_a, t_list *stack_b)
{
	t_data	data;

	data.i = 1;
	data.size = ft_lstsize(stack_a);
	data.min = get_min_index(stack_a);
	if (data.min > data.size / 2)
	{
		while (data.min++ <= data.size)
			reverse_rotate(&stack_a, 'a');
	}
	else
	{
		while (data.i++ < ft_lstsize(stack_a))
		{
			swap(stack_a, 'a');
			if (get_min_index(stack_a) == 1)
				break ;
		}
	}
	push(&stack_a, &stack_b, 'b');
	sort_5_half(stack_a, stack_b, data);
}
