CXXFLAGS=-Iinclude -Wall -DTEST

main: MenuManager.o MenuEntry.o CursesDisplay.o Display.o main.o
	${CXX} ${CXXFLAGS} -o main $^ -lncurses

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN)/menu
