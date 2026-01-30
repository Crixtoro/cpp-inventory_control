#include <iostream>
#include "Producto.h"

int main() {
    Producto p(1, "Mouse", 25.5, 10);

    std::cout << p.getNombre() << std::endl;
    std::cout << p.getCantidad() << std::endl;

    p.setCantidad(20);
    std::cout << p.getCantidad()<< std::endl;

    return 0;
}