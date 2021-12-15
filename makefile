SemesterProject: SemesterProjectMenu.o main.o echo.o
	g++ -o SemesterProjectMenu.o main.o echo.o

SemesterProjectMenu.o: SemesterProjectMenu.cpp
	g++ -c SemesterProjectMenu.cpp

main.o: main.cpp AudioFile.h
	g++ -c main.cpp AudioFile.h

echo.o: echo.cpp
	g++ -c echo.cpp

clean:
	rm *.o