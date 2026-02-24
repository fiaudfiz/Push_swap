/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:23:12 by miouali           #+#    #+#             */
/*   Updated: 2026/02/24 11:49:42 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/includes/libft.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;
	int		len;

	if (!stack || !*stack)
		return ;
	len = stack_size(*stack);
	current = *stack;
	while (len > 0)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		len--;
	}
	*stack = NULL;
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_all(t_stack **stack, char **tab)
{
	if (tab)
		ft_free_tab(tab);
	if (stack && *stack)
		ft_free_stack(stack);
}

void	free_stacks(t_stack **a, t_stack **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
}
