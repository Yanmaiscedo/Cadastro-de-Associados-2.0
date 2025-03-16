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


void cadastrar_associado(vector<Associado> &associados, int &prox_codigo, vector<Dependente> &dependentes, int &prox_codigode, ofstream &Adados, ofstream &Ddados)
{
    system("cls");
    Associado novoAssociado;
    Dependente novoDependente;

    int opc;
    int num_dependentes;
    cout << "Voce deseja adicionar um novo Socio ou fazer a manutenção do cadastro de um socio ja existente? " << endl;
    cout << "1 - Adicionar novo Socio " << endl;
    cout << "2 - Fazer a manutenção de um Cadastro " << endl;
    cin >> opc;
    if (opc == 1)
    {
        novoAssociado.codigo = prox_codigo++;
        cout << "=====================Cadastro de novo Sócio=====================" << endl;
        cin.ignore();
        cout << "CPF do associado: ";
        getline(cin, novoAssociado.cpf);
        cout << "Nome do associado: ";
        getline(cin, novoAssociado.nome);
        cout << "Data de Nascimento do associado (AAAA-MM-DD): ";
        getline(cin, novoAssociado.data_nasc);
        cout << "Endereço do associado: ";
        getline(cin, novoAssociado.endereco);
        cout << "Sexo do associado (M/F): ";
        getline(cin, novoAssociado.sexo);
        cout << "Telefolefone do associado: ";
        getline(cin, novoAssociado.telefone);
        cout << "E-mail do associado: ";
        getline(cin, novoAssociado.email);
        cout << "Data de associa��o (AAAA-MM-DD): ";
        getline(cin, novoAssociado.data_associacao);
        cout << "Tipo de s�cio (propriet�rio ou contribuinte): ";
        getline(cin, novoAssociado.tipo_socio);
        cout << "Quantos dependentes estão ligados a esse associado? ";
        cin >> num_dependentes;
        cout << "================================================================" << endl;
        for (int i = 0; i < associados.size(); i++)
        {
            if (associados[novoAssociado.codigo].cpf == associados[i].cpf)
            {
                cout << "Esse cadastro já existe.";
                cout << "Deseja adicionar um novo cadastro ou substituir o existente? (1 = adicionar / 2 = substituir)";
                int op;
                cin >> op;
                if (op == 1)
                {
                    novoAssociado.mensalidade = 200 + num_dependentes * 30;
                    associados.push_back(novoAssociado);
                    cout << "Associado cadastrado com sucesso." << endl;
                    cout << "*******************************************************************************************" << endl;
                    cout << "Esse é o codigo do seu cadastro: " << endl;
                    cout << novoAssociado.codigo << endl;
                    cout << "!!!Guardio-o para caso for nescessario realizar manutenção ou exclusão de cadastro!!!" << endl;
                    cout << "*******************************************************************************************" << endl;
                }
                if (op == 2)
                {
                    novoAssociado.mensalidade = 200 + num_dependentes * 30;
                    associados.insert(associados.begin() + novoAssociado.codigo, associados[i]); ////////////////////////////////////////////////
                    cout << "Associado alterado com sucesso." << endl;
                    cout << "*******************************************************************************************" << endl;
                    cout << "Esse é o codigo do seu cadastro: " << endl;
                    cout << novoAssociado.codigo << endl;
                    cout << "!!!Guardio-o para caso for nescessario realizar manutenção ou exclusão de cadastro!!!" << endl;
                    cout << "*******************************************************************************************" << endl;
                }
            }
            else
            {
                novoAssociado.mensalidade = 200 + num_dependentes * 30;
                associados.push_back(novoAssociado);
                cout << "Associado cadastrado com sucesso." << endl;
                cout << "*******************************************************************************************" << endl;
                cout << "Esse é o codigo do seu cadastro: " << endl;
                cout << novoAssociado.codigo << endl;
                cout << "!!!Guardio-o para caso for nescessario realizar manutenção ou exclusão de cadastro!!!" << endl;
                cout << "*******************************************************************************************" << endl;
            }
        }
        if (num_dependentes > 0)
        {
            for (int i = 0; i < num_dependentes; i++)
            {
                novoDependente.codigo = prox_codigode++;
                novoDependente.codExterno = stoi(novoAssociado.data_associacao.substr(0, 4)) * 1000 + novoDependente.codigo;
                novoDependente.cpf_associado = novoAssociado.cpf;

                cout << "===================Dependentes do novo Sócio===================" << endl;
                cin.ignore();
                cout << "Nome do dependente: ";
                getline(cin, novoDependente.nome);
                cout << "Data de nascimento do dependente (AAAA-MM-DD): ";
                getline(cin, novoDependente.data_nasc);
                cout << "Sexo do dependente (M/F): ";
                getline(cin, novoDependente.sexo);
                cout << "Telefone do dependente: ";
                getline(cin, novoDependente.telefone);
                cout << "Email do dependente: ";
                getline(cin, novoDependente.email);
                cout << "================================================================" << endl;
                cout << "Dependente cadastrado com sucesso." << endl;
                cout << "*******************************************************************************************" << endl;
                cout << "Esse é o codigo do seu dependente: " << endl;
                cout << novoDependente.codigo << endl;
                cout << "!!!Guardio-o para caso for nescessario realizar manutenção ou exclusão de cadastro!!!" << endl;
                cout << "*******************************************************************************************" << endl;
                dependentes.push_back(novoDependente);
            }
        }
    }
    else if (opc == 2)
    {
        int codigo_de_manutencao;
        cout << "Digite o codigo do cadastro que deseja alterar: ";
        cin >> codigo_de_manutencao;

        if (codigo_de_manutencao >= 0 && codigo_de_manutencao < associados.size())
        {
            cout << "=====================Manutenção de cadastro de Sócio=====================" << endl;
            cin.ignore();
            cout << "CPF do associado: ";
            getline(cin, associados[codigo_de_manutencao].cpf);
            cout << "Nome do associado: ";
            getline(cin, associados[codigo_de_manutencao].nome);
            cout << "Data de Nascimento do associado (AAAA-MM-DD): ";
            getline(cin, associados[codigo_de_manutencao].data_nasc);
            cout << "Endereço do associado: ";
            getline(cin, associados[codigo_de_manutencao].endereco);
            cout << "Sexo do associado (M/F): ";
            getline(cin, associados[codigo_de_manutencao].sexo);
            cout << "Telefolefone do associado: ";
            getline(cin, associados[codigo_de_manutencao].telefone);
            cout << "E-mail do associado: ";
            getline(cin, associados[codigo_de_manutencao].email);
            cout << "Data de associa��o (AAAA-MM-DD): ";
            getline(cin, associados[codigo_de_manutencao].data_associacao);
            cout << "Tipo de s�cio (propriet�rio ou contribuinte): ";
            getline(cin, associados[codigo_de_manutencao].tipo_socio);
            cout << "Associado alterado com sucesso." << endl;
            cout << "*******************************************************************************************" << endl;
            cout << "Esse é o codigo do seu cadastro: " << endl;
            cout << associados[codigo_de_manutencao].codigo << endl;
            cout << "!!!Guardio-o para caso for nescessario realizar manutenção ou exclusão de cadastro!!!" << endl;
            cout << "*******************************************************************************************" << endl;
            cout << "================================================================" << endl;
        }
        else
        {
            cout << "codigo inválido." << endl;
        }
    }
}

