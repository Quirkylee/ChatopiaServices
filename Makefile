all: src/chatopia.o src/serviceconf.o src/logger.o
	g++ -v -o chatopia src/chatopia.o src/serviceconf.o src/logger.o
	
src/chatopia.o:
	g++ -c src/chatopia.cc -o src/chatopia.o -Iincludes

src/logger.o:
	g++ -c src/logger.cc -o src/logger.o -Iincludes

src/serviceconf.o:
	g++ -c src/serviceconf.cc -o src/serviceconf.o -Iincludes

clean:
	rm src/*.o