# Compiler and flags
CXX := g++
CXXFLAGS := -g -Wall

# Libraries
LIBS := -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

# Source files and headers
SRCS := $(filter-out ./test_unitaire_cellule.cpp, $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g'))
HEADERS := $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

# Test files
TEST_FILE := test_unitaire_cellule.cpp
TEST_EXEC := test_unitaire_cellule

# Executable targets
TARGET := main
TARGET_DEBUG := main-debug

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LIBS)

$(TARGET_DEBUG): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -U_FORTIFY_SOURCE -O0 $(SRCS) -o $@ $(LIBS)

test: $(TEST_EXEC)

$(TEST_EXEC): $(TEST_FILE) $(filter-out ./main.cpp, $(SRCS)) $(HEADERS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET) $(TARGET_DEBUG) $(TEST_EXEC)
