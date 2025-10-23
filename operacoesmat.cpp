#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
int idade;
double salario, altura;
char genero;
string nome;

idade = 16;
salario = 5.000,
altura = 1.57;
genero = 'F';
nome = "Yasmin Gama Pará";

cout << fixed << setprecision(5);
cout << "IDADE: " << idade << endl;
cout << "SALARIO: " << salario << endl;
cout << "ALTURA: " << altura << endl;
cout << "GENERO: " << genero << endl;
cout << "NOME: " << nome << endl;

return 0;

}
