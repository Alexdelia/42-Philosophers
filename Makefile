# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/11/16 23:05:19 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	philo
CC = 	clang -Wall -Werror -Wextra
AR =	ar rcs
RM = 	rm -rf

FLAGS =	-pthread
#FLAGS += -O2
#FLAGS += -g
#FLAGS += -fsanitize=address
#FLAGS += -fsanitize=thread

# **************************************************************************** #

MAKEFLAGS += --silent

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #

SRCSPATH =	./srcs/
OBJSPATH =	./objs/
INC =		./includes/

SRCSNAME =	main.c \
			ft_arg.c \
			init.c \
			ft_run.c \
			utils.c

SRCS = $(addprefix $(SRCSPATH), $(SRCSNAME))
#SRCS = $(wildcard $(SRCS_PATH)**/*.c)
#SRCSNAME = $(notdir $(SRCS))

OBJSNAME = $(SRCSNAME:.c=.o)
OBJS = $(addprefix $(OBJSPATH), $(OBJSNAME))

# *************************************************************************** #

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(B)$(MAG)$(NAME) compiled$(D)"

$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@mkdir -p $(OBJSPATH) # 2> /dev/null || true
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

clean:
	@$(RM) $(OBJSNAME)
	@echo "$(B)Cleared.$(D)"


fclean:		clean
	@$(RM) $(OBJSPATH)
	@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re objs_dir

# **************************************************************************** #
