executable: user-interface.o AVLtree.o
	gcc -g -o executable user-interface.o AVLtree.o

user-interface.o: user-interface.c
	gcc -g -c user-interface.c

AVLtree.o: AVLtree.c AVLtree.h
	gcc -g -c AVLtree.c

clean:
	rm -f executable user-interface.o AVLtree.o
