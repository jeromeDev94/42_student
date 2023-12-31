/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_plus_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:19:16 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/30 19:43:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_plus_flag(t_format_spec spec, int content, t_buffer *buf_info)
{
	if (spec.flag_plus)
	{
		if (content < 0)
			ft_buffer_add(buf_info, '-');
		else
			ft_buffer_add(buf_info, '+');
	}
}