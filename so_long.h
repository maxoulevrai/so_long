/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:02:30 by maleca            #+#    #+#             */
/*   Updated: 2025/08/20 20:21:32 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>
# include "mlx/mlx.h"
# include "lib/libft.h"

# define IMG_HEIGHT		64
# define IMG_WIDTH		64

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
# define OBJ			'C'
# define PLAYER			'P'
# define MAP_EXIT		'E'

# define WALL_XMP		"sprites/wall.xpm"
# define FLOOR_XMP		"sprites/floor.xpm"
# define OBJ_XMP		"sprites/obj.xpm"
# define PLAYER_XMP		"sprites/player.xpm"
# define MAP_EXIT_XMP	"sprites/map_exit.xpm"

typedef struct s_point {
	int				x;
	int				y;
}				t_point;

typedef struct s_map
{
	char			**area;
	int				heigth;
	int				width;
	int				c_count;
	t_point			p_pos;
	t_point			e_pos;
}				t_map;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	void			*wall_img;
	void			*floor_img;
	void			*obj_img;
	void			*player_img;
	void			*map_exit_img;
	struct s_map	*map;

}				t_vars;


int		main(int ac, char **av);

t_map	*parse(char **av);
t_map	*open_and_duplicate(char **av);
int		is_char_valid(t_map *area);
int		is_map_enclosed(t_map *area);
int		is_map_solvable(t_map *area, int map_content[2]);

void	load_map(t_vars *vars);
void	load_sprites(t_vars *vars);

void	print_error(char *err_msg);
void	close_fd_error(char *err_msg, int fd);
void	free_map_error(char *err_msg, t_map *map);
void	free_vars_error(char *err_msg, t_vars *vars);
void	destroy_img(t_vars *vars);

#endif