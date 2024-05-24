/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:00:56 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/13 10:57:42 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_format(const char *str, va_list ap, int i, int *chars_p)
{
	if (str[i + 1] == 'c')
		ft_putchar(va_arg(ap, int), chars_p);
	else if (str[i + 1] == 's')
		ft_putstring(va_arg(ap, char *), chars_p);
	else if (str[i + 1] == 'p')
		ft_pointer((va_arg(ap, void *)), chars_p);
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_putnumber(va_arg(ap, int), chars_p);
	else if (str[i + 1] == 'u')
		ft_putunsigned(va_arg(ap, unsigned int), chars_p);
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
		ft_puthexa(va_arg(ap, unsigned int), chars_p, str[i + 1]);
	else if (str[i +1] == '%')
	{
		ft_putchar('%', chars_p);
	}
}
