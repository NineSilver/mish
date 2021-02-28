CC ?= gcc

DEBUG ?= no

ifeq (DEBUG, yes)
	CFLAGS := -g
else
	CFLAGS := -O2
endif

CFILES := $(shell find src -type f -name *.c)

.PHONY: run all clean

run: mish
	./$<

all: mish
mish:
	${CC} $(CFLAGS) $(CFILES) -o $@

clean:
	rm mish