#include <iostream>
#include <fstream> // para armazenar em arquivo txt

using namespace std;

int main() {
ofstream arquivo_declaracao; //Declarando variavel arquivo


float x;
float banca;
float lucro;

/* Como fazer cálculo de porcentagem: passo a passo
Por exemplo, se você quer calcular 35% de 500, multiplique 35 por 500. Fazendo isso você obtém o valor de 35 x 500 = 17500; Divida o resultado obtido por 100. No exemplo, teríamos 17500/100 = 175 */

cout << "\n \n \n"<< "Nunca esqueça de declarar Seu Imposto Corretamente Day Trader na Bolça tem taxa de 20% sobre o Lucro Liquido do Trader!!" <<"\n \n \n";


cout << "Digite o Valor final da Sua Banca" <<endl;
cin >> banca;
x = (20*banca)/100;

cout << "Valor da Darf a pagar e de: " << x <<endl;

lucro = banca - x;

cout << "Seu lucro do mês e de: " << lucro << endl;



} 
