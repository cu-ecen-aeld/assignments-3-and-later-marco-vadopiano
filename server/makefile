.PHONY : default_target
default_target : all

LDFLAGS ?= -lpthread -lrt
CFLAGS ?= -g -Wall -Werror
C_SRCS ?= main.c

OBJS := $(subst .cpp,.o,$(C_SRCS))
OBJS := $(subst .c,.o,$(OBJS))



CXX ?=$(CROSS_COMPILE)g++
AS ?=$(CROSS_COMPILE)gcc
CC ?=$(CROSS_COMPILE)gcc
LD ?=$(CC)

all : aesdsocket

./aesdsocket : $(OBJS)
	@echo   $(TYPE)LD        $@
	$(CC) -o aesdsocket $(CFLAGS)     $(OBJS) $(LDFLAGS) 



./%.o : %.c
	@echo   $(TYPE)CC        $<	
	$(CC) -c  $(CFLAGS)  -o $@ $<

clean : 
	-@echo   CLEAN     
	-$(RM) *.o *.d *.elf *.map aesdsocket
