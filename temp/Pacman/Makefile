ROOT=..
PROJ_NAME = pacman
include ${ROOT}/makedefs
SRCS += $(wildcard *.c)

$(PROJ_NAME).elf: $(OBJS)
		$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
