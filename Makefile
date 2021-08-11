# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igearhea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 16:20:44 by igearhea          #+#    #+#              #
#    Updated: 2020/12/28 16:20:50 by igearhea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libftprintf.a

GCC =			gcc

CFLAGS =		-Wall -Wextra -Werror

RM =			rm -rf

LIBSRCS =		ft_atoi.c\
				ft_get_num_length.c\
				ft_itoa.c\
				ft_utoa.c\
				ft_min.c\
				ft_max.c\
				ft_printf.c\
				ft_putchar_fd.c\
				ft_putstrn.c\
				ft_strlen.c\
				ft_substr.c\
				new_printf.c\
				get_hex_string.c\
				get_big_hex_string.c\
				./parse/parse.c\
				./parse/parse_width.c\
				./parse/parse_prec.c\
				./process/flg_big_x.c\
				./process/flg_c.c\
				./process/flg_di.c\
				./process/flg_di_zeros.c\
				./process/get_long_hex_string.c\
				./process/flg_p.c\
				./process/flg_s.c\
				./process/flg_small_x.c\
				./process/flg_u.c\
				./process/flg_per.c\
				./process/process.c\
				./process/operate_prec.c

OBJS =			$(LIBSRCS:.c=.o)

ARRC =			ar rc

.c.o:
				$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o) -I .

$(NAME):		$(OBJS)
				$(ARRC) $(NAME) $(OBJS)
				ranlib $(NAME)

all:			$(NAME)

clean:			
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re