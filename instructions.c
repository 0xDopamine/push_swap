/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:18:35 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/24 20:54:06 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, char which)
{
	int	temp;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	if (which == 'b')
		write (1, "sb", 2);
	else
		write (1, "sa", 2);
	write (1, "\n", 1);
}

void	rotate(t_list **stack, char which)
{
	t_list	*temp;

	if (*stack == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
	if (which == 'b')
		write (1, "rb", 2);
	else
		write (1, "ra", 2);
	write (1, "\n", 1);
}

void	push(t_list **from, t_list **to, char which)
{
	t_list	*temp;

	if (*from == NULL)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = NULL;
	ft_lstadd_front(to, temp);
	if (which == 'b')
		write (1, "pb", 2);
	else
		write (1, "pa", 2);
	write (1, "\n", 1);
}

void	reverse_rotate(t_list **stack, char which)
{
	t_list	*temp;
	t_list	*temp1;

	temp = *stack;
	temp1 = ft_lstlast(*stack);
	while (temp->next->next != NULL)
		temp = temp->next;
	temp1->next = *stack;
	*stack = temp1;
	temp->next = NULL;
	if (which == 'b')
		write (1, "rrb", 3);
	else
		write (1, "rra", 3);
	write (1, "\n", 1);
}
