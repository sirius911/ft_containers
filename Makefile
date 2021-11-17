# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 13:25:45 by clorin            #+#    #+#              #
#    Updated: 2021/11/15 07:55:42 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= ft_containers 	

CC		:= clang++

CFLAGS	+= -Wall -Wextra -Werror -std=c++98

SRCS_DIR = srcs/

OBJS_DIR = objs/

SRCS	= main.cpp

OBJS	= $(SRCS:.cpp=.o)

OBJS	:= ${addprefix ${OBJS_DIR}, ${OBJS}}

${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp
		mkdir -p ${@D}
		$(CC) $(FLAGS) -c $< -o $@

all:	${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:		
			@echo "Cleaning: ${OBJS}"
			@rm -rf ${OBJS_DIR}

fclean:		clean
			@rm -rf ${NAME}
			@echo "\033[0mdelete "${NAME}"... \033[32mok\033[0m"

re:			fclean all

run:		fclean all
			./$(NAME)

.phony: all clean fclean re