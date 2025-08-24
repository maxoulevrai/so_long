/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:25:07 by maleca            #+#    #+#             */
/*   Updated: 2025/08/24 22:00:27 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_vars(t_vars *vars)
{
	vars->map = NULL;
	vars->win = NULL;
	vars->mlx = NULL;
	vars->obj_img = NULL;
	vars->wall_img = NULL;
	vars->floor_img = NULL;
	vars->player_img = NULL;
	vars->closed_door_img = NULL;
}

void	init_map(t_map *map)
{
	map->area = NULL;
	map->heigth = 0;
	map->width = 0;
	map->moves = 0;
	map->c_count = 0;
	map->p_pos.x = 0;
	map->p_pos.y = 0;
	map->e_pos.x = 0;
	map->e_pos.y = 0;
}

// int	is_player_movable(t_map *map)
// {
// 	int i;
// 	int j;

	
// }