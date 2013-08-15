all: src/chatopia.o
	g++ -o chatopia src/chatopia.o

src/chatopia.o:
	g++ -c src/chatopia.cc -o src/chatopia.o -Iincludes

clean:
	rm src/*.o