CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = ss5k
OBJECTS = main.o board.o intboard.o level.o level0.o level1.o level2.o square.o textboard.o window.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBEJECTS} ${EXEC} ${DEPENDS}
