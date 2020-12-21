/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:20:38 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/19 17:47:12 by gdoge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
** Including of headers:
*/

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <errno.h>
# include "mlx.h"
# include "utils.h"

/*
** Key define:
*/

# define ESCAPE				53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_LEFT			123
# define KEY_RIGHT			124

/*
** Events and mask for X11 define:
*/

# define KEYPRESS_EVENT			2
# define KEYPRESS_MASK			1L << 0
# define KEYRELEASE_EVENT		3
# define KEYRELEASE_MASK		1L << 1
# define DESTROY_NOTIFY_EVENT	17
# define NO_EVENT_MASK			0L

/*
** Gameplay define:
*/

# define MOVE_SPEED		0.15
# define VIEW_ANGLE		66
# define MOVE_CHECK		0.3

/*
** Explaining define:
*/

# define RAY_NOT_CRASHED_INTO_WALL	1
# define FIRST_SECTOR	1
# define SECOND_SECTOR	2
# define THIRD_SECTOR	3
# define FOURTH_SECTOR	4

/*
** Math define:
*/

# define COS_ROTATE_SPEED	0.99619469809
# define SIN_ROTATE_SPEED	0.08715574274
# define ABS(x) ((x < 0) ? -x : x)

/*
** Necessary structs:
*/

typedef struct	s_player
{
	double		x_coord;
	double		y_coord;
	char		direction;
	double		x_direction;
	double		y_direction;
}				t_player;

typedef struct	s_config
{
	int			x_resolution;
	int			y_resolution;
	char		*path_north;
	char		*path_south;
	char		*path_west;
	char		*path_east;
	char		*path_sprite;
	int			floor_color[3];
	int			ceiling_color[3];
	uint32_t 	rgb_ceiling;
	uint32_t 	rgb_floor;
	int			fd;
	size_t		count;
	int			i;
	size_t		number_of_strings;
	size_t		longest_string;
	char		*buffer;

}				t_config;

typedef struct	s_key
{
	int8_t		forward;
	int8_t		backward;
	int8_t		left;
	int8_t		right;
	int8_t		clockwise;
	int8_t		anticlockwise;
}				t_key;

typedef struct	s_map
{
	char		**map;
}				t_map;

typedef struct	s_texture
{
	void		*instance;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	void 		*address;
}				t_texture;

typedef struct	s_textures
{
	t_texture	north_wall;
	t_texture	south_wall;
	t_texture	east_wall;
	t_texture	west_wall;
	t_texture	sprite;
}				t_textures;

typedef struct	s_image
{
	void		*snapshot;
	void		*image_adress;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_pattern
{
	int 		x_coord;
	int 		y_coord;
	int 		width;
	int 		height;
	uint32_t 	color;
	double 		offset;
	double 		coordinate;

}				t_pattern;

typedef struct	s_ray
{
	double		camera_plane;
	int			x_coord;
	int			y_coord;
	double		x_direction;
	double		y_direction;
	double		x_delta_step;
	double		y_delta_step;
	double		x_shift;
	double		y_shift;
	double		x_step;
	double		y_step;
	double		ordinate;
	double		abscissa;
	int8_t		sector;
	double		length;
}				t_ray;

typedef struct	s_wall
{
	double		height;
	double		moulding;
	double		plinth;
	double		coordinate;
}				t_wall;

typedef struct	s_screen
{
	int			x;
	int			y;
}				t_screen;

typedef struct	s_sprite
{

}				t_sprite;

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	t_screen	screen;
	t_wall		wall;
	t_textures	textures;
	t_pattern 	texture;
	t_player	player;
	t_map		map;
	t_key		key;
	t_ray		ray;
	t_image		image;
	t_config	config;
}				t_all;

/*
** ########################################################################
** ############################# ENGINE ###################################
** ########################################################################
** ########################## Folder: engine ##############################
** ########################################################################
*/

/*
** File: loops_and_hooks.c
*/

void			combined_loop(t_all *all);

/*
** File: work_with_images.c
*/

void			create_image(t_all *all);
void            put_to_image(t_all *all, unsigned int color);

/*
** File: engine.c
*/

int 			engine(t_all *all);

/*
** File: texture_capturing.c
*/

void			get_textures_address(t_all *all);
void			textures_capturing(t_all *all);
void		 	get_color_from_texture(t_all *all, t_texture texture);

/*
** File: ray_casting.c
*/

void 			ray_casting(t_all *all);
void 			ray_to_start(t_all *all);
void 			wall_collide(t_all *all);

/*
** File: calculations.c
*/

void 			calculate_wall_parameters(t_all *all);
void 			calculate_ray_length(t_all *all);
void 			camera_plane_shift(t_all *all);
void			delta_step_calculating(t_all *all);
void 			get_width(t_all *all);

/*
** File: initialisations.c
*/

void			init_some_stuff(t_all *all);

/*
** File: rendering.c
*/

void 			rendering(t_all *all);

/*
** File: rendering.c
*/

void 			sprite_calculations_and_rendering(t_all *all);

/*
** ########################################################################
** ########################## CONFIG PARSING ##############################
** ########################################################################
** ######################### Folder: parsing ##############################
** ########################################################################
*/

/*
** File: texture_parsing.c
*/

t_config		north_texture_parsing(char *string_with_path, t_config config);
t_config		south_texture_parsing(char *string_with_path, t_config config);
t_config		west_texture_parsing(char *string_with_path, t_config config);
t_config		east_texture_parsing(char *string_with_path, t_config config);
t_config		sprite_texture_parsing(char *string_with_path, t_config config);

/*
** File: color_parsing.c
*/

void			color_validation_check(t_config config);
t_config		ceiling_color_parsing(char *string_with_color, t_config config);
t_config		floor_color_parsing(char *string_with_color, t_config config);

/*
** File: resolution_parsing.c
*/

t_config		resolution_parsing(char *string_to_parse, t_config config);

/*
** File: config_parsing_utils.c
*/

int				map_started(char *string);
t_config		config_to_zero(int fd);
t_config		fd_validation(char *config_file);
t_config		get_number_of_strings(t_config config);

/*
** File: parsing.c
*/

t_all			get_all_information_from_config(char *filename);

/*
** File: free_parsed.c
*/

void			free_way_to_textures(t_all *all);

/*
** ########################################################################
** ########################### MAP PARSING ################################
** ########################################################################
** ######################### Folder: parsing ##############################
** ########################################################################
*/

/*
** File: map_parsing.c
*/

char			**map_parsing(t_config config, char *filename);

/*
** File: map_validation_00.c
*/

void			check_number_of_players(char **map);
void			check_unwanted_symbols(char **map);
void			check_gap(t_config config);

/*
** File: map_validation_01.c
*/

void			map_validation(char **map, t_config config);
void			check_if_closed(char **map, t_config config);

/*
** File: player_parsing.c
*/

void			player_parsing(char **map, t_all *all);

#endif
