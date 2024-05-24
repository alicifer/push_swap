/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:53:09 by alicifer          #+#    #+#             */
/*   Updated: 2024/05/24 07:30:57 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_leaks(void)
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	/*if (argc != 2)
		print_error("");
	if (check_num(argv) == 0)
		print_error("Invalid arguments");
	else
		printf("Check num ok\n");
	int *array = args_to_intarray(argv[1]);
	
	//	CHECKEO DE DUPLICADOS
	printf("\n-----DUPLICADOS Y ORDEN ------\n");
	if(check_dup(array) == 0)
		printf("No hay dup\n");
	else 
		printf("Error: Hay dup\n");
		
// CHEQUEO DE ARRAY PREVIAMENTE ORDENADO
	if(check_order(array) == 0)
		printf("No estan ordenados\n");
	else
		printf("Está ordenado\n");
*/
	
	int		*array;
	t_stack *a;
	t_stack	*temp;
	
	array = check_all_args(argc, argv);
	a = fill_stack(array);
	t_stack *b = NULL;
	push_all_to_b(&a, &b);
	sort_three(&a);
	do_sorting(&a, &b);
	exit (0);
	final_sort(&a);

	printf("\n-----------IMPRIMIR LUEGO DE SEND ALL TO B and SORT A ----\n");
	printf("\n-----------STACK A----------------------------------------\n");
	temp = a;
	while (temp)
	{
		printf("Value: %d	Index: %d	Taget_pos: %d	Pos: %d	Cost: %d				Cost_total: %d\n", temp->value, temp->index, temp->target_pos, temp->pos, temp->cost, temp->cost_total);
		temp = temp->next;
	}
	printf("\n-----------STACK B----------------------------------------\n");
	temp = b;
	while (temp)
	{
	printf("Value: %d	Index: %d	Taget_pos: %d	Pos: %d	Cost: %d				Cost_total: %d\n", temp->value, temp->index, temp->target_pos, temp->pos, temp->cost, temp->cost_total);
		temp = temp->next;

	}
	free_stack(b);
	free_stack (a);	
	atexit(check_leaks);
	return (0);	
}

