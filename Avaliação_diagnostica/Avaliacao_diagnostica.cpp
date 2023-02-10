#include <iostream>

#define TOTAL 1 //Torna-se uma vari�vel global do programa

using namespace std;

struct Contato{
    string Nome;
    string Email;
    string Endereco;
    string Telefone;
    string Cidade;
    string Estado; 
    string Observacoes;
    int Idade;
};

Contato Agenda[10];

//LEITURA DOS CONTATOS
void Ler_Contatos(Contato V[TOTAL]){
	int Count; //Contador para a repeti��o
	
	cout << "**************LEITURA DOS CONTATOS**************\n\n";
	for(Count=0; Count < TOTAL; Count++){
		cout << "\nContato [ " << Count << "]\n";
		cout << "-----------------------------\n";
		cout << "Digite o nome: ";
		cin >> V[Count].Nome;
		cout << "Digite o e-mail: ";
		cin >> V[Count].Email;
		cout << "Digite o endere�o: ";
		cin >> V[Count].Endereco;
		cout << "Digite o telefone: ";
		cin >> V[Count].Telefone;
		cout << "Digite a cidade: ";
		cin >> V[Count].Cidade;
		cout << "Digite o estado: ";
		cin >> V[Count].Estado;
		cout << "Digite as observa��es: ";
		cin >> V[Count].Observacoes;
		cout << "Digite a idade: ";
		cin >> V[Count].Idade;
		cout << "\n\n";
		
	}
}
//IMPRIME UM CONTATO
void Imprimir_Contato(Contato V[TOTAL], int Parcial, int Pos){ 	// Parcial = 0 ->
																//Total = 1 
			
					cout << "\nContato [ " << Pos << "]\n";
					cout << "-----------------------------\n";
					cout << "Nome: " << V[Pos].Nome;
					cout << "Telefone: "<< V[Pos].Telefone;
					cout << "E-mail: " << V[Pos].Email;
				
					
					if(Parcial != 1){
						cout << "Endere�o: "<< V[Pos].Endereco;
						cout << "idade: " << V[Pos].Cidade;
						cout << "Estado: "<< V[Pos].Estado;
						cout << "Observa��es: " << V[Pos].Observacoes;
						cout << "Idade: " << V[Pos].Idade;
						cout << "\n\n";		
					}
}

//IMPRIME AGENDA COMPLETA 
void Imprimir_Agenda(Contato V[TOTAL], int Parcial, string Estado){ 
	int Count; //Contador para a repeti��o
	
	cout << "**************IMPRIMINDO OS CONTATOS**************\n\n";
	for(Count=0; Count < TOTAL; Count++){
		if(Estado == "" || V[Count].Estado == Estado && V[Count].Idade >= 18){
			Imprimir_Contato(V, Count, Parcial);	
		}		
	}
	system("pause");
}


int Busca_Mais_velha(Contato V[10]){
	int Count, Pos, MaiorIdade;
	 
	for(Count == 0; Count < TOTAL; Count++){
		if(Count = 0 || MaiorIdade < V[Count].Idade){
			MaiorIdade = V[Count].Idade;
			Pos = Count;
		}
	}
}

int Opcao, OpImp;
	

void menu(Contato V[10]){
	setlocale(LC_ALL,"Portuguese");
	
	do{
		system("cls");
		cout << "[1] Agendar Pessoas \n";
		cout << "[2] Mostrar Agenda \n";
		cout << "[3] Buscar Por Estado \n";
		cout << "[4] Exibir Pessoa Mais Velha \n";
		cout << "[5] Exibir Dados\n";
		cout << "[6] Sair \n";
		cout << "Op��o: ";
		cin >> Opcao;
		
		//Analisndo a op��o escolhida
		
		switch(Opcao){
			case 1:
				Ler_Contatos(V);
				break;
			case 2:
				cout << "Forne�a um Estado";
				cin >> Estado;
				Imprimir_Agenda(V, OpImp, Estado);
				break;
			case 3: 
				Pos = Busca_Mais_velha(V);
				Imprimir_Contato(V, 0, Pos);
				system("pause");
				break;
			case 4 :
				cout << "\nImpress�o Total = (Qualquer tecla) ou Parcial (1)";
				cin >> OpImp;
				Imprimir_Agenda(V, OpImp, "");
				break;
			case 5:
				cout << "\nTem certeza que quer sair? ([6] = sim <Outro valor = N�o >)";
				cin >> Opcao;
				break;
			default:
				cout << "\nOp��o inv�lida, tente novamente";
				system("pause");
		}
		
	} while(Opcao!=5);
}

//IMRPRIME A PESSOA MAIS VELHA


int main(){
	
	menu(Agenda);	
	
	return 0;
}



