# ALGP2

<b>Descripcion:</b>

Repo utilizado par compartir los ejercicios propuestos en la práctica 2 de 
la asignatura Algorítmica. En cada problema se deben de proponer dos soluciones,
por un lado, la solución básica, por otro lado, una solución que aplique "Divide
y vencerás" para resolver algorítmicos. Se deberá de estudiar la eficiencia de 
ambas soluciones.


## Mayoría absoluta

Dada una lista de votos, devolvemos si hay algún candidato que tenga mayoría absoluta.

<b>Método básico: </b> Se reunen las frecuencias de voto para cada candidato, 
aquel con la mayor frecuencia de voto, si posee más del 50% de lo votos,
será el candidato con mayoría absoluta.

<b>Divide y vencerás </b>: Se ordena el vector de votos y se busca si existe algún 
elemento contenido en v[i], para el que v[i] = v[ i + n/2 ].


## Tuercas y tornillos

Tenemos dos cajones, cada uno lleno de tuercas y tornillos, los que no podemos comparar 
entre sí (tuercas con tuercas o tornillos con tornillos),y debemos de colocar las tuercas 
en la misma posición que los tornillos

<b>Método básico: </b> HAY QUE RELLENAR

<b>Divide y vencerás </b> HAY QUE RELLENAR

## Elementos repetidos

Dado un vector de enteros, se deberá de eliminar los elementos repetidos.

<b>Método básico:</b> Se usa un std::set<int> para evitar repetidos y se sobrescribe
el array.

<b>Divide y vencerás:</b> HAY QUE RELLENAR


## Producto de 3 

Dado un natural n, se debe encontrar la secuencia de 3 naturales consecutivos para 
los cuales k*(k+1)*(k+2)=n.

<b>Método básico:</b> Se empieza con k=2 y se avanza de 1 en 1 comparando el
producto hasta que este sea mayor a n.

<b>Divide y vencerás:</b> Se realiza una búsqueda binaria empezando por n/2.

# Organizar un calendario

Dado un número determinado de equipos, potencia de 2, debemos de organizar un calendario 
deportivo en el que cada equipo compita 

<b>Método básico: </b> Utilizamos el método round robin para repartir los partidos:
	
<b>Divide y vencerás </b> A partir de una matriz organizada de partidos, podemos vislumbrar
un patrón dentro de la misma si la dividimos en cuatro cuadrantes:
	
	-El primer y el tercer cuadrante poseen los mismo datos.
	
	-El segundo y cuarto cuadrante contienen los mismos datos que el primero y el tercero,
	 pero sumandole n/2 a cada casilla