void cadastrar_dependente(vector<Dependente> &dependentes, int &prox_codigode, vector<Associado> &associados, ofstream &Adados, ofstream &Ddados)
{
    system("cls");
    Associado novoAssociado;
    Dependente novoDependente;

    int opc;
    int num_dependentes;
    cout << "Voce deseja adicionar um novo Dependente ou fazer a manutenção do cadastro de um dependente ja existente? " << endl;
    cout << "1 - Adicionar novo Dependente " << endl;
    cout << "2 - Fazer a manutenção de um Cadastro " << endl;
    cin >> opc;
    if (opc == 1)
    {
        novoDependente.codigo = prox_codigode++;
        novoDependente.codExterno = 0;
        cout << "===================Cadastro de um novo dependente===================" << endl;
        cin.ignore();
        cout << "CPF do associado (respons�vel): ";
        getline(cin, novoDependente.cpf_associado);
        cout << "Nome do dependente: ";
        getline(cin, novoDependente.nome);
        cout << "Data de nascimento do dependente (AAAA-MM-DD): ";
        getline(cin, novoDependente.data_nasc);
        cout << "Sexo do dependente (M/F): ";
        getline(cin, novoDependente.sexo);
        cout << "Telefone do dependente: ";
        getline(cin, novoDependente.telefone);
        cout << "Email do dependente: ";
        getline(cin, novoDependente.email);
        cout << "====================================================================" << endl;
        for (int i = 0; i < novoDependente.codigo; i++)
        {
            if (novoDependente.cpf_associado[novoDependente.codigo] == novoDependente.cpf_associado[i])
            {
                cout << "Esse CPF já possue um dependente vinculado a ele.";
                cout << "Deseja adicionar um novo dependente ou substituir o existente? (1 = adicionar / 2 = substituir)";
                int op;
                cin >> op;
                if (op == 1)
                {
                    novoAssociado.mensalidade = 200 + num_dependentes * 30;
                    dependentes.push_back(novoDependente);
                    cout << "====================================================================" << endl;
                    cout << "*******************************************************************************************" << endl;
                    cout << "Dependente cadastrado com sucesso." << endl;
                    cout << "Esse é o codigo do seu dependente: " << endl;
                    cout << novoDependente.codigo << endl;
                    cout << "!!!Guardio-o para caso for nescessario realizar manutenção ou exclusão de cadastro!!!" << endl;
                    cout << "*******************************************************************************************" << endl;
                }
                else if (op == 2)
                {
                    novoAssociado.mensalidade = 200 + num_dependentes * 30;
                    dependentes.insert(dependentes.begin() + novoDependente.codigo, dependentes[i]);
                    cout << "====================================================================" << endl;
                    cout << "*******************************************************************************************" << endl;
                    cout << "Dependente alterado com sucesso." << endl;
                    cout << "Esse é o codigo do seu dependente: " << endl;
                    cout << novoDependente.codigo << endl;
                    cout << "!!!Guardio-o para caso for nescessario realizar manutenção ou exclusão de cadastro!!!" << endl;
                    cout << "*******************************************************************************************" << endl;
                }
            }
            else
            {
                novoAssociado.mensalidade = 200 + num_dependentes * 30;
                dependentes.push_back(novoDependente);
                cout << "====================================================================" << endl;
                cout << "*******************************************************************************************" << endl;
                cout << "Dependente cadastrado com sucesso." << endl;
                cout << "Esse é o codigo do seu dependente: " << endl;
                cout << novoDependente.codigo << endl;
                cout << "!!!Guardio-o para caso for nescessario realizar manutenção ou exclusão de cadastro!!!" << endl;
                cout << "*******************************************************************************************" << endl;
            }
        }
    }
    else if (opc == 2)
    {
        int codigo_de_manutencao;
        cout << "Digite o codigo do cadastro que deseja alterar: ";
        cin >> codigo_de_manutencao;

        if (codigo_de_manutencao >= 0 && codigo_de_manutencao < dependentes.size())
        {
            cout << "===================Manutecao de cadastro de dependente===================" << endl;
            cin.ignore();
            cout << "CPF do associado (respons�vel): ";
            getline(cin, dependentes[codigo_de_manutencao].cpf_associado);
            cout << "Nome do dependente: ";
            getline(cin, dependentes[codigo_de_manutencao].nome);
            cout << "Data de nascimento do dependente (AAAA-MM-DD): ";
            getline(cin, dependentes[codigo_de_manutencao].data_nasc);
            cout << "Sexo do dependente (M/F): ";
            getline(cin, dependentes[codigo_de_manutencao].sexo);
            cout << "Telefone do dependente: ";
            getline(cin, dependentes[codigo_de_manutencao].telefone);
            cout << "Email do dependente: ";
            getline(cin, dependentes[codigo_de_manutencao].email);
            cout << "Dependente alterado com sucesso." << endl;
            cout << "*******************************************************************************************" << endl;
            cout << "Esse é o codigo do seu dependente: " << endl;
            cout << dependentes[codigo_de_manutencao].codigo << endl;
            cout << "!!!Guardio-o para caso for nescessario realizar manutenção ou exclusão de cadastro!!!" << endl;
            cout << "*******************************************************************************************" << endl;
            cout << "====================================================================" << endl;
        }
    }
}

