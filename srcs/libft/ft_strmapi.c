/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:17:00 by miouali           #+#    #+#             */
/*   Updated: 2026/01/14 15:50:38 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
char map_transform(unsigned int index, char c)
{
    (void)index;
	if (c == ' ')
        return '-';
    if (c >= 'a' && c <= 'z')
        return c - 32;
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	dest = malloc (sizeof (char) * i + 1);
	if (!dest)
		return (NULL);
	while (j < i)
	{
		dest[j] = (*f)(j, s[j]);
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main()
{
	char s[] = "Hello World";
	printf("%s", ft_strmapi(s, map_transform));
}*/