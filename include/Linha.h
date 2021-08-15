#ifndef LINHA_H
#define LINHA_H
#include "Fila.hpp"

class Linha
{
public:
	Linha();
	Linha(std::string nome, int dados);
	~Linha();
	std::string nome;
	int dados;

private:

};
#endif 

