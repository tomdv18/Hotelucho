#ifndef CLIENTE_H
#define CLIENTE_H

#define MAXSIZE 1024

class Cliente {
private:
    int id;
    char nombre[MAXSIZE];
    int telefono;
    char direccion[MAXSIZE];

public:
    Cliente();
    Cliente(int id, char nombre[MAXSIZE],int telefono, char direccion[MAXSIZE]);

    bool cambiar_telefono(int telefonoNuevo);

    bool cambiar_direccion(char direccion[MAXSIZE]);

    /*
     * No queremos permitir que alguien haga copias
     */
    Cliente(const Cliente&) = delete;
    Cliente& operator=(const Cliente&) = delete;

    /*Move semantics*/
    Cliente(Cliente&&) = default;
    Cliente& operator=(Cliente&&) = default;
};


#endif
