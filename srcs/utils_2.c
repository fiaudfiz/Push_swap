/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:13:08 by miouali           #+#    #+#             */
/*   Updated: 2026/02/21 14:17:16 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int max_abs(int a, int b)
{
	if (abs(a) > abs(b))
		return (abs(a));
	return (abs(b));
}

int	is_sorted(t_stack *stack)
{
	t_stack *temp = stack;
	int	size_stack = stack_size(stack);

	while (--size_stack > 0)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return(1);
}