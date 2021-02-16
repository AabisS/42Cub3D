
SRCS = ./srcs/draw_wall_basic.c \
       ./srcs/exit.c \
       ./srcs/fill_structure.c \
	   ./srcs/fill_structure2.c \
       ./srcs/get_next_line.c \
       ./srcs/get_next_line_utils.c \
       ./srcs/init.c \
       ./srcs/init_storage.c \
       ./srcs/key.c \
       ./srcs/main.c \
       ./srcs/parce.c \
       ./srcs/player_move.c \
       ./srcs/raycasting.c \
       ./srcs/utils.c \
       ./srcs/error_manage.c \
       ./srcs/texture.c \
       ./srcs/draw_wall_text.c \
       ./srcs/sprite.c \
	   ./srcs/savepart.c \
	   ./srcs/parce2.c \
	   ./srcs/utils2.c \

OBJS = ${SRCS:%.c=%.o}
NAME = Cub3D
HEADER = cub3d.h 
HEADER2 = ./libft/libft.h 
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -c -I.${HEADER}
FT		= ./libft/
FT_INC	= ./libft/*.o
FT_INC2 = ./mlx/libmlx.a
FT_LNK	= ./libft/libft.a

all : lib ${NAME} 

clean : 
		rm -f ${OBJS} $(FT_INC)

fclean : clean
		 rm -f ${NAME} $(FT_LNK)

lib :
	      make -C $(FT)

$(NAME) : ${OBJS} ${HEADER2} $(HEADER) $(FT_LNK)
		  gcc -o ${NAME} ${OBJS} $(FT_INC) $(FT_INC2) -L/usr/include/../lib -lXext -lX11 -lm -lbsd

re : fclean all

.PHONY : all clean re fclean