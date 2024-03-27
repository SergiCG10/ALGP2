#elementosrepetidosDV no fufa el ejecutable correctamente
all:
	@g++ -o laMayoriaAbsolutaIterativo.bin laMayoriaAbsolutaIterativo.cpp -std=c++11
	@g++ -o ElementosRepetidosBasico.bin ElementosRepetidosBasico.cpp -std=c++11
	@g++ -o ElementosRepetidosDV.bin ElementosRepetidosDV.cpp -std=c++11
	@g++ -o Productode3DV.bin Productode3DV.cpp -std=c++11
	@echo Pruebe a ejecutar el algoritmo iterativo con ./laMayoriaAbsolutaIterativo 12345 1000000 100

#elimina los ejecutables
clean:
	@rm laMayoriaAbsolutaIterativo.bin
	@rm ElementosRepetidosBasico.bin
	@rm ElementosRepetidosDV.bin
	@rm Productode3DV.bin

.PHONY: clean
