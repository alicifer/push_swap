/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:36:47 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/18 12:51:29 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief returns a pointer to the tail of a list.
 * @param stack pinter to the stack
 * @return t_stack* 
 */
t_stack	*get_tail(t_stack *stack)
{	
	t_stack	*temp;

	temp = stack;
	if(!stack)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

/**
 * @brief The 1º element is sent to the bottom.
 * @param stack 
 * @return * void 
 */
void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;

	if(!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	tail = get_tail(*stack);
	*stack = (*stack)->next;
	temp->next = NULL;
	tail->next = temp;
}

void	move_ra(t_stack **a, t_stack *target)
{
	while (target->cost > 0 )
	{
		rotate(a);
		ft_printf("ra\n");
		target->cost--;
	}
}

void	move_rb(t_stack **b, t_stack *low_cost)
{
	while (low_cost->cost > 0)
	{
		rotate(b);
		ft_printf("rb\n");
		low_cost->cost--;
	}
}

void	move_rr(t_stack **a, t_stack **b, t_stack *target, t_stack *low_cost)
{
	while (target->cost > 0 && low_cost->cost > 0)	
	{
		rotate(a);
		rotate(b);
		ft_printf("rr\n");
		target->cost--;
		low_cost->cost--;
	}
}