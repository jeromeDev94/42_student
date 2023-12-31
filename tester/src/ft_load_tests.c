/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:36:52 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:38:57 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

t_tstlst	*ft_load_tests(const char *filepath)
{
	char 		**fextract;
	size_t		lst_size;
	size_t		i;
	t_tstlst	*data_lst;
	t_tstlst	*data_node;

	fextract = ft_flines_to_str(filepath);
	if (!fextract)
		return (NULL);
	lst_size = (size_t)ft_count_flines(filepath);
	data_lst = NULL;
	i = 0;
	while (i < lst_size)
	{
		if (fextract[i][0] != '#')
		{
			data_node = ft_parse_line_to_test(fextract[i]);
			if (!data_node)
			{
				ft_testlst_clear(&data_lst, ft_free_node);
				break;
			}
			ft_testlst_add_back(&data_lst, data_node);
		}
		i++;
	}
	ft_free_memory(fextract, lst_size);
	return (data_lst); 
}

/*Redundant Reading of File: Reading the file twice - once in 
 *ft_flines_to_str and again in ft_count_flines. This could be optimized. 
 *Ideally, should read the file only once and then both count the lines 
 *and split them. This optimization will improve efficiency, especially for 
 *large files.*/
