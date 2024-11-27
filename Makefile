# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtassel <dtassel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 14:36:19 by dtassel           #+#    #+#              #
#    Updated: 2022/11/14 12:45:39 by dtassel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
SRCS		=	main.c \
				srcs/check_arg.c \
				srcs/map.c \
				srcs/movement.c \
				srcs/action.c \
				srcs/check_map.c \
				srcs/path.c \
				srcs/check_map_bis.c \

OBJS		=	$(SRCS:%.c=%.o)

# /*------------LIBFT----------------*/
LIBFT		=	libft/libft.a

# /*------------GNL------------------*/
GNL_DIR		=	./get_next_line/
GNL			=	get_next_line.c \
				get_next_line_utils.c \

GNL_OBJS 	= 	${addprefix ${GNL_DIR}, ${GNL:.c=.o}}

# /*------------PRINTF---------------*/
PRINTF_DIR	=	./printf/
PRINTF		=	ft_printf.c \
				ft_pt_ptr.c \
				ft_ptchar.c \
				ft_pthexal.c \
				ft_pthexat.c \
				ft_ptnbr.c \
				ft_ptstr.c \
				ft_ptunsigned.c \

PRINTF_OBJS = 	${addprefix ${PRINTF_DIR}, ${PRINTF:.c=.o}}

# /*------------COMPIL---------------*/
CFLAGS		=	-Wall -Wextra -Werror
CC			=	gcc
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit

RM			=	rm -f

# /*----------------------------BONUS------------------------------*/
BONUS		=	so_long_bonus
BONUS_SRCS	=	main_bonus.c \
				srcs/bonus/check_arg_bonus.c \
				srcs/bonus/map_bonus.c \
				srcs/bonus/movement_bonus.c \
				srcs/bonus/action_bonus.c \
				srcs/bonus/animation_bonus.c \
				srcs/bonus/check_map_bonus.c \
				srcs/bonus/path_bonus.c \
				srcs/bonus/check_map_bis_bonus.c \

B_OBJS		=	$(BONUS_SRCS:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
			make -C libft	
			make clean -C libft
			$(CC) $(SRCS) $(LIBFT) $(GNL_OBJS) $(PRINTF_OBJS) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

$(BONUS):	$(B_OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
			make -C libft
			make clean -C libft
			$(CC) $(BONUS_SRCS) $(LIBFT) $(GNL_OBJS) $(PRINTF_OBJS) $(MLXFLAGS) $(CFLAGS) -o $(BONUS)

%o:			%.c
			$(CC) $(CFLAGS) -c $< -o $@

bonus:		$(BONUS)

clean:
			$(RM) $(OBJS)
			$(RM) $(B_OBJS)
			$(RM) $(PRINTF_OBJS)
			$(RM) $(GNL_OBJS)

fclean:		clean
			$(RM) $(NAME) $(BONUS)
			$(RM) *.out
			make fclean -C libft/

re:			fclean all bonus

.PHONY:		all clean fclean bonus re