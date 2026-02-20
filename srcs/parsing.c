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

#include "push_swap.h"
#include "../libft/includes/libft.h"

int check_double(t_stack *stack, int nb)
{
	t_stack *temp = stack;
	int	i = 0;
	int size_stack = stack_size(stack);

	if (!stack)
		return (0);
	while (i < size_stack)
	{
		if (temp->nbr == nb)
			return (-1);
		temp = temp->next;
		i++;
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
	new_node = ft_lstnew_stack(nb);
	if (!new_node)
		return (*error = 1, 0);
	ft_lstadd_back_stack(stack_a, new_node);
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
