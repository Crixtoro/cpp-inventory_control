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
    for (auto& prod : productos) {
        if (prod.getId() == id) {
            return &prod; //Dirección del producto dentro del vector
        }
    }
    return nullptr;
}

bool Inventario::actualizarStock(int id, int nuevaCantidad) {
    
}