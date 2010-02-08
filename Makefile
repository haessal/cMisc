CC = gcc
#CXXFLAGS =	-O2 -g -Wall -fmessage-length=0
CFLAGS = -g -Wall
OBJS =		getASIN.o chkEndian.o
#LIBS =
TARGETS =	getASIN.exe chkEndian.exe

#$(TARGET):	$(OBJS)
#	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

getASIN.exe:	getASIN.o
	$(CC) -o $@ $^

chkEndian.exe:	chkEndian.o
	$(CC) -m64 -o $@ $^

chkEndian.o:	CFLAGS += -m64

all:	$(TARGETS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGETS)
