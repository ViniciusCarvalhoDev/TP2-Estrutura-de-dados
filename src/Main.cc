#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "Fila.hpp"


int main(int argc, char *argv[])
{   
    std::string linha;
    std::string input;
    std::string temporaria;

    int operacao = std::stoi(argv[2]);
    int linhas = std::stoi(argv[3]); //verificar se a quantidade de linhas excede a quantidade de linhas do arquivo
    int aux = 0;

    Fila<std::string> lista;
    
    FILE* arquivo = fopen(argv[1],"rt");
    char buf[100];

    arquivo = fopen(argv[1],"rt");

    aux = 0;

    std::cout << "OPERACAO" << operacao << std::endl;
    std::cout << "LINHAS" << linhas << std::endl;

    while (std::fgets(buf, sizeof buf, arquivo) != nullptr) {

        //std::cout << buf << std::endl;

        if(aux < linhas){
            lista.Enfileirar(buf);
        }

        aux++;
    }

    lista.Imprimir();

    fclose (arquivo);
    return 0;
}
