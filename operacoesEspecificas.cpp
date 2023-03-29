#include<iostream>
#include "biblioEspecificas.h"

using namespace std;


#include<conio.h>
///Lista
//Lista de saida do hospital

void criarLPVazia(TListaP &lp){
    lp.primeiro = new TCelula;
    lp.ultimo = lp.primeiro;
    lp.ultimo->proximo = lp.primeiro;

    cout << "Lista Criada" << endl;
}

void inserirLP(TListaP &lp, TItem x){
    lp.ultimo->proximo = new TCelula;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->item = x;
    lp.ultimo->proximo = lp.primeiro;
}

bool estaVaziaLP(TListaP lp){
    return lp.primeiro->proximo == lp.primeiro;
}

void mostrar(TListaP lp){

    TCelula *celAux;
    celAux = lp.primeiro->proximo;

    cout << "=== SAÍDA DE PACIENTES EM 12 HORAS=== "<< endl;

    if (estaVaziaLP(lp)){
        cout << "Nenhum paciente frequentou a unidade em 12 HORAS. " << endl;
        cout << "-------------------------------------------" << endl;

    }
    else{
        while (celAux != lp.primeiro){

            cout << "   CPF do paciente:   " << celAux->item.chave << endl;
            cout << "   Nome:   " << celAux->item.valor << endl;

            celAux = celAux->proximo;

            cout << "-------------------------------------------" << endl;
        }
    }
}

TCelula *pegaAnterior(TListaP lp, int chaveBusca){

    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;

    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
    while (celAux->proximo != lp.primeiro){
        if (celAux->proximo->item.chave == chaveBusca){
            achou = true;
            return celAux;
        }
        celAux = celAux->proximo;
    }
    if (achou == false){
        return NULL;
    }
}

void retirarPorChave(TListaP &lp, int chaveBusca){
    TCelula *anterior = pegaAnterior(lp,chaveBusca);

    if (anterior == NULL){
        cout << "O paciente não foi encontrada. Nenhuma informação a retirar." << endl;
    }
    else{
        TCelula *celAlvo;

        celAlvo = anterior->proximo;
        anterior->proximo = celAlvo->proximo;

        cout << "End.Mem.Celula Anterior: " << anterior << endl;
        cout << "   Chave:   " << anterior->item.chave << endl;
        cout << "   Valor:   " << anterior->item.valor << endl;
        cout << "   Proximo: " << anterior->proximo << endl;

        cout << "End.Mem.Celula Alvo: " << celAlvo << endl;
        cout << "   Chave:   " << celAlvo->item.chave << endl;
        cout << "   Valor:   " << celAlvo->item.valor << endl;
        cout << "   Proximo: " << celAlvo->proximo << endl;
        delete(celAlvo);
    }
}

///MENU
void menu(){
char opcao;

    do{
        cout << "---Selecione uma opção:---" << endl;
        cout << "1 - Regitro de dados" << endl;
        cout << "2 - Lista de pacientes ativos" << endl;
        cout << "3 - Dar baixa em paciente" << endl;
        cout << "4 - Remocao do paciente do hospital" << endl;
        cout << "0 - Sair" << endl;

        opcao = getch();

        switch (opcao) {
            case '1':
                // Entrada de dados
                break;
            case '2':
                // Lista de pacientes ativos
                break;
            case '3':
                // Dar baixa em paciente
                break;
            case '4':
                // Remocao do paciente do hospital
                break;
            case '0':
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida" << endl;
                break;
        }
        }
        while (opcao!='0');

};

