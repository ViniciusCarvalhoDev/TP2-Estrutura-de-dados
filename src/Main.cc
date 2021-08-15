#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "Time.h"
#include "Fila.hpp"
#include "Linha.cpp"

//função que compara strings

bool compara(std::string n1, std::string n2) {

    int tamanho;

    if (n1.size() < n2.size() == true)
        tamanho = n1.size();
    else
        tamanho = n2.size();

    for (int i = 0; i < tamanho; i++)
    {
        if (n1[i] != n2[i] == true)
            return n1[i] < n2[i];
    }

    if (n2.size() > n1.size() == true)
        return true;

    return false;
}

//--- quickSort

void trocar(int i, int j, Fila<Linha> *lista)
{
    Celula<Linha>* item1 = lista->RecuperaPonteiro(i);
    Celula<Linha>* item2 = lista->RecuperaPonteiro(j);

    std::string aux = "";
    int aux2;

    aux = item1->dado.nome;
    aux2 = item1->dado.dados;

    item1->dado.nome = item2->dado.nome;
    item1->dado.dados = item2->dado.dados;

    item2->dado.nome = aux;
    item2->dado.dados = aux2;
}

int partir(Fila<Linha> *lista, int menor, int maior)
{
    std::string pivot = lista->RecuperaPonteiro(maior)->dado.nome; 
    int i = (menor - 1);  

    for (int j = menor; j <= maior - 1; j++)
    {
        Linha aux = lista->RecuperaPonteiro(j)->dado;
        if (compara(aux.nome, pivot) == true)
        {
            i++;    
            trocar(i,j, lista);
        }
    }
    trocar(i + 1,maior,lista);
    return (i + 1);
}


void quickSort(Fila<Linha> *lista, int menor, int maior)
{
    if (menor < maior)
    {
        int pi = partir(lista, menor, maior);

        quickSort(lista, menor, pi - 1);
        quickSort(lista, pi + 1, maior);
    }
}

//--------- merge sort

void merge(Fila<Linha>* lista, int  esq, int meio, int  direito)
{
    Fila<std::string> lista1;
    Fila<int> lista1Int;

    Fila<std::string> lista2;
    Fila<int> lista2Int;

    int  subLista1 = meio - esq + 1;
    int  subLista2 = direito - meio;

    for (auto i = 0; i < subLista1; i++) {
        lista1.Enfileirar(lista->RecuperaPonteiro(esq + i)->dado.nome);
        lista1Int.Enfileirar(lista->RecuperaPonteiro(esq + i)->dado.dados);
    }
    for (auto j = 0; j < subLista2; j++){
        lista2.Enfileirar(lista->RecuperaPonteiro(meio + 1 + j)->dado.nome);
        lista2Int.Enfileirar(lista->RecuperaPonteiro(meio + 1 +j)->dado.dados);
    }

    int indiceSubLista1 = 0,
        indiceSubLista2 = 0;
    int indiceListaMeio = esq; 


    while (indiceSubLista1 < subLista1 && indiceSubLista2 < subLista2) {
        if (compara(lista1.Recupera(indiceSubLista1), lista2.Recupera(indiceSubLista2)) == true) {
            lista->RecuperaPonteiro(indiceListaMeio)->dado.nome = lista1.Recupera(indiceSubLista1);
            lista->RecuperaPonteiro(indiceListaMeio)->dado.dados = lista1Int.Recupera(indiceSubLista1);
            indiceSubLista1++;
        }
        else {
            lista->RecuperaPonteiro(indiceListaMeio)->dado.nome = lista2.Recupera(indiceSubLista2);
            lista->RecuperaPonteiro(indiceListaMeio)->dado.dados = lista2Int.Recupera(indiceSubLista2);
            indiceSubLista2++;
        }
        indiceListaMeio++;
    }

    while (indiceSubLista1 < subLista1) {
        lista->RecuperaPonteiro(indiceListaMeio)->dado.nome = lista1.Recupera(indiceSubLista1);
        lista->RecuperaPonteiro(indiceListaMeio)->dado.dados = lista1Int.Recupera(indiceSubLista1);
        indiceSubLista1++;
        indiceListaMeio++;
    }

    while (indiceSubLista2 < subLista2) {
        lista->RecuperaPonteiro(indiceListaMeio)->dado.nome = lista2.Recupera(indiceSubLista2);
        lista->RecuperaPonteiro(indiceListaMeio)->dado.dados = lista2Int.Recupera(indiceSubLista2);
        indiceSubLista2++;
        indiceListaMeio++;
    }
}

