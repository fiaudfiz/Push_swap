/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:34:25 by miouali           #+#    #+#             */
/*   Updated: 2026/01/14 15:50:38 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


char	*ft_strrchr(const char *s, int c)
{
	ssize_t			i;
	unsigned char	d;

	i = 0;
	d = (unsigned char)c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == d)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
/*
int	main()
{
	char *s = "hello la team";
	printf ("%s", ft_strrchr(s, 97));
}
*/