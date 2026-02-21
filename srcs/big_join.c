/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:11:37 by miouali           #+#    #+#             */
/*   Updated: 2026/02/21 14:11:38 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/includes/libft.h"

int checker(char *str)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != 32 && str[i] != 43 && str[i] != 45)
		{
			return (-1);
		}
		if (str[i] >=48 && str[i] <= 57)
			count++;
		i++;
	}
	if(count > 0)
		return (0);
	return (-1);
}

char	*ft_strbigjoin(char **str_tab)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 1;
	j = 0;
	k = 0;
	while (str_tab[i])
	{
		if (checker(str_tab[i]) == -1)
			return (NULL);
		k = k + ft_strlen (str_tab[i]);
		i++;
	}
	dest = malloc(sizeof(char) * k + i);
	if (!dest)
		return (NULL);
	i = 1;
	while (str_tab[i])
	{
		k = 0;
		while(str_tab[i][k])
		{
			dest[j++] = str_tab[i][k++];
		}
		dest[j++] = ' ';
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

