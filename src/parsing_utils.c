/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:22:46 by maleca            #+#    #+#             */
/*   Updated: 2025/08/22 21:43:11 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(char **map_cpy, int x, int y, int map_content[2])
{
	char	current;

	if (x < 0 || y < 0 || !map_cpy)
		return ;
	if (!map_cpy[y])
		return ;
	if (!map_cpy[y][x] || map_cpy[y][x] == WALL || map_cpy[y][x] == 'X')
		return ;
	current = map_cpy[y][x];
	map_cpy[y][x] = 'X';
	if (current == 'C')
		map_content[0]--;
	else if (current == 'E')
		map_content[1] = 1;
	flood_fill(map_cpy, x + 1, y, map_content);
	flood_fill(map_cpy, x - 1, y, map_content);
	flood_fill(map_cpy, x, y + 1, map_content);
	flood_fill(map_cpy, x, y - 1, map_content);
}

static char	*duplicate_and_clean_line(char *line)
{
	char	*clean_line;
	size_t	len;
	size_t	i;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	clean_line = malloc(sizeof(char) * (len + 1));
	if (!clean_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		clean_line[i] = line[i];
		i++;
	}
	clean_line[i] = '\0';
	return (clean_line);
}

int	is_map_solvable(t_map *map, int map_content[2])
{
	char	**map_cpy;
	t_point	*p_pos;
	int		i;

	map_cpy = malloc(sizeof(char *) * (map->heigth + 1));
	if (!map_cpy)
		return (0);
	map_content[0] = map->c_count;
	map_content[1] = 0;
	i = 0;
	while (map->area[i])
	{
		map_cpy[i] = duplicate_and_clean_line(map->area[i]);
		if (!map_cpy[i])
			free_dtab(map_cpy);
		i++;
	}
	p_pos = &map->p_pos;
	map_cpy[i] = NULL;
	flood_fill(map_cpy, p_pos->x, p_pos->y, map_content);
	free_dtab(map_cpy);
	if (map_content[0] == 0 && map_content[1] == 1)
		return (1);
	return (0);
}

int	is_map_enclosed(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->area[0][i] != WALL || map->area[map->heigth - 1][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < map->heigth)
	{
		if (map->area[i][0] != WALL || map->area[i][map->width - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	is_char_valid(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->heigth)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->area[i][j] != FLOOR && map->area[i][j] != WALL
				&& map->area[i][j] != OBJ && map->area[i][j] != MAP_EXIT
				&& map->area[i][j] != PLAYER)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
