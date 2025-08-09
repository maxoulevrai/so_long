/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:34:40 by maleca            #+#    #+#             */
/*   Updated: 2025/08/09 03:07:00 by root             ###   ########.fr       */
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

static void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->area)
	{
		i = 0;
		while (map->area[i])
		{
			free(map->area[i]);
			i++;
		}
		free(map->area);
	}
	free(map);
}

void	print_free_error(char *err_msg, t_map *map)
{
	free_map(map);
	print_error(err_msg);
}
