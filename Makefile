NAME	=	cub3D

INCDIR	=	./includes/

INC     =   $(addprefix ${INCDIR}, \
			cub3d.h \
            utils.h \
            mlx.h)

ENGDIR	=	./engine/

ENGINE	=	$(addprefix ${ENGDIR}, \
			engine.c \
			calculations.c \
			initialisations.c \
			loops_and_hooks.c \
			texture_capturing.c \
			work_with_images.c \
			raycasting.c \
			rendering.c \
			program_arguments_checking.c \
			sprite_calculation_and_rendering.c \
			sprite_utils.c \
			screenshot.c )

PARSDIR	=	./parsing/

PARSING	=	$(addprefix ${PARSDIR}, \
			color_parsing.c \
			sprite_parsing.c \
			config_parsing_utils.c \
			free_parsed.c \
			map_parsing.c \
			map_validation_00.c \
			map_validation_01.c \
			parsing.c \
			player_parsing.c \
			resolution_parsing.c \
			texture_parsing.c )

UTILDIR	=	./utils/

UTILS	=	$(addprefix ${UTILDIR}, \
			ft_atoi.c \
			ft_isdigit.c \
			ft_strdup.c \
			ft_strdup_with_border.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			get_next_line.c \
			ft_bzero.c )

SRCDIR	=	./srcs/

SRCS	=	$(addprefix ${SRCDIR}, main.c \
			${ENGINE} \
			${PARSING} \
			${UTILS})

CC		=	gcc

CFLAFS	=	-g -Wall -Wextra -Werror

MLXDIR	=	./minilibx

MLXLIB	=	libmlx.dylib

LAUNCH	=	./cub3D

MAP		=	maps/map.cub

SAVE	=	--save

BMP		=	cub3D.bmp

GREEN	=	\033[0;32m

CYAN	=	\033[0;36m

MAGENTA	=	\033[0;35m

LGREEN	=	\033[1;32m

FGREEN	=	\033[1;32m

BLUE	=	\033[1;31m

PINK	=	\033[0;34m

RM      =   rm -rf

COMPILATION_MSG	=	"${CYAN}"${NAME}" succesfully compiled"

LIBRARY_MSG		=	"${GREEN}MLX Library succesfully compiled"

BONUS_MSG	=	"${FGREEN}Bonus part succesfully compiled"

LAUNCH_MSG	=	"${MAGENTA}CUB3D launched. You're welcome!"

STOP_MSG	=	"${PINK}Bye! Hope, you had fun!"

SCREEN_MSG	=	"${PINK}Screenshot is saved!"

CLEAN_MSG	=	"${BLUE}MLX Library succesfully deleted"

FCLEAN_MSG	=	"${BLUE}Every created file succesfully deleted"

.PHONY: all clean fclean re bonus screen launch

all: ${NAME}

${NAME}: ${INC} ${SRCS} ${MLXLIB}
	@${CC} ${CFLAGS} ${MLXLIB} -o ${NAME} -I ${INCDIR} ${SRCS} -lmlx -framework OpenGL -framework Appkit
	@echo ${COMPILATION_MSG}

${MLXLIB}:
	@$(MAKE) -C ${MLXDIR}
	@mv ${MLXDIR}/${MLXLIB} ${MLXLIB}
	@echo ${LIBRARY_MSG}

bonus: re
	@echo ${BONUS_MSG}

launch: ${NAME}
	@echo ${LAUNCH_MSG}
	@./${NAME} ${MAP}
	@echo ${STOP_MSG}

screen: all
	@./${NAME} ${MAP} ${SAVE}
	@echo ${SCREEN_MSG}

clean:
	@${RM} ${BMP}
	@echo ${CLEAN_MSG}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${MLXLIB}
	@echo ${FCLEAN_MSG}

re: fclean all