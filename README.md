# ALGP2

<b>Descripcion:</b>

Repo utilizado par compartir los ejercicios propuestos en la práctica 2 de 
la asignatura Algorítmica. En cada problema se deben de proponer dos soluciones,
por un lado, la solución básica, por otro lado, una solución que aplique "Divide
y vencerás" para resolver algorítmicos. Se deberá de estudiar la eficiencia de 
ambas soluciones.


## Elementos repetidos

Dado un vector de enteros, se deberá de eliminar los elementos repetidos.

<b>Método básico:</b> Se usa un std::set<int> para evitar repetidos y se sobrescribe
el array.

<b>Divide y vencerás:</b> a.


## Producto de 3 

Dado un natural n, se debe encontrar la secuencia de 3 naturales consecutivos para 
los cuales k*(k+1)*(k+2)=n.

<b>Método básico:</b> Se empieza con k=2 y se avanza de 1 en 1 comparando el
producto hasta que este sea mayor a n.

<b>Divide y vencerás:</b> Se realiza una búsqueda binaria empezando por n/2.


## Mayoría absoluta

Dada una lista de votos a partidos políticos, se devuelve si habrá mayoría absoluta
y el partido que la obtiene.

<b>Método básico: </b> Se reunen las frecuencias de voto para cada partido, 
aquel con la mayor frecuencia de voto, siendo esta mayor al 50% de lo votos,
será el partido con mayoría absoluta.

<b>Divide y vencerás </b>: a.

