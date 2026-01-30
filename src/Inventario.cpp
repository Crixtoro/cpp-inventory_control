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

}

Producto* Inventario::buscarProductoPorId(int id) {

}

bool Inventario::actualizarStock(int id, int nuevaCantidad) {
    
}