CC	= gcc
CFLAGS	= -Og -g -Wall -Wextra

RM	= rm -fv

SRCS	= main.c biquad.c
OBJS	= $(SRCS:%=%.o)
DEPS	= $(SRCS:%=%.d)

.PHONY: all
.DEFAULT_GOAL: all

all: tst-biquad

-include $(DEPS)

tst-biquad: $(OBJS)
	$(CC) -o $@ $^ 

%.c.o: %.c
	$(CC) -MMD -MP $(CFLAGS) -o $@ -c $<

clean:
	$(RM) *.o *.d
