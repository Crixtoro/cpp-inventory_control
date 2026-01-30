#include "Inventario.h"
#include <iostream>

bool Inventario::agregarProducto(const Producto& producto) {
    for(const Producto& prod : productos) {
        if (prod.getId() == producto.getId()) {
            return false;
        }
    }
    productos.push_back(producto);
    return true;
}

void Inventario::mostrarProductos() const  {
    if (productos.empty()) {
        std::cout << "Inventario vacío\n";
        return;
    }

    for(const Producto& prod : productos) {
        std::cout << "Producto: " << prod.getNombre()
                  << " | Cantidad: " << prod.getCantidad() << "\n";               
    }
}

Producto* Inventario::buscarProductoPorId(int id) {

}

bool Inventario::actualizarStock(int id, int nuevaCantidad) {
    
}