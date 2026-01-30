#include <iostream>
#include "Producto.h"
#include "Inventario.h"

int main() {
    Inventario inventario; 

    inventario.agregarProducto(Producto(1, "Laptop", 5, 1));
    inventario.agregarProducto(Producto(2, "Mouse", 20, 3));
    inventario.agregarProducto(Producto(3, "Teclado", 10, 2));

    Producto* p = inventario.buscarProductoPorId(2);

    if (p != nullptr) {
        std::cout << "Producto encontrado:\n";
        std::cout << "Nombre: " << p->getNombre() << "\n";
        std::cout << "Cantidad: " << p->getCantidad() << "\n";
    }

    return 0;
}