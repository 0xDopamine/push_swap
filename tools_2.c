/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:32:16 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/25 18:53:54 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calres(const char *str, int i, int sign)
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

int	*simplify_nums(t_list *stack)
{
	t_data	data;
	int		*temp;

	data.i = 0;
	data.size = ft_lstsize(stack);
	data.arr = malloc(sizeof(int) * data.size);
	temp = malloc(sizeof(int) * data.size);
	while (stack)
	{
		data.arr[data.i] = stack->content;
		temp[data.i] = data.arr[data.i];
		stack = stack->next;
		data.i++;
	}
	bubble_sort(temp, data.size);
	data.i = 0;
	while (data.i++ < data.size)
	{
		data.j = 0;
		while (data.j++ < data.size)
		{
			if (data.arr[data.i] == temp[data.j]
				&& data.j != data.arr[data.i] && data.i != temp[data.j])
			{
				data.arr[data.i] = data.j;
				break ;
			}
		}
	}
	return (data.arr);
}

int	issorted(int *arr, int size)
{
	t_data	data;
	int		temp;
	int		test;

	data.i = 0;
	test = 1;
	if (size < 3)
		return (0);
	while (data.i++ < size - 1)
	{
		data.j = 0;
		while (data.j++ < size - data.i - 1)
		{
			if (arr[data.j++] > data.arr[data.j + 1])
			{
				temp = data.arr[data.j];
				data.arr[data.j] = data.arr[data.j + 1];
				data.arr[data.j + 1] = temp;
				test = 0;
			}
		}
	}
	return (test);
}

int	issorted_rev(int *arr, int size)
{
	t_data	data;
	int		temp;
	int		test;

	data.i = 0;
	test = 1;
	if (size < 3)
		return (0);
	while (data.i++ < size - 1)
	{
		data.j = 0;
		while (data.j++ < size - data.i - 1)
		{
			if (arr[data.j] < arr[data.j + 1])
			{
				temp = arr[data.j];
				arr[data.j] = arr[data.j + 1];
				arr[data.j + 1] = temp;
				test = 0;
			}
		}
	}
	return (test);
}
