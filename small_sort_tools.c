/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:38:21 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/31 20:22:13 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4_half(t_list *stack_a, t_list *stack_b, t_data data)
{
	int *arr;
	arr = copytoarray(stack_a);
	if (!(issorted(arr, data.size)))
	{
		if (ft_lstsize(stack_a) == 3)
		{
			if (!(issorted(arr, data.size)))
				sort_3(&stack_a);
			push(&stack_b, &stack_a, 'a');
			free(arr);
			// ft_lstclear(&stack_a);
			return ;
		}
	}
	else
		push(&stack_b, &stack_a, 'a');
	free(arr);
	// ft_lstclear(&stack_a);
}

void	sort_5_half(t_list *stack_a, t_list *stack_b, t_data data)
{
	int *arr;

	arr = copytoarray(stack_a);
	data.size = ft_lstsize(stack_a);
	if (!(issorted(arr, data.size)))
	{
		if (ft_lstsize(stack_a) == 4)
		{
			if (!(issorted(arr, data.size)))
				sort_4(stack_a, stack_b);
			push(&stack_b, &stack_a, 'a');
			//ft_lstclear(&stack_a);
			free(arr);
			return ;
		}
	}
	else
		push(&stack_b, &stack_a, 'a');
	free(arr);
	// ft_lstclear(&stack_a);
}
