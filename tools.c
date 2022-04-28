/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:07:17 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/04/24 00:53:50 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	t_list *temp;

	temp = stack_a;
	while(temp != NULL)
	{
		min = get_min(stack_a);
		if(temp->content == min)
		{	
			push(&stack_a, &stack_b);	
			temp = stack_a;
			printf("head: %d\n", stack_a->content);
		}
		else
		{
			temp = temp->next;
			stack_a = stack_a->next;
		}
	}
	while (stack_b != NULL)
	{
		printf("b: %d\n", stack_b->content);
		stack_b = stack_b->next;
	}
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