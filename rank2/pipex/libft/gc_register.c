/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_register.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:25:20 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/05 10:46:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	gc_register(void *ptr)
{
	t_gc_node	*new_node;

	if (!ptr)
		return ;
	new_node = malloc(sizeof(t_gc_node));
	if (!new_node)
	{
		errno = ENOMEM;
		return ;
	}
	new_node->ptr = ptr;
	new_node->is_marked = false;
	new_node->is_array = false;
	new_node->fd = -1;
	new_node->next = g_garbage_collector.head;
	g_garbage_collector.head = new_node;
	ft_printf("Registered pointer: %p\n", ptr);
}