void cadastrar_visitante(vector<Visitante> &visitantes, int &prox_codigovi, vector<Associado> &associados, int &prox_codigo, vector<Dependente> &dependentes, int &prox_codigode, ofstream &Adados, ofstream &Vdados, ofstream &Ddados)
{
    system("cls");
    Visitante novoVisitante;

    string cpf_associado;
    cout << "CPF do associado relacionado: ";
    getline(cin, cpf_associado);

    bool associado_encontrado = false;
    for (const Associado &associado : associados)
    {
        if (associado.cpf == cpf_associado)
        {
            novoVisitante.codigo_associado = to_string(associado.codigo);
            associado_encontrado = true;
            break;
        }
    }

    if (!associado_encontrado)
    {
        cout << "Associado n�o encontrado. O visitante deve estar vinculado a um associado." << endl;
        return;
    }

    cin.ignore();
    cout << "Nome do visitante: ";
    getline(cin, novoVisitante.nome);
    cout << "Data de nascimento do visitante (AAAA-MM-DD): ";
    getline(cin, novoVisitante.data_nasc);
    cout << "Sexo do visitante (M/F): ";
    getline(cin, novoVisitante.sexo);
    cout << "Data da visita (inicial) (AAAA-MM-DD): ";
    getline(cin, novoVisitante.data_visita_inicial);
    cout << "Data da visita (final) (AAAA-MM-DD): ";
    getline(cin, novoVisitante.data_visita_final);
    cin.ignore();
    cout << "====================================================================" << endl;

    int num_visitas;

    int idade_visitante;
    for (int i; i < visitantes.size(); i++)
    {
        if (novoVisitante.cpf[novoVisitante.codigo] == novoVisitante.cpf[i])
        {
            num_visitas++;
            if (num_visitas >= 3)
            {
                cout << "Numero máximo de visitas alcançado!!!" << endl
                     << "Para contiunuar tornece um Associado ou um Dependente!!!" << endl;
                cout << "Informe sua idade: ";
                cin >> idade_visitante;
                if (idade_visitante >= 18)
                {
                    cadastrar_associado(associados, prox_codigo, dependentes, prox_codigode, Adados, Ddados);
                }
                else if (idade_visitante < 18)
                {
                    cadastrar_dependente(dependentes, prox_codigode, associados, Adados, Ddados);
                }
            }
            else
            {
                visitantes.push_back(novoVisitante);
                cout << "Visitante cadastrado com sucesso." << endl;
                cout << "====================================================================" << endl;
            }
        }
        else
        {
            visitantes.push_back(novoVisitante);
            cout << "Visitante cadastrado com sucesso." << endl;
            cout << "====================================================================" << endl;
        }
    }
}

