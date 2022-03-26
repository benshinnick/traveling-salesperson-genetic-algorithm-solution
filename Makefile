CXX = g++
CXXFLAGS = -g -std=c++17

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS:%.hpp=%.o)

main: $(OBJECTS) main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* *.dSYM $(addprefix test/,$(TESTS)) core main $(CATCH)