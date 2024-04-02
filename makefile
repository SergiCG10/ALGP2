#elementosrepetidosDV no fufa el ejecutable correctamente
all:
	#Ejercicio1
	@g++ -o laMayoriaAbsolutaIterativo.bin laMayoriaAbsolutaIterativo.cpp -std=c++11
	@g++ -olaMayoriaAbsolutaDV.bin laMayoriaAbsolutaDV.cpp -std=c++11
	@echo Ejercicio 1 compilado
	
	#Ejercicio2
	
	#Ejercicio3
	@g++ -o ElementosRepetidosBasico.bin ElementosRepetidosBasico.cpp -std=c++11
	@g++ -o ElementosRepetidosDV.bin ElementosRepetidosDV.cpp -std=c++11
	@echo Ejercicio 3 compilado
	
	#Ejercicio4
	@g++ -o Productode3Iterativo.bin Productode3Iterativo.cpp -std=c++11
	@g++ -o Productode3DV.bin Productode3DV.cpp -std=c++11
	@echo Ejercicio 4 compilado
	
	#Ejercicio5
	@g++ -o calendarioCampeonato_DV.bin calendarioCampeonato_DV.cpp -std=c++11
	@g++ -o calendarioCampeonato_iterativo.bin calendarioCampeonato_iterativo.cpp -std=c++11
	@echo Ejercicio 5 compilado
	
	@echo Pruebe a ejecutar el algoritmo iterativo con ./laMayoriaAbsolutaIterativo 12345 1000000 100

#elimina los ejecutables
clean:
	@rm laMayoriaAbsolutaIterativo.bin
	@rm laMayoriaAbsolutaDV.bin
	@rm ElementosRepetidosBasico.bin
	@rm ElementosRepetidosDV.bin
	@rm Productode3Iterativo.bin
	@rm Productode3DV.bin
	@rm calendarioCampeonato_DV.bin
	@rm calendarioCampeonato_iterativo.bin

.PHONY: clean
