#Compiler flags
CXXFLAGS = -g -ansi -pedantic -std=c++11 -MMD -MP
WARNING = -Wall -Wextra
CC=g++

#Project flags
FILES = $(wildcard src/*.cpp src/*/*.cpp)
OBJS = $(patsubst src/%.cpp, build/%.o, $(FILES))
EXEC = bin/main	

all: $(EXEC)

print:
	@echo $(FILES)
	@echo $(OBJS)
	@echo $(EXEC)

$(EXEC): $(OBJS)
	mkdir -p $(@D)
	$(CC) -g -o $@ $^ $(CXXFLAGS) $(WARNING)

build/%.o: src/%.cpp
	mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CXXFLAGS) $(WARNING)

clean:
	rm -f $(OBJS) $(EXEC)
	rm -R build
	rm -R bin