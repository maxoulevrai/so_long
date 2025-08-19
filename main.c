/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:03:38 by maleca            #+#    #+#             */
/*   Updated: 2025/08/19 04:32:00 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars);
	exit(0);
}

static int	key_press_hdl(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars);
		exit(0);
	}
	return (0);
}
static t_vars	*init(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map = NULL;
	vars->obj_img = NULL;
	vars->wall_img = NULL;
	vars->floor_img = NULL;
	vars->player_img = NULL;
	vars->map_exit_img = NULL;
	return (vars);
}

void	so_long(char **av)
{
	t_map	*map;
	t_vars	*vars;

	map = parse(av);
	vars = init();
	if (!vars)
		print_free_error("failed allocating vars", map);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		print_free_error("failed starting mlx", map);
	vars->win = mlx_new_window(vars->mlx, map->width * IMG_WIDTH,
		map->heigth * IMG_HEIGHT, "so_long");
	load_map(map, vars);
	mlx_key_hook(vars->win, key_press_hdl, vars);
	mlx_hook(vars->win, 17, 1L<<17, close_win, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		print_error("Too few arguments");
	if (ac > 2)
		print_error("Too many arguments");
	so_long(av);
	return (0);
}
