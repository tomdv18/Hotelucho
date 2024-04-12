#include <string>
#include "../habitacion.h"
#include <gtest/gtest.h>



struct HabitacionTest : testing::Test{
    Habitacion * hab;

    HabitacionTest(){
        hab = new Habitacion(1,1,4);
    }

    ~HabitacionTest(){
        delete hab;
    }
};


TEST_F(HabitacionTest, PisoInicializado){
    EXPECT_EQ(1, hab->get_piso());
}
TEST_F(HabitacionTest, NumeroInicializado){
    EXPECT_EQ(1, hab->get_numero());
}
TEST_F(HabitacionTest, CapacidadInicializada){
    EXPECT_EQ(4, hab->get_capacidad());
}
TEST_F(HabitacionTest, DisponibleDefault){
    EXPECT_TRUE(hab->esta_disponible());
}

TEST_F(HabitacionTest, EnMantenimientoNoDisponible){

    hab->comenzar_mantenimiento();
    EXPECT_FALSE(hab->esta_disponible());
}

int main(int argc, char*argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}