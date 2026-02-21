/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:48:28 by miouali           #+#    #+#             */
/*   Updated: 2026/02/21 14:52:03 by miouali          ###   ########.fr       */
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

void	finish_rotation(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (cheapest->cost_a != 0)
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
	while (cheapest->cost_b != 0)
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
}
