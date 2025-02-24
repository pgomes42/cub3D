# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgomes <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 09:44:09 by pgomes            #+#    #+#              #
#    Updated: 2025/02/11 13:16:50 by pgomes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  				= cub3D
CC					= cc

RM					= rm -rf

FLAGS				= -Wall -Wextra -Werror -g
LFLAGS      		= -lft -lmlx -lmlx_Linux -lX11 -lXext -lm
INCLUDES 			= -Iincludes -I$(LIBFT_PATH)/includes

MLX_PATH    		= lib/minilibx-linux
LIBFT_PATH  		= lib/libft
OBJ_DIR				= obj
PATH_LIBS 			= -L$(LIBFT_PATH) -L$(MLX_PATH)
SRCS      			=	src/cub3d.c\
						src/events/key_listener.c\
						src/reder/render.c\
						src/reder/render_utils.c\
						src/reder/texture.c\
						src/garbager_colletor.c\
						src/validation/validate_map.c\
						src/validation/validate_utils.c\
						src/validation/init_game.c\
						src/validation/init_utils.c
               
OBJS				= $(addprefix $(OBJ_DIR)/, $(SRCS:src/%.c=%.o)) 
             
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@${CC} ${FLAGS} -c $< -o $@ ${INCLUDES}

$(NAME): ${OBJS}
	@echo "$(GREEN)Compiling${CLR_RMV} of ${YELLOW}$(NAME) ${CLR_RMV}..."
	@make -C $(LIBFT_PATH) 
	@make -C $(MLX_PATH)
	@${CC} ${FLAGS} $(OBJS) -o $(NAME) $(PATH_LIBS) $(LFLAGS)
	@echo "$(GREEN)$(NAME) created${CLR_RMV} ✔️"
	
all: ${NAME} clean

clean:
	@${RM} ${OBJ_DIR} 
	@rm -rf $(NAME)
	@echo "$(RED)Deleting $(CYAN)$(NAME) ${CLR_RMV}objs ✔️"

fclean: clean
	@${RM} ${NAME} ${NAME_B}
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(MLX_PATH)
	@echo "$(RED)Deleting $(CYAN)$(NAME) ${CLR_RMV}binary ✔️"

re: fclean all

.PHONY: all clean fclean re
