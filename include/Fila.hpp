#ifndef FILA_H
#define FILA_H
#include <iostream>
#include "Celula.hpp"

template <typename T>
class Fila
{
	public:
		//Construtor da Fila
		Fila();
		//Destrutor da Fila
		~Fila();
		//Adiciona um item no final da Fila
		void Enfileirar(T item);
		//Remove o primeiro item da Fila 
		void Desenenfileirar();
		//Insere um item no inicio da Fila
		void FurarFila(T item);
		//Esvazia a Fila
		void Limpar();
		//Imprime o conteúdo da Fila
		void Imprimir();
		//Retorna o tamanho da Fila
		int Tamanho();
		//Remove o item na posição especificada 
		void Remover(int pos);
		//Recupera item na posição especificada
		T Recupera(int i);
		//Recupera o ponteiro para o item na posição especificada
		Celula<T>* RecuperaPonteiro(int i);
	private:
		int tamanho;
		Celula<T> *frente;
		Celula<T> *tras;
		//Retorna verdadeiro caso a Fila esteja vazia
		bool IsVazia();
};

template <typename T>
Fila<T>::Fila() {
	frente =  nullptr;
	tras = nullptr;
	tamanho = 0;
}

template <typename T>
Fila<T>::~Fila() {
	Limpar();
}

template <typename T>
void Fila<T>::Enfileirar(T item) {

	Celula<T>* temporaria = new Celula<T>(item);

	if (IsVazia())
	{
		frente = temporaria;
		tras = frente;
	}
	else
	{
		tras->prox = temporaria;
		tras = temporaria;
	}

	tamanho++;
}
template <typename T>
void Fila<T>::Desenenfileirar() {
	if (IsVazia())
	{
		return;
	}
	else if (frente == tras)
	{
		delete frente;
		frente = nullptr;
		tras = nullptr;
	}
	else
	{
		Celula<T>* temporaria = frente;
		frente = frente->prox;
		delete temporaria;
	}
	tamanho--;
}
template <typename T>
bool Fila<T>::IsVazia() {

	if (frente == nullptr && tras == nullptr)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
template <typename T>
void Fila<T>::Limpar() {

	while (!IsVazia() != 0)
		Desenenfileirar();
	
	tamanho = 0;
}

template <typename T>
void Fila<T>::Imprimir(){
	if(IsVazia())
	{
		return;
	}else
	{
		Celula<T> * itemAtual = frente;

		while(itemAtual != NULL)
		{
			std::cout << itemAtual->dado << std::endl;
			itemAtual = itemAtual->prox; 
		}
	}
}

template<typename T>
int Fila<T>::Tamanho(){
	return tamanho;
}

template<typename T>
Celula<T>* Fila<T>::RecuperaPonteiro(int i){

	if (i > tamanho)
	{
		return nullptr;
	}
	else if(IsVazia())
	{
		return nullptr;
	}
	int aux = 0;
	Celula<T> * itemAtual = frente;

		while(aux != i)
		{
			itemAtual = itemAtual->prox; 
			aux++;
		}
	return itemAtual;
}

template<typename T>
void Fila<T>::FurarFila(T item){

	Celula<T>* temporaria = new Celula<T>(item);

	if (IsVazia())
	{
		frente = temporaria;
		tras = frente;
	}
	else
	{
		temporaria->prox = frente;
		frente = temporaria;
	}

	tamanho++;
}

template<typename T>
T Fila<T>::Recupera(int i) {

	if (i > tamanho)
	{
		return NULL;
	}
	else if (IsVazia())
	{
		return NULL;
	}
	int aux = 0;
	Celula<T>* itemAtual = frente;

	while (aux != i)
	{
		itemAtual = itemAtual->prox;
		aux++;
	}
	return itemAtual->dado;
}

template<typename T>
void Fila<T>::Remover(int pos){

	int aux = 0;
	Celula<T>* temporaria = frente;

	if (IsVazia())
	{
		return;
	}
	if(pos == 0)
	{
		frente = temporaria->prox;
		free(temporaria);
	}
	else
	{
		while(aux != pos -1)
		{
			temporaria = temporaria->prox; 
			aux++;
		}

		if(temporaria == NULL || temporaria == nullptr || temporaria->prox == NULL || temporaria->prox == nullptr)
		{
			return;
		}

		Celula<T>* proxima = temporaria->prox->prox;
		free(temporaria->prox);
		temporaria->prox = proxima;
	}

	tamanho--;
}
#endif