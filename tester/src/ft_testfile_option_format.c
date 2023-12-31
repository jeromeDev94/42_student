/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testfile_option_format.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:26:43 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:40:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

char	*ft_testfile_option_format(char *s)
{

	if (!ft_strncmp("EMPTY", s, 6))
		return ("");
	else if (!ft_strncmp("SPACE", s, 6))
		return (" ");
	else if (!ft_strncmp("SPACES", s, 7))
		return ("         ");
	else
		return (s);
}
