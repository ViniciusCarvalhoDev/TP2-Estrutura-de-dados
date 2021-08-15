#include "Linha.h"

Linha::Linha()
{
	this->nome;
	this->dados;
}

Linha::Linha(std::string nome, int dados)
{
	this->nome = nome;
	this->dados = dados;
}

Linha::~Linha()
{
}