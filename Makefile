# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Executable name
TARGET = calc

# Source files
SRCS = main.cpp sqrt.cpp factorial.cpp ln.cpp power.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Build executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run program after build
run: all
	./$(TARGET)

# Run PyUnit tests WITHOUT rebuilding
test:
	python3 -m unittest discover -s tests -p "test_*.py"

# Run PyUnit tests AFTER building
test-build: all
	python3 -m unittest discover -s tests -p "test_*.py"

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# make → build executable.

# make run → run calc.

# make test → run Python tests without rebuilding calc.

# make test-build → rebuild calc then run Python tests.

# make clean → remove object files and executable.