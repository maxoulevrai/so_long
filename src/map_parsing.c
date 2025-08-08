/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:24:31 by maleca            #+#    #+#             */
/*   Updated: 2025/08/08 23:12:33 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_map(t_map *map)
{
	map->area = NULL;
	map->heigth = 0;
	map->width = 0;
	map->c_count = 0;
	map->e_pos.x = 0;
	map->e_pos.y = 0;
	map->p_pos.x = 0;
	map->p_pos.y = 0;
}

static int	check_ext(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i -= 5;
	if (!ft_strcmp(&str[i], ".ber"))
		return (0);
	return (1);
}

static void	get_map_content(t_map *map, int map_content[2])
{
	t_point	point;

	map_content[0] = 0;
	map_content[1] = 0;
	point.y = 0;
	while (map->area[point.y])
	{
		point.x = 0;
		while (map->area[point.y][point.x])
		{
			if (map->area[point.y][point.x] == 'C')
				map->c_count += 1;
			if (map->area[point.y][point.x] == 'E')
			{
				map_content[0] += 1;
			}
			if (map->area[point.y][point.x] == 'P')
				map_content[1] += 1;
			point.x++;
		}
		point.y++;
	}
	if (map->c_count < 1 || map_content[0] != 1 || map_content[1] != 1)
		print_free_error("invalid map components count", map);
}

static void	get_map_size(char **av, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("failed loading the map");
	line = get_next_line(fd);
	map->width = ft_strlen(line);
	if (line[map->width] == '\n')
		map->width -= 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if ()
		if (ft_strlen(line) != map->width) // probleme size quand \n present
		{
			free(line);
			print_close_error("unconsistant collumn count", fd);
		}
		map->heigth++;
	}
	free(line);
	close(fd);
}

t_map	*open_and_duplicate(char **av)
{
	t_map	*map;
	int		fd;
	int		i;
	
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_map(map);
	fd = open(av[1], O_RDWR);
	if (fd < 0)
		print_error("failed loading the map");
	get_map_size(av, map);
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

t_map	*parse(char **av)
{
	t_map	*map;
	int		map_content[2];
	
	// map = NULL;
	// init_map(map);
	map = open_and_duplicate(av);
	map_content[0] = 0;
	map_content[1] = 0;
	if (!check_ext(av[1]))
		print_free_error("invalid map", map);
	if (map->heigth == map->width)
		print_free_error("map is not rectangular", map);
	if (!is_map_enclosed(map))
		print_free_error("map is not enclosed properly", map);
	if (!is_char_valid(map))
		print_free_error("unrecognized char in map", map);
	get_map_content(map, map_content);
	if (!is_map_solvable(map, map_content))
		print_free_error("map is not solvable", map);
	return (map);
}
