#include <iostream>
#include <cstring>

// 1766 - O Elfo das Trevas

using namespace std;

struct Rena{
	char Nome[110];
	int Peso;
	int Idade;
	double Altura;
};

void Swap(Rena *R, int Pos1, int Pos2){
	Rena Aux;
	Aux = R[Pos1];
	R[Pos1] = R[Pos2];
	R[Pos2] = Aux;
}

void selectionSort(Rena *R, int Tam){
	int Cont1, Cont2, Min;
	
	for(Cont1 = 0; Cont1 < Tam; Cont1++){
		Min = Cont1;
		
		for(Cont2 = Cont1+1; Cont2 < Tam; Cont2++){
			if(R[Min].Peso < R[Cont2].Peso){
				Min = Cont2;
			}
			else{
				if(R[Min].Peso == R[Cont2].Peso){ //Se o peso for igual, comparar idade
					if(R[Min].Idade > R[Cont2].Idade){
						Min = Cont2;
					}
					else{
						if(R[Min].Idade == R[Cont2].Idade){ //Se idade for igual, comparar altura
							if(R[Min].Altura > R[Cont2].Altura){
								Min = Cont2;
							}
							else{
								if(R[Min].Altura == R[Cont2].Altura){//Se altura for igual, comparar os nomes
									if(strcmp(R[Min].Nome, R[Cont2].Nome) < 0){
                            			Min = Cont2;
                        			}
								}
							}
						}
					}
				}
			}
		}
		
		Swap(R, Cont1, Min);
	}
}

void preencherDados(Rena *R, char Nome[], int Peso, int Idade, double Altura, int Cont){
	strcpy(R[Cont].Nome, Nome);
	R[Cont].Peso = Peso;
	R[Cont].Idade = Idade;
	R[Cont].Altura = Altura;
}

void limpaDados(Rena *R, int Tam){
	int Cont;
	
	for(Cont = 0; Cont < Tam; Cont++){
		memset(R[Cont].Nome, 0, sizeof(R[Cont].Nome)); 
        R[Cont].Peso = 0;
        R[Cont].Idade = 0;
        R[Cont].Altura = 0.0;
	}
}

void imprimeRena(Rena *R, int renaPuxa, int contCaso){
	int Cont;
	
	cout << "CENARIO {" << contCaso+1 << "}" << endl;
	for(Cont = 0; Cont < renaPuxa; Cont++){
		cout << Cont+1 << " - " << R[Cont].Nome << endl;
	}
}

char Nome[110];
double Altura;
int Peso, Idade, casoTeste, renaTotal, renaPuxa, Cont, contCaso;
int main(){	
	cin >> casoTeste;
		
	if(casoTeste >= 1){
		
		for(contCaso = 0; contCaso < casoTeste; contCaso++){	
			cin >> renaTotal >> renaPuxa;
			Rena R[renaTotal];
			
			for(Cont = 0; Cont < renaTotal; Cont++){
				cin >> Nome >> Peso >> Idade >> Altura;
				preencherDados(R, Nome, Peso, Idade, Altura, Cont);
			}	
					
			selectionSort(R, renaTotal);
			imprimeRena(R, renaPuxa, contCaso);
			limpaDados(R, renaTotal);			
		}
	}
	
			
	return 0;
}
