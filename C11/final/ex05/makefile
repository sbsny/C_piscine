CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
INCDIR = includes
TARGET = do-op
SRCS = $(SRCDIR)/main.c $(SRCDIR)/op.c $(SRCDIR)/validate.c $(SRCDIR)/atoi.c
OBJECTS = $(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)
	
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all










CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op

SRC_DIR = srcs/
INC_DIR = includes/

INCLUDES = $(INC_DIR)ft_do_op.h
SOURCES = $(SRC_DIR)ft_atoi.c $(SRC_DIR)ft_printall.c $(SRC_DIR)ft_calc.c $(SRC_DIR)main.c

$(NAME) : $(SOURCES)
		$(CC) $(CFLAGS) $^ -o $@ -I $(INC_DIR)

all : $(NAME)

clean :
		rm -f

fclean : clean
		rm -f $(NAME)

re : fclean all





SRCS	= ${wildcard ./srcs/*.c}
OBJS	= ${SRCS:.c=.o}
INCL	= includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= do-op

.c.o :	
			${CC} -I ${INCL} ${CFLAGS} -c $< -o ${<:.c=.o}
all :		${OBJS}
			${CC} -o ${NAME} ${OBJS}
clean :
			rm -f ${OBJS}
fclean :	clean
			rm -f ${NAME}
re :		fclean all



NAME = do-op

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

SRCS = do_op.c operate.c tool.c
OBJS = $(SRCS:.c=.o)

.PHONY: all
all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ -I mylib.h

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all