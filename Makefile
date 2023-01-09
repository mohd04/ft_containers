VEC_SRCS = vec_test.cpp

MAP_SRCS = map_test.cpp

STACK_SRCS = stack_test.cpp

VEC_NAME = $(addprefix $(VEC_DIR), ${VEC_SRCS})

MAP_NAME = $(addprefix $(MAP_DIR), ${MAP_SRCS})

STACK_NAME = $(addprefix $(STACK_DIR), ${STACK_SRCS})

VEC_DIR = vector/

MAP_DIR = map/

STACK_DIR = stack/

VEC_OBJ_NAME = $(addprefix $(OBJ_DIR), ${VEC_NAME:%.cpp=%.o})

MAP_OBJ_NAME = $(addprefix $(OBJ_DIR), ${MAP_NAME:%.cpp=%.o})

STACK_OBJ_NAME = $(addprefix $(OBJ_DIR), ${STACK_NAME:%.cpp=%.o})

OBJ_DIR = objs/

CXX = c++ -g

CXX_FLAGS = -Wall -Wextra -Werror -std=c++98

VNAME = ft_vec

MNAME = ft_map

SNAME = ft_stack

NAME = ft

all:  $(NAME)

$(NAME) : objs_tree $(VNAME) $(MNAME) $(SNAME)

$(VNAME): objs_tree $(VEC_OBJ_NAME)
	$(CXX) ${CXX_FLAGS} $(VEC_OBJ_NAME) -o $(VNAME)

$(MNAME): objs_tree $(MAP_OBJ_NAME)
	$(CXX) ${CXX_FLAGS} $(MAP_OBJ_NAME) -o $(MNAME)

$(SNAME): objs_tree $(STACK_OBJ_NAME)
	$(CXX) ${CXX_FLAGS} $(STACK_OBJ_NAME) -o $(SNAME)

objs_tree:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(VEC_DIR)
	mkdir -p $(OBJ_DIR)$(MAP_DIR)
	mkdir -p $(OBJ_DIR)$(STACK_DIR)

$(OBJ_DIR)$(VEC_DIR)%.o : $(SRC_DIR)$(VEC_DIR)%.cpp
	$(CXX) ${CXX_FLAGS} -c $< -o $@

$(OBJ_DIR)$(MAP_DIR)%.o : $(SRC_DIR)$(MAP_DIR)%.cpp
	$(CXX) ${CXX_FLAGS} -c $< -o $@

$(OBJ_DIR)$(STACK_DIR)%.o : $(SRC_DIR)$(STACK_DIR)%.cpp
	$(CXX) ${CXX_FLAGS} -c $< -o $@

clean_o_files:
	rm -rf $(OBJ_DIR)

clean_vexec_file:
	rm -rf $(VNAME)

clean_mexec_file:
	rm -rf $(MNAME)

clean_sexec_file:
	rm -rf $(SNAME)

clean_exec_file: clean_vexec_file clean_mexec_file clean_sexec_file

clean: n_o_files

fclean: clean_o_files clean_exec_file

rev: clean_o_files clean_vexec_file $(VNAME)

rem: clean_o_files clean_mexec_file $(MNAME)

res:  clean_o_files clean_sexec_file $(SNAME)

re: clean_o_files clean_exec_file $(NAME)

.PHONY: all clean fclean re
