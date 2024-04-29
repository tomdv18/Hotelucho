#include "launcher.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "ERROR: Debe insertar el nombre del hotel al crearlo" << std::endl;
        return 1;
    }
    system("clear");
    Launcher launcher(argv[1]);
    launcher.run();
    return 0;
}
