CC = gcc
CXX = g++
CFLAGS = -g -Wall

test: CFLAGS += -O0 -fprofile-arcs -ftest-coverage
test: CXXFLAGS = -g -Wall -O0 -fprofile-arcs -ftest-coverage

OBJS = \
  cmisc.o \
  help.o \
  main.o \

TESTOBJS = \
  $(filter-out cmisc.o, $(OBJS)) \
  gtest_cmisc.o \
  gtest_main.o \

TARGET = cmisc
TESTTARGET = googletest


$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(TESTTARGET): $(TESTOBJS)
	$(CXX) -o $@ $^ -lgtest -lgmock -lpthread -fprofile-arcs -ftest-coverage

.PHONY: test
test: $(TESTTARGET)
	./$(TESTTARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
	rm -f $(TESTOBJS:.o=.gcno) $(TESTOBJS:.o=.gcda) $(TESTOBJS) $(TESTTARGET)


%.o : unit-test/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<
