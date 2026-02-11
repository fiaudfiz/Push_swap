/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:23:44 by miouali           #+#    #+#             */
/*   Updated: 2026/01/14 15:50:38 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_putchar_c(char c)
{
	write(1, &c, 1);
}

int	ft_format_c(va_list ap)
{
	int	c_int;

	c_int = va_arg(ap, int);
	ft_putchar_c((char)c_int);
	return (1);
}
