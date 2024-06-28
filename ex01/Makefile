NAME = ex01

CC	= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC_PATH = srcs/
OBJ_PATH = objects/

SRC = main.cpp\
	Bureaucrat.cpp\

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.cpp=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

INC		= -I ./includes/

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
