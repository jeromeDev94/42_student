/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:13:47 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/10 09:13:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	ft_parse_args(pipex, argc, argv, envp);
//	gc_collect();
	pipex->prev_pipefd[0] = -1;
	pipex->prev_pipefd[1] = -1;
	ft_open_files(pipex);
}
