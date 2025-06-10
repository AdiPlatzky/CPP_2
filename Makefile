# 12adi45@gmail.com
CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++11 -g

SRC = SquareMat.cpp

TEST = tests/SquareMat_test.cpp

IMCLUDES = -I.

TARGET_MAIN = run_main
TARGET_TEST = run_test

.PHONY: all clean run-main run-test test main

all: $(TARGET_MAIN) $(TARGET_TEST)

$(TARGET_MAIN): $(SRC) main.cpp
	$(CXX) $(CXXFLAGS) $(SRC) main.cpp -o $(TARGET_MAIN) $(INCLUDES)

$(TARGET_TEST): $(SRC) $(TEST)
	$(CXX) $(CXXFLAGS) $(SRC) $(TEST) -o $(TARGET_TEST) $(INCLUDES)

run-main: $(TARGET_MAIN)
	./$(TARGET_MAIN)

run-test: $(TARGET_TEST)
	./$(TARGET_TEST)

main: run-main
test: run-test

valgrind: $(TARGET_TEST)
	valgrind --leak-check=full ./$(TARGET_TEST)

clean:
	rm -f $(TARGET_MAIN) $(TARGET_TEST)