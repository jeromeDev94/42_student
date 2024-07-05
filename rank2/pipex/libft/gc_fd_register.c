/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_fd_register.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:18:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/05 10:09:01 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	gc_fd_register(int fd)
{
	t_gc_node	*new_node;

	if (!fd)
		return ;
	new_node = malloc(sizeof(t_gc_node));
	if (!new_node)
	{
		errno = ENOMEM;
		return ;
	}
	new_node->ptr = NULL;
	new_node->is_marked = false;
	new_node->is_array = false;
	new_node->fd = fd;
	new_node->next = g_garbage_collector.head;
	g_garbage_collector.head = new_node;
	ft_printf("Registered fd: %i\n", fd);
}
