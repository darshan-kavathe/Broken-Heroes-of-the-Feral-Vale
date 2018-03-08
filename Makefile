#
# Top level Unix style makefile
#
# @author Sean Strout @ RIT CS
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s .S
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.S.s:
		$(CPP) -o $*.s $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
CPP = $(CPP) $(CPPFLAGS)
########## Flags from header.mak

CXXFLAGS = -g -gdwarf-2 -Wall -Wextra -Weffc++ -pedantic -std=c++17

########## End of flags from header.mak

GAME_OBJFILES = game/battle.o game/squad.o
HERO_OBJFILES = hero/fighter.o hero/hero.o hero/heroes.o hero/role.o hero/tank.o hero/healer.o hero/team.o
UTIL_OBJFILES = util/random.o util/queue.o
OBJFILES = $(GAME_OBJFILES) $(HERO_OBJFILES) $(UTIL_OBJFILES)

#
# Main targets
#

.PHONY: all
all: main test_queue

parts:
	+$(MAKE) -C game
	+$(MAKE) -C hero
	+$(MAKE) -C util

main: parts $(OBJFILES) main.o
	$(CXX) $(CXXFLAGS) -o main $(OBJFILES) main.o $(CCLIBFLAGS)

test_queue:	parts $(OBJFILES) test_queue.o
	$(CXX) $(CXXFLAGS) -o test_queue $(OBJFILES) test_queue.o $(CCLIBFLAGS)

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

.PHONY: clean
clean:
	+$(MAKE) -C game clean
	+$(MAKE) -C hero clean
	+$(MAKE) -C util clean
	-/bin/rm -f main.o test_queue.o

.PHONY: realclean
realclean:        clean
	-/bin/rm -f  main
	-/bin/rm -f  test_queue

