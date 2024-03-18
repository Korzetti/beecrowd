#include <iostream>
#include <cstring>

//2633 - Churras no Yuri

using namespace std;

struct Peca{
	int Val;
	char Nome[20];
};

void carregaLista(Peca *C, int Val, char Nome[], int Cont){
		strcpy(C[Cont].Nome, Nome);
		C[Cont].Val = Val;
}

void imprimirLista(Peca *C, int Tam){
	int Cont;
	for(Cont = 0; Cont < Tam; Cont++){
		cout << C[Cont].Nome;
		if(Cont < Tam - 1){
			cout << " ";
		}
	}
	cout << endl;
}

void Swap(Peca *C, int Pos1, int Pos2){
	Peca Aux;
	
	Aux = C[Pos1];
	C[Pos1] = C[Pos2];
	C[Pos2] = Aux;
}

void selectionSort(Peca *C, int Tam){
	int Cont1, Cont2, Min;
	
	for(Cont1 = 0; Cont1 < Tam; Cont1++){
		Min = Cont1;
		
		for(Cont2 = Cont1 + 1; Cont2 < Tam; Cont2++){
			if(C[Cont2].Val < C[Min].Val){
				Min = Cont2;
			}
		}
		
		Swap(C, Cont1, Min);
	}
}

int Qnt, Cont, Val;
char Nome[20];
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	while(cin >> Qnt){
		Peca C[Qnt];
				
		for(Cont = 0; Cont < Qnt; Cont++){	
			cin >> Nome >> Val;
			carregaLista(C, Val, Nome, Cont);
		}
	
		selectionSort(C, Qnt);
		imprimirLista(C, Qnt);		
	}
	
	return 0;
}
