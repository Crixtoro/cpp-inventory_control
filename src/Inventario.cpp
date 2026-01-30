#include "Inventario.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
    Producto* p = buscarProductoPorId(id);
    
    if (p == nullptr) {
        return false;
    }

    p->setCantidad(nuevaCantidad);
    return true; 
}

void Inventario::guardarEnArchivo(const std::string& ruta) const {
    std::ofstream archivo(ruta);

    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para guardar\n";
        return;
    }

    for (const auto& prod : productos) {
        archivo << prod.getId() << ","
                << prod.getNombre() << ","
                << prod.getPrecio() << ","
                << prod.getCantidad() << "/n";
    }
}

bool Inventario::eliminarProducto(int id) {
    for (size_t i = 0; i < productos.size(); i++) {
        if (productos[i].getId() == id) {
            productos.erase(productos.begin() + i);
            return true;
        }
    }
    return false; 
}

void Inventario::cargarDesdeArchivo(const std::string& ruta) {
    std::ifstream archivo(ruta);

    if (!archivo) {
        return; // inventario vacío
    }

    productos.clear();

    std::string linea;
    std::getline(archivo, linea); //saltar encabezado

    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue;
        std::stringstream ss(linea);
        std::string idStr, nombre, precioStr, cantidadStr;

        std::getline(ss, idStr, ',');
        std::getline(ss, nombre, ',');
        std::getline(ss, precioStr, ',');
        std::getline(ss, cantidadStr, ',');

        int id = std::stoi(idStr);
        int cantidad = std::stoi(cantidadStr);
        double precio = std::stod(precioStr);

        productos.push_back(Producto(id, nombre, precio, cantidad));

    }
}

