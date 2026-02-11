/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 02:14:17 by miouali           #+#    #+#             */
/*   Updated: 2026/01/14 15:50:38 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}
/*
int	main()
{
	printf("%ld", ft_strlen("hello"));
}*/