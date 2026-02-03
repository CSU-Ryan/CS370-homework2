CC := gcc
FILES := src/Checker.c src/Coordinator.c
OUT_EXE := hw2.o

all: build

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES)

clean:
	rm -f *.o $(OUT_EXE)