void registrar_visita(vector<Visitante> &visitantes, int &prox_codigovi, vector<Associado> &associados, int &prox_codigo, vector<Dependente> &dependentes, int &prox_codigode, ofstream &Adados, ofstream &Vdados, ofstream &Ddados)
{
    system("cls");
    Visitante novoVisitante;

    string cpf_associado;
    cout << "CPF do associado relacionado: ";
    getline(cin, cpf_associado);

    bool associado_encontrado = false;
    for (const Associado &associado : associados)
    {
        if (associado.cpf == cpf_associado)
        {
            novoVisitante.codigo_associado = to_string(associado.codigo);
            associado_encontrado = true;
            break;
        }
    }

    if (!associado_encontrado)
    {
        cout << "Associado n�o encontrado. O visitante deve estar vinculado a um associado." << endl;
        return;
    }

    cin.ignore();
    cout << "Nome do visitante: ";
    getline(cin, novoVisitante.nome);
    cout << "Data de nascimento do visitante (AAAA-MM-DD): ";
    getline(cin, novoVisitante.data_nasc);
    cout << "Sexo do visitante (M/F): ";
    getline(cin, novoVisitante.sexo);
    cout << "Data da visita (inicial) (AAAA-MM-DD): ";
    getline(cin, novoVisitante.data_visita_inicial);
    cout << "Data da visita (final) (AAAA-MM-DD): ";
    getline(cin, novoVisitante.data_visita_final);
    cin.ignore();
    cout << "====================================================================" << endl;

    int num_visitas;

    int idade_visitante;
    for (int i; i < visitantes.size(); i++)
    {
        if (novoVisitante.cpf[novoVisitante.codigo] == novoVisitante.cpf[i])
        {
            num_visitas++;
            if (num_visitas >= 3)
            {
                cout << "Numero máximo de visitas alcançado!!!" << endl
                     << "Para contiunuar tornece um Associado ou um Dependente!!!" << endl;
                cout << "Informe sua idade: ";
                cin >> idade_visitante;
                if (idade_visitante >= 18)
                {
                    cadastrar_associado(associados, prox_codigo, dependentes, prox_codigode, Adados, Ddados);
                }
                else if (idade_visitante < 18)
                {
                    cadastrar_dependente(dependentes, prox_codigode, associados, Adados, Ddados);
                }
            }
            else
            {
                visitantes.push_back(novoVisitante);
                cout << "Visitante cadastrado com sucesso." << endl;
                cout << "====================================================================" << endl;
            }
        }
        else
        {
            visitantes.push_back(novoVisitante);
            cout << "Visitante cadastrado com sucesso." << endl;
            cout << "====================================================================" << endl;
        }
    }
}

