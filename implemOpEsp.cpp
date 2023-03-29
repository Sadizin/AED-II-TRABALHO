#include <iostream>
#include <conio.h>
#include <fstream>

#include "bibTAD-LA.h"
#include "bibOpEsp.h"

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void salvarDados(TNo *&no)
{
  // abrindo o arquivo em modo de escrita
  ofstream file("dados.txt");

  if (file.is_open()) {
    string no.item.dadosPessoais;

    // escrevendo as informações no arquivo
    file << "Nome: " << nome << endl;
    file << "Idade: " << idade << endl;

    file.close();
    cout << "Informações salvas com sucesso!" << endl;
  } else {
    cout << "Não foi possível abrir o arquivo." << endl;
  }

  // abrindo o arquivo em modo de leitura
  ifstream file2("dados.txt");

  if (file2.is_open()) {
    string line;

    cout << "Conteúdo do arquivo:" << endl;
    while (getline(file2, line)) { // lendo linha por linha
      cout << line << endl;
    }
    file2.close();
  } else {
    cout << "Não foi possível abrir o arquivo." << endl;
  }





TItem recuperarDados(TArvoreBin arvore)
{
    TItem item;
    ifstream arquivo("dados.txt");
    //arquivo >> item.id >> dados.nome >> dados.valor;
    arquivo.close();
    return item;
}

void limpaTela()
{
    system("cls");
}

void pausaTela()
{
    system("pause");
}

TCelula *pegaprioridade(TListaP lp, int chaveBusca)
{

    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;

    while (celAux->proximo != lp.primeiro)
    {
        if (celAux->proximo->item.dadosClinicos.urgencia == chaveBusca)
        {
            achou = true;
            return celAux;
        }
        celAux = celAux->proximo;
    }
    if (achou == false)
    {
        return NULL;
    }
}



void prioridade(TListaP lista,TFilaP &fila)
{

    for(int i=1; i<6;)
    {

        TCelula *anterior = pegaprioridade(lista,i);

        if (anterior == NULL)
        {
            i++;
        }
        else
        {
            TCelula *celAlvo;

            celAlvo = anterior->proximo;
            anterior->proximo = celAlvo->proximo;

            enfileirar(fila,celAlvo->item);
            retirarPorChave(lista,celAlvo->item.dadosPessoais.CPF);

            delete(celAlvo);
        }

    }


}

bool retirarPaciente (TArvoreBin &arvore, TListaP &lista, TFilaP &fila)
{
    double cpf;
    char confirma;
    cout << "----REMOCAO DE PACIENTE DO HOSPITAL PERMANENTEMENTE----" << endl;
    cout << "Digite o CPF do paciente (0 para sair):" << endl;
    cin >> cpf;
    if (cpf == 0)
    {
        return true;
    }
    else
    {
        if(cpf==lista.primeiro->item.dadosPessoais.CPF)
        {
            do
            {
                limpaTela();
                cout << "Voce tem certeza que deseja remover o CPF: " << cpf << " (""S"" ou ""N"")" << endl;
                cin >> confirma;
                if(confirma=='s') break;
                if(confirma=='n') return false;
            }
            while(confirma!= 's' && confirma!='n');
        }
        else
        {
            limpaTela();
            cout << "---PACIENTE AINDA NÃO FOI ATENDIDO---" << endl;
            pausaTela();
            return false;
        }
    }


    retirarPorChave(lista,cpf);

    retirarArvore(cpf,arvore.raiz);


    if(fila.frente->item.dadosPessoais.CPF==cpf)desenfileirar(fila);
    limpaTela();
    cout << "---PACIENTE REMOVIDO COM SUCESSO!---" << endl;
    pausaTela();
    return false;

}

bool darbaixa(TArvoreBin &arvore, TFilaP &fila, TListaP &lista)
{
    int cpf;
    char confirma;
    cout << "Digite o CPF do paciente (0 para sair): " << endl;
    cin >> cpf;
    if (cpf == 0)
    {
        return true;
    }
    else
    {
        if(cpf==lista.primeiro->item.dadosPessoais.CPF)
        {
            do
            {
                limpaTela();
                cout << "Voce tem certeza que deseja dar baixa no o CPF: " << cpf << " (""S"" ou ""N"")" << endl;
                cin >> confirma;
                if(confirma=='s') break;
                if(confirma=='n') return false;
            }
            while(confirma!= 's' && confirma!='n');

            arvore.raiz->item.dadosClinicos.ativo=false;
            desenfileirar(fila);
            retirarPorChave(lista,cpf);
        }
        else
        {
            limpaTela();
            cout << "---PACIENTE AINDA NÃO FOI ATENDIDO---" << endl;
            pausaTela();
        }
    }
    return false;

}


bool cadastroPaciente(TArvoreBin &arvore, TListaP &lp1)
{
    TItem paciente;

    cout << "----ENTRADA DE DADOS PESSOAIS----" << endl;

    cout << "Digite o CPF do paciente (0 para sair): ";
    cin >> paciente.dadosPessoais.CPF;

    if (paciente.dadosPessoais.CPF == 0) return true;

    cout << "Digite o nome completo do paciente: ";
    cin >> paciente.dadosPessoais.nomeCompleto;
    /*
    cout << "Digite a idade do paciente: ";
    cin >> paciente.dadosPessoais.idade;

    cout << "Digite a data de nascimento do paciente: ";
    cin >> paciente.dadosPessoais.dataNascimento;

    cout << "Filiação: " << endl;
    cout << "   Digite o nome da mae do paciente: ";
    cin >> paciente.dadosPessoais.filiacao.mae;
    cout << "   Digite o nome do pai do paciente: ";
    cin >> paciente.dadosPessoais.filiacao.pai;

    cout << "Digite o estado civil do paciente: ";
    cin >> paciente.dadosPessoais.estadoCivil;

    cout << "Digite a raca do paciente: ";
    cin >> paciente.dadosPessoais.raca;

    cout << "Digite o sexo do paciente: ";
    cin >> paciente.dadosPessoais.sexo;

    cout << "Digite a religiao do paciente: ";
    cin >> paciente.dadosPessoais.religiao;

    cout << "Digite a profissao do paciente: ";
    cin >> paciente.dadosPessoais.profissao;

    cout << "Digite a naturalidade do paciente: ";
    cin >> paciente.dadosPessoais.naturalidade;

    cout << "Endereco: " << endl;
    cout << "   Digite a rua no qual paciente reside: ";
    cin >> paciente.dadosPessoais.endereco.rua;
    cout << "   Digite o bairro no qual paciente reside: ";
    cin >> paciente.dadosPessoais.endereco.bairro;
    cout << "   Digite o numero da casa/apto no qual paciente reside: ";
    cin >> paciente.dadosPessoais.endereco.numero;
    cout << "   Digite a cidade no qual paciente reside: ";
    cin >> paciente.dadosPessoais.endereco.cidade;
    cout << "   Digite o estado no qual paciente reside: ";
    cin >> paciente.dadosPessoais.endereco.estado;

    cout << "Contato: " << endl;
    cout << "   Digite o telefone pessoal do paciente: ";
    cin >> paciente.dadosPessoais.contato.pessoal;
    cout << "   Digite o telefone de um familiar do paciente: ";
    cin >> paciente.dadosPessoais.contato.familiar;

    limpaTela();
    cout << "Carregando entrada de dados clinicos.." << endl;
    pausaTela();
    limpaTela();

    cout << "----ENTRADA DE DADOS CLINICOS----" << endl;

    cout << "Digite o peso do paciente: ";
    cin >> paciente.dadosClinicos.peso;

    cout << "Digite a pressao do paciente: ";
    cin >> paciente.dadosClinicos.pressao;

    cout << "Digite a temperatura do paciente: ";
    cin >> paciente.dadosClinicos.temperatura;

    cout << "Digite os sintomas do paciente: ";
    cin >> paciente.dadosClinicos.sintomas;
    */
    cout << "Digite a urgencia do paciente: ";
    cin >> paciente.dadosClinicos.urgencia;

    paciente.dadosClinicos.ativo = true;

    inserirArvore(arvore,arvore.raiz,paciente);
    salvarDados(arvore.raiz);
    if(paciente.dadosClinicos.ativo=true)
    {
        inserirLP(lp1,paciente);
    }

    return false;
}



void menu(TArvoreBin &arvore, TListaP &lp1, TFilaP &fila)
{
    char opcao;

    do
    {
        limpaTela();
        cout << "\033[1;34m---Selecione uma opcao:---\033[0m" << endl;
        cout << "1 - \033[1;32mRegistro de dados\033[0m" << endl;
        cout << "2 - \033[1;32mFila de urgencia\033[0m" << endl;
        cout << "3 - \033[1;32mLista de pacientes ativos\033[0m" << endl;
        cout << "4 - \033[1;32mLista de pacientes cadastrados\033[0m" << endl;
        cout << "5 - \033[1;32mRemocao do paciente do hospital\033[0m" << endl;
        cout << "6 - \033[1;32mDar baixa em paciente\033[0m" << endl;
        cout << "0 - \033[1;31mSair\033[0m" << endl;
        cout << "\033[1;34mOpcao:\033[0m ";
        opcao = getch();

        switch (opcao)
        {
        case '1':
            limpaTela();
            while (true)
            {
                limpaTela();
                if (cadastroPaciente(arvore,lp1)) break;
            }
            break;

        case '2':
            limpaTela();
            prioridade(lp1,fila);
            mostrarFila(fila);
            pausaTela();

            break;
        case '3':
            limpaTela();

            cout << "=================================" << endl;
            mostrarLista(lp1);

            pausaTela();
            break;
        case '4':
            limpaTela();

            cout << "=================================" << endl;
            if(arvore.contItens==0)
            {
                cout << "Não existem pacientes cadastrados" << endl;
                cout << "=================================" << endl;
            }

            percorrerINOrdem(arvore.raiz);

            pausaTela();
            break;
        case '5':
            limpaTela();


            while (true)
            {
                limpaTela();
                if (retirarPaciente(arvore,lp1,fila )) break;
            }
            break;
        case '6':
            limpaTela();
            while (true)
            {
                limpaTela();
                if (darbaixa(arvore,fila,lp1)) break;
            }

            break;

        case '0':
            limpaTela();
            cout << "Saindo..." << endl;
            salvarDados(arvore.raiz);
            pausaTela();
            break;
        default:
            limpaTela();
            cout << "Opcao invalida" << endl;
            pausaTela();
            break;
        }
    }
    while (opcao!='0');

};

