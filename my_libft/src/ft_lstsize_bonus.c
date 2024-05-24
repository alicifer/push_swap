/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:55:20 by alicifer          #+#    #+#             */
/*   Updated: 2023/10/17 12:28:32 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*aux;

	if (!lst)
		return (0);
	size = 1;
	aux = lst;
	while (aux->next)
	{
		aux = aux->next;
		size ++;
	}
	return (size);
}
