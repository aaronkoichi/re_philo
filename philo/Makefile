# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 15:41:01 by zlee              #+#    #+#              #
#    Updated: 2025/04/09 17:45:39 by zlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -pthread

# MEM_CHECK = -fsanitize=address -fsanitize=undefined -fsanitize

INCLUDES = -Iincludes

SRCS = philo_utils.c \
	   philo_utils_two.c \
	   philo_main.c \
	   philo_set_forks.c \
	   philo_monitoring.c \
	   philo_simulation.c \
	   philo_threads.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MEM_CHECK) $^ -o $@

%.o : %.c
	$(CC) $(INCLUDES) $(CFLAGS) $(MEM_CHECK) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean re

.PHONY : all clean fclean re
