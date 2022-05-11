/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:45:06 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/11 18:41:15 by mbaioumy         ###   ########.fr       */
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
		swap(*stack, 'A');
	else if (temp->content == max && ft_lstlast(temp)->content == min)
	{
		swap(*stack, 'A');
		reverse_rotate(stack, 'A');
	}
	else if (temp->content == max && temp->next->content == min)
		rotate(stack, 'A');
	else if (temp->content == min && temp->next->content == max)
	{
		swap(*stack, 'A');
		rotate(stack, 'A');
	}
	else if (temp->next->content == max && ft_lstlast(temp)->content == min)
		reverse_rotate(stack, 'A');
	else
		return ;
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

void	copytolist(int *arr, t_list *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		ft_lstadd_back(&stack, ft_lstnew(arr[i]));
		i++;
	}
}

int	*simplify_nums(t_list *stack)
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
	return(arr);
}

void	big_sort(t_list *stack_a, t_list *stack_b)
{
	int	size;
	int	max;
	int	max_bits;
	int	i;
	int	*arr;
	int	j;
	int	num;

	i = 0;
	arr = simplify_nums(stack_a);
	max_bits = 0;
	size = ft_lstsize(stack_a);
	max = size - 1;
	copytolist(arr, stack_a, size);
	while ((max >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = stack_a->content;
			if ((num >> i)&(1 == 1))
				rotate(&stack_a, 'A');
			else
				push(&stack_a, &stack_b, 'A');
			j++;
		}
		i++;
	}
	while (stack_b == NULL)
		push(&stack_b, &stack_a, 'B');
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
	char	**arg;

	stack_a = NULL;
	stack_b = NULL;
	arg = NULL;
	// printf("im here");
	// if (argc == 2)
	// {
	// 	i = 0;
	// 	while (*arg[i])
	// 	{
	// 		//ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(arg[i])));
	// 		i++;
	// 	}
	// }
	// else
	// {
		i = 1;
		while (i < argc)
		{
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
	//}
	if (argc == 6 || argc == 5)
		mapping(stack_a, stack_b);
	else if (argc == 4)
		sort_3(&stack_a);
	else if (argc > 6)
		big_sort(stack_a, stack_b);
	else
		write(2, "Error\n", 6);
    return (0);
}