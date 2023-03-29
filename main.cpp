//Padrão
#include <iostream>
#include<conio.h>
#include<clocale>

//Bibliotecas feitas
#include"biblioEspecificas.h"

using namespace std;



int main() {

    setlocale(LC_ALL,"Portuguese");

    TListaP lista;
    TItem item;


    TDadosPessoais paciente;
    TDadosClinicos TDadosClinicos;


    criarLPVazia(lista);

    item.chave = 1;
    item.valor = "Gabriel";
    inserirLP(lista,item);

    mostrar(lista);


    menu();




    return 0;
}

