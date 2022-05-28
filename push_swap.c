/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:45:06 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/28 20:04:22 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *stack_a, t_list *stack_b, int argc)
{
	if (!(issorted(copytoarray(stack_a), ft_lstsize(stack_a))))
	{
		if (argc)
		{
			if (argc == 6)
				sort_5(stack_a, stack_b);
			else if (argc == 5)
				sort_4(stack_a, stack_b);
			else if (argc == 4)
				sort_3(&stack_a);
			else if (argc > 6)
				big_sort(stack_a, stack_b);
			else if (argc == 2 || argc == 1)
				return ;
			else
				write (2, "Error\n", 6);
		}
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int		i;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_atoi_tester(argv[i])
			&& check_dups(argv, argc) && checker(argv[i]))
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		else
		{
			write (2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	push_swap(stack_a, stack_b, argc);
	return (0);
}
