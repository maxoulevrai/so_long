/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:02:30 by maleca            #+#    #+#             */
/*   Updated: 2025/08/15 20:44:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>
# include "mlx/mlx.h"
# include "lib/libft.h"

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define KEY_ESC		65307

# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_UP			65362
# define KEY_DOWN		65364

# define WALL			'1'
# define FLOOR			'0'
# define BALL			'C'
# define PLAYER			'P'
# define MAP_EXIT		'E'

# define WALL_XMP		"sprites/wall.xpm"
# define FLOOR_XMP		"sprites/floor.xpm"
# define BALL_XMP		"sprites/ball.xpm"
# define PLAYER_XMP		"sprites/player.xpm"
# define MAP_EXIT_XMP	"sprites/map_exit.xpm"

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int 	endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;	
}				t_vars;

typedef struct s_map
{
	char	**area;
	size_t	heigth;
	size_t	width;
	int		c_count;
}				t_map;

int		main(int ac, char **av);
void	so_long(char **av);

t_map	*parse(char **av);
t_map	*open_and_duplicate(char **av);
int		is_char_valid(t_map *area);
int		is_map_enclosed(t_map *area);
int		is_map_solvable(t_map *area, int map_content[2], t_point *p_pos);
	
void	free_map(t_map *map);
void	print_error(char *err_msg);
void	print_close_error(char *err_msg, int fd);
void	print_free_error(char *err_msg, t_map *area);

void	print_tab(char **zone);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif