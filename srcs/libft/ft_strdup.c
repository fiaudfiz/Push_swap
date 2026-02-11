/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:28:25 by miouali           #+#    #+#             */
/*   Updated: 2026/01/14 15:50:38 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len;
	size_t	i;
	char	*temp;

	len = 0;
	i = 0;
	temp = (char *)s;
	while (temp[len])
		len++;
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = temp[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			printf("%s\n", ft_strdup(argv[i]));
			printf("%s\n", strdup(argv[i]));
			i++;
		}
	}
	return (0);
}*/
