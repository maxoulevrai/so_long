/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:32:14 by root              #+#    #+#             */
/*   Updated: 2025/08/19 04:27:38 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	load_sprites(t_vars *vars)
{
	vars->wall_img = mlx_xpm_file_to_image(vars->mlx, WALL_XMP,
		&vars->map->width, &vars->map->heigth);
	vars->floor_img = mlx_xpm_file_to_image(vars->mlx, FLOOR_XMP,
		&vars->map->width, &vars->map->heigth);
	vars->obj_img = mlx_xpm_file_to_image(vars->mlx, OBJ_XMP,
		&vars->map->width, &vars->map->heigth);
	vars->player_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_XMP,
		&vars->map->width, &vars->map->heigth);
	vars->map_exit_img = mlx_xpm_file_to_image(vars->mlx, MAP_EXIT_XMP,
		&vars->map->width, &vars->map->heigth);
}

static void	*id_sprite(t_map *map, t_vars *vars, int x, int y)
{
	if (map->area[y][x] == WALL)
		return(vars->wall_img);
	if (map->area[y][x] == FLOOR)
		return(vars->floor_img);
	if (map->area[y][x] == OBJ)
		return(vars->obj_img);
	if (map->area[y][x] == PLAYER)
		return(vars->player_img);
	if (map->area[y][x] == MAP_EXIT)
		return(vars->map_exit_img);
	return (NULL);
}

void	load_map(t_map *map, t_vars *vars)
{
	int		x;
	int		y;
	void	*img_ptr;

	y = 0;
	load_sprites(vars);
	while (map->area[y])
	{
		x = 0;
		while (map->area[y][x] && map->area[y][x] != '\n')
		{
			img_ptr = id_sprite(map, vars, x, y);
			if (!img_ptr)
			{
				free(vars);
				print_free_error("failed loading sprites", map);
			}
			mlx_put_image_to_window(vars->mlx, vars->win,
				img_ptr, x * IMG_HEIGHT, y * IMG_WIDTH);
			x++;
		}
		y++;
	}
}
