/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoge <gdoge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:20:38 by gdoge             #+#    #+#             */
/*   Updated: 2020/12/16 22:10:59 by gdoge            ###   ########.fr       */
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
# define KEY_DOWN			125
# define KEY_UP				126

/*
** Events and mask for X11 define:
*/

# define KEYPRESS_EVENT			2
# define KEYPRESS_MASK			1L << 0
# define KEYRELEASE_EVENT		3
# define KEYRELEASE_MASK		1L << 1
# define DESTROYNOTIFY_EVENT	17
# define NO_EVENT_MASK			0L

/*
** Gameplay define:
*/

# define MOVE_SPEED		0.0001
# define ROTATE_SPEED	0.01

/*
** Necessary structs:
*/

typedef struct	s_player
{
	float	x_coord;
	float	y_coord;
	float	angle;
	char	direction;
	float	step_cos;
	float	step_sin;
}				t_player;

typedef struct	s_config
{
	int		x_resolution;
	int		y_resolution;
	char	*path_north;
	char	*path_south;
	char	*path_west;
	char	*path_east;
	char	*path_sprite;
	int		floor_color[3];
	int		ceiling_color[3];
	int		fd;
	size_t	count;
	int		i;
	size_t	number_of_strings;
	size_t	longest_string;
	char	*buffer;
	int		validity;
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
	void		*address;
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
	void	*snapshot;
	void	*adress;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_ray
{
	float	camera_plane;
	float	x_coord;
	float	y_coord;
	float	x_direction;
	float	y_direction;

}				t_ray;

typedef struct s_all
{
	void		*mlx;
	void		*win;
	t_textures	textures;
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

/*
** File: action.c
*/

int				action(t_all *all);
void			player_movement(t_all *all);
void			player_changing_direction_of_looking(t_all *all);

/*
** File: wall_detections_00.c
*/

int8_t			wall_detection_x_forward(t_all *all);
int8_t			wall_detection_y_forward(t_all *all);
int8_t			wall_detection_x_backward(t_all *all);
int8_t			wall_detection_y_backward(t_all *all);

/*
** File: wall_detections_01.c
*/

int8_t			wall_detection_x_left(t_all *all);
int8_t			wall_detection_y_left(t_all *all);
int8_t			wall_detection_x_right(t_all *all);
int8_t			wall_detection_y_right(t_all *all);

/*
** File: texture_capturing.c
*/

void			get_textures_address(t_all *all);
void			textures_capturing(t_all *all);

/*
** File: work_with_rays.c
*/

void	rays_to_start(t_all *all);


/* 
** ########################################################################
** ################### Functions for config parsing #######################
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
t_config		config_parsing(t_config config);
t_config		config_validation(t_config config, void *mlx);
t_config		get_config(char *config_file, void *mlx);

/*
** File: free_parsed.c
*/

void			free_way_to_textures(t_all *all);
void			free_map(t_all *all);
void			free_everything(t_all *all);

/* 
** ########################################################################
** #################### Functions for map parsing #########################
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

t_player		player_parsing(char **map, t_player player);

#endif
