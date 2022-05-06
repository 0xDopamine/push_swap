/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:07:17 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/06 18:55:56 by mbaioumy         ###   ########.fr       */
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
	int	max;
	int	min;
	int	i;
	t_list	*tmp;

	i = 1;
	//tmp = NULL;
	max = get_max_index(stack_a);
	min = get_min_index(stack_a);
	printf("max: %d\nmin: %d\n", get_max_index(stack_a), get_min_index(stack_a));
	while (stack_a != NULL)
	{
		// printf("current node: %d\n", stack_a->content);
		// printf("before push %d\n", i);
		printf("a: \n");
		print_list(stack_a);
		printf("---------------\n");
		// printf("b: \n");
		// //print_list(stack_b);
		// printf("---------------\n");
		if (i == get_max_index(stack_a))
			push(&stack_a, &stack_b);
		else if (i == get_min_index(stack_a))
			push(&stack_a, &stack_b);
		//printf("b size: %d in: %d\n", ft_lstsize(stack_a), i);
		// printf("after push %d\n", i);
		// print_list(stack_a);
		// printf("---------------\n");
		// printf("b: \n");
		// printf("---------------\n");
		//ft_lstadd_back(&stack_a, tmp);
		if (ft_lstsize(stack_b) == 2)
			break ;
		stack_a = stack_a->next;
		i++;
		//print_list(tmp);
	}
	print_list(stack_a);
	printf("---------------\n");
	sort_3(&stack_a);
	push(&stack_b, &stack_a);
	push(&stack_b, &stack_a);
	rotate(&stack_a);
	print_list(stack_a);
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