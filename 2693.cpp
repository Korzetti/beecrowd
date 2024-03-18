#include <iostream>
#include <cstring>

// 2693 - Van

using namespace std;

struct Aluno{
	char Nome[50];
	char Regiao[2];
	int Custo;
};

void preencherDados(Aluno *A, char Nome[], char Regiao[], int Custo, int Cont){
	strcpy(A[Cont].Nome, Nome);
	strcpy(A[Cont].Regiao, Regiao);
	A[Cont].Custo = Custo;
}

void Swap(Aluno *A, int Pos1, int Pos2){
	Aluno Aux;
	Aux = A[Pos1];
	A[Pos1] = A[Pos2];
	A[Pos2] = Aux;
}

void selectionSort(Aluno *A, int Tam){
	int Cont1, Cont2, Min;
	
	for(Cont1 = 0; Cont1 < Tam; Cont1++){
		Min = Cont1;	
			
		for(Cont2 = Cont1+1; Cont2 < Tam; Cont2++){
			if(A[Min].Custo > A[Cont2].Custo){
				Min = Cont2;
			}
			else{
				if(A[Min].Custo == A[Cont2].Custo){ // Se ambos custos forem iguais
					if(strcmp(A[Min].Regiao, A[Cont2].Regiao) > 0){ //Ordenar as regiões em ordem alfabética
						Min = Cont2;
					}
					else{
						if(strcmp(A[Min].Regiao, A[Cont2].Regiao) == 0){ //Se as regiões forem iguais, ordenar os nomes em ordem alfabética
							if(strcmp(A[Min].Nome, A[Cont2].Nome) > 0){
								Min = Cont2;
							}
						}
					}		
				}								
			}						
		}
		
		Swap(A, Cont1, Min);
	}
}

void imprimeAluno(Aluno *A, int Qnt){
	int Cont;
	
	for(Cont = 0; Cont < Qnt; Cont++){
		cout << A[Cont].Nome << endl;
	}
}

char Nome[50], Regiao[2];
int Qnt, Custo, Cont;
int main(){

	while(cin >> Qnt){
		Aluno A[Qnt];
		
		for(Cont = 0; Cont < Qnt; Cont++){
			cin >> Nome >> Regiao >> Custo;
			preencherDados(A, Nome, Regiao, Custo, Cont);
		}	
		
		selectionSort(A, Qnt);
		imprimeAluno(A, Qnt);
	}
		
	return 0;
}
