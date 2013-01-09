CXXFLAGS=-Iinclude -Wall -DTEST

all: MenuManager.o MenuEntry.o CursesDisplay.o Display.o Queue.o main.o
	${CXX} ${CXXFLAGS} -o main $^ -lncurses

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN)/menu
