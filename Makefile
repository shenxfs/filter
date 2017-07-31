TARGET = filter
SRC = main.c iirfilter.c
OBJ =$(SRC:.c=.o)
CFLAGES ?= -DDEBUG
all:$(TARGET)
$(TARGET):$(OBJ)
	$(CC) $(OBJ) -o $@
clean:
	$(RM) -f $(TARGET) $(OBJ)
%.o:%.c
	$(CC)	$(CFLAGES) -c $< -o $@
.PHONY:all clean
