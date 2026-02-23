/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:02:09 by miouali           #+#    #+#             */
/*   Updated: 2026/02/23 17:18:14 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (0);
	i = parsing(av, &stack_a);
	if (i == -1)
		return (write(2, "ERROR\n", 6));
	init_index(&stack_a);
	line = get_next_line(0);
	while (line)
	{
		if (fetch_and_execute(line, &stack_a, &stack_b) == -1)
			return (write(2, "ERROR\n", 6));
		line = get_next_line(0);
	}
	get_next_line(-1);
	if (is_sorted(stack_a) == 0 || stack_size(stack_b) != 0)
    {
        ft_free_stack(&stack_a);
        ft_free_stack(&stack_b);
		return (write(1, "KO\n", 3));
    }
    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
	return (write(1, "OK\n", 3));
}
