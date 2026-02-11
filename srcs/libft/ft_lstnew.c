/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:23:52 by miouali           #+#    #+#             */
/*   Updated: 2026/01/15 13:55:45 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


t_stack	*ft_lstnew(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> nbr = nbr;
	new -> index = -1;
	new -> next = NULL;
	return (new);
}
/*
int	main()
{
	int	i = 63;
	t_stack* result = ft_lstnew(&i);
	printf("%d", *(int*)result->content);
}
*/