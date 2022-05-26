/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:07:28 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/26 20:12:04 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	box_1(t_list *stack_a, t_list *stack_b, t_data data)
{
	data.num_a = stack_a->content;
	if ((data.num_a >> data.i) & 1)
		rotate(&stack_a, 'a');
	else
		push(&stack_a, &stack_b, 'b');
}

void	box_0(t_list *stack_a, t_list *stack_b, t_data data)
{
	if ((stack_b != NULL
			&& (!issorted(copytoarray(stack_a), data.size_a))))
	{
		data.num_b = stack_b->content;
		if ((data.num_b >> (data.i + 1)) & 1)
			push(&stack_b, &stack_a, 'a');
		else if (((data.num_b >> (data.i + 1)) & 1) == 0)
			rotate (&stack_b, 'b');
	}
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
			if (data.arr[data.i] == temp[data.j]
				/*&& data.j != data.arr[data.i] && data.i != temp[data.j]*/)
			{
				data.arr[data.i] = data.j;
				break ;
			}
			data.j++;
		}
		data.i++;
	}
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
	return (connecting(data));
}
