NAME := FragTrap
CXX  := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98
SRC  := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ  := $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o : %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re