CC = gcc
CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		getASIN.o

LIBS =

TARGET =	getASIN

$(TARGET):	$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
