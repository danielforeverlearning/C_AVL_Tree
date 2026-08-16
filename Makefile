executable: user-interface.o AVLtree.o
	gcc -o executable user-interface.o AVLtree.o

user-interface.o: user-interface.c
	gcc -c user-interface.c

AVLtree.o: AVLtree.c AVLtree.h
	gcc -c AVLtree.c

clean:
	rm -f executable user-interface.o AVLtree.o
