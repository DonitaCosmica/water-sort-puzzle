CC = gcc

SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCDIR = include

TARGET = main
RESULT = app
LIBNAME = libgame.so

CFLAGS = -Wall -I./$(INCDIR)
LDFLAGS = -shared -Wl,-soname,$(BINDIR)/$(LIBNAME).1

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

all: directories $(RESULT)

$(RESULT): symbolic_linkers
	$(CC) -o $(RESULT) $(OBJDIR)/$(TARGET).o -L./$(BINDIR) -lgame -Wl,-rpath,'$$ORIGIN' $(CFLAGS)

symbolic_linkers: $(BINDIR)/$(LIBNAME).1.2.3
	ln -sf $(LIBNAME).1.2.3 $(BINDIR)/$(LIBNAME).1
	ln -sf $(LIBNAME).1 $(BINDIR)/$(LIBNAME)

$(BINDIR)/$(LIBNAME).1.2.3: $(OBJS) $(OBJDIR)/$(TARGET).o
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/$(TARGET).o: $(TARGET).c
	$(CC) -fPIC -c $< -o $@ $(CFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -fPIC -c $< -o $@

directories:
	mkdir -p $(OBJDIR) $(BINDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: clean directories symbolic_linkers all
