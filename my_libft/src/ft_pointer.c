/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:59:02 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/12 11:07:00 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_pointer(void *pointer, int *chars_p)
{
	unsigned long	ulong_point;
	char			*str;
	int				i;

	ulong_point = (unsigned long)pointer;
	ft_putstring("0x", chars_p);
	if (ulong_point == 0)
	{
		ft_putchar('0', chars_p);
		return ;
	}
	str = ft_hexa_to_str(ulong_point);
	i = ft_strlen(str);
	while (i--)
		ft_putchar(str[i], chars_p);
	free (str);
}
