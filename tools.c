/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:07:17 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/25 18:43:30 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_list *stack)
{
	int	min;
	int	min_index;
	int	i;

	i = 1;
	min_index = i;
	min = stack->content;
	while (stack != NULL)
	{
		if (stack->content < min)
		{	
			min = stack->content;
			min_index = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_index);
}

int	get_max_index(t_list *stack)
{
	int	max;
	int	max_index;
	int	i;

	i = 1;
	max_index = 1;
	max = stack->content;
	while (stack != NULL)
	{
		if (stack->content > max)
		{	
			max = stack->content;
			max_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (max_index);
}

int	get_min(t_list *stack)
{
	int	min;

	min = stack->content;
	while (stack != NULL)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	get_max(t_list *stack)
{
	int	max;

	max = stack->content;
	while (stack != NULL)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}
