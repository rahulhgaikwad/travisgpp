# Building GoogleTest and running exercise-gtest unit tests against
# all code in SOURCECODE subdirectory. This Makefile is based on the
# sample Makefile provided in the official GoogleTest GitHub Repo v1.7

# Points to the root of Google Test. Change it to reflect where your
# clone of the googletest repo is
CPPFLAGS += --coverage -isystem -std=c++11
CXXFLAGS += -g -Wall -Wextra -pthread

# All tests produced by this Makefile.
TESTS = ConnectXTest

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o *.gcov *.gcda *.gcno

ConnectX.o : ConnectX.cpp ConnectX.h /usr/local/lib/libgtest_main.a /usr/local/lib/libgtest.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c ConnectX.cpp

ConnectXTest.o : ConnectXTest.cpp \
                     ConnectX.h /usr/local/lib/libgtest_main.a /usr/local/lib/libgtest.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c ConnectXTest.cpp

ConnectXTest : ConnectX.o ConnectXTest.o /usr/local/lib/libgtest_main.a /usr/local/lib/libgtest.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@