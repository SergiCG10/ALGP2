#elementosrepetidosDV no fufa el ejecutable correctamente
all:
	#Ejercicio1
	@g++ -o laMayoriaAbsolutaIterativo.bin laMayoriaAbsolutaIterativo.cpp -std=c++11
	#@g++ -olaMayoriaAbsolutaDV.bin laMayoriaAbsolutaDV.cpp -std=c++11
	
	#Ejercicio2
	
	#Ejercicio3
	@g++ -o ElementosRepetidosBasico.bin ElementosRepetidosBasico.cpp -std=c++11
	@g++ -o ElementosRepetidosDV.bin ElementosRepetidosDV.cpp -std=c++11
	
	#Ejercicio4
	@g++ -o Productode3DV.bin Productode3DV.cpp -std=c++11
	
	#Ejercicio5
	@g++ -ocalendarioCampeonato_DV.bin calendarioCampeonato_DV.cpp -std=c++11
	@g++ -ocalendarioCampeonato_iterativo.bin calendarioCampeonato_iterativo.cpp -std=c++11
	
	@echo Pruebe a ejecutar el algoritmo iterativo con ./laMayoriaAbsolutaIterativo 12345 1000000 100

#elimina los ejecutables
clean:
	@rm laMayoriaAbsolutaIterativo.bin
	@rm ElementosRepetidosBasico.bin
	@rm ElementosRepetidosDV.bin
	@rm Productode3DV.bin

.PHONY: clean
