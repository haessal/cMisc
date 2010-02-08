CC = gcc
#CXXFLAGS =	-O2 -g -Wall -fmessage-length=0
CFLAGS = -g -Wall
OBJS =		getASIN.o chkEndian.o
#LIBS =
TARGETS =	getASIN chkEndian

#$(TARGET):	$(OBJS)
#	$(CC) -o $(TARGET) $(OBJS) $(LIBS)

getASIN:	getASIN.o
	$(CC) -o $@ $^

chkEndian:	chkEndian.o
	$(CC) -m64 -o $@ $^

chkEndian.o:	CFLAGS += -m64

all:	$(TARGETS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGETS)
