NAME	=	cub3D1

SRCDIR	=	./srcs/

PARSSRCDIR	=	./srcs/parsing/

PARSSRCS	=	$(addprefix ${PARSSRCDIR}, config_parsing.c \
			map_parsing.c \
			) \
			srcs/drawing_map.c
			
CC		=	gcc

CFLAFS	=	-Wall -Wextra -Werror

INCDIR	=	includes/

UTILLIB	=	srcs/utils.a

MAP		=	map.cub

all:
	gcc -g   -I./includes/ -o ${NAME} engine/*.c parsing/*c main.c libmlx.dylib -framework OpenGL -framework AppKit utils/*c && ./${NAME} maps/map.cub
#	${CC} ${CFLAGS} -g -o ${NAME} -I ${INCDIR} ${PARSSRCS} engine/*.c srcs/main.c ${UTILLIB} ${SRCDIR}libmlx.a -framework OpenGL -framework Appkit
#	./${NAME} ${MAP}

re: fclean all

fclean:
	rm cub3D
