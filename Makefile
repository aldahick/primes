# Automatically generated by makegen (https://github.com/aldahick/makegen)
COMPILER = g++
COMPILER_FLAGS = -std=c++17
COMPILER_HEADERS = -I./inc
COMPILER_LIBRARIES = -lstdc++fs
OBJECT_FILES = obj/PrimeGenerator.o obj/util.o obj/PrimeGenerator.IO.o obj/main.o
OUTPUT_FILE = bin/find
all: mkdirs $(OBJECT_FILES)
	$(COMPILER) $(COMPILER_FLAGS) $(COMPILER_HEADERS) $(OBJECT_FILES) -o $(OUTPUT_FILE) $(COMPILER_LIBRARIES)
obj/PrimeGenerator.o:  ./src/PrimeGenerator.cpp
	$(COMPILER) $(COMPILER_FLAGS) $(COMPILER_HEADERS) -c ./src/PrimeGenerator.cpp -o obj/PrimeGenerator.o $(COMPILER_LIBRARIES)
obj/util.o:  ./src/util.cpp
	$(COMPILER) $(COMPILER_FLAGS) $(COMPILER_HEADERS) -c ./src/util.cpp -o obj/util.o $(COMPILER_LIBRARIES)
obj/PrimeGenerator.IO.o: obj/util.o obj/PrimeGenerator.o ./src/PrimeGenerator.IO.cpp
	$(COMPILER) $(COMPILER_FLAGS) $(COMPILER_HEADERS) -c ./src/PrimeGenerator.IO.cpp -o obj/PrimeGenerator.IO.o $(COMPILER_LIBRARIES)
obj/main.o: obj/util.o obj/PrimeGenerator.o ./src/main.cpp
	$(COMPILER) $(COMPILER_FLAGS) $(COMPILER_HEADERS) -c ./src/main.cpp -o obj/main.o $(COMPILER_LIBRARIES)
clean:
	rm -rf $(OUTPUT_FILE)
	rm -rf $(OBJECT_FILES)
mkdirs:
	mkdir -p obj
	mkdir -p bin
