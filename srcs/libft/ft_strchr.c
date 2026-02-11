/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:12:30 by miouali           #+#    #+#             */
/*   Updated: 2026/01/14 15:50:38 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	d;

	i = 0;
	d = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == d)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (d == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main()
{
	printf ("%s", ft_strchr("hjfddfddg", 't' + 256));
}
*/
