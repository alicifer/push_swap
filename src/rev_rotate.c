/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:50:55 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/18 13:19:06 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief returns a pointer to the node before the tail of a list.
 * @param stack pinter to the stack
 * @return t_stack* 
 */
t_stack	*get_node_before_tail(t_stack *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}
/**
 * @brief Rotates the stack downwards, moving the last element to the beginning.
 * 
 * @param stack Pointer to the pointer to the stack
 */
void	rev_rotate(t_stack **stack)
{
	t_stack *temp;
	t_stack *newtail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = get_tail(*stack);
	newtail = get_node_before_tail(*stack);
	temp->next = *stack;
	stack = &temp;
	newtail->next = NULL;
}

void	move_rra(t_stack **a, t_stack *target)
{
	while (target->cost < 0)
	{
		rev_rotate(a);
		ft_printf("rra\n");
		target->cost++;
	}
}

void	move_rrb(t_stack **b, t_stack *low_cost)
{
	while(low_cost->cost < 0)
	{
		rev_rotate(b);
		ft_printf("rrb\n");
		low_cost->cost++;
	}
}
void	move_rrr(t_stack **a, t_stack **b, t_stack *target, t_stack *low_cost)
{
	while(target->cost < 0 && low_cost->cost < 0)
	{
		rev_rotate(a);
		rev_rotate(b);
		ft_printf("rrr\n");
		target->cost++;
		low_cost->cost++;
	}
}
