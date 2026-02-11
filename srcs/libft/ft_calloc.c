/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:24:02 by miouali           #+#    #+#             */
/*   Updated: 2026/01/14 15:50:38 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (size != 0 && nmemb > __SIZE_MAX__ / size)
		return (NULL);
	ptr = malloc(size * nmemb);
	i = 0;
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
int	main()
{
	char *test;
	int	i;
	int	j;
	char	*test1;

	i = 0;
	j = 0;
	test = (char *)ft_calloc(8,1);
	test1 = (char *)calloc(8,1);
	while (i < 8)
	{
		printf("%d", test[i++]);
	}
	printf ("\n");
	while (j < 8)
	{
		printf("%d", test1[j++]);
	}
	free (test);
	free (test1);
	return (0);
}*/