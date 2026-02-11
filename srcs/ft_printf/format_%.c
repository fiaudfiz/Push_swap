/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_%.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miouali <miouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:19:03 by miouali           #+#    #+#             */
/*   Updated: 2026/01/14 15:50:38 by miouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_putchar_percent(char c)
{
	return (write (1, &c, 1));
}

int	ft_format_percent(va_list ap)
{
	(void)ap;
	return (ft_putchar_percent('%'));
}
