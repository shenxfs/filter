TARGET = filter
SRC = main.c iirfilter.c
OBJ =$(SRC:.c=.o)
all:$(TARGET)
$(TARGET):$(OBJ)
	$(CC) $(OBJ) -o $@
clean:
	$(RM) -f $(TARGET) $(OBJ)
%.o:%.c
	$(CC)	-c $< -o $@
.PHONY:all clean
