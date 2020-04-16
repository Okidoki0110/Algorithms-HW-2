

# Task 1: 
Pe baza vectorului de distante se construieste lista muchiilor. Aceasta rezolvare are o complexitate de O (n * log n).

# Task 2:
-
	- parcurg matricea a si caut elemnete care pot fi adaugate folosind DFS
	- la finalul fiecarui dfs, am cate o arie, iar la sfarsit, se va calcula aria maxima dintre cele obtinute in fiecare 
parcurgere
	- caut doar elemente mai mari decat punctul de plecare ca sa verific conditia ca oricare 2 elemente sa nu difere mai
mult de k, daca conditia se respecta pentru primul element (cel mai mic), atunci se respecta pentru toate celelalte 
adaugate
	- vectorii xx si yy reprezinta toate directiile de deplasare, daca am o solutie corecta voi incerca sa ii adaug 
vecinii  (in masura in care respecta conditiile problemei)
	- in plus, la fiecare apel dfs se creste aria curenta cu o unitate, si se marcheaza nodul curent ca vizitat

# Task 3:
Consider ca dist[i][j] este distanta pana la nodul i cu ultima muchie de tipul j. Am făcut un Dijkstra modificat, care sa rețină și timpul muchiei.


# Rulare:

- local:
		./check.sh

- sursele + Makefile trebuie sa se afle in directorul curent

Run time error = eroare aparuta in timpul rularii unui test
TLE = time limit exceeded (s-a depasit limita de timp a testului curent)
WA = wrong answer (valoarea din fisierul .out difera de cea din .ref)

Timpi de executie problema $id:
	
- C/C++:
		-_utils/timeout/c.timeout$id

-  Java: 
		- _utils/timeout/java.timeout$id

Checker coding style:
	
- C/C++:
		- utils/coding_style/check_cpp.py
		- sursa: https://google.github.io/styleguide/cppguide.html

-  Java:
		- utils/coding_style/check_java.jar
		- sursa: http://checkstyle.sourceforge.net/google_style.html

Exemplu debug
	Rulez `./check.sh` si obtin WA la problema gigel, pe testul 4.
		Decomentez urmatoarea linie din checker.sh
			# DEBUG=on
			(activez DEBUG - by default fisierele de out sunt sterse)

		Ma uit in fisierele:
		- public_test/gigel/input/4-gigel.in   // ce input am
		- public_test/gigel/out/4-gigel.out    // ce raspuns gaseste algoritmul meu
		- public_test/gigel/ref/4-gigel.ref    // care este raspunsul corect (asteptat)
