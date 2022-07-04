/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:38:21 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/12 23:43:20 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4_half(t_list *stack_a, t_list *stack_b, t_data data)
{
	if (!(issorted(copytoarray(stack_a), data.size)))
	{
		if (ft_lstsize(stack_a) == 3)
		{
			if (!(issorted(copytoarray(stack_a), data.size)))
				sort_3(&stack_a, data);
			push(&stack_b, &stack_a, 'a');
			return ;
		}
	}
	else
		push(&stack_b, &stack_a, 'a');
}

void	sort_5_half(t_list *stack_a, t_list *stack_b, t_data data)
{
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
