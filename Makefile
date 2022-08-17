NAME =	cub3D

SRC_DIR =	srcs
OBJ_DIR =	objs

VPATH =	srcs/ get_next_line/ srcs_bonus/

SRCS =	main.c\
		keys.c\
		utils.c\
		errors.c\
		parser.c\
		ray_cast.c\
		key_hooks.c\
		parse_map.c\
		parse_utils.c\
		parse_errors.c\
		cubes_drawer.c\
		get_next_line.c\
		color_ceiling.c\
		parse_elements.c\
		get_next_line_utils.c

SRCS_BONUS =	main_bonus.c\
				keys_bonus.c\
				utils_bonus.c\
				mouse_bonus.c\
				errors_bonus.c\
				parser_bonus.c\
				minimap_bonus.c\
				ray_cast_bonus.c\
				key_hooks_bonus.c\
				parse_map_bonus.c\
				animation_bonus.c\
				parse_utils_bonus.c\
				cubes_drawer_bonus.c\
				handle_doors_bonus.c\
				parse_errors_bonus.c\
				color_ceiling_bonus.c\
				minimap_utils_bonus.c\
				parse_elements_bonus.c\
				get_next_line.c\
				get_next_line_utils.c

OBJS_LIST =	$(SRCS:.c=.o)
OBJS :=	$(addprefix $(OBJ_DIR)/,$(OBJS_LIST))

OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_B :=	$(addprefix $(OBJ_DIR)/,$(OBJS_BONUS))

LIBFT = libft/libft.a

CFLAGS =	-Wall -Wextra -Werror

CPPFLAGS =	-I includes/ -I libft/ -I get_next_line/ -MMD -MP

MLXFLAGS =	-I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(if $(findstring bonus, $(MAKECMDGOALS)),$(OBJS_B), $(OBJS)) $(LIBFT) 
	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR) :
	mkdir -p $@

$(LIBFT) : libft ;

bonus : $(NAME)

libft : 
	$(MAKE) -C libft/ bonus

clean :
	$(MAKE) -C libft clean
	rm -rf $(OBJS)
	rm -rf $(OBJS:.o=.d)
	rm -rf $(OBJS_B)
	rm -rf $(OBJS_B:.o=.d)
	rm -rf $(OBJ_DIR)

fclean : clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re libft bonus

-include $(OBJS:.o=.d)