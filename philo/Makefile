# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 15:41:01 by zlee              #+#    #+#              #
#    Updated: 2025/05/05 20:41:52 by zlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS =  -pthread -g3

# MEM_CHECK = -fsanitize=undefined -fsanitize=thread

INCLUDES = -Iincludes

SRCS = philo_utils.c \
	   philo_monitoring.c \
	   philo_set_forks.c \
	   philo_simulation.c \
	   philo_threads.c \
	   philo_init.c \
	   philo_main.c \
	   philo_utils_getter.c \
	   philo_utils_getter_ms.c \
	   philo_utils_getter_two.c \
	   philo_simulation_lonely_edition.c \
	   philo_simulation_pickup_forks.c \
	   philo_utils_setter.c \
	   philo_free.c \
	   philo_print.c \

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

re: fclean all

.PHONY : all clean fclean re
