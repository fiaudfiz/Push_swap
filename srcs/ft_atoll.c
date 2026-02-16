/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:25:49 by miouali           #+#    #+#             */
/*   Updated: 2026/01/15 13:10:29 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "../libft/includes/libft.h"

int	ft_atoll(const char *str, int *error)
{
	int				i;
	long long int	r;
	int				sign;

	sign = 1;
	i = 0;
	r = 0;
	if (str[i] == '-' || str[i] == '+')
    {
    	if (str[i++] == '-')
        	sign = -1;
    }
	if (!str[i])
		return (*error = 1, 0);
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			r = r * 10 + (str[i] - '0');
			if (r * sign > 2147483647 || r * sign < -2147483648)
            	return (*error = 1, 0);
			i++;
		}
		else
			return (*error = 1, 0);
	}
	return (r * sign);
}
