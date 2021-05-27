NAME     := containers_test

SRCS     :=	tests/List.cpp \
			tests/Vector.cpp \
			tests/Queue.cpp \
			tests/Stack.cpp \
			tests/Map.cpp \
			tests/main.cpp

OBJS     := $(SRCS:.cpp=.o)

CPP      := clang++
CPPFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(OBJS) -o $@
	@echo Done!

%.o: %.cpp
	@echo Compiling $<...
	@$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed!"

re:     fclean all

test:	re
		./containers_test

.PHONY: all clean fclean re test