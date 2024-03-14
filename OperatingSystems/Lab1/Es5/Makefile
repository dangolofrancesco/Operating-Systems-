AB_PATH = /Users/brunobryan/Desktop/Programmazione/Operating\ Systems/Lab1/Es4
OPTION = -Wall -o
compilation:
	echo "Compiling"
	gcc ${OPTION} Esercizio ${AB_PATH}/QuartoEsercizio.c
	./Esercizio ${AB_PATH}/Lab01e03in.copy ${AB_PATH}/t.txt

install:
	mkdir ./bin
	mv Esercizio ./bin/Esercizio

distclean: clean
	rm -fr ./bin

clean:
	rm -f *.o