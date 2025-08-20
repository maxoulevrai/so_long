/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:34:40 by maleca            #+#    #+#             */
/*   Updated: 2025/08/20 20:24:58 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_img(t_vars *vars)
{
	if (vars->floor_img)
		mlx_destroy_image(vars->mlx, vars->floor_img);
	if (vars->obj_img)
		mlx_destroy_image(vars->mlx, vars->obj_img);
	if (vars->wall_img)
		mlx_destroy_image(vars->mlx, vars->wall_img);
	if (vars->player_img)
		mlx_destroy_image(vars->mlx, vars->player_img);
	if (vars->map_exit_img)
		mlx_destroy_image(vars->mlx, vars->map_exit_img);
}

void	print_error(char *err_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

void	close_fd_error(char *err_msg, int fd)
{
	close(fd);
	print_error(err_msg);
}

void	free_map_error(char *err_msg, t_map *map)
{
	free_dtab(map->area);
	free(map);
	print_error(err_msg);
}

void	free_vars_error(char *err_msg, t_vars *vars)
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
	print_error(err_msg);
}
