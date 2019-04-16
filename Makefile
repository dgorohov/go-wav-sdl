CC			:= gcc
CPPFLAGS	:= -g -I/usr/local/include -Wall
LDFLAGS		:= -g -L/usr/local/lib -lSDL2
INCLUDE  	:= -I.
SRCS		:= sdl2.c audio/wav/sdl2-wav.c
OBJS		:= $(subst .c,.o,$(SRCS))

all: wav-test

%.o: %.c
	$(CC) $(CPPFLAGS) $(INCLUDE) -o $@ -c $<

wav-test: $(OBJS) cpp-test/wav.o
	$(CC) $(LDFLAGS) -o $@ $(OBJS) cpp-test/wav.o $(LDLIBS)

clean:
	@rm -f $(OBJS) cpp-test/wav.o
	@rm -f wav-test
