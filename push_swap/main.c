/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/24 18:34:25 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/push_swap.h"
#include "include/ft_printf.h"

int	main(int argc, char **argv)
{
	t_dclst	*stack_a;
	t_dclst	*stack_b;

	ft_printf("Hello, World! :)\n");
	ft_printf("Programe name: %s\n", argv[0]);
	ft_init_stack(&stack_a);
	ft_init_stack(&stack_b);
	if (argc > 1)
	{

		ft_parse_arg(argc, argv, stack_a);
		ft_print_stack(stack_a, 'a');
		ft_print_stack(stack_b, 'b');
		radix_sort(stack_a, stack_b);
		ft_print_stack(stack_a, 'a');
		ft_print_stack(stack_b, 'b');
		ft_empty_stack(stack_a);
		ft_empty_stack(stack_b);
	}
	free(stack_a);
	free(stack_b);
	return (0);
}

/*
 * TO DO LIST PUSH_SWAP
 * implem small data algo et faire test
 * implem radix et faire test
 * implem quick sort et faire test
 * implem turkish algo et faire test.
 * implem gestionaire d'algo en fonction de la taille de la stack
 * opti big_data algo and quicksort/radixsort switch points
 */

