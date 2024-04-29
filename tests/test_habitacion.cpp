#include <string>
#include "../habitacion.h"
#include "../cliente.h"
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

TEST_F(HabitacionTest, DespuesDeMantenimientoDisponible){
    hab->comenzar_mantenimiento();
    EXPECT_FALSE(hab->esta_disponible());
    hab->terminar_mantenimiento();
    EXPECT_TRUE(hab->esta_disponible());
}

TEST_F(HabitacionTest, ReservarHabitacion){
    Cliente cliente(4444444, "Perez", 12345678, "Bolivar 34");
    hab->reservar(&cliente);
    EXPECT_FALSE(hab->esta_disponible());
}
TEST_F(HabitacionTest, DespuesDeReservaEnMantenimiento){
    Cliente cliente(4444444, "Perez", 12345678, "Bolivar 34");
    hab->reservar(&cliente);
    EXPECT_FALSE(hab->esta_disponible());
    hab->terminar_reserva();
    EXPECT_FALSE(hab->esta_disponible()); // Luego de terminar la reserva, 
                                          //la habitacion debe estar en mantenimiento
}
TEST_F(HabitacionTest, DespuesDeReservayMantenimientoDisponible){
    Cliente cliente(4444444, "Perez", 12345678, "Bolivar 34");
    hab->reservar(&cliente);
    EXPECT_FALSE(hab->esta_disponible());
    hab->terminar_reserva();
    EXPECT_FALSE(hab->esta_disponible()); // Luego de terminar la reserva, 
                                          //la habitacion debe estar en mantenimiento
    hab->terminar_mantenimiento();
    EXPECT_TRUE(hab->esta_disponible());
}
TEST_F(HabitacionTest, ObtenerInfoCliente){
    Cliente cliente(4444444, "Perez", 12345678, "Bolivar 34");
    hab->reservar(&cliente);
    std::string nombre;
    EXPECT_TRUE(hab->get_nombre_cliente(nombre));
    EXPECT_EQ("Perez", nombre);
    EXPECT_EQ(4444444, hab->get_dni_cliente());
}

TEST_F(HabitacionTest, ObtenerInfoSinCliente){
    std::string nombre;
    EXPECT_FALSE(hab->get_nombre_cliente(nombre));
    EXPECT_EQ(-1, hab->get_dni_cliente());
}

int main(int argc, char*argv[]){
    std::cout << "Tests Habitacion" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}