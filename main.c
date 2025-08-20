/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:03:38 by maleca            #+#    #+#             */
/*   Updated: 2025/08/20 20:24:25 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_win(t_vars *vars)
{
	if (vars->map)
		free_dtab(vars->map->area);
	free(vars->map);
	destroy_img(vars);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free(vars);
	exit(EXIT_SUCCESS);
}

static int	key_press_hdl(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		close_win(vars);
	
	return (0);
}

static t_vars	*init(char **av)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		print_error("failed allocating vars");
	vars->map = parse(av);
	if (!vars->map)
		free_vars_error("failed allocating map", vars);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		free_vars_error("failed starting mlx", vars);
	vars->win = mlx_new_window(vars->mlx, vars->map->width * IMG_WIDTH,
			vars->map->heigth * IMG_HEIGHT, "so_long");
	if (!vars->win)
		free_vars_error("failed opening win", vars);
	load_sprites(vars);
	return (vars);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac < 2)
		print_error("Too few arguments");
	if (ac > 2)
		print_error("Too many arguments");
	vars = init(av);
	load_map(vars);
	mlx_key_hook(vars->win, key_press_hdl, vars);
	mlx_hook(vars->win, 17, 1L << 17, close_win, vars);
	mlx_loop(vars->mlx);
	return (0);
}