void mergeSort(Fila<Linha>* lista, int  inicio, int  fim)
{
    if (inicio >= fim) {
        return;
    }
    int meio = inicio + (fim - inicio) / 2;
    mergeSort(lista, inicio, meio);
    mergeSort(lista, meio + 1, fim);
    merge(lista, inicio, meio, fim);
}

//merge sort fim

//heapSort

void heapify(Fila<Linha>* lista, int n, int i)
{
    int maior = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && lista->RecuperaPonteiro(l)->dado.dados > lista->RecuperaPonteiro(maior)->dado.dados)
        maior = l;

    if (r < n && lista->RecuperaPonteiro(r)->dado.dados > lista->RecuperaPonteiro(maior)->dado.dados)
        maior = r;

    if (maior != i) {
        trocar(i, maior,lista);
        heapify(lista, n, maior);
    }
}


void heapSort(Fila<Linha> *lista, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(lista, n, i);


    for (int i = n - 1; i >= 0; i--) {
        
        trocar(0,i, lista);
        heapify(lista, i, 0);
    }
}

//heapSort fim

//hadix 

int getMax(Fila<Linha>* lista, int n)
{
    int maior = lista->RecuperaPonteiro(0)->dado.dados;
    for (int i = 1; i < n; i++)
        if (lista->RecuperaPonteiro(i)->dado.dados > maior)
            maior = lista->RecuperaPonteiro(i)->dado.dados;
    return maior;
}


void organizar(Fila<Linha>* lista, int n, int exp)
{
    int *output = new int[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(lista->RecuperaPonteiro(i)->dado.dados / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(lista->RecuperaPonteiro(i)->dado.dados / exp) % 10] - 1] = lista->RecuperaPonteiro(i)->dado.dados;
        count[(lista->RecuperaPonteiro(i)->dado.dados / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        lista->RecuperaPonteiro(i)->dado.dados = output[i];
}

std::string formatar(int numero)
{
    std::string aux = std::to_string(numero);
    std::string final = "";

    int zeros = 8 - aux.size();

    for (int i = 0; i < zeros; i++)
    {
        final += "0";
    }

    return final + aux;
    
}
// Radix Sort
void radixsort(Fila<Linha>* lista, int n)
{
    int m = getMax(lista, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        organizar(lista, n, exp);
}

int main(int argc, char *argv[])
{   
    std::string linha;
    std::string input;
    std::string temporaria;

    int operacao = std::stoi(argv[2]);
    int linhas = std::stoi(argv[3]); //verificar se a quantidade de linhas excede a quantidade de linhas do arquivo
    int aux = 0;

    Fila<std::string> listaNomes;
    Fila<int> listaInteiros;

    Fila<Linha> Listalinhas;
    
    FILE* arquivo = fopen(argv[1],"rt");
    char buf[100];

    arquivo = fopen(argv[1],"rt");

    aux = 0;

    while (std::fgets(buf, sizeof buf, arquivo) != nullptr) {

        if(aux < linhas){
            linha = buf;
            Linha aux = Linha(linha.substr(0,linha.find(" ")),std::stoi( linha.substr(linha.find(" ") +1, linha.size())));
            Listalinhas.Enfileirar(aux);
        }

        aux++;
    }

    //clock_t relogio;
    //relogio = clock();

    switch (operacao)
    {
    case 1:
        heapSort(&Listalinhas, Listalinhas.Tamanho());
        quickSort(&Listalinhas,0,Listalinhas.Tamanho()-1);
        break;
    case 2:
        radixsort(&Listalinhas, Listalinhas.Tamanho());
        quickSort(&Listalinhas,0,Listalinhas.Tamanho()-1);
        break;
    case 3:
        heapSort(&Listalinhas, Listalinhas.Tamanho());
        mergeSort(&Listalinhas, 0, Listalinhas.Tamanho() - 1);
        break;
    case 4:
        radixsort(&Listalinhas, Listalinhas.Tamanho());
        mergeSort(&Listalinhas, 0, Listalinhas.Tamanho() - 1);
    default:
        break;
    }

    
    //relogio = (clock() - relogio) / (CLOCKS_PER_SEC / 1000);
    //std::cout << relogio;


    for (int i = 0; i < linhas; i++)
    {
        std::cout << Listalinhas.RecuperaPonteiro(i)->dado.nome << " " << formatar(Listalinhas.RecuperaPonteiro(i)->dado.dados) << std::endl;
    }
    

    fclose (arquivo);
    return 0;
}
