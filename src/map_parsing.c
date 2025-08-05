/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:24:31 by maleca            #+#    #+#             */
/*   Updated: 2025/08/05 23:49:47 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_map_content(char **map)
{
	t_point	point;
	int		E;
	int		C;
	int		P;

	point.y = 0;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x])
		{

		}

	}
	
}

static void	get_map_size(char **av, int map_size[2])
{
	char	*line;
	int		fd;

	map_size[0] = 0;
	map_size[1] = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error("failed loading map");
	line = get_next_line(fd);
	map_size[0] = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) != map_size[0])
		{
			free(line);
			close_error("uneven collumn count", fd);
		}
		map_size[1]++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
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
		error("failed loading the map");
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
		free_error("invalid map", map);
}
