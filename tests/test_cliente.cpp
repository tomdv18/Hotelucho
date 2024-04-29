#include <string>
#include "../cliente.h"
#include <gtest/gtest.h>



struct ClientTest : testing::Test{
    Cliente * client;

    ClientTest(){
        client = new Cliente(1001546,"Juan J.", 1154545466, "Entre Rios 5004");
    }

    ~ClientTest(){
        delete client;
    }
};


TEST_F(ClientTest, DNIInicializado){
    EXPECT_EQ(1001546, client->get_dni());
}
TEST_F(ClientTest, TelefonoInicializado){
    EXPECT_EQ(1154545466, client->get_telefono());
}
TEST_F(ClientTest, NombreInicializado){
    EXPECT_EQ("Juan J.", client->get_nombre());
}
TEST_F(ClientTest, DireccionInicializada){
    EXPECT_EQ("Entre Rios 5004", client->get_direccion());
}

TEST_F(ClientTest, CambioDireccion){
    client->cambiar_direccion("Calle San Paoli 231");
    EXPECT_EQ("Calle San Paoli 231", client->get_direccion());
}
TEST_F(ClientTest, CambioTelefono){
    client->cambiar_telefono(1234554321);
    EXPECT_EQ(1234554321, client->get_telefono());
}

int main(int argc, char*argv[]){
    std::cout << "Tests Cliente" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}