int calcular_idade(const string &data_nasc)
{
    time_t now;
    struct tm birthdate;
    time(&now);
    birthdate = *localtime(&now);
    sscanf(data_nasc.c_str(), "%d-%d-%d", &birthdate.tm_year, &birthdate.tm_mon, &birthdate.tm_mday);
    birthdate.tm_year -= 1900;
    birthdate.tm_mon--;
    time_t birthtime = mktime(&birthdate);
    time_t dif = difftime(now, birthtime);
    return dif / (60 * 60 * 24 * 365);
}

void aviso_maioridade_dependentes(const vector<Dependente> &dependentes)
{
    Dependente novoDependente;
    system("cls");
    cout << "Dependentes que atingiram a maioridade:" << endl;
    for (int i = 0; i < dependentes.size(); i++)
    {
        int idade = calcular_idade(novoDependente.data_nasc);
        if (idade >= 18)
        {
            cout << "Nome: " << novoDependente.nome << ", CPF: " << novoDependente.cpf_associado << endl;
        }
    }
}

void salvaAD(vector<Associado> &associados, vector<Dependente> &dependentes, ofstream &Adados, ofstream &Ddados)
{
    // fstream Adados("Cadastros_de_associados.txt", ios::trunc | ios::out);
    //  fstream Ddados("Cadastros_de_dependentes.txt", ios::trunc | ios::out);
    Dependente novoDependente;
    Associado novoAssociado;

    if (Adados.is_open() && Ddados.is_open())
    {
        for (const Associado &associado : associados)
        {
            Adados << novoAssociado.nome << ',' << novoAssociado.data_nasc << ',' << novoAssociado.email << endl;
            for (const Dependente &dependente : dependentes)
            {
                if (dependente.cpf_associado == associado.cpf)
                {
                    Ddados << "  Dependente - Nome: " << novoDependente.nome << ", Data de Nascimento: " << novoDependente.data_nasc << endl;
                }
            }
        }

        // Fechar o arquivo após a escrita
        Adados.close();
        Ddados.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo." << endl;
        return; // Encerrar o programa com código de erro
    }
}

void salvaV(vector<Visitante> &visitantes, vector<Associado> &associados, ofstream &Adados, ofstream &Vdados)
{
    // fstream Vdados("Cadastros_de_visitantes.txt", ios::trunc | iostream::out);
    // fstream Adados("Cadastros_de_associados.txt", ios::trunc | iostream::out);

    if (Vdados.is_open())
    {
        for (const Associado &associado : associados)
        {
            Vdados << "Associado - CPF: " << associado.cpf << ", Nome: " << associado.codigo << endl;
            for (const Visitante &visitante : visitantes)
            {
                if (visitante.codigo_associado == to_string(associado.codigo))
                {
                    Vdados << "  Visitante - Nome: " << visitante.nome << ", Data de Visita: " << visitante.data_visita_inicial << " a " << visitante.data_visita_final << endl;
                }
            }
        }
    }
}

