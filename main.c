/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:03:38 by maleca            #+#    #+#             */
/*   Updated: 2025/08/15 20:53:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_win(t_vars *vars)
{
	(void)vars;
	exit(0);
}

static int	key_press_hdl(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	so_long(char **av)
{
	t_map	*map;
	t_vars	vars;
	char	*relative_path = "./sprites_xpm/";

	map = parse(av);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		print_free_error("failed starting mlx", map);
	vars.win = mlx_new_window(vars.mlx, map->heigth * IMG_HEIGHT,
		map->width * IMG_HEIGHT, "so_long");
	load_map(map, vars);
	mlx_key_hook(vars.win, key_press_hdl, &vars);
	mlx_hook(vars.win, 17, 1L<<17, close_win, &vars);
	mlx_loop(vars.mlx);
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
