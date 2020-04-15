# PA-Tema-2

Corcodel Denisa, 325CD

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
