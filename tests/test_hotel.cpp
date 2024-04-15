#include <string>
#include "../habitacion.h"
#include "../cliente.h"
#include "../hotel.h"
#include <gtest/gtest.h>


struct HotelTest : testing::Test{
    Hotel * hotel;

    HotelTest(){
        hotel = new Hotel("Hotelucho Test");
    }

    ~HotelTest(){
        delete hotel;
    }
};

TEST_F(HotelTest, CapacidadInicializada){
    EXPECT_EQ(0, hotel->get_capacidad());
}

TEST_F(HotelTest, OcupacionInicializada){
    EXPECT_EQ(0, hotel->get_ocupacion());
}

TEST_F(HotelTest, OcupacionPorcentualIncializada){
    EXPECT_EQ(0, hotel->get_ocupacion_porcentual());
}
TEST_F(HotelTest, NoExisteHabitacion){
    EXPECT_FALSE(hotel->existe_habitacion(01,01));
}
TEST_F(HotelTest, NoExisteCliente){
    EXPECT_FALSE(hotel->existe_cliente(103411));
}
TEST_F(HotelTest, AgregarHabitacion){
    EXPECT_FALSE(hotel->existe_habitacion(101,1));
    hotel->agregar_habitacion(101, 1, 2);
    EXPECT_TRUE(hotel->existe_habitacion(101,1));
    EXPECT_EQ(2, hotel->get_capacidad());
    EXPECT_EQ(0, hotel->get_ocupacion());
}

int main(int argc, char*argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}