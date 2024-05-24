/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:22:03 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/12 11:24:12 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnumber(int nbr, int *chars_p)
{
	char	*str;

	str = ft_itoa(nbr);
	ft_putstring(str, chars_p);
	free (str);
}
