#include <iostream>
#include <string>
#include "empleado.h"
#include "inventario.h"
#include "produccion.h"


// AQUI IRAN LOS USOS DE TODAS LAS CLASES;
int main() {
    // Cargar datos quemdos
    cargarInventario(); 
    //cargarProduccion();

    // Variables locales
    bool salir = false;
    int opcion = 0;
    do
    {   
        
        std::cout << "========================================" << std::endl;
        std::cout << "|             MENU PRINCIPAL           |" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << " " << std::endl;
        std::cout << "1. Recursos Humanos" << std::endl;
        std::cout << "2. Inventario" << std::endl;
        std::cout << "3. Fases de proyecto" << std::endl;
        std::cout << "4. Salir" << std::endl;

        std::cout << " " << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1: 
            std::system("cls");      // Limpiar la pantalla
            mostrarMenu();
            break;
        case 2:
            std::system("cls");      // Limpiar la pantalla
            mainInventario();
            break;
        case 3:
            std::system("cls");      // Limpiar la pantalla
            mainProduccion();
            break;
        case 4:
            salir = true;
            break;

        default:
            std::cout << "Opcion invalida" << std::endl;
            break;
        }

    } while (!salir);
    
    return 0;
}
