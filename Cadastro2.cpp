#include <iostream>
#include <locale.h>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Associado
{
    int codigo, num_dependentes;
    string cpf, data_associacao, tipo_socio, nome, data_nasc, endereco, sexo, telefone, email;
    double mensalidade;
};

struct Dependente
{
    int codigo, codExterno;
    string cpf_associado, nome, data_nasc, sexo, telefone, email;
};

struct Visitante
{
    int codigo, num_visitas;
    string cpf, codigo_associado, nome, data_nasc, sexo, data_visita_inicial, data_visita_final;
};

int main(){
    setlocale(LC_ALL, "Portuguese");
    system("cls");

    int prox_codigo = 0;
    int prox_codigode = 0;
    int prox_codigovi = 0;

    vector<Associado> associados;
    vector<Dependente> dependentes;
    vector<Visitante> visitantes;

    return 0;
}