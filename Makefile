CXXFLAGS=-Iinclude -Wall -DTEST

main: MenuEntry.o CursesDisplay.o main.o
	${CXX} ${CXXFLAGS} -o main $^ -lncurses

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN)/menu
