/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:51:23 by miouali           #+#    #+#             */
/*   Updated: 2026/01/14 15:50:38 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	k = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	if (size <= i)
		return (size + j);
	else if (size > i)
	{
		while (i < (size - 1) && src[k])
		{
			dst[i] = src[k];
			k++;
			i++;
		}
	}
	dst[i] = '\0';
	return (i - k + j);
}
/*
int	main()
{
	char src[] = "hello";
	char dest[] = "world";
	printf("%ld", ft_strlcat(dest, src, 6));
}
*/