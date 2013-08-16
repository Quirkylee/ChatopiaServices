all: src/chatopia.o src/serviceconf.o
	gcc -o chatopia src/chatopia.o src/serviceconf.o

src/chatopia.o:
	gcc -c src/chatopia.cc -o src/chatopia.o -Iincludes
src/serviceconf.o:
	gcc -c src/serviceconf.cc -o src/serviceconf.o -Iincludes

clean:
	rm src/*.o