/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:24:31 by maleca            #+#    #+#             */
/*   Updated: 2025/08/24 18:27:14 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_ext(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 4)
		return (0);
	if (!ft_strcmp(&str[i - 4], ".ber"))
		return (1);
	return (0);
}

void	get_map_content(t_map *map, int map_content[2])
{
	t_point	point;

	point.y = 0;
	while (map->area[point.y])
	{
		point.x = 0;
		while (map->area[point.y][point.x])
		{
			if (map->area[point.y][point.x] == OBJ)
				map->c_count += 1;
			if (map->area[point.y][point.x] == MAP_EXIT)
			{
				map->e_pos = point;
				map_content[0] += 1;
			}
			if (map->area[point.y][point.x] == PLAYER)
			{
				map->p_pos = point;
				map_content[1] += 1;
			}
			point.x++;
		}
		point.y++;
	}
}

static void	check_line_width(char *line, int width, int fd)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	if (len != width)
	{
		free(line);
		close_fd_error("inconsistent column count", fd);
	}
}

static void	get_map_size(char *map_file, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		print_error("failed loading the map");
	line = get_next_line(fd);
	if (!line)
		close_fd_error("empty map", fd);
	map->width = ft_strlen(line);
	if (line[map->width - 1] == '\n')
		map->width--;
	map->heigth = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			check_line_width(line, map->width, fd);
			map->heigth++;
		}
	}
	close(fd);
}

t_map	*open_and_duplicate(char *map_file)
{
	t_map	*map;
	int		fd;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_map(map);
	fd = open(map_file, O_RDWR);
	if (fd < 0)
		return (free(map), NULL);
	get_map_size(map_file, map);
	map->area = malloc(sizeof(char *) * (map->heigth + 1));
	if (!map->area)
		return (NULL);
	i = -1;
	map->area[++i] = get_next_line(fd);
	while (map->area[i])
		map->area[++i] = get_next_line(fd);
	map->area[i] = NULL;
	close(fd);
	return (map);
}
