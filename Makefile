%.o: %.cpp %.hpp
	g++ -c $<

all:
	g++ main.cpp -o village

clean:
	rm *.o