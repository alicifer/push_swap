/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:30:20 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/10 11:39:50 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Swaps the first two elements if both exists.
 * 
 * @param stack Double pointer to the stack.
 */

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!*stack || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*stack = second;
}

/**
 * @brief Swaps the first 2 elem from stack a. And prints sa\n
 *  * @param a Double pointer to stack a.
 */
void	move_sa(t_stack **a)
{
	swap (a);
	ft_printf("sa\n");
}

/**
 * @brief Swaps the first 2 elem from stack b. And prints sb\n
 *  * @param a Double pointer to stack b.
 */
void	move_sb(t_stack **b)
{
	swap (b);
	ft_printf("sb\n");
}

/**
 * @brief Swaps the first 2 elem from stack a + b. And prints ss\n
 *  * @param a Double pointer to stack a + b.
 */
void	move_ss(t_stack **a, t_stack **b)
{
	swap (a);
	swap (b);
	ft_printf("ss\n");
}
