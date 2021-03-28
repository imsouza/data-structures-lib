PROJECT = dslib

SRC			=	$(wildcard *.c)

OBJS		=	$(patsubst %.c, %.o, $(SRC))

CC			=	gcc

LIBS		=	-lm
 
C_FLAGS =		-O2		\
						-Werror		\
						-Wextra		\
						-Wno-sign-compare			\
						-Wno-unused-parameter	\
						-Wno-unused-variable	\
						-Wshadow

.PHONY: all

all: $(OBJS)
	@echo Creating executable file: $@
	$(CC) $(OBJS) $(LIBS) -o $(PROJECT)

%.o: %.c
	@echo Compiling object file: $@
	$(CC) $(C_FLAGS) -c $(SRC)

clean:
	rm -rf $(OBJS) $(PROJECT)

run: $(PROJECT)
	./$(PROJECT)

memcheck: $(PROJECT)
	valgrind --tool=memcheck --leak-check=full ./$(PROJECT)