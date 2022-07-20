NAME = containers

CPP = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

INCL_MAP = -I $(addprefix ./map/, avlTree.hpp)

SRCS_MAP = $(addprefix ./map/, map_test.cpp)

OBJS_MAP = ${SRCS_MAP:.cpp=.o}

RM = rm -f

$(NAME): $(OBJS_MAP)
	$(CPP) $(CFLAGS) $(OBJS_MAP) -o $(NAME)

all: $(NAME)

map: $(OBJS_MAP)
	$(CPP) $(CFLAGS) $(OBJS_MAP) -o $(NAME)

clean:
		$(RM) $(OBJS_MAP)

fclean: clean
		$(RM) $(NAME)

re: fclean all
