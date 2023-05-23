TARGET = matrix
OBJ = project.o matrix.o
LFLAGS = -pthread -lpthread
CFLAGS = -D_REENTRANT
all: $(OBJ)
	gcc -o $(TARGET) $(LFLAGS) $(OBJ)

project.o: project.c
	gcc -c $(CFLAGS) project.c

matrix.o: matrix.c
	gcc -c $(CFLAGS) matrix.c

clean:
	rm -r *.o $(TARGET)
