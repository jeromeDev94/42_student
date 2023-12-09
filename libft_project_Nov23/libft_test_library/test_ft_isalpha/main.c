/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:52:49 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/09 13:05:13 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../function_libraries/libfmanip.h"
#include "../function_libraries/libft.h"

int	main(void)
{
	t_tstlst	*lst;
	int		i;

	lst = ft_load_tests("ft_isalpha_test_data.txt");
	if (!lst)
		exit(EXIT_FAILURE);
	i = 1;
	printf("FT_ISALPHA TEST:\n");
	while (lst->next)
	{
        ft_test_function(lst, isalpha, ft_isalpha, ARG_INT);
		i++;
		lst = lst->next;
	}
	ft_test_function(lst, isalpha, ft_isalpha, ARG_INT);
    return (0);
}
