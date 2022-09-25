NAME = containers
NAME_VEC = vec
NAME_MAP = mapp

CPP = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

INCL_MAP = -I $(addprefix ./map/, avlTree.hpp)
INCL_VEC = -I $(addprefix ./vector/, vector.hpp)

SRCS_MAP = $(addprefix ./map/, map_test.cpp)
SRCS_VEC = $(addprefix ./vector/, vec_test.cpp)

OBJS_MAP = ${SRCS_MAP:.cpp=.o}
OBJS_VEC = ${SRCS_VEC:.cpp=.o}

RM = rm -f

$(NAME): $(OBJS_MAP) ${OBJS_VEC}
	$(CPP) $(CFLAGS) $(OBJS_MAP) $(OBJS_VEC) -o $(NAME)

all: $(NAME)

vector: $(OBJS_VEC)
	$(CPP) $(CFLAGS) $(OBJS_VEC) -o $(NAME_VEC)

map: $(OBJS_MAP)
	$(CPP) $(CFLAGS) $(OBJS_MAP) -o $(NAME_MAP)

clean:
		$(RM) $(OBJS_MAP) $(OBJS_VEC)

fclean: clean
		$(RM) $(NAME) $(NAME_MAP) $(NAME_VEC)

re: fclean all
