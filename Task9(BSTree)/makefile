# --- CONFIGURATION ---
CXX = g++
CXXFLAGS = -Wall -g
TARGET = main.exe
OBJS = main.o BSTree.o

# --- TARGETS & RECIPES ---

# Default target: Compiles everything and generates the executable
all: $(TARGET)

# Links the object files into the final main.exe
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compiles main.cpp (depends on BSTree.h because main usually includes it)
main.o: main.cpp BSTree.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compiles BSTree.cpp (depends on its own header)
BSTree.o: BSTree.cpp BSTree.h
	$(CXX) $(CXXFLAGS) -c BSTree.cpp

# Cleans up the directory (Windows native commands)
clean:
	del /Q $(OBJS) $(TARGET) 2>nul || exit 0
