all:
	#Compilando Ejercicio1...
	@g++ -o laMayoriaAbsolutaIterativo.bin laMayoriaAbsolutaIterativo.cpp -std=c++11
	@g++ -o laMayoriaAbsolutaDV.bin laMayoriaAbsolutaDV.cpp -std=c++11
	@echo Ejercicio 1 compilado
	@echo Pruebe a ejecutar el algoritmo iterativo con ./laMayoriaAbsolutaIterativo.bin salida.txt 7895 1000 2 2000 10 3000 20 4000 30
	@echo Pruebe a ejecutar el algoritmo recursivo con ./laMayoriaAbsolutaDV.bin salida.txt 7895 1000 2000 3000 4000 5000 6000 7000 8000 9000 10000

	#Compilando Ejercicio2...
	@g++ -o Tuercas_Iterativo.bin Tuercas_Iterativo.cpp -std=c++11
	@g++ -o Tuercas_DV.bin Tuercas_Recursivo.cpp -std=c++11
	@echo Ejercicio 2 compilado

	@echo Pruebe a ejecutar el algoritmo iterativo con ./Tuercas_Iterativo.bin salida.txt 12345 1000 2000 3000 4000 5000 6000 7000 8000 9000 10000
	@echo Pruebe a ejecutar el algoritmo recursivo con ./Tuercas_DV.bin salida.txt 12345 1000 2000 3000 4000 5000 6000 7000 8000 9000 10000

	#Compilando Ejercicio3...
	@g++ -o ElementosRepetidosBasico.bin ElementosRepetidosBasico.cpp -std=c++11
	@g++ -o ElementosRepetidosDV.bin ElementosRepetidosDV.cpp -std=c++11
	@echo Ejercicio 3 compilado

	@echo Pruebe a ejecutar el algoritmo iterativo con ./ElementosRepetidosBasico.bin salida.txt 123512 1000 2000 3000 4000 5000 6000 7000 8000 9000 10000
	@echo Pruebe a ejecutar el algoritmo recursivo con ./ElementosRepetidosDV.bin salida.txt 12345 1000 2000 3000 4000 5000 6000 7000 8000 9000 10000
	
	#Compilando Ejercicio4...
	@g++ -o Productode3Iterativo.bin Productode3Iterativo.cpp -std=c++11
	@g++ -o Productode3DV.bin Productode3DV.cpp -std=c++11
	@echo Ejercicio 4 compilado

	@echo Pruebe a ejecutar el algoritmo iterativo con ./ElementosRepetidosBasico.bin salida.txt 
	@echo Pruebe a ejecutar el algoritmo recursivo con ./ElementosRepetidosDV.bin salida.txt 

	#Compilando Ejercicio5...
	@g++ -o calendarioCampeonato_DV.bin calendarioCampeonato_DV.cpp -std=c++11
	@g++ -o calendarioCampeonato_iterativo.bin calendarioCampeonato_iterativo.cpp -std=c++11
	@echo Ejercicio 5 compilado

	@echo Pruebe a ejecutar el algoritmo iterativo con ./calendarioCampeonato_iterativo.bin salida.txt 2 4 8 16 32 64 128 256 512 1024 2048 4096
	@echo Pruebe a ejecutar el algoritmo recursivo con ./calendarioCampeonato_DV.bin salida.txt 2 4 8 16 32 64 128 256 512 1024 2048 4096
	
#elimina los ejecutables
clean:
	@rm laMayoriaAbsolutaIterativo.bin
	@rm laMayoriaAbsolutaDV.bin
	@rm Tuercas_Iterativo.bin
	@rm Tuercas_DV.bin
	@rm ElementosRepetidosBasico.bin
	@rm ElementosRepetidosDV.bin
	@rm Productode3Iterativo.bin
	@rm Productode3DV.bin
	@rm calendarioCampeonato_DV.bin
	@rm calendarioCampeonato_iterativo.bin

.PHONY: clean
