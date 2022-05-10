/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:45:06 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/10 21:59:01 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	calres(const char *str, int i, int sign)
{
	long	temp;
	long	res;

	temp = 0;
	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		temp = (temp * 10) + (str[i] - '0');
		if (temp < res && sign == -1)
			return (0);
		if (temp < res && sign == 1)
			return (-1);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (calres(str, i, sign));
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(int content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL && new == NULL)
		return ;
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	sort_3(t_list **stack)
{
	int		min;
	int		max;
	t_list	*temp;

	temp = *stack;
	min = get_min(*stack);
	max = get_max(*stack);
	if (temp->next->content == min && ft_lstlast(temp)->content == max)
		swap(*stack);
	else if (temp->content == max && ft_lstlast(temp)->content == min)
	{
		swap(*stack);
		reverse_rotate(stack);
	}
	else if (temp->content == max && temp->next->content == min)
		rotate(stack);
	else if (temp->content == min && temp->next->content == max)
	{
		swap(*stack);
		rotate(stack);
	}
	else if (temp->next->content == max && ft_lstlast(temp)->content == min)
		reverse_rotate(stack);
	else
		return ;
}

void	sort_5(t_list *stack_a, t_list *stack_b)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = stack_a;
	//printf("---------------\n");
	//print_list(tmp);
	while (tmp != NULL)
	{
		//printf("---------------\n");
		if (tmp->content == get_max(tmp))
		{
			push(&tmp, &stack_b);
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	//stack_a = tmp;
	//sort_3(&stack_a);
	//push(&stack_b, &stack_a);
	//push(&stack_b, &stack_a);
	//rotate(&stack_a);
}
void	print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", arr[i]);
		i++;
	}
}

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


void	simplify_nums(t_list *stack)
{
	int	lst_size;
	int	*arr;
	int	i;
	int	j;
	int	*temp;

	i = 0;
	lst_size = ft_lstsize(stack);
	arr = malloc(sizeof(int) * lst_size);
	temp = malloc(sizeof(int) * lst_size);
	while (stack)
	{
		arr[i] = stack->content;
		temp[i] = arr[i];
		i++;
		stack = stack->next;
	}
	bubble_sort(temp, lst_size);
	i = 0;
	while (i < lst_size)
	{
		j = 0;
		while (j < lst_size)
		{
			if (arr[i] == temp[j])
				arr[i] = j;
			j++;
		}
		i++;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	int		i;
	t_list	*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	//print_list(stack_a);
	//swap(stack_a);
	//reverse_rotate(&stack_a);
	//mapping(stack_a, stack_b);
	simplify_nums(stack_a);
	// while (stack_b != NULL)
	// {
	// 	printf("b: %d\n", stack_b->content);
	// 	stack_b = stack_b->next;
	// }
	//swap(stack_a);
	//printf("max: %d, min: %d\n", get_max(stack_a), get_min(stack_a));
	// printf("a: %d\n", stack_a->content);
    return (0);
}