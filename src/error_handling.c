/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:34:40 by maleca            #+#    #+#             */
/*   Updated: 2025/08/06 22:21:38 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error(char *err_msg)
{
	ft_putendl_fd("Error\n", 2);
	ft_putendl_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

void	print_close_error(char *err_msg, int fd)
{
	close(fd);
	print_error(err_msg);
}

void	print_free_error(char *err_msg, char **map)
{
	free_dtab(map);
	print_error(err_msg);
}
