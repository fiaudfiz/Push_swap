/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:48:28 by miouali           #+#    #+#             */
/*   Updated: 2026/02/23 11:21:27 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		cheapest->cost_a--;
		cheapest->cost_b--;
		rr(stack_a, stack_b);
	}
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		cheapest->cost_a++;
		cheapest->cost_b++;
		rrr(stack_a, stack_b);
	}
}

void	finish_rotation_stack_a(t_stack **stack_a, t_stack *cheapest)
{
	if (cheapest->cost_a > 0)
	{
		ra(stack_a);
		cheapest->cost_a--;
	}
	else
	{
		rra(stack_a);
		cheapest->cost_a++;
	}
}

void	finish_rotation_stack_b(t_stack **stack_b, t_stack *cheapest)
{
	if (cheapest->cost_b > 0)
	{
		rb(stack_b);
		cheapest->cost_b--;
	}
	else
	{
		rrb(stack_b);
		cheapest->cost_b++;
	}
}

void	finish_rotation(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (cheapest->cost_a != 0)
	{
		finish_rotation_stack_a(stack_a, cheapest);
	}
	while (cheapest->cost_b != 0)
	{
		finish_rotation_stack_b(stack_b, cheapest);
	}
}

int	find_cost(t_stack *temp_a)
{
	if (temp_a->cost_a > 0 && temp_a->cost_b > 0)
		return (max(temp_a->cost_a, temp_a->cost_b));
	else if (temp_a->cost_a < 0 && temp_a->cost_b < 0)
		return (max_abs(temp_a->cost_a, temp_a->cost_b));
	else
		return (abs(temp_a->cost_a) + abs(temp_a->cost_b));
}
