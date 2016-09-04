CC = g++

SRCDIR = src
BUILDDIR = build
TARGET = bin/tictactoe

SRCEXT = cpp

SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

CFLAGS = -Wall -Wextra -std=c++11
LDFLAGS = -lSDL2
INC = -I include


$(TARGET): $(OBJECTS)
	@$(CC) $^ -o $(TARGET) $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."
	@$(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: run
run: $(TARGET)
	./$(TARGET)	
