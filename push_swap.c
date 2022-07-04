/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:45:06 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/12 22:53:52 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list *stack_a)
{
	if (stack_a->content > stack_a->next->content)
		swap(stack_a, 'a');
	else
		return ;
}

void	push_swap(t_list *stack_a, t_list *stack_b, int argc, t_data data)
{
	int		*arr;

	arr = copytoarray(stack_a);
	if (!(issorted(arr, ft_lstsize(stack_a))))
	{
		if (argc)
		{
			if (argc == 6)
				sort_5(stack_a, stack_b);
			else if (argc == 5)
				sort_4(stack_a, stack_b);
			else if (argc == 4)
				sort_3(&stack_a, data);
			else if (argc > 6)
				big_sort(stack_a, stack_b);
			else if (argc == 2 || argc == 1)
				return ;
			else if (argc == 3)
				sort_2(stack_a);
			else
				write(2, "Error\n", 6);
		}
	}
	free(arr);
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int		i;
	t_list	*stack_b;
	t_data	data;

	stack_b = NULL;
	stack_a = NULL;
	i = 0;
	while (++i < argc)
	{
		if (ft_atoi_tester(argv[i])
			&& check_dups(argv, argc) && checker(argv[i]))
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		else
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	if (stack_a == NULL)
		return (0);
	data.min = get_min(stack_a);
	data.max = get_max(stack_a);
	push_swap(stack_a, stack_b, argc, data);
	return (0);
}
