/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:12:05 by miouali           #+#    #+#             */
/*   Updated: 2026/02/21 14:12:06 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_stack **stack_a)
{
	int	i;
	int	j;
	int	k;
	int	count;
	t_stack	*check;

	k = 0;
	j = stack_size(*stack_a);
	i = 0;
	while (i < j)
	{
		count = 0;
		check = *stack_a;
		k = 0;
		while (k < j)
		{
			if (check->nbr < (*stack_a)->nbr)
				count++;
			check = check->next;
			k++;
		}
		(*stack_a)->index = count;
		*stack_a = (*stack_a)->next;
		i++;
	}
}
