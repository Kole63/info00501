all: a.exe

cellule.o: cellule.c cellule.h
	gcc -Wall -Wextra -Werror -c cellule.c

liste.o: liste.c liste.h cellule.h
	gcc -Wall -Wextra -Werror -c liste.c

arete.o: arete.c arete.h cellule.h graphe.h
	gcc -Wall -Wextra -Werror -c arete.c
tri.o: tri.c tri.h arete.h
	gcc -Wall -Wextra -Werror -c tri.c
tas.o: tas.c tas.h arete.h
	gcc -Wall -Wextra -Werror -c tas.c
ensembles.o: ensembles.c ensembles.h
	gcc -Wall -Wextra -Werror -c ensembles.c
graphe.o: graphe.c graphe.h liste.h cellule.h
	gcc -Wall -Wextra -Werror -c graphe.c
prog_liste.o: prog_liste.c cellule.h liste.h
	gcc -Wall -Wextra -Werror -c prog_liste.c
prog_graphe.o: prog_graphe.c cellule.h liste.h graphe.h arete.o tri.o tas.o ensembles.o
	gcc -Wall -Wextra -Werror -c prog_graphe.c
a.out: cellule.o liste.o prog_liste.o
	gcc -Wall -Wextra -Werror cellule.o liste.o prog_liste.o -o a.out
a.exe: cellule.o liste.o graphe.o prog_graphe.o arete.o tri.o ensembles.o
	gcc -Wall -Wextra -Werror cellule.o liste.o graphe.o arete.o tri.o tas.o ensembles.o prog_graphe.o -o a.exe
clean:
	rm -f *.out *.exe *.o
run:
	./a.exe
