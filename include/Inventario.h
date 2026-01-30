#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include "Producto.h"

class Inventario {
private:
    std::vector<Producto> productos;

public:
    bool agregarProducto(const Producto& producto);
    void mostrarProductos() const;
    Producto* buscarProductoPorId(int id);
    bool actualizarStock(int id, int nuevaCantidad);
    //Métodos persistencia
    void cargarDesdeArchivo(const std::string& ruta);
    void guardarEnArchivo(const std::string& ruta) const;

};

#endif