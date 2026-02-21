/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:20:41 by miouali           #+#    #+#             */
/*   Updated: 2026/02/21 14:12:20 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/includes/libft.h"


int main(int ac, char **av)
{
	int	i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac <2 || (ac == 2 && !av[1][0]))
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	i = parsing (av, &stack_a);
	if (i == -1)
		return (write (2, "ERROR\n" , 6));
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

/*
	char	*dest;
	int		error = 0;
	char **tmp;
	int		i;
	long		nb;
	t_stack		*new_node;
	t_stack *stack_a;
	t_stack	*curr;

	i = 0;
	stack_a = NULL;
	nb  = 0;
	ft_printf ("ac = %d\n", ac);
	if (ac < 2)
		return (0);

	dest = ft_strbigjoin(av);
	if (!dest)
	{
		printf("ERROR ARGS");
		return (0);
	}
	printf("\ndest = %s", dest);
	tmp = ft_split (dest, 32);
	free (dest);
	while (tmp[i])
	{
		ft_printf("case %d = %s\n", i, tmp[i]);
		i++;
	}
	i = 0;
	while (tmp[i])
	{
		nb = ft_atoll(tmp[i], &error);
		if (error == 1)
		{
			ft_printf ("ERROR ARGS");
			ft_free_all(&stack_a, tmp);
			return (0);
		}
		if (check_double(stack_a, nb) == -1)
		{
			ft_printf ("Doublon Trouve");
			ft_free_all(&stack_a, tmp);
			return (0);
		}
		new_node = ft_lstnew(nb);
		if (!new_node)
		{
    		ft_free_all(&stack_a, tmp);
    		return (1);
		}
		ft_lstadd_back(&stack_a, new_node);
		ft_printf ("\narg %d OK\n", i);
		i++;
	}
	curr = stack_a;
	while (curr != NULL)
	{
		ft_printf ("%d\n", curr -> nbr);
		curr = curr -> next;
	}
	ft_free_tab(tmp);
	return (0);
}





int main()
{
	printf ("%d", ft_atoi("+1+-1233"));
}*/
