# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 13:07:13 by fheidi            #+#    #+#              #
#    Updated: 2022/04/03 16:26:16 by fheidi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long
NAME_BNS 	= so_long_bonus

OPTFLAGS 	= -O2
CFLAGS 		= -Wall -Wextra -Werror

LIBFT 		=	./libft/libft.a
LIBFT_PATH 	= ./libft/

MLX 		= ./minilibx/libmlx.a
MLX_PATH 	= ./minilibx/

SRC_PATH 	= ./
SRC 		= so_long.c \
			sl_utils.c \
			map_parse.c \
			map_check.c \
			mem_free.c \
			sl_put_images.c \
			sl_drawing.c
SRC_BNS		= so_long_bonus.c \
			sl_utils_bonus.c \
			map_parse_bonus.c \
			map_check_bonus.c \
			mem_free_bonus.c \
			sl_put_images_bonus.c \
			sl_drawing_bonus.c
				
OBJ = $(patsubst %.c,%.o,$(addprefix $(SRC_PATH),$(SRC)))
D_FILES = $(patsubst %.c,%.d,$(addprefix $(SRC_PATH), $(SRC)))
OBJ_BNS = $(patsubst %.c,%.o,$(addprefix $(SRC_PATH),$(SRC_BNS)))
D_FILES_BNS = $(patsubst %.c,%.d,$(addprefix $(SRC_PATH), $(SRC_BNS)))

all:	$(LIBFT) $(MLX) $(NAME)

$(LIBFT):		
		@echo "Compiling libft..."
		@make -s -C $(LIBFT_PATH)
		@echo "Libft is compliled"

$(MLX):		
		@echo "Compiling libmlx..."
		@make -s -C $(MLX_PATH)
		@echo "Libmlx is compliled"

$(NAME):	$(OBJ)
		@cc $(CFLAGS) $(OPTFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		@echo "Game is ready to play!"

bonus:	$(OBJ_BNS)
		@make -C $(MLX_PATH) clean
		@cc $(CFLAGS) $(OPTFLAGS) $(OBJ_BNS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BNS)
		@echo "BONUS Game is ready to play!"

%.o: %.c
		@cc $(CFLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean: 
		@make -C $(LIBFT_PATH) clean
		@make -C $(MLX_PATH) clean
		@rm -f $(OBJ) $(D_FILES)
		@rm -f $(OBJ_BNS) $(D_FILES_BNS)
		@echo "OBJS and DEPS were deleted"

fclean:	clean
		@make -C $(LIBFT_PATH) fclean
		@rm -f $(NAME)
		@rm -f $(NAME_BNS)
		@echo "All clean"

re:	fclean all

.PHONY: all clean fclean re
