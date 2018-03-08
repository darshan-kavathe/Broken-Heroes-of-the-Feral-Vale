#
# Created by gmakemake (Ubuntu Jul 25 2014) on Sat Feb 10 13:25:56 2018
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
########## Default flags (redefine these with a header.mak file if desired)
CXXFLAGS = -g -gdwarf-2 -Wall -Wextra -Weffc++ -pedantic -std=c++17
CFLAGS =	-ggdb
CLIBFLAGS =	-lm
CCLIBFLAGS =	
########## End of default flags


CPP_FILES =	fighter.cpp hero.cpp heroes.cpp role.cpp tank.cpp healer.cpp team.cpp
C_FILES =	
PS_FILES =	
S_FILES =	
H_FILES =	heroes.h fighter.h tank.h hero.h role.h team.h
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	hero.o heroes.o role.o fighter.o tank.o healer.o team.o

#
# Main targets
#

all: $(OBJFILES)

#
# Dependencies
#

fighter.o:	heroes.h fighter.h hero.h role.h team.h
healer.o: heroes.h healer.h hero.h role.h team.h
hero.o:	fighter.h hero.h role.h team.h ../util/random.h
heroes.o:	heroes.h fighter.h hero.h role.h team.h
role.o:	role.h
tank.o: heroes.h tank.h hero.h role.h team.h
team.o: team.h

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm -f $(OBJFILES) core

realclean:        clean
