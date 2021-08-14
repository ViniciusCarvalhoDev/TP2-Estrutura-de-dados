#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "Fila.hpp"

//função que compara strings e retorna uma string dizendo é a ordem entre as duas

std::string compara(std::string n1, std::string n2) {
    int aux = -1;

    if (n1.length() > n2.length()) {
        for (int i = 0; i < n2.length(); i++)
        {
            if (n2[i] != n1[i])
            {
                if (n2[i] < n1[i]) {
                    aux = 2;
                }
                else {
                    aux = 1;
                }
                break;
            }
        }
    }
    else if (n2.length() > n1.length()) {
        for (int i = 0; i < n1.length(); i++)
        {
            if (n1[i] != n2[i])
            {
                if (n1[i] < n2[i])
                {
                    aux = 1;
                }
                else {
                    aux = 2;
                }
                break;
            }
        }
    }
    else {
        for (int i = 0; i < n1.length(); i++)
        {
            if (n1[i] != n2[i])
            {
                if (n1[i] < n2[i])
                {
                    aux = 1;
                }
                else {
                    aux = 2;
                }

            }
            else {
                aux = 0;
            }
        }
    }

    if (aux == 1)
    {
        return "A primeira vem antes";
    }
    else if (aux == 2) {
        return "A segunda vem antes";
    }
    else if (aux == 0)
    {
        return "Sao iguais";
    }
    else
    {
        if (n1.length() > n2.length())
        {
            return "A segunda vem antes";
        }
        else {
            return "A primeira vem antes";
        }
    }
}

//--- quickSort

// Essa função troca os elementos i e j de uma mesma linha
void trocar(int i, int j, Fila<std::string> *lista)
{
    Celula<std::string>* item1 = lista->RecuperaPonteiro(i);
    Celula<std::string>* item2 = lista->RecuperaPonteiro(j);
    std::string aux = "";

    aux = item1->dado;
    item1->dado = item2->dado;
    item2->dado = aux;
}

// Essa função troca os elementos i e j de uma mesma linha
void trocarInt(int i, int j, Fila<int>* lista)
{
    Celula<int>* item1 = lista->RecuperaPonteiro(i);
    Celula<int>* item2 = lista->RecuperaPonteiro(j);
    int aux;

    aux = item1->dado;
    item1->dado = item2->dado;
    item2->dado = aux;
}

int partition(Fila<std::string> *lista, int low, int high)
{
    std::string pivot = lista->Recupera(high); 
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++)
    {
        
        if (compara(lista->Recupera(j), pivot) == "A primeira vem antes")
        {
            i++;    
            trocar(i,j, lista);
        }
    }
    trocar(i + 1,high,lista);
    return (i + 1);
}


void quickSort(Fila<std::string> *lista, int low, int high)
{
    if (low < high)
    {
        
        int pi = partition(lista, low, high);

        quickSort(lista, low, pi - 1);
        quickSort(lista, pi + 1, high);
    }
}

//Implementação do merge sort
void merge(Fila<std::string>* lista, int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    Fila<std::string> lista1;
    Fila<std::string> lista2;

    for (auto i = 0; i < subArrayOne; i++)
        lista1.Enfileirar(lista->Recupera(left + i));
    for (auto j = 0; j < subArrayTwo; j++)
        lista2.Enfileirar(lista->Recupera(mid + 1 + j));

    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 


    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (compara(lista1.Recupera(indexOfSubArrayOne), lista2.Recupera(indexOfSubArrayTwo)) == "A primeira vem antes") {
            lista->RecuperaPonteiro(indexOfMergedArray)->dado = lista1.Recupera(indexOfSubArrayOne);
            indexOfSubArrayOne++;
        }
        else {
            lista->RecuperaPonteiro(indexOfMergedArray)->dado = lista2.Recupera(indexOfSubArrayTwo);
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        lista->RecuperaPonteiro(indexOfMergedArray)->dado = lista1.Recupera(indexOfSubArrayOne);
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        lista->RecuperaPonteiro(indexOfMergedArray)->dado = lista2.Recupera(indexOfSubArrayTwo);
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(Fila<std::string>* lista, int const begin, int const end)
{
    if (begin >= end) {
        return;
    }
    auto mid = begin + (end - begin) / 2;
    mergeSort(lista, begin, mid);
    mergeSort(lista, mid + 1, end);
    merge(lista, begin, mid, end);
}

//merge sort fim

//heapSort

void heapify(Fila<int>* lista, int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && lista->Recupera(l) > lista->Recupera(largest))
        largest = l;

    if (r < n && lista->Recupera(r) > lista->Recupera(largest))
        largest = r;

    if (largest != i) {
        trocarInt(i, largest,lista);
        heapify(lista, n, largest);
    }
}


void heapSort(Fila<int> *lista, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(lista, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        trocarInt(0,i, lista);

        heapify(lista, i, 0);
    }
}

//heapSort fim

//hadix 

int getMax(Fila<int>* lista, int n)
{
    int mx = lista->Recupera(0);
    for (int i = 1; i < n; i++)
        if (lista->Recupera(i) > mx)
            mx = lista->Recupera(i);
    return mx;
}


void countSort(Fila<int>* lista, int n, int exp)
{
    int *output = new int[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(lista->Recupera(i) / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(lista->Recupera(i) / exp) % 10] - 1] = lista->Recupera(i);
        count[(lista->Recupera(i) / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        lista->RecuperaPonteiro(i)->dado = output[i];
}

// Radix Sort
void radixsort(Fila<int>* lista, int n)
{
    int m = getMax(lista, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(lista, n, exp);
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
    
    FILE* arquivo = fopen(argv[1],"rt");
    char buf[100];

    arquivo = fopen(argv[1],"rt");

    aux = 0;

    while (std::fgets(buf, sizeof buf, arquivo) != nullptr) {

        if(aux < linhas){
            linha = buf;
            listaNomes.Enfileirar(linha.substr(0,linha.find(" ")));
            listaInteiros.Enfileirar(std::stoi( linha.substr(linha.find(" ") +1, linha.size())));
        }

        aux++;
    }

    listaNomes.Imprimir();
    listaInteiros.Imprimir();

    fclose (arquivo);
    return 0;
}
