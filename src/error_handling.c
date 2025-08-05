/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:34:40 by maleca            #+#    #+#             */
/*   Updated: 2025/08/05 23:29:26 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char *err_msg)
{
	ft_putendl_fd("Error\n", 2);
	ft_putendl_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

void	close_error(char *err_msg, int fd)
{
	close(fd);
	error(err_msg);
}

void	free_error(char *err_msg, char **map)
{
	free_dtab(map);
	error(err_msg);
}
