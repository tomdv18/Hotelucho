#include "launcher.h"
#include <iostream>

int main(int argc, char* argv[]){
    std::string input;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    std::cout << "Bienvenido al sistema de gestion de hoteles Hotelucho" << std::endl;
    std::cout << "Por favor, ingrese el nombre del hotel: "<< std::endl;
    getline(std::cin, input);
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
    Launcher launcher(input);
    launcher.run();
    return 0;
}
