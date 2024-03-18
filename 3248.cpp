#include <iostream>

// 3248 - Mega Inversões

using namespace std;

void Swap(int Vet[], int Pos1, int Pos2){
	int Aux;
	Aux = Vet[Pos1];
	Vet[Pos1] = Vet[Pos2];
	Vet[Pos2] = Aux;
}

void bubbleSort(int Vet[], int Tam){
	int Cont1, Cont2, FezSwap;
	Cont1 = 0;
	FezSwap = 0;
	
	do{
		FezSwap = 0;
		
		for(Cont2 = Tam-1; Cont2 > Cont1; Cont2--){
			if(Vet[Cont2-1] > Vet[Cont2]){
				Swap(Vet, Cont2-1, Cont2);
				FezSwap = 1;
			}
		}
		Cont1++;
				
	}while(FezSwap && Cont1 < Tam);
	
}

void verificaTriplaInvertida(int Vet[], int Tam){
	int vetTripla[3], Cont1, Cont2;
	
	while(Cont1 < Tam){
		for(Cont2 = Cont1; Cont2 < Cont1+3; Cont2++){
			vetTripla[Cont2] = Vet[Cont2];
		}
		
		Cont1++;
	}
	
	
	
		
}

int Tam, Cont;
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	cin >> Tam;
	int Vet[Tam];
	
	for(Cont = 0; Cont < Tam; Cont++){
		cin >> Vet[Cont];
	}
	
	bubbleSort(Vet, Tam);
	

	
	return 0;
}
