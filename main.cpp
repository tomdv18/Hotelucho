#include <iostream>

#include "launcher.h"

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        system("clear");
        Launcher launcher(argv[1]);
        if (argc == 3) {
            launcher.leer(argv[2]);
        }
        system("clear");
        launcher.run();
        return 0;
    } else {
        std::cerr << "Error: Debe haber al menos dos argumentos" << std::endl;
        return 1;
    }
}
