CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD 
EXEC = botfight
OBJECTS = botfight.o gamecontroller.o subject.o textdisplay.o board.o bot.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
	
