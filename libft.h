/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:43:32 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/05/08 16:22:21 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int arg);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str, const void *str2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
void			*ft_memset(void *str, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(char *src);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strnstr(const char *big, const char *small, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int ch);
int				ft_toupper(int ch);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(int content);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void	sort_5(t_list *stack_a, t_list *stack_b);
void			swap (t_list *stack, char which);
void			rotate(t_list **stack, char which);
void			reverse_rotate(t_list **stack, char which);
void			push(t_list **from, t_list **to, char which);
int		get_min(t_list *stack);
int		get_max(t_list *stack);
void	mapping(t_list *stack_a, t_list *stack_b);
int	ft_lstsize(t_list *lst);
void	sort_3(t_list **stack);
void	print_list(t_list *stack);
int		get_min_index(t_list *stack);
int		get_max_index(t_list *stack);
#endif