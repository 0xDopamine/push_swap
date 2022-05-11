/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:07:17 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/11 18:38:58 by mbaioumy         ###   ########.fr       */
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
	min_index = 1;
	min = stack->content;
	while (stack != NULL)
	{
		if (stack->content < min)
		{	
			min = stack->content;
			min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_index);
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
	write (1, "S", 1);
	if (which == 'B')
		write (1, &which, 1);
	else
		write (1, &which, 1);
	write (1, "\n", 1);
}

void	mapping(t_list *stack_a, t_list *stack_b)
{
	int	min;
	int	i;
	int	max;

	max = get_max_index(stack_a);
	i = 1;
	min = get_min_index(stack_a);
	if (min < (ft_lstsize(stack_a) / 2))
		while (i++ < min)
			rotate(&stack_a, 'A');
	else
		while (min++ <= ft_lstsize(stack_a))
			reverse_rotate(&stack_a, 'A');
	push(&stack_a, &stack_b, 'A');
	if (ft_lstsize(stack_a) == 3)
	{
		sort_3(&stack_a);
		push(&stack_b, &stack_a, 'B');
		push(&stack_b, &stack_a, 'B');
		return ;
	}
	else
		mapping(stack_a, stack_b);
}

void    rotate(t_list **stack, char which)
{
	t_list  *temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
	write (1, "R", 1);
	if (which == 'B')
		write (1, &which, 1);
	else
		write (1, &which, 1);
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
	write (1, "RR", 2);
	if (which == 'B')
		write (1, &which, 1);
	else
		write (1, &which, 1);
	write (1, "\n", 1);
}

void    push(t_list **from, t_list **to, char which)
{
	t_list  *temp;

	temp = *from;
	*from = (*from)->next;
	temp->next = NULL;
	ft_lstadd_front(to, temp);
	write (1, "P", 1);
	if (which == 'B')
		write (1, &which, 1);
	else
		write (1, &which, 1);
	write (1, "\n", 1);
}