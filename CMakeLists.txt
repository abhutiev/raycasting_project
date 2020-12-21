cmake_minimum_required(VERSION 3.17)
project(cub3d C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Lmlx -lmlx -framework OpenGL -framework AppKit")
link_directories(./)
include_directories(./includes)

add_executable(cub3d
        engine/action.c
        engine/calculations.c
        engine/initialisations.c
        engine/loops_and_hooks.c
        engine/texture_capturing.c
        engine/work_with_images.c
        engine/raycasting.c
        engine/rendering.c
        ./libmlx.dylib
#        minilibx/font.c
#        minilibx/mlx_png.c
#        minilibx/mlx_rgb.c
#        minilibx/mlx_string_put.c
#        minilibx/mlx_xpm.c
        parsing/color_parsing.c
        parsing/config_parsing_utils.c
        parsing/free_parsed.c
        parsing/map_parsing.c
        parsing/map_validation_00.c
        parsing/map_validation_01.c
        parsing/parsing.c
        parsing/player_parsing.c
        parsing/resolution_parsing.c
        parsing/texture_parsing.c
        utils/ft_atoi.c
        utils/ft_isdigit.c
        utils/ft_strdup.c
        utils/ft_strdup_with_border.c
        utils/ft_strlcpy.c
        utils/ft_strlen.c
        utils/ft_strncmp.c
        utils/get_next_line.c
        utils/program_arguments_checking.c
        utils/get_color_from_texture.c
        main.c)
