/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:59:57 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/03 02:53:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_fill_base(long long nbr, int size, char *base, char *res)
{
	int	len;
	int	i;

	len = ft_strlen(base);
	i = size - 1;
	if (nbr == 0)
		res[i] = base[0];
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		res[i] = base[nbr % len];
		i -= 1;
		nbr /= len;
	}
	res[size] = '\0';
	return (res);
}

char	*ft_lltoa_base(long long nbr, char *base)
{
	int		len;
	int		size;
	char	*res;
	long long	nbr_base;

	len = ft_strlen(base);
	size = 0;
	if (nbr <= 0)
		size++;
	nbr_base = nbr;
	while (nbr_base)
	{
		nbr_base /= len;
		size++;
	}
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	return (ft_fill_base(nbr, size, base, res));
}
