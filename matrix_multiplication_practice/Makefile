TARGET = matrix
OBJ = project.o matrix.o

all: $(OBJ)
	gcc -o $(TARGET) $(OBJ)

project.o: project.c
	gcc -c project.c

matrix.o: matrix.c
	gcc -c matrix.c

clean:
	rm -r *.o $(TARGET)
