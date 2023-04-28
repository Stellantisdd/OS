TARGET = thread2
SRC = thread2.c
OBJ = thread2.o
CC = gcc
LDFALAGS = -pthread -lpthread
CFLAGS = -D_REENTRANT

all: $(OBJ)
	$(CC) -o $(TARGET) $(LDFLAGS) $(OBJ)

.c.o:
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf *.o $(TARGET)
