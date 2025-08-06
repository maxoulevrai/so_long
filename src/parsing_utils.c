/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:11:12 by maleca            #+#    #+#             */
/*   Updated: 2025/08/06 23:47:16 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(char **map_cpy, int x, int y, int map_content[3])
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

t_point	get_start_point(char **map, t_point start)
{
	int	i;
	int	j;
}

int	is_map_solvable(char **map, int map_content[3], int map_size[2])
{
	t_point	start;
	char 	**map_cpy;
	int		i;

	map_cpy = malloc(sizeof(char *) * (map_size[1] + 1));
	if (!map_cpy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		i++;
	}
	start = get_start_point(map, start);
	flood_fill(map_cpy, )
	
}

int	is_map_enclosed(char **map,int map_size[2])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][map_size[0]] && map[j][map_size[0]])
	{
		if (map[i][map_size[0]] != '1' || map[j][map_size[0]] != '1')
			return (0);
		i++;
		j++;
	}
	i = 0;
	j = 0;
	while (map[map_size[1]][i] && map[map_size[1]][j])
	{
		if (map[map_size[1]][i] != '1' || map[map_size[1]][j] != '1')
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	is_char_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'C' && map[i][j] != 'E'
				&& map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
