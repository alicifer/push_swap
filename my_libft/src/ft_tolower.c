/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:20:41 by alicifer          #+#    #+#             */
/*   Updated: 2023/09/28 09:32:50 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
	{
		c = c + 32;
	}
	return (c);
}

//#include<stdio.h>
//int main()
//{
//	int c;
//
//	c =  'A';
//	printf("%d.\n", c);
//	printf("%d.\n", ft_tolower(c));
//	printf("%d.\n", tolower(c));
//	return (0);
//
//}
