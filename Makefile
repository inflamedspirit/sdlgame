# Makefile to build the SDL tests

srcdir  = .
CC      = gcc
CPP     = g++
EXE	= 
CFLAGS  = -I/usr/local/include/SDL2
#CFLAGS  = -g -O2 -D_REENTRANT -I/usr/local/include/SDL2   -DHAVE_OPENGLES -DHAVE_OPENGLES2 -DHAVE_OPENGL -g
LIBS	=  -lSDL2_test -lSDL2

TARGETS = \
	testime$(EXE) \
	testsprite2$(EXE) \
	main$(EXE)

REQS = \
	sdlbox.cpp \
	world.cpp

all: $(TARGETS)

testime$(EXE): $(srcdir)/testime.c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) 

testsprite2$(EXE): $(srcdir)/testsprite2.c
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

main$(EXE): $(srcdir)/main.cpp $(REQS)
	$(CPP) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGETS)
