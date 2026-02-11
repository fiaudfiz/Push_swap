/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:18:31 by miouali           #+#    #+#             */
/*   Updated: 2026/01/14 15:50:38 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;
	size_t	lens;

	lens = 0;
	if (!s)
		return (NULL);
	while (s[lens])
		lens++;
	i = 0;
	if (start >= lens)
		len = 0;
	if (len > lens - start)
		len = lens - start;
	dest = ft_calloc(len + 1, 1);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
    printf("1: %s\n", ft_substr("hola", 2000, 18446744073709551615UL));
    printf("2: %s\n", ft_substr("hola", 4294, 18446));
    printf("3: %s\n", ft_substr("HelloWorld", 42, 5));
    //printf("4: %s\n", ft_substr("HelloWorld", 5, 99));
    //printf("5: %s\n", ft_substr("HelloWorld", 10, 10));
    printf("6: %s\n", ft_substr("HelloWorld", 2, 0));
    //printf("7: %s\n", ft_substr("", 0, 5));
    //printf("8: %s\n", ft_substr("ABC\0DEF", 0, 6));
    //printf("9: %s\n", ft_substr("ABC\0DEF", 2, 10));
    printf("10: %s\n", ft_substr("ABC\0DEF", 4, 3));

    return 0;
}
*/