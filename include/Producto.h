#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

class Producto{
private:
    int id;
    std::string nombre;
    double precio;
    int cantidad;

public:
    Producto(int id, const std::string& nombre, double precio, int cantidad);

    int getId() const;
    std::string getNombre() const;
    double getPrecio() const; 
    int getCantidad() const;

    void setCantidad(int nuevaCantidad); 
};

#endif
