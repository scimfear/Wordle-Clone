OBJS = wordle.o WordleSolver.o WordleGameUI.o
CXX = g++
CXXFLAGS = -std=c++14 -g

all: wordle

wordle: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o wordle

wordle.o: wordle.cpp WordleSolver.h WordleGameUI.h
	$(CXX) $(CXXFLAGS) -c wordle.cpp

WordleSolver.o: WordleSolver.cpp WordleSolver.h
	$(CXX) $(CXXFLAGS) -c WordleSolver.cpp

WordleGameUI.o: WordleGameUI.cpp WordleGameUI.h WordleSolver.h
	$(CXX) $(CXXFLAGS) -c WordleGameUI.cpp

clean:
	rm -f $(OBJS) wordle
