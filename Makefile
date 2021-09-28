CC = g++
CFLAGS = -W -Wall -ansi -g
LIBS =
LDFLAGS = `sdl2-config --cflags --libs`


SRCDIR = src
BUILDDIR = build

SRCS = $(shell find $(SRCDIR) -name *.cpp)
OBJS = $(SRCS:%.c=$(BUILDDIR)/%.o)

EXEC = main

play: $(EXEC)
	./$(BUILDDIR)/$<

$(EXEC): $(OBJS)
	$(CC) $^ -o $(BUILDDIR)/$@ $(LDFLAGS)

# Assembly
$(BUILDDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	-c $< -o $@

# C srcs
$(BUILDDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -r build/src
	rm -rf *.o
mrproper:
	rm -r build