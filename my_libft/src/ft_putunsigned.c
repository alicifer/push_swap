/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:23:35 by alicifer          #+#    #+#             */
/*   Updated: 2024/02/12 11:24:00 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putunsigned(unsigned int nbr, int *chars_p)
{
	char	*str;

	str = ft_unsign_itoa(nbr);
	ft_putstring(str, chars_p);
	free (str);
}
