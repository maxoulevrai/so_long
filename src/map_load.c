/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:32:14 by root              #+#    #+#             */
/*   Updated: 2025/08/15 20:50:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_map(t_map *map, t_vars *vars)
{
	
}

char	*id_sprite(t_map *map, t_vars *vars, t_point *point)
{
	char	param;

	param = map->area[point->y][point->x];
	if (param == WALL)
		mlx_xpm_to_image(vars->mlx, WALL_XMP, point->x, point->y);
	if (param == FLOOR)
		mlx_xpm_to_image(vars->mlx, FLOOR_XMP, point->x, point->y);
	if (param == BALL)
		mlx_xpm_to_image(vars->mlx, BALL_XMP, point->x, point->y);
	if (param == PLAYER)
		mlx_xpm_to_image(vars->mlx, PLAYER_XMP, point->x, point->y);
	if (param == MAP_EXIT)
		mlx_xpm_to_image(vars->mlx, MAP_EXIT_XMP, point->x, point->y);
	
}
