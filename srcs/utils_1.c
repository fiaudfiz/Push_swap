/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:12:59 by miouali           #+#    #+#             */
/*   Updated: 2026/02/21 15:13:21 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_stack(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*lst)->prev;
	last->next = new;
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
}

t_stack	*ft_lstnew_stack(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->index = -1;
	new->pos = -1;
	new->cheapest = 0;
	new->target_node = NULL;
	new->next = new;
	new->prev = new;
	return (new);
}

int	stack_size(t_stack *stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	if (!stack)
		return (0);
	temp = stack;
	while (1)
	{
		i++;
		temp = temp->next;
		if (temp == stack)
			break ;
	}
	return (i);
}

t_stack	*find_max_stack(t_stack *stack)
{
	t_stack	*temp;
	int		max;
	int		len;
	int		i;
	t_stack	*max_node;

	temp = stack;
	max = INT_MIN;
	len = stack_size(stack);
	i = 0;
	max_node = NULL;
	while (i < len)
	{
		if (temp->index > max)
		{
			max = temp->index;
			max_node = temp;
		}
		temp = temp->next;
		i++;
	}
	return (max_node);
}

t_stack	*find_min_stack(t_stack *stack)
{
	t_stack	*temp;
	int		min;
	int		len;
	int		i;
	t_stack	*min_node;

	temp = stack;
	min = INT_MAX;
	len = stack_size(stack);
	i = 0;
	while (i < len)
	{
		if (temp->index < min)
		{
			min = temp->index;
			min_node = temp;
		}
		temp = temp->next;
		i++;
	}
	return (min_node);
}
