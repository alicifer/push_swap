/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:21:37 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/08 10:36:50 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar(char c, int *chars_p)
{
	if (write(1, &c, 1) == -1)
		*chars_p = -2;
	(*chars_p)++;
}

void	ft_putstring(char *str, int *chars_p)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i], chars_p);
		i++;
	}
}
