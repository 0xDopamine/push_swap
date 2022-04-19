/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:07:17 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/04/18 23:13:48 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    swap(t_list *stack)
{
    t_list  *temp;

    *temp = *stack;
    *stack = *stack->next;
    *stack->next = *temp;
}

void    rotate(t_list **stack)
{
    t_list  *temp;

    temp = *stack;
    *stack = (*stack)->next;
    temp->next = NULL;
    ft_lstadd_back(stack, temp);
}

void    reverse_rotate(t_list **stack)
{
    t_list  *temp;

    temp = ft_lstlast(*stack);
    *stack = (*stack)->next;
    (*stack)->next = NULL;
    ft_lstadd_front(stack, temp);
}

// void    reverse_reverse(t_list *stack_a, t_list *stack_b)
// {
//     int temp_a;
//     int temp_b;

    
// }