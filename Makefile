CC = gcc
#CXXFLAGS =	-O2 -g -Wall -fmessage-length=0
CFLAGS = -g -Wall

OBJS =		getASIN.o

LIBS =

TARGET =	getASIN.exe

$(TARGET):	$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
