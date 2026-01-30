#include "Producto.h"

Producto::Producto(int id, const std::string& nombre, double precio, int cantidad) : id(id), nombre(nombre), precio(precio), cantidad(cantidad) {}

int Producto::getId() const{
    return id;
}

std::string Producto::getNombre() const {
    return nombre;
}

int Producto::getCantidad() const {
    return cantidad;
}

double Producto::getPrecio() const {
    return precio;
}

void Producto::setCantidad(int nuevaCantidad) {
    cantidad = nuevaCantidad;
}