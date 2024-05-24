/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:32:11 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/18 13:45:19 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a || !a)
		return ; // ver los casos de error y tratarlos. no debería hacer un push si no hay *a
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void	move_pa(t_stack **a, t_stack **b)
{
	move_push(b, a);
	printf("pa\n");
}

void	move_pb(t_stack **a, t_stack **b)
{
	move_push(a, b);
	printf("pb\n");
}