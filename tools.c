/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:07:17 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/09 18:03:47 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_list(t_list *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = lst;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int		get_min_index(t_list *stack)
{
	int	min;
	int	min_index;
	int	i;

	i = 1;
	min_index = 1;
	min = stack->content;
	while (stack != NULL)
	{
		if (stack->content < min)
		{	
			min = stack->content;
			min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_index);
}

int		get_max_index(t_list *stack)
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

int		get_min(t_list *stack)
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

int		get_max(t_list *stack)
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

void    swap(t_list *stack)
{
	int temp;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	mapping(t_list *stack_a, t_list *stack_b)
{
	int	min;
	int	i;
	int	max;

	max = get_max_index(stack_a);
	i = 1;
	min = get_min_index(stack_a);
	if (min < ft_lstsize(stack_a) / 2)
		while (i++ < min)
			rotate(&stack_a);
	else
		while (min++ <= ft_lstsize(stack_a))
			reverse_rotate(&stack_a);
	push(&stack_a, &stack_b);
	if (ft_lstsize(stack_a) == 3)
	{
		sort_3(&stack_a);
		push(&stack_b, &stack_a);
		push(&stack_b, &stack_a);
		print_list(stack_a);
		return ;
	}
	else
		mapping(stack_a, stack_b);
}

void    rotate(t_list **stack)
{
	t_list  *temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
}

void    del(void *content)
{
	(void)(*content);
}

void    reverse_rotate(t_list **stack)
{
	t_list  *temp;
	t_list  *temp1;
	
	temp = *stack;
	temp1 = ft_lstlast(*stack);
	while (temp->next->next != NULL)
		temp = temp->next;
	temp1->next = *stack;
	*stack = temp1; 
	temp->next = NULL;
}

void    push(t_list **from, t_list **to)
{
	t_list  *temp;

	temp = *from;
	*from = (*from)->next;
	temp->next = NULL;
	ft_lstadd_front(to, temp);
	//ft_lstadd_front(from, temp);
	//to->next = NULL;
}