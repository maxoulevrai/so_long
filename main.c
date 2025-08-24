/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:03:38 by maleca            #+#    #+#             */
/*   Updated: 2025/08/24 21:49:03 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_vars *vars)
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

t_map	*parse(char *map_file)
{
	t_map	*map;
	int		map_content[2];

	map = open_and_duplicate(map_file);
	if (!map)
		return (NULL);
	map_content[0] = 0;
	map_content[1] = 0;
	if (!check_ext(map_file))
		free_map_error("wrong map extension", map);
	if (map->heigth <= 3 && map->width <= 3)
		free_map_error("map is too small", map);
	if (!is_map_enclosed(map))
		free_map_error("map is not enclosed properly", map);
	if (!is_char_valid(map))
		free_map_error("unrecognized char in map", map);
	get_map_content(map, map_content);
	if (map->c_count < 1 || map_content[0] != 1 || map_content[1] != 1)
		free_map_error("invalid map components count", map);
	if (!is_map_solvable(map, map_content))
		free_map_error("map is not solvable", map);
	// if (!is_player_movable(map))
	// 	free_map_error("player cannot move", map);
	return (map);
}

static t_vars	*init(char **av)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		print_error("failed allocating vars");
	init_vars(vars);
	vars->map = parse(av[1]);
	if (!vars->map)
		free_vars_error("failed loading the map", vars);
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
	mlx_hook(vars->win, 2, 1L << 0, key_press_hdl, vars);
	mlx_hook(vars->win, 17, 1L << 17, close_win, vars);
	mlx_loop(vars->mlx);
	return (0);
}
