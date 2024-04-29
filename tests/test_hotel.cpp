#include <string>
#include "../habitacion.h"
#include "../cliente.h"
#include "../hotel.h"
#include <gtest/gtest.h>
#define ERROR -1

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

TEST_F(HotelTest, ClientesRegistradosINicializado){
    EXPECT_EQ(0, hotel->cantidad_clientes_registrados());
}

TEST_F(HotelTest, HabitacionesRegistradasInicializado){
    EXPECT_EQ(0, hotel->cantidad_habitaciones());
}

TEST_F(HotelTest, NoExisteHabitacion){
    EXPECT_FALSE(hotel->existe_habitacion(01,01));
}
TEST_F(HotelTest, NoExisteCliente){
    EXPECT_FALSE(hotel->existe_cliente(103411));
}
TEST_F(HotelTest, AgregarHabitacion){
    EXPECT_FALSE(hotel->existe_habitacion(101,1));
    EXPECT_EQ(0, hotel->agregar_habitacion(101, 1, 2));
    EXPECT_TRUE(hotel->existe_habitacion(101,1));
    
    EXPECT_EQ(2, hotel->get_capacidad());
    EXPECT_EQ(0, hotel->get_ocupacion());
    EXPECT_EQ(1, hotel->cantidad_habitaciones());

    EXPECT_TRUE(hotel->habitacion_disponible(101,1));
}

TEST_F(HotelTest, AgregarHabitacionYaExistente){
    EXPECT_FALSE(hotel->existe_habitacion(101,1));
    hotel->agregar_habitacion(101, 1, 2);
    EXPECT_EQ(ERROR, hotel->agregar_habitacion(101, 1, 2));
        EXPECT_EQ(1, hotel->cantidad_habitaciones());
}

TEST_F(HotelTest, CrearReserva){
    EXPECT_EQ(0, hotel->cantidad_clientes_registrados());
    hotel->agregar_habitacion(11, 1, 2);
    EXPECT_EQ(0, hotel->crear_reserva(11, 1, 103411, "Juan", 123456, "Calle Falsa 123"));
    EXPECT_EQ(2, hotel->get_ocupacion());
    EXPECT_EQ(100, hotel->get_ocupacion_porcentual());
    EXPECT_EQ(1, hotel->cantidad_clientes_registrados());
    EXPECT_FALSE(hotel->habitacion_disponible(11,1));
}

TEST_F(HotelTest, CrearReservaEnHabitacionNoExistente){
    hotel->agregar_habitacion(11, 1, 2);
    EXPECT_EQ(ERROR, hotel->crear_reserva(11, 02, 103411, "Juan", 123456, "Calle Falsa 123"));
    EXPECT_EQ(0, hotel->get_ocupacion());
    EXPECT_EQ(0, hotel->get_ocupacion_porcentual());
    EXPECT_EQ(0, hotel->cantidad_clientes_registrados());
}

TEST_F(HotelTest, NoSeCreanDosClientesIguales){
    hotel->agregar_habitacion(11, 1, 2);
    hotel->agregar_habitacion(11, 2, 2);
    hotel->crear_reserva(11, 1, 103411, "Juan", 123456, "Calle Falsa 123");
    hotel->crear_reserva(11, 2, 103411, "Juan", 123456, "Calle Falsa 123");
    EXPECT_EQ(1, hotel->cantidad_clientes_registrados());
}

TEST_F(HotelTest, FinalizarReserva){
    hotel->agregar_habitacion(11, 1, 2);
    hotel->crear_reserva(11, 1, 103411, "Juan", 123456, "Calle Falsa 123");
    EXPECT_EQ(0, hotel->finalizar_reserva(11, 1));
    EXPECT_EQ(0, hotel->get_ocupacion());
    EXPECT_EQ(0, hotel->get_ocupacion_porcentual());
    EXPECT_FALSE(hotel->habitacion_disponible(11,1));
}

TEST_F(HotelTest, FinalizarReservaNoExistente){
    EXPECT_EQ(ERROR, hotel->finalizar_reserva(11, 1));
}

TEST_F(HotelTest, ComenzarMantenimiento){
    hotel->agregar_habitacion(11, 1, 2);
    EXPECT_EQ(0, hotel->comenzar_mantenimiento(11, 1));
    EXPECT_FALSE(hotel->habitacion_disponible(11,1));
}

TEST_F(HotelTest, FinalizarMantenimiento){
    hotel->agregar_habitacion(11, 1, 2);
    hotel->crear_reserva(11, 1, 103411, "Juan", 123456, "Calle Falsa 123");
    EXPECT_EQ(0, hotel->finalizar_reserva(11, 1));
    EXPECT_EQ(0, hotel->terminar_mantenimiento(11, 1));
    EXPECT_TRUE(hotel->habitacion_disponible(11,1));
}

TEST_F(HotelTest, FinalizarMantenimientoNoExistente){
    EXPECT_EQ(ERROR, hotel->terminar_mantenimiento(11, 1));
}

TEST_F(HotelTest, EliminarHabitacionNoExistente){
    EXPECT_EQ(ERROR, hotel->eliminar_habitacion(11, 1));
}
TEST_F(HotelTest, EliminarHabitacionOcupada){
    hotel->agregar_habitacion(11, 1, 2);
    hotel->crear_reserva(11, 1, 103411, "Juan", 123456, "Calle Falsa 123");
    EXPECT_EQ(ERROR, hotel->eliminar_habitacion(11, 1));
}

TEST_F(HotelTest, EliminarHabitacion){
    hotel->agregar_habitacion(11, 1, 2);
    EXPECT_EQ(0, hotel->eliminar_habitacion(11, 1));
    EXPECT_EQ(0, hotel->cantidad_habitaciones());
}

int main(int argc, char*argv[]){
    std::cout << "Tests Hotel" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}