CXX = g++
CXXFLAGS = -Wall -g -I include
TARGET = ising_model

SRCS = $(wildcard src/*.cpp)
OBJS = $(addprefix obj/, $(notdir $(SRCS:.cpp=.o)))
OBJDIR = obj/

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)%.o : src/%.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

