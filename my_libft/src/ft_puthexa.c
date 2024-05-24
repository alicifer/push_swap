/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:05:15 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/13 10:58:21 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_puthexa(unsigned int hex, int *chars_p, char c)
{
	int				i;
	char			*str;

	if (hex == 0)
	{
		ft_putchar('0', chars_p);
		return ;
	}
	str = ft_hexa_to_str((unsigned long)hex);
	i = ft_strlen(str);
	while (i--)
	{
		if (c == 'x')
			ft_putchar(str[i], chars_p);
		else
			ft_putchar(ft_toupper(str[i]), chars_p);
	}
	free (str);
}
