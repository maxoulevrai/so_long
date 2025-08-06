/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:24:31 by maleca            #+#    #+#             */
/*   Updated: 2025/08/06 23:49:00 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	*get_map_content(char **map)
{
	t_point	point;
	int		map_content[3];

	map_content[0] = 0;
	map_content[1] = 0;
	map_content[2] = 0;
	point.y = 0;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x])
		{
			if (map[point.y][point.x] == 'C')
				map_content[0] += 1;
			if (map[point.y][point.x] == 'E')
				map_content[1] += 1;
			if (map[point.y][point.x] == 'P')
				map_content[2] += 1;
			point.x++;
		}
		point.y++;
	}
	if (map_content[0] < 1 || map_content[1] != 1 || map_content[2] != 1)
		print_free_error("invalid map components count", map);
	return (map_content);
}

static void	get_map_size(char **av, int map_size[2])
{
	char	*line;
	int		fd;

	map_size[0] = 0;
	map_size[1] = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("failed loading the map");
	line = get_next_line(fd);
	map_size[0] = ft_strlen(line) - 1;
	while (line)
	{
		if (ft_strlen(line) - 1 != map_size[0])
		{
			free(line);
			print_close_error("unconsistant collumn count", fd);
		}
		map_size[1]++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

static int	is_map_valid(char **map)
{
	int	*map_content;
	int	*map_size;

	get_map_size(map, map_size);
	if (!is_map_enclosed(map, map_size))
		print_free_error("map is not enclosed properly", map);
	if (!is_char_valid(map))
		print_free_error("unrecognized char in map", map);
	map_content = get_map_content(map);
	map_content[1] = 0;
	if (!is_map_solvable(map, map_content, map_size))
		print_free_error("map is not solvable", map);
}

char	**open_and_duplicate(char **av)
{
	int		map_size[2];
	int		fd;
	int		i;
	char	**map;
	char	*line;
	
	get_map_size(av, map_size);
	map = malloc(sizeof(char *) * (map_size[1] + 1));
	fd = open(av[1], O_RDWR);
	if (fd < 0)
		print_error("failed loading the map");
	i = -1;
	map[++i] = get_next_line(fd);
	while (line)
		map[++i] = get_next_line(fd);
	close(fd);
	return (map);
}

char	**parse(char **av)
{
	char **map;
	
	map = open_and_duplicate(av);
	if (!is_map_valid(map))
		print_free_error("invalid map", map);
}
