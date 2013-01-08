CXXFLAGS=-Iinclude -Wall -DTEST

main: MenuEntry.o ConsoleDisplay.o main.o
	${CXX} ${CXXFLAGS} -o main $^

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN)/menu
