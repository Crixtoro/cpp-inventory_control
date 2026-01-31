#include <iostream>
#include "Producto.h"
#include "Inventario.h"

int main() {
    Inventario inventario; 

    inventario.cargarDesdeArchivo("data/inventario.csv");

    int opcion = 0;

    while (opcion != 6) {
        std::cout << "\n=== MENU INVENTARIO ===\n";
        std::cout << "1. Agregar producto\n";
        std::cout << "2. Mostrar productos\n";
        std::cout << "3. Buscar producto por ID\n";
        std::cout << "4. Actualizar stock\n";
        std::cout << "5. Eliminar producto\n";
        std::cout << "6. Guardar y salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int id;
                std::string nombre;
                double precio;
                int cantidad;

                std::cout <<"ID: ";
                std::cin >> id;
                std::cin.ignore(); // limpiamos bufer para getline
                
                std::cout <<"Nombre: ";
                std::getline(std::cin, nombre);
                
                std::cout << "Precio: ";
                std::cin >> precio;

                std::cout << "Cantidad: ";
                std::cin >> cantidad;

                inventario.agregarProducto(Producto(id, nombre, precio, cantidad));
                
                break;
            }
            case 2:
                inventario.mostrarProductos();
                break;
            case 3: {
                std::cout << "Buscar producto\n";
                int id;
                std::cout << "Ingrese el ID del producto a buscar: ";
                std::cin >> id;

                Producto* p = inventario.buscarProductoPorId(id);

                if (p != nullptr) {
                    std::cout << "\nProducto encontrado:\n";
                    std::cout << "ID: " << p->getId() << "\n";
                    std::cout << "Nombre: " << p->getNombre() << "\n";
                    std::cout << "Precio: " << p->getPrecio() << "\n";
                    std::cout << "Cantidad: " << p->getCantidad() << "\n"; 
                } else {
                    std::cout << "Producto con ID " << id << " no encontrado.\n";
                }
                
                break;
            }
            case 4: {
                int id;
                std::cout << "Ingrese el ID del producto";
                std::cin >> id;

                Producto* p = inventario.buscarProductoPorId(id);

                if (p == nullptr) {
                    std::cout << "Producto no encontrado.\n";
                    break;
                }

                int nuevaCantidad;
                std::cout << "Cantidad actual: " << p->getCantidad() << "\n";
                std::cout << "Ingrese la nueva cantidad: "; 
                std::cin >> nuevaCantidad;

                if (nuevaCantidad < 0) {
                    std::cout << "La cantidad no puede ser negativa.\n";
                } else {
                    p->setCantidad(nuevaCantidad);
                    std::cout << "Stock actualizado correctamente.\n";
                }

                break;
            }
            case 5:
                std::cout << "Eliminar producto\n";
                break;
            case 6:
                inventario.guardarEnArchivo("data/inventario.csv");
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida\n";
        }
    }

    return 0;
}