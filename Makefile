# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuissa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 17:36:49 by asuissa           #+#    #+#              #
#    Updated: 2018/02/15 11:20:55 by asuissa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
.SUFFIXES:

# couleurs
RED = \x1B[31m
GREEN = \x1B[32m
YELLOW = \x1B[33m
BLUE = \x1B[34m
PURPLE = \x1B[35m
RESET = \033[0m
HEAD = \033[H\033[2J


CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
CPPFLAGS = -I $(INCLUDE)
OBJ = $(FILES:.c=.o)
CLIBFT = -L libft -lft
SRC_PATH = src/
INC_PATH = inc/
INCLUDE = $(addprefix $(INC_PATH), $(HEADER))
SRC = $(addprefix $(SRC_PATH), $(FILES))
FILES = \
			ft_apply_flags.c\
			ft_check.c\
			ft_dispatcher.c\
			ft_display_char.c\
			ft_display_numb.c\
			ft_flag_s.c\
			ft_flag_c.c\
			ft_flag_d.c\
			ft_flag_p_undefined.c\
			ft_flag_wu_wo.c\
			ft_flag_u_o.c\
			ft_flag_x.c\
			ft_handler.c\
			ft_printf.c\
			ft_buf.c\
			ft_transform_wchar.c\
			bonus.c\
			pf_ft_itoa_base.c\
			ft_atoi.c\
			ft_isdigit.c\
			ft_itoa_base.c\
			ft_strlen.c\
			ft_strsub.c\
			ft_wcharlen.c\
			ft_strlwr.c\
			ft_wstrlen.c\
			ft_wstrsub.c\
			ft_bzero.c\
			ft_memalloc.c\
			ft_memset.c\
			ft_strncat.c\
			pf_ft_strlen.c\
			ft_itoa.c\
			ft_strrev.c\
			ft_atoi_base.c\
			ft_strchr.c\
			ft_strclen.c

all : $(NAME)

$(NAME) : $(OBJ)
	@printf "\r\e[K[$(YELLOW)Make .o done$(RESET)]\n"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "[$(PURPLE)Make $(NAME) done$(RESET)]"

%.o: $(SRC_PATH)%.c
	@$(CC) -c $(CFLAGS) $< -o $@ $(CPPFLAGS)
	@printf "\r\e[K[$(YELLOW)Make $@ done$(RESET)]"

clean :
	@/bin/rm -f $(OBJ)
	@echo "[$(RED)Clean .o done$(RESET)]"

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "[$(RED)Clean $(NAME) done$(RESET)]"

re : fclean all

norme :
	@norminette $(SRC) $(INCLUDE)
