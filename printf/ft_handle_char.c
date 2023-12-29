/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:12:16 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/29 14:48:08 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_handle_char(t_format_spec spec, va_list args, char *buffer, int *index)
{
	char	c;
	int		content_len;

	c = (char)va_arg(args, int);
	content_len = 1;
	if (spec.flag_minus)
		ft_buffer_add(buffer, index, c);
	ft_apply_width(spec, buffer, index, content_len);
	if (!spec.flag_minus)
		ft_buffer_add(buffer, index, c);
}
