#include <iostream>

#include "bibTAD-LA.h"

using namespace std;

void criarLPVazia(TListaP &lp)
{
    lp.primeiro = new TCelula;
    lp.ultimo = lp.primeiro;
    lp.ultimo->proximo = lp.primeiro;
}

void inserirLP(TListaP &lp, TItem x)
{
    lp.ultimo->proximo = new TCelula;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->item = x;
    lp.ultimo->proximo = lp.primeiro;
}

bool estaVaziaLP(TListaP lp)
{
    return lp.primeiro->proximo == lp.primeiro;
}

void mostrarLista(TListaP lp)
{

    TCelula *celAux;
    celAux = lp.primeiro->proximo;


    if (estaVaziaLP(lp))
    {
        cout << "Não existem pacientes ativos no momento" << endl;
        cout << "=================================" << endl;

    }
    else
    {
        while (celAux != lp.primeiro)
        {

            cout << "   Nome:   " << celAux->item.dadosPessoais.nomeCompleto<< endl;
            cout << "   CPF :   " << celAux->item.dadosPessoais.CPF << endl;

            celAux = celAux->proximo;

            cout << "=================================" << endl;
        }
    }
}

TCelula *pegaAnterior(TListaP lp, int chaveBusca)
{

    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;

    cout << "=== PROCURANDO ITEM NA LISTA === "<< endl;
    while (celAux->proximo != lp.primeiro)
    {
        if (celAux->proximo->item.dadosPessoais.CPF == chaveBusca)
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

void retirarPorChave(TListaP &lp, int chaveBusca)
{
    TCelula *anterior = pegaAnterior(lp,chaveBusca);

    if (anterior == NULL)
    {
        cout << "O paciente não foi encontrada. Nenhuma informação a retirar." << endl;
    }
    else
    {
        TCelula *celAlvo;

        celAlvo = anterior->proximo;
        anterior->proximo = celAlvo->proximo;

        cout << "End.Mem.Celula Anterior: " << anterior << endl;
        cout << "   Chave:   " << anterior->item.dadosPessoais.CPF << endl;
        cout << "   Proximo: " << anterior->proximo << endl;

        cout << "End.Mem.Celula Alvo: " << celAlvo << endl;
        cout << "   Chave:   " << celAlvo->item.dadosPessoais.CPF << endl;
        cout << "   Proximo: " << celAlvo->proximo << endl;
        delete(celAlvo);
    }
}

///Fila

void criarFilaPVazia(TFilaP &f)
{
    f.frente = new TCelula;
    f.tras = f.frente;
    f.frente->proximo = NULL;
}

bool estaVaziaFilaP(TFilaP f)
{
    return f.frente == f.tras;
}

void enfileirar(TFilaP &f, TItem x)
{
    f.tras->proximo = new TCelula;
    f.tras = f.tras->proximo;
    f.tras->item = x;
    f.tras->proximo = NULL;
}

void mostrarFila(TFilaP f)
{
    TCelula *celAux;
    celAux = f.frente->proximo;

    cout << "=== MOSTRANDO A FILA === "<< endl;
    if (estaVaziaFilaP(f))
    {
        cout << "Fila vazia! Nenhum elemento para mostrar!" << endl;
        cout << "-------------------------------------------" << endl;
    }
    else
    {
        while (celAux != NULL)
        {
            cout << "seila: " << celAux << endl;
            cout << "   Chave:   " << celAux->item.dadosClinicos.urgencia << endl;
            celAux = celAux->proximo;
            cout << "-------------------------------------------" << endl;
        }
    }
}

void desenfileirar(TFilaP &f)
{
    if (estaVaziaFilaP(f))
    {
        cout << "Fila Vazia! Nenhum elemento para desenfileirar..." << endl;
        cout << "-------------------------------------------" << endl;
    }
    else
    {
        TCelula *aux = f.frente;
        cout << "Desenfilerei o item de chave: " << aux->proximo->item.dadosPessoais.CPF << endl;
        f.frente = f.frente->proximo;
        delete(aux);
    }
}


///Arvore

void criarArvoreBinVazia(TArvoreBin &a, string n)
{
    a.nomeArvore = n;
    a.contItens = 0;
    a.raiz = NULL;
}

void inserirArvore(TArvoreBin &a, TNo *&no, TItem i)
{
    if (no == NULL)
    {
        no = new TNo;
        no->item = i;
        no->esquerda = NULL;
        no->direita = NULL;
        a.contItens++;
        if (a.raiz == NULL)
        {
            a.raiz = no;
        }
    }
    else
    {
        if (i.dadosPessoais.CPF < no->item.dadosPessoais.CPF)
        {
            inserirArvore(a,no->esquerda,i);
        }
        else
        {
            if (i.dadosPessoais.CPF > no->item.dadosPessoais.CPF)
            {
                inserirArvore(a,no->direita,i);
            }
            else
            {
                if (i.dadosPessoais.CPF == no->item.dadosPessoais.CPF)
                {
                    cout << "Não posso inserir. Item já existe!" << endl;
                }
            }
        }

    }
}

void percorrerINOrdem(TNo *&no)
{
    if(no!=NULL)
    {
        percorrerINOrdem(no->esquerda);
        cout << "Nome:" << no->item.dadosPessoais.nomeCompleto << endl;
        cout << "CPF: " << no->item.dadosPessoais.CPF << endl;
        cout << "=================================" << endl;
        percorrerINOrdem(no->direita);
    }
}

void percorrerPreOrdem(TNo *&no)
{
    if(no!=NULL)
    {
        cout << "Nome:" << no->item.dadosPessoais.nomeCompleto << endl;
        cout << "CPF: " << no->item.dadosPessoais.CPF << endl;
        cout << "=================================" << endl;
        percorrerPreOrdem(no->esquerda);
        percorrerPreOrdem(no->direita);
    }
}

void percorrerPosOrdem(TNo *&no)
{
    if(no!=NULL)
    {
        percorrerPosOrdem(no->esquerda);
        percorrerPosOrdem(no->direita);
        cout << "Nome:" << no->item.dadosPessoais.nomeCompleto << endl;
        cout << "CPF: " << no->item.dadosPessoais.CPF << endl;
        cout << "=================================" << endl;
    }
}


void pesquisarArvore(int c, TNo *&n, int &cont)
{


    if (n == NULL)
    {
        cout << "Estou no Nó: " << &n << endl;
        cout << "Registro não localizado na árvore" << endl;

    }
    else
    {
        cout << "Estou no Nó: " << &n << "   Chave: " << n->item.dadosPessoais.CPF << endl;

        if (c < n->item.dadosPessoais.CPF)
        {
            cont++;
            pesquisarArvore(c, n->esquerda,cont);

        }
        else
        {
            if (c > n->item.dadosPessoais.CPF)
            {
                cont++;
                pesquisarArvore(c, n->direita,cont);
            }
            else
            {
                cout << "Achei o item: " << n->item.dadosPessoais.CPF << endl;
                cout << "O dia está lindo!" << endl;
                cout << "Valor do cont: " << cont << endl;
                cout << "Chave: " << c << "   - Nó: " << &n << endl;
            }
        }
    }

}


void pegarAnterior(TNo *q, TNo *&r)
{

    if (r->direita != NULL)
    {
        pegarAnterior(q, r->direita);
    }
    else
    {
        q->item = r->item;
        q = r;
        r = r->esquerda;
        delete q;
    }
}


void retirarArvore(int c, TNo *&p)
{
    TNo *aux;

    if (p == NULL)
    {

    }
    else
    {
        if (c < p->item.dadosPessoais.CPF)
        {
            retirarArvore(c, p->esquerda);
        }
        else
        {
            if (c > p->item.dadosPessoais.CPF)
            {
                retirarArvore(c, p->direita);
            }
            else
            {
                if (p->direita == NULL)
                {
                    aux = p;
                    p = p->esquerda;
                    delete aux;
                }
                else
                {
                    if (p->esquerda != NULL)
                    {
                        pegarAnterior(p, p->esquerda);
                    }
                    else
                    {
                        aux = p;
                        p = p->direita;
                        delete aux;
                    }
                }
            }
        }
    }
}
