/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:20:30 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/23 13:37:48 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_lowest_cost(t_stack **stack_b)
{
	t_stack	*b;
	t_stack	*lowest;

	b = *stack_b;
	lowest = b;
	if (!stack_b || !*stack_b)
		return (NULL);
	while (b)
	{
		if (b->cost_total < lowest->cost_total)
			lowest = b;
		b = b->next;
	}
	return (lowest);
}

void	do_move(t_stack **stack_a, t_stack **stack_b, t_stack *low_cost_node)
{
	t_stack 	*target;
	int			loop;

	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	target = *stack_a;
	loop = low_cost_node->target_pos;
	while(loop-- > 0 && target)
		target = target->next;
	if(!target)
		return ;
	if (low_cost_node->cost > 0 && target->cost > 0)
		move_rr(stack_a, stack_b, target, low_cost_node);
	else if (low_cost_node->cost < 0 && target->cost < 0)
		move_rrr(stack_a, stack_b, target, low_cost_node);
	if (low_cost_node->cost == 0 && target->cost != 0)
	{
		if (target->cost > 0)
			move_ra(stack_a, target);
		else if (target->cost < 0)
			move_rra(stack_a, target);
	}
	else if (target->cost == 0 && low_cost_node->cost != 0)
	{
		if (low_cost_node->cost > 0)
			move_rb(stack_b, low_cost_node);
		else if (low_cost_node->cost < 0)
			move_rrb(stack_b, low_cost_node);
	}
	if (target->cost == 0 && low_cost_node->cost == 0)
		move_pa(stack_a, stack_b);
	return ;
}

void do_sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*low_cost_node;
	t_stack *temp;

	if (!stack_b || !stack_a ||!*stack_a ||!*stack_b)
		return ;
	while(*stack_b)
	{
		put_position(*stack_a);
		put_position(*stack_b);
		put_target_pos(*stack_a, *stack_b);
		put_cost(stack_a);
		put_cost(stack_b);
		put_total_cost(stack_a, stack_b);
		low_cost_node = find_lowest_cost(stack_b);
		do_move(stack_a, stack_b, low_cost_node);
	}
	put_index(*stack_a);
	printf("\n-----------IMPRIMIR LUEGO DE SEND ALL TO B and SORT A ----\n");
	printf("\n-----------STACK A----------------------------\n");
	temp = *stack_a;
	while (temp)
	{
		printf("Value: %d	Index: %d	Taget_pos: %d	Pos: %d	Cost: %d		Cost_total: %d\n", temp->value, temp->index, temp->target_pos, temp->pos, temp->cost, temp->cost_total);
		temp = temp->next;
	}
	 printf("\n-----------STACK B----------------------------\n");
	temp = *stack_b;
	while (temp)
	{
		printf("Value: %d	Index: %d	Taget_pos: %d	Pos: %d	Cost: %d		Cost_total: %d\n", temp->value, temp->index, temp->target_pos, temp->pos, temp->cost, temp->cost_total);
		temp = temp->next;
	}
}