CC := gcc
SRC_PATH := ./src
BIN_PATH := ./bin

all: build

run: $(ARGS)
	$(BIN_PATH)/coordinator.o $(ARGS)

build:
	$(CC) -o $(BIN_PATH)/checker.o $(SRC_PATH)/Checker.c
	$(CC) -o $(BIN_PATH)/coordinator.o $(SRC_PATH)/Coordinator.c

clean:
	rm -r $(BIN_PATH)/*