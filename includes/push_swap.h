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
