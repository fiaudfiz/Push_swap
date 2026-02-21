/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:12:53 by miouali           #+#    #+#             */
/*   Updated: 2026/02/21 14:48:00 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack *stack)
{
	int		i;
	int		mid;
	int		size;
	t_stack	*tmp;

	if (!stack)
		return ;
	size = stack_size(stack);
	i = 0;
	mid = (size - 1) / 2;
	tmp = stack;
	while (i < size)
	{
		tmp->pos = i;
		if (i <= mid)
			tmp->above_median = 1;
		else
			tmp->above_median = 0;
		tmp = tmp->next;
		i++;
	}
}

void	set_target_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	long	size_stack_a;
	long	size_stack_b;
	long	i;
	long	j;
	t_stack	*temp_a;
	t_stack	*temp_b;
	long	best_match_index;
	t_stack	*target_node;

	i = 0;
	j = 0;
	size_stack_a = stack_size(stack_a);
	size_stack_b = stack_size(stack_b);
	temp_a = stack_a;
	temp_b = stack_b;
	best_match_index = LONG_MIN;
	while (i < size_stack_a)
	{
		j = 0;
		temp_b = stack_b;
		best_match_index = LONG_MIN;
		while (j < size_stack_b)
		{
			if (temp_b->index < temp_a->index
				&& temp_b->index > best_match_index)
			{
				target_node = temp_b;
				best_match_index = temp_b->index;
			}
			j++;
			temp_b = temp_b -> next;
		}
		if (best_match_index == LONG_MIN)
			temp_a->target_node = find_max_stack(stack_b);
		else
			temp_a->target_node = target_node;
		i++;
		temp_a = temp_a->next;
	}
}

void	set_cost(t_stack *stack_a, t_stack *stack_b)
{
	int		size_stack_a;
	int		size_stack_b;
	int		i;
	t_stack	*temp_a;

	temp_a = stack_a;
	i = 0;
	size_stack_b = stack_size(stack_a);
	size_stack_b = stack_size(stack_b);
	while (i < size_stack_a)
	{
		if (temp_a->above_median  == 1)
			temp_a->cost_a = temp_a->pos;
		else
			temp_a->cost_a = -(size_stack_a - temp_a->pos);
		if (temp_a->target_node->above_median == 1)
			temp_a->cost_b = temp_a->target_node->pos;
		else
			temp_a->cost_b = -(size_stack_b - temp_a->target_node->pos);
		temp_a = temp_a->next;
		i++;
	}
}

void	set_cheapest(t_stack *stack_a)
{
	int		size_stack_a;
	int		i;
	int		lowest_cost;
	t_stack	*temp_a;
	int		current_cost;
	t_stack	*best_node;

	size_stack = stack_size(stack_a);
	i = 0;
	lowest_cost = 0;
	best_node = NULL;
	if (!stack_a)
		return ;
	lowest_cost = INT_MAX;
	temp_a = stack_a;
	while (i < size_stack_a)
	{
		temp_a->cheapest = 0;
		if (temp_a->cost_a > 0 && temp_a->cost_b > 0)
			current_cost = max(temp_a->cost_a, temp_a->cost_b);
		else if (temp_a->cost_a < 0 && temp_a->cost_b < 0)
			current_cost = max_abs(temp_a->cost_a, temp_a->cost_b);
		else
			current_cost = abs(temp_a->cost_a) + abs(temp_a->cost_b);
		if (current_cost < lowest_cost)
		{
			lowest_cost = current_cost;
			best_node = temp_a;
		}
		temp_a = temp_a->next;
		i++;
	}
	best_node->cheapest = 1;
}
