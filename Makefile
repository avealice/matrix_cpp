CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra -Wpedantic
AR = ar
ARFLAGS = rcs
SRC = s21_matrix_oop.cc
OBJ = $(SRC:.cc=.o)
LIB = s21_matrix.a
LDLIBS = -DGTEST_HAS_PTHREAD=1 -I/usr/local/include -lgtest
TESTSRC = tests/*.cc

all: clean $(LIB)

$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
	ranlib $(LIB)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

test: $(LIB)
	$(CXX) -g $(TESTSRC) $(LIB) $(CXXFLAGS) -o test $(LDLIBS)
	./test
	rm -rf *.gcda *.gcno

clean:
	@rm -rf *.o *.a report.info *.gcda *.gcno report RESULT_VALGRIND.txt test test.dSYM

style_check:
	clang-format -style=Google -n *.cc  *.h

style_fix:
	clang-format -style=Google -i *.cc  *.h