void relatorio_dependentes_associados(vector<Associado> &associados, vector<Dependente> &dependentes, ofstream &Adados, ofstream &Ddados)
{
    Associado novoAssociado;
    Dependente novoDependente;
    system("cls");
    int i;
    cout << "Relatrio de dependentes/associados:" << endl;
    for (size_t i = 0; i < associados.size(); ++i)
    {
        cout << "Índice: " << associados[i].codigo << ", Nome: " << associados[i].nome << ", Idade: " << associados[i].data_nasc << ", E-mail: " << associados[i].email << endl;
        for (size_t j = 0; j < dependentes.size(); ++j)
        {
            if (novoDependente.cpf_associado == novoAssociado.cpf)
            {
                cout << "  Dependente - Nome: " << dependentes[j].nome << ", Data de Nascimento: " << dependentes[j].data_nasc << endl;
            }
        }
    }
    cout << endl;
}
/*
// Função para excluir algum cadastro que poderia ser implementada
 void exclusao_de_cadastro(vector<Associado> &associados, int &prox_codigo, vector<Dependente> &dependentes, int &prox_codigode)
{
    Dependente dependente;
    Associado associado;
    string nomizin;
    int opção, Acpf, D.cpf;
    cout << "Deseja excluir o cadastro de um Associado ou de um Dependente (1 = Associado / 2= Dependente)?";
    cin >> opção;
    if (opção == 1)
    {
        cout << "digite o cpf do associado que desejas excluir: ";
        cin >> Acpf;
        for (int i = 0; i < associado.codigo; i++)
        {
            if (Acpf == associado.cpf[i]) ////////////////////////////////////////////////////////////////////
            {
                // associados.erase(associado[i]);
                cout << "Associado excluido com sucesso!!!";
                for (int i = 0; i < associado.codigo; i++)
                {
                    for (int i = 0; i < dependente.codigo; i++)
                    {
                        if (dependente.cpf_associado[i] == Acpf) ////////////////////////////////////////////////////////////////////
                        {
                            // dependentes.erase(dependente[i]);
                            cout << "Dependentes ligados a esse associado excluidos com sucesso!!!";
                        }
                        else
                            cout << "Esse nome não esta cadastrado, c é besta?";
                    }
                }
            }
            else
                cout << "Esse cpf não esta cadastrado, c é besta?";
        }
    }
    else if (opção == 2)
    {
        cout << "digite o cpf do associado responsável pelo dependente que desejas excluir: ";
        cin >> Acpf;
        for (int i = 0; i < associado.codigo; i++)
        {
            if (Acpf == dependente.cpf_associado[i])
            {
                for (int i = 0; i < dependente.codigo; i++)
                {
                    cout << "Digite o nome do dependente: ";
                    cin << nomizin;
                    if (nomizin == dependente.nome[i]) ////////////////////////////////////////////////////////////////////
                    {
                        // dependentes.erase(dependente[i]);
                        cout << "Dependente excluido com sucesso!!!";
                    }
                    else
                        cout << "Esse nome não esta cadastrado, c é besta?";
                }
            }
            else
                cout << "Esse cpf não esta cadastrado, c é besta?";
        }
    }
}
*/
void relatorio_visitas_por_associado(vector<Visitante> &visitantes, vector<Associado> &associados, ofstream &Adados, ofstream &Vdados)
{
    Associado associado;
    Dependente dependente;
    Visitante visitante;

    system("cls");
    cout << "Relat�rio de visitas por associado:" << endl;
    for (size_t i = 0; i < associados.size(); ++i)
    {
        cout << "Associado - CPF: " << associados[i].cpf << ", Nome: " << associados[i].codigo << endl;
        for (size_t j = 0; j < visitantes.size(); ++j)
        {
            if (visitante.codigo_associado == to_string(associado.codigo))
            {
                cout << "  Visitante - Nome: " << visitantes[j].nome << ", Data de Visita: " << visitantes[j].data_visita_inicial << " a " << visitantes[j].data_visita_final << endl;
            }
        }
    }
}


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