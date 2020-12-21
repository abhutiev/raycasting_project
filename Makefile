NAME	=	cub3D

SRCS	=	main.c \
            engine/engine.c \
            engine/calculations.c \
            engine/initialisations.c \
            engine/loops_and_hooks.c \
            engine/texture_capturing.c \
            engine/work_with_images.c \
            engine/raycasting.c \
            engine/rendering.c \
            engine/program_arguments_checking.c \
            engine/screenshot.c \
            parsing/color_parsing.c \
            parsing/config_parsing_utils.c \
            parsing/free_parsed.c \
            parsing/map_parsing.c \
            parsing/map_validation_00.c \
            parsing/map_validation_01.c \
            parsing/parsing.c \
            parsing/player_parsing.c \
            parsing/resolution_parsing.c \
            parsing/texture_parsing.c \
            utils/ft_atoi.c \
            utils/ft_isdigit.c \
            utils/ft_strdup.c \
            utils/ft_strdup_with_border.c \
            utils/ft_strlcpy.c \
            utils/ft_strlen.c \
            utils/ft_strncmp.c \
            utils/get_next_line.c \
            utils/ft_bzero.c \

CC		=	gcc

CFLAFS	=	-Wall -Wextra -Werror

INCDIR	=	includes/

INC     =   $(addprefix ${INCDIR}, cub3d.h \
            utils.h \
            mlx.h)

MLXLIB =   libmlx.dylib

LAUNCH  =   ./cub3D

MAP		=	maps/map.cub

GREEN	=	\033[0;32m

CYAN	=	\033[0;36m

MAGENTA	=	\033[0;35m

LGREEN	=	\033[1;32m

LRED	=	\033[1;31m

LBLUE	=	\033[1;34m

RM      =   rm -rf

all: ${NAME}

${NAME}: ${INC} ${SRCS} ${MLXLIB}
	@${CC} ${CFLAGS} ${MLXLIB} -o ${NAME} -I ${INCDIR} ${SRCS} -lmlx -framework OpenGL -framework Appkit
	@echo "${LBLUE}"${NAME}" succesfully compiled"

${MLXLIB}:
	@$(MAKE) -C ./minilibx
	@mv ./minilibx/${MLXLIB} ${MLXLIB}

bonus: re

clean:
	@echo "${CYAN}Nothing to delete${MAGENTA}"


fclean:
	@${RM} ${NAME}
	@${RM} ${MLXLIB}
	@echo "${LRED}Every created file succesfully deleted"

re: fclean all

.PHONY: all clean fclean re