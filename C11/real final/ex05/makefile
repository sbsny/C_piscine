CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCDIR = includes
SRCDIR = srcs

TARGET = do-op
SRCS = $(SRCDIR)/main.c $(SRCDIR)/op.c $(SRCDIR)/check.c $(SRCDIR)/atoi.c
OBJECTS = $(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ -I $(INCDIR)
	
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)
	
re: fclean all
