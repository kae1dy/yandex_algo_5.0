TARGET := main
OBJECTS := main.cpp

LIBS := -lm

CPPFLAGS := -Wall -Werror -std=c++20 -O2 -Wextra
COLOC := -fno-elide-constructors -O0 -std=gnu++11

CPP := g++

all: $(OBJECTS)
	$(CPP) $(CPPFLAGS) $(OBJECTS) -o $(TARGET) $(LIBS)

.PHONY: clean help

clean:
	rm -f $(TARGET)
	