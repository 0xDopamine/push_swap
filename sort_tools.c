/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:21:16 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/26 20:21:59 by mbaioumy         ###   ########.fr       */
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
	if (temp->next->content == data.min
		&& ft_lstlast(temp)->content == data.max)
		swap(*stack, 'a');
	else if (temp->content == data.max
		&& ft_lstlast(temp)->content == data.min)
	{
		swap(*stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else if (temp->content == data.max
		&& temp->next->content == data.min)
		rotate(stack, 'a');
	else if (temp->content == data.min
		&& temp->next->content == data.max)
	{
		swap(*stack, 'a');
		rotate(stack, 'a');
	}
	else if (temp->next->content == data.max
		&& ft_lstlast(temp)->content == data.min)
		reverse_rotate(stack, 'a');
}

void	sort_4(t_list *stack_a, t_list *stack_b)
{
	t_data	data;

	data.min = get_min_index(stack_a);
	data.size = ft_lstsize(stack_a);
	data.i = 1;
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
	if (!(issorted(copytoarray(stack_a), data.size)))
	{
		if (ft_lstsize(stack_a) == 3)
		{
			if (!(issorted(copytoarray(stack_a), data.size)))
				sort_3(&stack_a);
			push(&stack_b, &stack_a, 'a');
			return ;
		}
	}
	else
		push(&stack_b, &stack_a, 'a');
	return ;
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
	if (!(issorted(copytoarray(stack_a), data.size)))
	{
		if (ft_lstsize(stack_a) == 4)
		{
			if (!(issorted(copytoarray(stack_a), data.size)))
				sort_4(stack_a, stack_b);
			push(&stack_b, &stack_a, 'a');
			return ;
		}
	}
	else
		push(&stack_b, &stack_a, 'a');
}

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
	while (++data.i < data.max_bits)
	{
		data.j = -1;
		data.size_a = ft_lstsize(new_stack_a);
		while (++data.j < data.size_a)
		{
			data.num_a = new_stack_a->content;
			if ((data.num_a >> data.i) & 1)
				rotate(&new_stack_a, 'a');
			else
				push(&new_stack_a, &stack_b, 'b');
			//data.j++;
			//box_1(new_stack_a, stack_b, data);
		}
		data.j = 0;
		data.size_b = ft_lstsize(stack_b);
		while (data.j < data.size_b
			/*&& (!issorted(copytoarray(new_stack_a), data.size_a))*/)
		{
			if ((stack_b != NULL
					&& (!issorted(copytoarray(new_stack_a), data.size_a))))
			{
				data.num_b = stack_b->content;
				if ((data.num_b >> (data.i + 1)) & 1)
					push(&stack_b, &new_stack_a, 'a');
				else
					rotate (&stack_b, 'b');
			}
			else
				break ;
			data.j++;
		}
		if ((issorted_rev(copytoarray(stack_b), data.size_b))
			&& (issorted(copytoarray(new_stack_a), data.size_a)))
			break ;
	}
	while (stack_b)
		push(&stack_b, &new_stack_a, 'a');
}
