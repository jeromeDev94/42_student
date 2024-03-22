/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:00:46 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 18:57:59 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	radix_sort(t_dclst *stack_a, t_dclst *stack_b)
{
    ft_print_stack(stack_a, 'a');
    ft_print_stack(stack_b, 'b');

    ft_printf("\n");
    sa(stack_a);
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_printf("\n");

    ft_print_stack(stack_a, 'a');
    ft_print_stack(stack_b, 'b');
}
