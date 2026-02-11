/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:25:42 by miouali           #+#    #+#             */
/*   Updated: 2026/01/14 15:50:38 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*middle;

	middle = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if ((unsigned char *)src > (unsigned char *)dest)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = middle[i];
			i++;
		}
		return (dest);
	}
	while (n > 0)
	{
		((unsigned char *)dest)[n - 1] = middle[n - 1];
		n--;
	}
	return (dest);
}
/*
int	main()
{
	void* dest[8];
	void* src = "hello";
	printf("%s", (char *)ft_memmove(dest, src, 2));
}*/