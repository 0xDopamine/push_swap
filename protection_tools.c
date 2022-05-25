/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:24:23 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/24 20:56:20 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	calres_tester(const char *str, int i, int sign)
{
	long		temp;
	long		res;

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

int	ft_atoi_tester(const char *str)
{
	int		i;
	long	res;
	int		sign;
	long	temp;

	sign = 1;
	res = 0;
	i = 0;
	temp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = calres_tester(str, i, sign);
	if (res > 2147483647 || res < -2147483648)
		return (0);
	return (1);
}

int	check_dups(char **stack, int argc)
{
	int		temp;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		temp = ft_atoi(&stack[i][0]);
		while (j < argc)
		{
			if (ft_atoi(&stack[j][0]) == temp)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	checker(char *str)
{
	int	i;

	i = -1;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
