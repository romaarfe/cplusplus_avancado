// Rodrigo.cpp : Produ��o de C++ Avan�ado (0810 - UFCD 15)
// Elaborado por Rodrigo Fernandes

#include <iostream>
#include <locale> // Para uso de acentua��o
#include <string> // Para uso do getline()
#include <conio.h> // Para uso do _getch()
#include <fstream> // Para trabalhar com ficheiros
#include <Windows.h> // Para uso do temporizador

using namespace std; // Para facilitar o uso dos couts e cins

// Fun��o menor de intermit�ncia
void fIntermitencia(int t) {
	cout << "."; Sleep(t); cout << "."; Sleep(t);
	cout << "."; Sleep(t); cout << "."; Sleep(t);
	cout << "."; Sleep(t); cout << "."; Sleep(t);
	cout << "."; Sleep(t);
}

// In�cio das fun��es principais

// Fun��o que imprime as op��es do menu
void fdesenhaMenu() {
	cout << endl << " --- MENU DE OP��ES --- " << endl;
	cout << " 1. Inicializa o ficheiro de texto com 16 nomes" << endl;
	cout << " 2. Inicializa outro ficheiro de texto com 16 localidades" << endl;
	cout << " 3. Lista nomes e respetivas localidades" << endl;
	cout << " 4. Contar ocorr�ncia da localidade e listar nomes correspondentes" << endl;
	cout << " 5. Verificar nome e alterar localidade" << endl;

	cout << endl << " ESC - sair" << endl;
}

// Fun��o que inicializa os 16 nomes
void f1InicializaNomes() {

	ofstream ofp("nomes.txt");

	ofp << "Ana Rita Cunha" << "\n";
	ofp << "Bela Costa Silva" << "\n";
	ofp << "Carlos Alberto Costa" << "\n";
	ofp << "Carlos Serafim Ferreira" << "\n";
	ofp << "Daniel Bastos Gomes" << "\n";
	ofp << "Diogo Silva Ferraz" << "\n";
	ofp << "Elvira Gomes Pendes" << "\n";
	ofp << "Fernanda Maria Silva" << "\n";
	ofp << "Fernando Gomes Barros" << "\n";
	ofp << "Guilherme Alexandre Barros" << "\n";
	ofp << "Hilda Fonseca Silva" << "\n";
	ofp << "Jos� Manuel Carvalho" << "\n";
	ofp << "Jos� Alberto Gomes" << "\n";
	ofp << "Maria Silv�ria Bastos" << "\n";
	ofp << "Anabela Bastos Torres" << "\n";
	ofp << "Teodoro Armando Matos" << "\n";
	ofp.close();

	cout << endl << "Ficheiro nomes.txt inicializado com sucesso!" << endl;
	fIntermitencia(300);
	cout << endl;
}

// Fun��o que inicializa as 16 localidades
void f2InicializaLocalidades() {

	ofstream ofp("localidades.txt");

	ofp << "Braga" << endl
		<< "Porto" << endl
		<< "Lisboa" << endl
		<< "Lisboa" << endl
		<< "Porto" << endl
		<< "Braga" << endl
		<< "Braga" << endl
		<< "Porto" << endl
		<< "Lisboa" << endl
		<< "Lisboa" << endl
		<< "Porto" << endl
		<< "Braga" << endl
		<< "Braga" << endl
		<< "Porto" << endl
		<< "Lisboa" << endl
		<< "Braga" << endl;
	ofp.close();

	cout << endl << "Ficheiro localidades.txt inicializado com sucesso!" << endl;
	fIntermitencia(300);
	cout << endl;
}

// Fun��o para buscar o nome
string fPegarNome(int n) {
	string s, nome;
	int p = 1;

	ifstream ifp("nomes.txt");
	while (getline(ifp, s)) {
		if (p == n) {
			nome = s;
		}
		p++;
	}
	ifp.close();

	return nome;
}

// Fun��o para buscar a localidade
string fPegarLocalidade(int n) {
	string s, localidade;
	int p = 1;

	ifstream ifp("localidades.txt");
	while (getline(ifp, s)) {
		if (p == n) {
			localidade = s;
		}
		p++;
	}
	ifp.close();

	return localidade;
}

// Fun��o para listar o nome e a localidade
void f3ListarNomesLocalidades() {
	string s, p;

	cout << endl << endl;

	for (int i = 1; i <= 16; i++) {
		s = fPegarNome(i);
		p = fPegarLocalidade(i);
		cout << s << ", " << p << endl;
	}

	cout << endl << "Nomes e localidades listados com sucesso!" << endl;
	fIntermitencia(300);
	cout << endl;
}

// Fun��o que conta ocorr�ncias e lista nomes correspondentes
void f4OcorrenciaLocalidade() {

	int contador = 0;
	string s, p,localidade;

	cout << endl << "Qual localidade quer verificar? ";
	getline(cin, localidade);

	cout << endl;
	cout << "Os moradores de " << localidade << " s�o: " << endl << endl;
	for (int i = 1; i <= 16; i++) {
		s = fPegarNome(i);
		p = fPegarLocalidade(i);
		if (p == localidade) {
			contador++;
			cout << s << endl;
		}
	}

	cout << endl << "No total, s�o " << contador << " ocorr�ncias da localidade que digitou." << endl;

	fIntermitencia(300);
	cout << endl;
}

// Fun��o que verifica nome e se exitir modifica a localidade
void f5ModificarLocalidade() {
	int contador = 0;
	string s, p, r, nomeAProcurar, novaLocalidade;
	ofstream ofp("lista.txt");
	ifstream ifp("localidades.txt");

	cout << endl << "Qual nome quer verificar? ";
	getline(cin, nomeAProcurar);

	cout << "Qual ser� a nova localidade? ";
	getline(cin, novaLocalidade);

	cout << endl;

	for (int i = 1; i <= 16; i++) {
		s = fPegarNome(i);
		p = fPegarLocalidade(i);
		if (s != nomeAProcurar) {
			ofp << p << endl;
		}
		else {
			ofp << novaLocalidade << endl;
		}
	}
	ifp.close();
	ofp.close();

	ofstream ofp2("localidades.txt");
	ifstream ifp2("lista.txt");

	while (getline(ifp2, r)) {
		ofp2 << r << endl;
	}

	ifp2.close();
	ofp2.close();

	remove("lista.txt");

	fIntermitencia(300);

}

// Fun��o main
int main() {

	setlocale(LC_ALL, ""); // Configura��o de acentua��o

	char op;

	// Op��es do menu por acesso �s fun��es
	do {

		fdesenhaMenu();
		cout << endl << "Insira uma op��o: ";
		op = _getch();

		switch (op) {

			case '1': f1InicializaNomes();			break;
			case '2': f2InicializaLocalidades();	break;
			case '3': f3ListarNomesLocalidades();	break;
			case '4': f4OcorrenciaLocalidade();		break;
			case '5': f5ModificarLocalidade();		break;

			default: "Op��o Inv�lida!";				break;
		}

	} while (op != 27); 
	
}
