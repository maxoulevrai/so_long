/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:02:30 by maleca            #+#    #+#             */
/*   Updated: 2025/08/06 23:42:44 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>
# include "mlx/mlx.h"
# include "lib/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int 	endian;
}			t_data;

typedef struct s_point {
	int	x;
	int	y;
}				t_point;


int		main(int ac, char **av);
void	so_long(char **av);

char	**parse(char **av);
char	**open_and_duplicate(char **av);
int		is_map_enclosed(char **map,int map_size[2]);
int		is_map_solvable(char **map, int map_content[3], int map_size[2]);

void	print_error(char *err_msg);
void	print_close_error(char *err_msg, int fd);
void	print_free_error(char *err_msg, char **map);

void	print_tab(char **zone);

#endif