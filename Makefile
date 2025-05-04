CXX = /opt/homebrew/opt/llvm/bin/clang++

CXXFLAGS = -std=c++17 -fopenmp \
  -I/opt/homebrew/opt/llvm/include

LDFLAGS = -L/opt/homebrew/opt/llvm/lib \
  -L/opt/homebrew/lib

SRC = main.cpp
OUT = my_app

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)