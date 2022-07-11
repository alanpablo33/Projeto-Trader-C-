# Aprendendo-c++
#include <iostream> // para escrever
#include <fstream> // para armazenar em arquivo txt
#include <string> // para utilizar string
#include <cstring> // para utilizar string
#include <time.h> // manipular data tempo

using namespace std;

/* Criar um Programa que Receba a Data da Operação, 
valor da entrada e faça a meta que e 10% ganho e a perda que e 5% (isso de acordo com o valor da entrada), e Documente tudo em um arquivo em TXT, com a Data de cada dia.
Nesse Documento deve ter o valor do ganho ou perda do dia separado do valor da entrada, ainda deve ter um campo onde vai ter uma OBS, do ocorrido no dia para estudos futuros.
*/ 

/* Segunda Parte Fazer com que esse programa seja salvo e no dia seguinte ao entrar novamente ele puxe o ultimo valor da Banca para Ser somada ou subitraida com o valor de gain e loss dos proximos dias */


//codigo para mostrar data e Hora Local
const std::string data_hora(){
time_t     agora = time(0);
struct tm  tstruct;
char       buf[80];
tstruct = *localtime(&agora);
  
strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
return buf;
std::cout << "Data e Hora Local: " << data_hora() << std::endl;
getchar();  // aguarde a entrada do teclado
}

//variavel global da banca inicial
float inicial_banca;
float *pi; // ponteiro da Banca Inicial

//codigo para inserir o valor da banca inicial do Trader
float banca_inicial(){
cout << "Digite o Valor da Sua Banca INICIAL: " << endl;

cin >> inicial_banca;
pi= &inicial_banca; //endereço do ponteiro da Banca Inicial
return *pi;
}

//codigo para inserir o valor da entrada no dia da operação
int operacao_do_dia(){
float entrada;
float meta;
float perda;
cout <<"Digite o Valor da sua entrada: "<< endl;
cin >> entrada;
cout <<"Sua entrada e de: " << entrada <<endl;
meta= 10 * entrada / 100; // calcular meta de ganho
perda = 5 * entrada / 100; // calcular limite da perda
cout <<"Meta Calculada : "<< meta <<endl;
cout<<"Limite de Perda Calculada :  "<< perda << endl;
return entrada;
}

//variavel gain global
float gain;
//codigo para inserir valor do gain
float resultado_gain(){
cout << "Digite seu Gain: "<< endl;
cin >> gain; 
return gain;
}

//variavel Loss global
float loss;

//codigo para inserir valor do loss
float resultado_loss(){
cout << "Digite seu LOSS: "<< endl;
cin >> loss;
return loss;
}

//variavel banca global
float atual_banca ;

//codigo para atualizar o valor da banco de acordo com gain ou loss
float banca_atual(){
//se gain for maior que 0 some o gain com a atual_banca e ira obter o falor atualizado da banca.
if(gain>0){
atual_banca = *pi + gain;
}
//se o loss for maior que 0 subitraia o valor do loss na atual_banca e ira obter o valor da atual_banca atualizado
if(loss>0){
atual_banca= *pi- loss;
}
cout << "Valor da Sua Banca Atual e de: " <<atual_banca << endl;
return atual_banca;
}

//codigos para detalhar a entrada do dia
string detalhes(){
string detalhe;
cin.ignore();// serve para pular o \n que fica armazenado no buffer antes do getline.
cout <<"Descreva como foi sua entrada de hoje: " <<endl;
getline (cin , detalhe);
return detalhe;
}

//codigo para detalhar erros do dia
string erros(){
string erro;
cin.ignore();// serve para pular o \n que fica armazenado no buffer antes do getline.
cout <<"Teve Algum Erro Hoje? " <<endl;
getline (cin , erro);
return erro;
}

//codigo para colocar observações adicionais
string adicionais(){
string adicionai;
cin.ignore();// serve para pular o \n que fica armazenado no buffer antes do getline.
cout <<"Observações sobre a Operação:  " <<endl;
getline (cin , adicionai);
return adicionai;
}


//iniciar o programa
int main(){

//codigo para a abertura do arquivo txt ENTRADA.
ifstream arquivo_valor_banca_atual;
string linha; //variavel para ler o que esta dentro do arquivo txt

arquivo_valor_banca_atual.open("Banca Atual.txt");
if(arquivo_valor_banca_atual.is_open()){
  
while(getline (arquivo_valor_banca_atual,linha)){
cout << linha <<endl;
}
}
else{ cout << "Não Foi Possivel Abrir o Arquivo" << endl;
}
arquivo_valor_banca_atual.close(); 


ofstream arquivo_banca , arquivo_resto , arquivo_banca_atual; //Declarando variavel arquivo SAIDA

arquivo_banca.open("Banca Inicial.txt",ios::app); //Criando Arquivos txt
arquivo_resto.open("Informações Do Dia.txt",ios::app);//crinado arquivo txt
arquivo_banca_atual.open("Banca Atual.txt");//crinado arquivo txt

arquivo_resto <<"_____________________________________________"<<endl;
arquivo_resto <<"Data e Hora da Operação: "<< data_hora() << "\n" ; // coloca a DATA e Hora Automaticamente no Documento

arquivo_banca <<"_____________________________________________"<<endl;
arquivo_banca <<"Data e Hora: "<< data_hora() << "\n" ; // coloca a DATA e Hora Automaticamente no Documento


arquivo_banca <<"VALOR DE BANCA CADASTRADO: " << banca_inicial() <<"\n \n"; // atribuindo o valor da Banca ao arquivo txt

//salvar valores
arquivo_resto <<"SUA ENTRADA FOI DE: " << operacao_do_dia() <<"\n";
arquivo_resto <<"SEU GAIN FOI DE: " << resultado_gain() <<"\n";
arquivo_resto <<"SEU LOSS FOI DE: " << resultado_loss() <<"\n";

//salvar valores
arquivo_resto<<"VALOR DE BANCA ATUAL: "<< banca_atual() <<"\n";
arquivo_banca_atual <<"_____________________________________________"<<endl;
arquivo_banca_atual <<"Data e Hora da Operação: "<< data_hora() << "\n" ; // coloca a DATA e Hora Automaticamente no Documento
arquivo_banca_atual <<"VALOR DA BANCA ATUALIZADO: " <<  banca_atual() <<"\n \n"; // atribuindo o valor da Banca ao arquivo txt


//salvar detalhes da operação
arquivo_resto <<"Descreva como foi sua entrada de hoje: "<<"\n"<< detalhes() << "\n";
arquivo_resto <<"Teve Algum Erro Hoje? "<<"\n"<< erros() << "\n";
arquivo_resto <<"Observações sobre a Operação: "<<"\n"<< adicionais() << "\n";
arquivo_resto <<"_____________________________________________"<<endl;


arquivo_banca_atual.close(); // fechando o arquivo txt
arquivo_banca.close(); // fechando o arquivo txt
arquivo_resto.close(); // fechando o arquivo txt


}
