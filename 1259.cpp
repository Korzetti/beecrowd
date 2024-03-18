#include <iostream>

// 1259 - Pares e Ímpares

using namespace std;

void Swap(int Vet[], int Pos1, int Pos2){
	int Aux;
	
	Aux = Vet[Pos1];
	Vet[Pos1] = Vet[Pos2];
	Vet[Pos2] = Aux;
}

void selectionSort(int Vet[], int Tam){
	int Min, Cont1, Cont2;
	
	for(Cont1 = 0; Cont1 < Tam; Cont1++){
		Min = Cont1;
		
		for(Cont2 = Cont1+1; Cont2 < Tam; Cont2++){
			if(Vet[Cont2] % 2 == 0 && Vet[Cont2] < Vet[Min]){
				if(Vet[Cont2] > 0){
					Min = Cont2;
				}
			}
			else{
				if(Vet[Cont2] % 2 != 0 && Vet[Cont2] > Vet[Min]){
					if(Vet[Cont2] > 0){
						Min = Cont2;
					}
				}
			}
		}
		
		Swap(Vet, Cont1, Min);
	}
}

void imprimeVetor(int Vet[], int Tam){
	int Cont;
	
	for(Cont = 0; Cont < Tam; Cont++){
		cout << Vet[Cont] << endl;
	}
}

void preencherVetores(int vetPar[], int vetImpar[], int Tam){
	int Cont, contPar, contImpar, Num;	
	contPar = 0;
	contImpar = 0;
	
	for(Cont = 0; Cont < Tam; Cont++){
		vetPar[Cont] = 0;
		vetImpar[Cont] = 0;
	}
	
	Cont = 0;
			
	while(Cont < Tam){
		cin >> Num;
		
		if(Num % 2 == 0){
			vetPar[contPar] = Num;
			contPar++;
		}
		else{
			vetImpar[contImpar] = Num;
			contImpar++;
		}
		
		Cont++;
	}
	
}

int concatenaVetor(int vet[], int vetPar[], int vetImpar[], int Tam){
	int Cont, Cont2;
	Cont2 = 0;
	
	for(Cont = 0; Cont < Tam; Cont++){
		vet[Cont] = vetPar[Cont];
		if(vetPar[Cont] == 0){
			vet[Cont] = vetImpar[Cont2];
			Cont2++;
		}
	}	

}


int Linha;
int main(){	
	cin >> Linha;
	int vet[Linha], vetPar[Linha], vetImpar[Linha];
		
	if(Linha > 1){
		preencherVetores(vetPar, vetImpar, Linha);// Divide em dois vetores, organiza e em seguida concatenar-os
		system("cls"); 
		selectionSort(vetPar, Linha);
		selectionSort(vetImpar, Linha);
		concatenaVetor(vet, vetPar, vetImpar, Linha);
		
		imprimeVetor(vet, Linha);		
	}
				
	return 0;
}
