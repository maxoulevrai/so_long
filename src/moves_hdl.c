/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_hdl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:08:05 by maleca            #+#    #+#             */
/*   Updated: 2025/08/22 22:02:25 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	hdl_win(t_vars *vars)
{
	printf("bravo !\n");
	close_win(vars);
}

int	is_valid(t_map *map, int new_pos_y, int new_pos_x)
{
	if (new_pos_x == 0 || new_pos_y == 0)
		return (0);
	if (map->area[new_pos_y][new_pos_x] == WALL)
		return (0);
	return (1);
}

void	update_display(t_vars *vars, t_point new_pos)
{
	t_point	prev_pos;

	prev_pos.x = vars->map->p_pos.x;
	prev_pos.y = vars->map->p_pos.y;
	if (vars->map->c_count == 0
		&& vars->map->area[new_pos.y][new_pos.x] == MAP_EXIT)
		hdl_win(vars);
	if (vars->map->c_count != 0
		&& vars->map->area[new_pos.y][new_pos.x] == MAP_EXIT)
		return ;
	if (vars->map->area[new_pos.y][new_pos.x] == OBJ)
	{
		vars->map->area[new_pos.y][new_pos.x] = 0;
		vars->map->c_count--;
	}
	vars->map->moves++;
	printf("movements: %d\n", vars->map->moves);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->floor_img, prev_pos.x * IMG_HEIGHT, prev_pos.y * IMG_WIDTH);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->player_img, new_pos.x * IMG_HEIGHT, new_pos.y * IMG_WIDTH);
	vars->map->p_pos = new_pos;
}

int	key_press_hdl(int keycode, t_vars *vars)
{
	t_point	new_pos;

	new_pos.x = vars->map->p_pos.x;
	new_pos.y = vars->map->p_pos.y;
	if (keycode == KEY_ESC)
		close_win(vars);
	else if ((keycode == KEY_W || keycode == KEY_UP)
		&& is_valid(vars->map, new_pos.y - 1, new_pos.x))
			new_pos.y--;
	else if ((keycode == KEY_S || keycode == KEY_DOWN)
		&& is_valid(vars->map, new_pos.y + 1, new_pos.x))
			new_pos.y++;
	else if ((keycode == KEY_D || keycode == KEY_RIGHT)
		&& is_valid(vars->map, new_pos.y, new_pos.x + 1))
			new_pos.x++;
	else if ((keycode == KEY_A || keycode == KEY_LEFT)
		&& is_valid(vars->map, new_pos.y, new_pos.x - 1))
			new_pos.x--;
	if (vars->map->p_pos.x != new_pos.x || vars->map->p_pos.y != new_pos.y)
		update_display(vars, new_pos);
	return (0);
}
