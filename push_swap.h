/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:20:49 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/23 12:36:58 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "my_libft/libft.h"
# include <limits.h>

/**
 * @brief 
 * value: the integer to sort
 * index: the index int the list of all values 
 * pos: the current position in its stack
 * target_pos: for elements in stack B, the target pos in stack A 
 * where it should be
  */
typedef struct s_stack
{
	int				value;
	int				index;
	int				index_max;
	int				pos;
	int				target_pos;
	int				cost;
	int				cost_total;
	struct s_stack	*next;
}	t_stack;

//	--------------------stack.c------------------
/**
 * @brief Create a new node, allocate memory 
 * 
 * @param value 
 * @return t_stack* Returns a pointer to the new node 
 */
t_stack		*ft_new_node(int value, int len);
void		insert_back(t_stack *a, t_stack *newnode);
/**
 * @brief Fills a stack with integers from an integer array 
 * starting from the last element. bas
 * !Excluding array[0] where is store len of array
 * Returns a pointer to the stack created.
 * @param array Pointer to the integer array.
 */
t_stack		*fill_stack(int *array);
t_stack		*insert_beg(t_stack *a, int value);
void		put_index(t_stack *a);
void		put_position(t_stack *a);
void		put_cost(t_stack **stack);
void		put_total_cost(t_stack **stack_a, t_stack **stack_b);
//	--------------------utils.c------------------
long		ft_atol(const char *str);
char		**args_to_string(char *s);
/**
 * @brief Splits an array of strings into an array of integers.
 * !Storing the int array length  as the first element of the array.
 * @param s The array of strings to convert.
 * @return int* A pointer to the array of integers.
 */
int			*split_to_intarray(char **s);
int			*args_to_intarray(char *s);
int			*split_to_intarray(char **s);
int			*args_to_intarray(char *s);
void		print_stack(t_stack *stack, char *msg);
//	--------------------checkargs.c--------------
int			check_dup(int *array);
int			ft_atoi_err(char **s, int index);
int			check_num(char **argv);
int			check_order(int *array);
int			stack_check_order(t_stack *a);
//	--------------------error.c------------------
void		free_matrix(char **mat);
void		free_stack(t_stack *stack);
void		print_error(char *msg);
int			*check_all_args(int argc, char **argv);
//  ---------------------MOVES------------------
//	--------------------swap.c------------------
void		move_sa(t_stack **a);
void		move_sb(t_stack **b);
void		move_ss(t_stack **a, t_stack **b);
//	-------------------rotate.c-----------------
/**
 * @brief returns a pointer to the tail of a list.
 * @param stack pinter to the stack
 * @return t_stack* 
 */
t_stack	*get_tail(t_stack *stack);
/**
 * @brief The 1º element is sent to the bottom.
 * @param stack 
 * @return * void 
 */
void	rotate(t_stack **stack);
void	move_ra(t_stack **a, t_stack *target);
void	move_rb(t_stack **b, t_stack *low_cost);
void	move_rr(t_stack **a, t_stack **b, t_stack *target, t_stack *low_cost);
//	------------------rev_rotate.c--------------
/**
 * @brief returns a pointer to the node before the tail of a list.
 * @param stack pinter to the stack
 * @return t_stack* 
 */
t_stack	*get_node_before_tail(t_stack *stack);
void	rev_rotate(t_stack **stack);
void	move_rra(t_stack **a, t_stack *target);
void	move_rrb(t_stack **b, t_stack *low_cost);
void	move_rrr(t_stack **a, t_stack **b, t_stack *target, t_stack *low_cost);
//	------------------push.c--------------
void    move_push(t_stack **a, t_stack **b);
void	move_pa(t_stack **b, t_stack **a);
void	move_pb(t_stack **a, t_stack **b);
//	------------------sort.c--------------
/**
 * @brief Sorts a stack of 3 elements
 * @param a pointer to t_stack
 */
void	sort_three(t_stack **a);
int		stack_len(t_stack	*a);
void	push_all_to_b(t_stack **a, t_stack **b);
void 	put_target_pos(t_stack *a, t_stack *b);
int		find_smallest(t_stack **stack);
//	------------------sort2.c--------------
void	final_sort(t_stack **a);
//	------------------makemoves.c--------------
void 	do_sorting(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_lowest_cost(t_stack **stack_b);
void	do_move(t_stack **stack_a, t_stack **stack_b, t_stack *low_cost_node);



#endif