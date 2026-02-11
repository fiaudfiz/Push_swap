/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:13:27 by miouali           #+#    #+#             */
/*   Updated: 2026/01/16 13:32:17 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stddef.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <string.h>
# include <strings.h>
# include <limits.h>
# include <stdarg.h>

typedef struct	s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//libft


int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_lstsize(t_stack *lst);
int    ft_putnbr_base(int n, char* base);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);

char	**ft_split(char const *s, char c);

void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
void	ft_putchar_fd(char c, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putendl_fd(char *str, int fd);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *b, int c, size_t len);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

t_stack	*ft_lstnew(int nbr);
t_stack	*ft_lstlast(t_stack *lst);

//gnl

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *src);
int		ft_strchr_gnl(char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

//printf

int					ft_size_base(long long int n, int len_base);
int					ft_format_d(va_list ap);
int					ft_format_s(va_list ap);
int					ft_format_u(va_list ap);
int					ft_format_big_x(va_list ap);
int					ft_format_x(va_list ap);
int					ft_format_c(va_list ap);
int					ft_format_percent(va_list ap);
int					ft_printf(const char *prototype, ...);
int					ft_format_p(va_list ap);
int					ft_format_i(va_list ap);

typedef int				(*t_format)(va_list);

typedef struct format_stuct
{
	char		letter;
	t_format	format_alias;
}	t_alias;
/*40: Definition of a structure using typedef.
42: We will need it for comparison.
43: Alias used to call a function.
44: Complete structure alias.*/
extern const t_alias	g_format_tab[];

//push_swap

int parsing(char **av, t_stack **stack_a);
char	*ft_strbigjoin(char **str_tab);
int		ft_atoll(const char *str, int *error);
void ft_free_stack(t_stack **stack);
void ft_free_tab(char **tab);
void ft_free_all(t_stack **stack, char **tab);
void    sa(t_stack *stack);
void    sb(t_stack *stack);
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_b, t_stack **stack_a);
void    ra(t_stack  **stack_a);
void    rb(t_stack  **stack_b);
void    rra(t_stack  **stack_a);
void    rrb(t_stack  **stack_b);
void push(t_stack **src, t_stack **dest);
void    swap(t_stack *src);
void rotate(t_stack **src);
void reverse_rotate(t_stack **src);
void    ft_display_stacks(t_stack *stack_a, t_stack *stack_b);

#endif
