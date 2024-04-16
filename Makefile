CC = g++
CFLAGS = -Wall -Werror -pedantic -pedantic-errors -O0 -D _POSIX_C_SOURCE=200809L -ggdb -DDEBUG -fno-inline -std=c++17
SOURCES = $(wildcard *.cpp)
EXECUTABLE = hotel

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
