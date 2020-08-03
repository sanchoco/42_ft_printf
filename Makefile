# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sancho <sancho@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/18 09:39:13 by sancho            #+#    #+#              #
#    Updated: 2020/06/15 13:33:39 by sancho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
HEADER = ./
SRC = ft_printf.c\
ft_unit.c\
ft_unit_d.c\
ft_unit_c.c\
ft_unit_u.c\
ft_unit_bx.c\
ft_unit_lx.c\
ft_unit_p.c\
ft_unit_s.c\
ft_unit_pct.c

OBJ = $(SRC:.c=.o)

.c.o :
	gcc -c $(CFLAGS) -I $(HEADER) $< -o $(<:.c=.o)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
re : fclean all

.PHONY : all clean fclean re
