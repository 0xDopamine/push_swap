/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:07:28 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/04 17:41:13 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_list *stack_a, t_list *stack_b)
{
	t_data	data;
	t_list	*new_stack_a;

	data.i = -1;
	data.size_a = 0;
	data.size_b = 0;
	data.arr = simplify_nums(stack_a);
	data.max_bits = 0;
	new_stack_a = NULL;
	data.max = ft_lstsize(stack_a) - 1;
	new_stack_a = copytolist(data.arr, ft_lstsize(stack_a));
	while ((data.max >> data.max_bits) != 0)
		data.max_bits++;
	free(data.arr);
	ft_lstclear(&stack_a);
	radix(data, new_stack_a, stack_b);
}

void	radix(t_data data, t_list *stack_a, t_list *stack_b)
{
	while (++data.i < data.max_bits)
	{
		data.j = -1;
		data.size_a = ft_lstsize(stack_a);
		while (++data.j < data.size_a)
		{
			data.num_a = stack_a->content;
			if ((data.num_a >> data.i) & 1)
				rotate(&stack_a, 'a');
			else
				push(&stack_a, &stack_b, 'b');
		}
		data.j = -1;
		data.size_b = ft_lstsize(stack_b);
		while (++data.j < data.size_b && stack_b)
		{
			data.num_b = stack_b->content;
			if ((data.num_b >> (data.i + 1)) & 1)
				push(&stack_b, &stack_a, 'a');
			else
				rotate (&stack_b, 'b');
		}
	}
	while (stack_b)
		push(&stack_b, &stack_a, 'a');
	ft_lstclear(&stack_a);
}

int	*connecting(t_data data)
{
	int		*temp;

	temp = malloc(sizeof(int) * data.size);
	data.i = 0;
	while (data.i < data.size)
	{
		data.j = 0;
		while (data.j < data.size)
		{
			if (data.arr[data.i] == temp[data.j])
			{
				data.arr[data.i] = data.j;
				break ;
			}
			data.j++;
		}
		data.i++;
	}
	free(temp);
	return (data.arr);
}

int	*simplify_nums(t_list *stack)
{
	t_data	data;
	int		*temp;

	data.size = ft_lstsize(stack);
	temp = malloc(sizeof(int) * data.size);
	data.i = 0;
	data.arr = malloc(sizeof(int) * data.size);
	while (stack)
	{
		data.arr[data.i] = stack->content;
		temp[data.i] = data.arr[data.i];
		stack = stack->next;
		data.i++;
	}
	bubble_sort(temp, data.size);
	free(temp);
	return (connecting(data));
}
