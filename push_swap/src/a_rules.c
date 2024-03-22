/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:43:18 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 18:56:36 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	sa(t_dclst *stack_a)
{
	t_dcnode	*first_node;
	t_dcnode	*second_node;

	if (!stack_a || !stack_a->begin || !stack_a->begin->next)
		return ; 
	first_node = stack_a->begin;
	second_node = stack_a->begin->next;
	stack_a->begin = second_node;
	first_node->next = second_node->next;
	second_node->next = first_node;
	if (first_node->next)
		first_node->next->back = first_node;
	first_node->back = second_node;
	second_node->back = NULL;
	ft_printf("sa\n");
}

void	pb(t_dclst *stack_a, t_dclst *stack_b)
{
	t_dcnode	*top_a;

	if (!stack_a || !stack_a->begin)
		return ;
	top_a = stack_a->begin;
	stack_a->begin = top_a->next;
	if (stack_a->begin)
		stack_a->begin->back = NULL;
	if (!stack_b->begin)
	{
		stack_b->begin = top_a;
		stack_b->end = top_a;
		top_a->next = NULL;
	}
	else
	{
		top_a->next = stack_b->begin;
		stack_b->begin->back = top_a;
		stack_b->begin = top_a;
	}
	top_a->back = NULL;
	stack_a->length--;
	stack_b->length++;
	ft_printf("pb\n");
}

void	ra(t_dclst *stack_a);

void	rra(t_dclst *stack_a);
