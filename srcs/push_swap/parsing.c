/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:41:01 by miouali           #+#    #+#             */
/*   Updated: 2026/01/16 13:44:09 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int check_double(t_stack *stack, int nb)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack ->nbr == nb)
			return (-1);
		stack = stack -> next;
	}
	return (0);
}

char **join_and_split(char** av)
{
	char	*tmp;
	char	**dest;

	tmp = ft_strbigjoin(av);
	if (!tmp)
		return (NULL);
	dest = ft_split (tmp, 32);
	free (tmp);
	if (!dest)
		return (NULL);
	return (dest);
}

int	ft_check_and_add(t_stack **stack_a, long nb, int* error)
{
	t_stack	*new_node;

	if (check_double(*stack_a, nb) == -1)
		return (*error = 1, 0);
	new_node = ft_lstnew(nb);
	if (!new_node)
		return (*error = 1, 0);
	ft_lstadd_back(stack_a, new_node);
	return (0);
}

int parsing(char **av, t_stack **stack_a)
{
	char	**dest;
	int 	i;
	int 	error;
	long		nb;
	
	error = 0; 
	i = 0;
	dest = join_and_split(av);
	if (!dest)
	{
		ft_free_all(stack_a, dest);
		return (-1);
	}
	while (dest[i])
	{
		nb = ft_atoll(dest[i], &error);
		if (error == 1)
		{
			ft_free_all(stack_a, dest);
			return (-1);
		}
		ft_check_and_add(stack_a, nb, &error);
		if (error == 1)
		{
			ft_free_all(stack_a, dest);
			return (-1);
		}
		i++;
	}
	return (0);
}
