/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:45:38 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/12 11:01:53 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		chars_p;
	va_list	ap;

	i = 0;
	chars_p = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (chars_p == -1)
			return (-1);
		else if (str[i] != '%')
		{
			ft_putchar(str[i], &chars_p);
			i++;
		}
		else
		{
			ft_print_format(str, ap, i, &chars_p);
			i += 2;
		}
	}
	va_end(ap);
	return (chars_p);
}
