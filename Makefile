CC = gcc
CFLAGS = -g -Wall
OBJS = \
  cmisc.o \
  cmisc_main.o \

TARGET = cmisc


.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^
