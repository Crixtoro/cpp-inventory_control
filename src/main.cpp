#include <iostream>
#include "Producto.h"
#include "Inventario.h"

int main() {
    Inventario inventario; 

    Producto p1(1, "Teclado", 50.0, 10);
    Producto p2(2, "Mouse", 25.5, 20);
    Producto p3(1, "Monitor", 200, 5);


        if (inventario.agregarProducto(p1)) {
        std::cout << "P1 agregado\n";
    } else {
        std::cout << "P1 NO agregado\n";
    }

    if (inventario.agregarProducto(p2)) {
        std::cout << "P2 agregado\n";
    } else {
        std::cout << "P2 NO agregado\n";
    }

    if (inventario.agregarProducto(p3)) {
        std::cout << "P3 agregado\n";
    } else {
        std::cout << "P3 ID duplicado\n";
    }

    return 0;
}