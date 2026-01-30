#include <iostream>
#include "Producto.h"
#include "Inventario.h"

int main() {
    Inventario inventario; 

    inventario.cargarDesdeArchivo("data/inventario.csv");

    inventario.agregarProducto(Producto(2, "Mouse", 20, 3));
    inventario.actualizarStock(2,13);

    inventario.mostrarProductos();

    inventario.guardarEnArchivo("data/inventario.csv");
    return 0;
}