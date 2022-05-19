/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:07:17 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/19 22:22:01 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	len;
	void			*ptr;

	len = count * size;
	ptr = malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	freethis(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	wdlen(char **s, char c)
{
	int	i;

	i = 0;
	while (*s[i] && ft_strncmp((char *)&*s[i], &c, 1))
		i++;
	return (i);
}

int	wdcount(char **s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s[i])
	{
		if (*s[i] != c && (*s[i + 1] == c || *s[i + 1] == '\0'))
			count += 1;
		i++;
	}
	return (count);
}

char	**splitting(char **s, char c, int len, char **str)
{
	int		k;
	int		j;
	int		i;

	i = 0;
	j = -1;
	while (*s[i])
	{
		while (*s[i] && !ft_strncmp((char *)&*s[i], &c, 1))
			i++;
		if (!*s[i])
			break ;
		len = wdlen(s + i, c);
		str[++j] = (char *)ft_calloc(len + 1, sizeof(char));
		if (!str[j])
		{
			freethis(str);
			return (NULL);
		}
		k = -1;
		while (++k < len)
			str[j][k] = *s[i++];
	}
	return (str);
}

char	**ft_split(char **s, char c)
{
	char	**split;
	char	**str;

	if (!*s)
		return (NULL);
	str = (char **)ft_calloc((wdcount(s, c) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	split = splitting(s, c, 0, str);
	return (split);
}

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
	min_index = i;
	min = stack->content;
	while (stack != NULL)
	{
		if (stack->content < min)
		{	
			min = stack->content;
			min_index = i;
		}
		i++;
		stack = stack->next;
	}
	//printf("min index: %d\nmin value: %d\n", min_index, min);
	return (min_index);
}

int	*copytoarray(t_list *stack)
{
	int	size;
	int	i;
	int	*arr;

	i = 0;
	size = ft_lstsize(stack);
	arr = (int *)malloc(sizeof(int) * size);
	while (stack)
	{
		arr[i] = stack->content;
		i++;
		stack = stack->next;
	}
	return (arr);
}

int		issorted(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;
	int	test;

	i = 0;
	test = 1;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				test = 0;
			}
			j++;
		}
		i++;
	}
	return (test);
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

void    swap(t_list *stack, char which)
{
	int temp;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	if (which == 'b')
		write (1, "sb", 2);
	else
		write (1, "sa", 2);
	write (1, "\n", 1);
}

int	check_dups(char *argv)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		temp = argv[i];
		while (argv[j])
		{
			if (temp == argv[j])
				return (0);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	checker(char *argv)
{
	int	i;
	
	i = 0;
	while (argv[i])
	{
		if (argv[i] >= 48 && argv[i] <= 57)
			return (1);
		i++;
	}
	return (0);
}

void	sort_4(t_list *stack_a, t_list *stack_b)
{
	int	min;
	int	i;
	int	size;

	min = get_min_index(stack_a);
	size = ft_lstsize(stack_a);
	i = 1;
	if (min > size / 2)
	{
		while (min++ <= size)
			reverse_rotate(&stack_a, 'a');
	}
	else
		while (i++ < ft_lstsize(stack_a))
		{
			swap(stack_a, 'a');
			if (get_min_index(stack_a) == 1)
				break ;
		}
	push(&stack_a, &stack_b, 'b');
	if (ft_lstsize(stack_a) == 3)
	{
		sort_3(&stack_a);
		push(&stack_b, &stack_a, 'a');
		push(&stack_b, &stack_a, 'a');
		//print_list(stack_a);
		return ;
	}
	else
		sort_5(stack_a, stack_b);
}

void	sort_5(t_list *stack_a, t_list *stack_b)
{
	int	min;
	int	i;
	int	size;

	//stack_b = NULL;
	i = 1;
	size = ft_lstsize(stack_a);
	min = get_min_index(stack_a);
	if (min > size / 2)
	{
		while (min++ <= size)
			reverse_rotate(&stack_a, 'a');
	}
	else
		while (i++ < ft_lstsize(stack_a))
		{
			swap(stack_a, 'a');
			if (get_min_index(stack_a) == 1)
				break ;
		}
	push(&stack_a, &stack_b, 'b');
	if (ft_lstsize(stack_a) == 4)
	{
		sort_4(stack_a, stack_b);
		return ;
	}
	else
		sort_5(stack_a, stack_b);
}

void    rotate(t_list **stack, char which)
{
	t_list  *temp;

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

void    reverse_rotate(t_list **stack, char which)
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
	if (which == 'b')
		write (1, "rrb", 3);
	else
		write (1, "rra", 3);
	write (1, "\n", 1);
}

void    push(t_list **from, t_list **to, char which)
{
	t_list  *temp;

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