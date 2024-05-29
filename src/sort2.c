/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:14:55 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/23 13:25:49 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	final_sort(t_stack **a)
{
	t_stack	*first;
	t_stack	*tmp;
	int		len;

	len = stack_len(*a);
	put_position(*a);
	tmp = *a;
	first = tmp;
	while (tmp->next && tmp->index != 1)
		tmp = tmp->next;
	first = tmp;
	printf("--------------sort final.....................\n");
	printf("first value: %d pos: %d\n ---------------------------\n",first->value, first->pos);
	while (*a && (*a)->index != 1)
	{
		if (first->pos > (len / 2))
		{
				rotate(a);
				ft_printf("ra\n");
		}
		else 
		{
			rev_rotate(a);
			ft_printf("rra\n");
		}
	}
	printf("sale\n");
}
