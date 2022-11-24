// p2MRodrigo.cpp : Mini Mini Produ��o de C++ Avan�ado (0810 - UFCD 15)
// Elaborado por Rodrigo Fernandes

#include <iostream>
#include <locale> // Para uso de acentua��o
#include <string> // Para uso do getline()
#include <conio.h> // Para uso do _getch()
#include <fstream> // Para trabalhar com ficheiros
#include <Windows.h> // Para uso do temporizador

using namespace std; // Para facilitar o uso dos couts e cins

struct avaliacao { // Struct com nomes e notas a serem validadas
	string nomes;
	float notas;
};

avaliacao curso[15]; // Array da struct

int n = 5; // Vari�vel global para incremento no array

// Fun��o menor de intermit�ncia
void fIntermitencia(int t) { 
	cout << "."; Sleep(t); cout << "."; Sleep(t);
	cout << "."; Sleep(t); cout << "."; Sleep(t);
	cout << "."; Sleep(t); cout << "."; Sleep(t);
	cout << "."; Sleep(t);
}

// In�cio das fun��es principais

// Fun��o que imprime as op��es do menu
void fDesenhaMenu() {
	
	cout << endl << "######   CURSO DE PROGRAMA��O   ######" << endl;
	cout << endl << " --- MENU DE OP��ES --- " << endl;
	cout << " 1. Lista os alunos matriculados" << endl;
	cout << " 2. Adiciona novo aluno" << endl;
	cout << " 3. Insere notas em falta" << endl;
	cout << " 4. Regista os validados no ficheiro de texto" << endl;
	cout << " 5. Lista os validados diretamente do ficheiro" << endl;
	cout << endl << " ESC - sair" << endl;
}

// Fun��o que inicializa os alunos previamente cadastrados
void fInicializaAlunos() {
	curso[0].nomes = "Silvano";
	curso[1].nomes = "Hugo";
	curso[2].nomes = "F�bio";
	curso[3].nomes = "Ana";
	curso[4].nomes = "Carla";
}

// Fun��o que lista os alunos matriculados
void f1ListarNomes() {
	system("cls");
	cout << endl << "Alunos matriculados: " << endl;

	for (int i = 0; i < 15; i++) {
		if (curso[i].nomes != "") {
			cout << i+1 << ") " << curso[i].nomes << endl;
		}	
	}
	cout << endl;
	fIntermitencia(300);
	cout << endl << endl;
}

// Fun��o que realiza a matricula de novo aluno
void f2AdicionarNovoAluno() {
	system("cls");
	string nome;

	if (n < 15) {
		cout << endl << "Qual o nome do aluno novo? ";
		cin >> curso[n].nomes;
		n++;
	}
	else {
		cout << endl << "Vagas esgotadas!" << endl;
	}
	fIntermitencia(300);
	cout << endl;
}

// Fun��o para inserir notas em falta
void f3InserirNotas() {
	system("cls");
	cout << endl;

	for (int i = 0; i < 15; i++) {
		if (curso[i].notas == NULL && curso[i].nomes != "") {
			cout << "Insira a nota do aluno: " << curso[i].nomes << endl;
			cout << "Valor: ";
			cin >> curso[i].notas;
		}
	}
	cout << endl;
	fIntermitencia(300);
	cout << endl << endl;
}

// Fun��o para identificar quem ser� validado e enviar o nome para o ficheiro
void f4RegistaValidados() {
	system("cls");
	string s;
	ofstream ofp("validados.txt");

	for (int i = 0; i < 15; i++) {
		if (curso[i].notas > 10) {
			if (curso[i].nomes != "") {
				ofp << curso[i].nomes << endl;
			}
		}
	}
	ofp.close();
	cout << endl << "Os alunos validados foram registados!" << endl << endl;
	fIntermitencia(300);
	cout << endl << endl;
}

// Fun��o para buscar os nomes dos validados diretamente do ficheiro
string fPegarNome(int n) {
	string s, nome;
	int p = 1;
	ifstream ifp("validados.txt");

	while (getline(ifp, s)) {
		if (p == n) {
			nome = s;
		}
		p++;
	}
	ifp.close();

	return nome;
}

// Fun��o para listar os nomes dos validados a partir do ficheiro
void f5ListarNomesValidados() {
	system("cls");
	string s;
	cout << endl << "Lista de alunos validados:" << endl;

	for (int i = 1; i <= 15; i++) {
		if (curso[i].nomes != "") {
			s = fPegarNome(i);
			cout << s << endl;
		}
	}
	fIntermitencia(300);
	cout << endl << endl;
}

// Fun��o main
int main() {
	// Configura��o de acentua��o
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);

	fInicializaAlunos();
	char op;
	
	// Op��es do menu por acesso �s fun��es
	do {
		fDesenhaMenu();
		cout << endl << "Insira uma op��o: ";
		op = _getch();

		switch (op) {

		case '1': f1ListarNomes();				break;
		case '2': f2AdicionarNovoAluno();		break;
		case '3': f3InserirNotas();				break;
		case '4': f4RegistaValidados();			break;
		case '5': f5ListarNomesValidados();		break;

		default: cout << endl << "Op��o Inv�lida!" << endl;				break;
		}

	} while (op != 27); // Para finalizar o programa
}
