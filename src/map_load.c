/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:24:42 by maleca            #+#    #+#             */
/*   Updated: 2025/08/20 20:07:43 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*id_sprite(t_vars *vars, int x, int y)
{
	if (vars->map->area[y][x] == WALL)
		return (vars->wall_img);
	if (vars->map->area[y][x] == FLOOR)
		return (vars->floor_img);
	if (vars->map->area[y][x] == OBJ)
		return (vars->obj_img);
	if (vars->map->area[y][x] == PLAYER)
		return (vars->player_img);
	if (vars->map->area[y][x] == MAP_EXIT)
		return (vars->map_exit_img);
	return (NULL);
}

void	load_sprites(t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->wall_img = mlx_xpm_file_to_image(vars->mlx, WALL_XMP,
			&img_width, &img_height);
	if (!vars->wall_img)
		free_vars_error("failed loading wall sprite", vars);
	vars->floor_img = mlx_xpm_file_to_image(vars->mlx, FLOOR_XMP,
			&img_width, &img_height);
	if (!vars->floor_img)
		free_vars_error("failed loading floor sprite", vars);
	vars->obj_img = mlx_xpm_file_to_image(vars->mlx, OBJ_XMP,
			&img_width, &img_height);
	if (!vars->obj_img)
		free_vars_error("failed loading obj sprite", vars);
	vars->player_img = mlx_xpm_file_to_image(vars->mlx, PLAYER_XMP,
			&img_width, &img_height);
	if (!vars->player_img)
		free_vars_error("failed loading player sprite", vars);
	vars->map_exit_img = mlx_xpm_file_to_image(vars->mlx, MAP_EXIT_XMP,
			&img_width, &img_height);
	if (!vars->map_exit_img)
		free_vars_error("failed loading exit sprite", vars);
}

void	load_map(t_vars *vars)
{
	int		x;
	int		y;

	y = 0;
	while (vars->map->area[y])
	{
		x = 0;
		while (vars->map->area[y][x] && vars->map->area[y][x] != '\n')
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				id_sprite(vars, x, y), x * IMG_HEIGHT, y * IMG_WIDTH);
			x++;
		}
		y++;
	}
}
