// bibliotecas da linguagem
#include <iostream>
#include <clocale>
#include <fstream>
// minhas bibliotecas
#include "bibTAD-LA.h"
#include "bibOpEsp.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");

    TArvoreBin arvore;
    TListaP pacientesAtivos;
    TFilaP fila;

    criarLPVazia(pacientesAtivos);
    criarArvoreBinVazia(arvore,"SHD");
    criarFilaPVazia(fila);

    menu(arvore,pacientesAtivos,fila);

    return 0;
}
