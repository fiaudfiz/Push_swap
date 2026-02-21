/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:20:41 by miouali           #+#    #+#             */
/*   Updated: 2026/02/21 15:17:19 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/includes/libft.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	i = parsing (av, &stack_a);
	if (i == -1)
		return (write (2, "ERROR\n", 6));
	init_index(&stack_a);
	ft_display_stacks(stack_a, stack_b);
	if (!is_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(stack_a);
		else if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	ft_display_stacks(stack_a, stack_b);
	ft_free_all(&stack_a, NULL);
	ft_free_all(&stack_b, NULL);
	return (0);
}
