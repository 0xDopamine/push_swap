/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:32:16 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/28 18:16:54 by mbaioumy         ###   ########.fr       */
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

int	issorted(int *arr, int size)
{
	t_data	data;
	int		temp;
	int		test;

	data.i = -1;
	test = 1;
	if (size < 3)
		return (0);
	while (++data.i < size - 1)
	{
		data.j = -1;
		while (++data.j < size - data.i - 1)
		{
			if (arr[data.j] > arr[data.j + 1])
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
