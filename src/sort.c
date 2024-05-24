/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:05:47 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/18 13:38:32 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	**tmp;

	tmp = a;
	while (1)
	{
		if (stack_check_order(*tmp) == 1)
			return ;
		else
		{
			if ((*tmp)->value > (*tmp)->next->value
				&& (*tmp)->value > (*tmp)->next->next->value)
			{
				rotate(a);
				printf("ra\n");
			}
			else if ((*tmp)->next->value > (*tmp)->value
				&& (*tmp)->next->value > (*tmp)->next->next->value)
			{
				rev_rotate(a);
				printf("rra\n");
			}
			else if ((*tmp)->value > (*tmp)->next->value)
				move_sa(tmp);
		}
	}
}

int	stack_len(t_stack	*a)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = 0;
	if(!a)
		return (0);
	while(tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/**
 * @brief Moves half of the elements from stack a to stack b, 
 * leaving only 3 elements in stack a.
 * If the length of stack a is less than or equal to 3, no elements are moved.
 * first moves the smallest 50 %
 * @param a Pointer to the pointer to stack a.
 * @param b Pointer to the pointer to stack b.
 */
void	push_all_to_b(t_stack **a, t_stack **b)
{
	int		half_len;
	int		i;

	i = 0;
	half_len = stack_len(*a) / 2;
	while (i < half_len && stack_len(*a) > 3)
	{
		if ((*a)->index <= half_len)
		{
			move_pb(a, b);
			i++;
		}
		else
		{
			rotate(a);
			printf("ra\n");
		}
	}
	while (stack_len(*a) > 3)  
	{
		move_pb(a, b);
	}
}

void	put_target_pos(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target_pos;
	t_stack	*a;
	t_stack	*b;

	if (!stack_a || !stack_b)
		return ;
	b = stack_b;
	while (b)
	{
		a = stack_a;
		target_pos = NULL;
		while (a)
		{
			if (b->value < a->value
				&& (target_pos == NULL || target_pos->value > a->value))
				target_pos = a;
			a = a->next;
		}
		if (target_pos == NULL)
			b->target_pos = find_smallest(&stack_a);
		else
			b->target_pos = target_pos->pos;
		b = b->next;
	}
}
int	find_smallest(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*smallest;
	int		position;

	aux = *stack;
	smallest = *stack;
	position = 0;
	while (aux)
	{
		if (smallest->index > aux->index)
		{
			position = aux->pos;
			smallest = aux;
		}
		aux = aux->next;
	}
	return (position);
}
