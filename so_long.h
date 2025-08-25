/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:02:30 by maleca            #+#    #+#             */
/*   Updated: 2025/08/25 16:19:52 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>
# include <errno.h>
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

# define WALL_XPM		"sprites/wall.xpm"
# define FLOOR_XPM		"sprites/floor.xpm"
# define OBJ_XPM		"sprites/obj.xpm"
# define PLAYER_XPM		"sprites/player.xpm"
# define OPEN_DOOR_XPM	"sprites/open_door.xpm"
# define CLOSED_DOOR_XPM	"sprites/closed_door.xpm"

typedef struct s_point {
	int				x;
	int				y;
}				t_point;

typedef struct s_map
{
	char			**area;
	int				heigth;
	int				width;
	int				moves;
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
	void			*closed_door_img;
	void			*open_door_img;
	struct s_map	*map;
}				t_vars;

int		main(int ac, char **av);

// Parsing
t_map	*parse(char *map_file);
t_map	*open_and_duplicate(char *map_file);
int		check_ext(char *str);
int		is_map_enclosed(t_map *area);
int		is_char_valid(t_map *area);
int		is_map_solvable(t_map *area, int map_content[2]);
void	init_map(t_map *map);
void	init_vars(t_vars *vars);
void	get_map_content(t_map *map, int map_content[2]);

void	load_map(t_vars *vars);
void	load_sprites(t_vars *vars);
int		is_valid(t_map *map, int new_pos_y, int new_pos_x);
int		key_press_hdl(int keycode, t_vars *vars);
void	update_display(t_vars *vars, t_point new_pos);
int		close_win(t_vars *vars);

void	print_error(char *err_msg);
void	close_fd_error(char *err_msg, int fd);
void	free_map_error(char *err_msg, t_map *map);
void	free_vars_error(char *err_msg, t_vars *vars);
void	destroy_img(t_vars *vars);

#endif