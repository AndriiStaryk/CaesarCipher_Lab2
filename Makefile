CXX = /opt/homebrew/opt/llvm/bin/clang++

CXXFLAGS = -std=c++17 -fopenmp \
  -I/opt/homebrew/opt/llvm/include

LDFLAGS = -L/opt/homebrew/opt/llvm/lib \
  -L/opt/homebrew/lib

SRC = caesar.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
OUT = my_app

all: $(OUT)

$(OUT): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(OUT) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OUT) $(OBJ)
