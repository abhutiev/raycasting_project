NAME	=	utils.a

HEADER	=	utils.h

SRC     =	ft_strlen.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isdigit.c \
			get_next_line.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_strdup_with_border.c \
			


OBJS	=	${SRC:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

GREEN	=	\033[0;32m

CYAN	=	\033[0;36m

MAGENTA	=	\033[0;35m

LGREEN	=	\033[1;32m

LYELLOW	=	\033[1;33m

LRED	=	\033[1;31m

LBLUE	=	\033[1;34m

.PHONY: all clean fclean re

all:	${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "${MAGENTA}Object file: ${LYELLOW}$@ ${GREEN}successfuly compiled"

${NAME}:	${OBJS} ${HEADER}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}
	@echo "${CYAN}Library ${NAME} succesfully compiled"
	@mv ${NAME} ../srcs
	@make clean

clean:
	@rm -f ${OBJS}
	@echo "${LRED}All object files were cleaned"

fclean:		clean
	@rm -f ${NAME}
	@echo "${LRED}Binary file was cleaned"
	@echo "${LGREEN}Everything is cleaned succesfully"

re:		fclean all
	@echo "${LBLUE}Library ${NAME} successfuly rebuilt"
