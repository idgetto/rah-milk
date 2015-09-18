# # All Google Test headers.  Usually you shouldn't change this
# # definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

CC := clang++
SRCDIR := src
TESTDIR := test
BUILDDIR := build
EXECDIR := bin
TARGET := $(EXECDIR)/run

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
TESTS := $(shell find $(TESTDIR) -type f -name *_test.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o)) \
			$(patsubst $(TESTDIR)/%,$(BUILDDIR)/%,$(TESTS:.$(SRCEXT)=.o))
CFLAGS := -Wall -pedantic -std=c++11 -isystem $(GTEST_DIR)/include
LIB := -pthread
INC := -I include 

TEST_TARGETS := $(EXECDIR)/$(basename $(notdir $(TESTS)))

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@echo "$(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

tests: $(OBJECTS) build/gtest_main.a 
	@echo "Linking..."
	$(CC) $^ -o $(TEST_TARGETS) $(LIB)

$(BUILDDIR)/%.o: $(TESTDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning..."; 
	$(RM) -rf $(BUILDDIR)/* $(EXECDIR)/* $(TARGET)/*

.PHONY: clean

# # Where to find user code.
# USER_DIR = ../samples
# 
# # Flags passed to the preprocessor.
# # Set Google Test's header directory as a system directory, such that
# # the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include
# 
# # Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread
# 
# # All tests produced by this Makefile.  Remember to add new tests you
# # created to the list.
# TESTS = sample1_unittest
# 

# # House-keeping build targets.
# 
# all : $(TESTS)
# 
# clean :
# 	rm -f $(TESTS) gtest.a gtest_main.a *.o
# 
# # Builds gtest.a and gtest_main.a.
# 
# # Usually you shouldn't tweak such internal variables, indicated by a
# # trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
# 
# # For simplicity and to avoid depending on Google Test's
# # implementation details, the dependencies specified below are
# # conservative and not optimized.  This is fine as Google Test
# # compiles fast and for ordinary users its source rarely changes.
build/gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -o $@ -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc 

build/gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -o $@ -I$(GTEST_DIR) $(CPPFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

build/gtest.a : build/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

build/gtest_main.a : build/gtest-all.o build/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# # Builds a sample test.  A test should link with either gtest.a or
# # gtest_main.a, depending on whether it defines its own main()
# # function.
# 
# sample1.o : $(USER_DIR)/sample1.cc $(USER_DIR)/sample1.h $(GTEST_HEADERS)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1.cc
# 
# sample1_unittest.o : $(USER_DIR)/sample1_unittest.cc \
#                      $(USER_DIR)/sample1.h $(GTEST_HEADERS)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1_unittest.cc
# 
# sample1_unittest : sample1.o sample1_unittest.o gtest_main.a
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
# 
