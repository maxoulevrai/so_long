/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:11:12 by maleca            #+#    #+#             */
/*   Updated: 2025/08/08 22:49:31 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(char **map_cpy, int x, int y, int *map_content)
{
	if (map_cpy[y][x] == 'E')
		map_content[1] = 1;
	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'E')
		return ;
	if (map_cpy[y][x] == 'C')
		map_content[0]--;
	map_cpy[y][x] = 'F';
	flood_fill(map_cpy, x + 1, y, map_content);
	flood_fill(map_cpy, x - 1, y, map_content);
	flood_fill(map_cpy, x, y + 1, map_content);
	flood_fill(map_cpy, x, y - 1, map_content);
}

static void	get_start_end(t_map *map)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	while (map->area[point.y])
	{
		point.y = 0;
		while (map->area[point.y][point.x])
		{
			if (map->area[point.y][point.x] == 'P')
				map->p_pos = point;
			if (map->area[point.y][point.x] == 'E')
				map->e_pos = point;
			point.x++;
		}
		point.y++;
	}
}

int	is_map_solvable(t_map *map, int map_content[2])
{
	char 	**map_cpy;
	int		i;

	map_cpy = malloc(sizeof(char *) * (map->heigth + 1));
	if (!map_cpy)
		return (0);
	map_content[0] = map->c_count;
	map_content[1] = 0;
	i = 0;
	while (map->area[i])
	{
		map_cpy[i] = ft_strdup(map->area[i]);
		i++;
	}
	get_start_end(map);
	flood_fill(map_cpy, map->p_pos.x, map->p_pos.y, map_content);
	free_dtab(map_cpy);
	if (map_content[0] == 0 && map_content[1] == 1)
		return (1);
	return (0);
}

int	is_map_enclosed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->area[i][0] && map->area[j][map->heigth])
	{
		if (map->area[i][0] != '1' || map->area[j][map->heigth] != '1')
			return (0);
		i++;
		j++;
	}
	i = 0;
	j = 0;
	while (map->area[0][i] && map->area[map->width][j])
	{
		if (map->area[0][i] != '1' || map->area[map->width][j] != '1')
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	is_char_valid(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->area[i])
	{
		j = 0;
		while (map->area[i][j])
		{
			if (map->area[i][j] != '0' && map->area[i][j] != '1'
				&& map->area[i][j] != 'C' && map->area[i][j] != 'E'
				&& map->area[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
