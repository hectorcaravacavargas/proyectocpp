#include <iostream>
#include <string>
#include <cstdlib> // Para limpiar la pantalla

class Objeto { // Clase para crear objetos del inventario
public:
    Objeto(const std::string& nombre, const std::string& categoria, int cantidad)
        : nombre(nombre), categoria(categoria), cantidad(cantidad), siguiente(nullptr) {}

    std::string getNombre() const {
        return nombre;
    }

    std::string getCategoria() const {
        return categoria;
    }

    int getCantidad() const {
        return cantidad;
    }

    void setCantidad(int cantidad) {
        this->cantidad = cantidad;
    }

    Objeto* getSiguiente() const {
        return siguiente;
    }

    void setSiguiente(Objeto* obj) {
        siguiente = obj;
    }

private:
    std::string nombre;
    std::string categoria;
    int cantidad;
    Objeto* siguiente;
};

class Inventario { // Clase para crear el inventario de objetos
public:
    Inventario() : primero(nullptr) {}

    /**
     * @brief Constructor de la clase Inventario
     * 
     * @param nombre 
     * @param categoria 
     * @param cantidad 
     */
    void agregarObjeto(const std::string& nombre, const std::string& categoria, int cantidad) { // Funcion publica para agregar objetos al inventario
        Objeto* nuevoObjeto = new Objeto(nombre, categoria, cantidad);
        nuevoObjeto->setSiguiente(primero);
        primero = nuevoObjeto;
    }

    // Clases amigas
    friend bool cantidadObjeto(Inventario& inventario, const std::string& nombre, int cantidadUtilizada);
    friend bool estadoInventario(Inventario& inventario, const std::string& nombre, int cantidad);

    /**
     * @brief Metodo para aumentar el inventario de un objeto ya existente
     * 
     */
    void aumentarInventario() { // Funcion publica para aumentar el inventario ya existente
        bool salir = false;

        // Variables locales
        std::string nombre;
        int cantidad;
        std::cout << "Ingrese el nombre del objeto: ";

        std::cin.ignore();                              // Ignora el carácter de nueva línea anterior
        std::getline(std::cin, nombre);                 // Leer linea completa

        // Validar que el objeto exista
        Objeto* actual = primero;
        while (actual) {
            if (actual->getNombre() == nombre) {
                salir = true;
                break;
            }
            actual = actual->getSiguiente();
        }

        if (!salir) {
            std::cout << "El objeto no existe" << std::endl;
            return;
        }
        
        std::cout << "Ingrese la cantidad: ";
        std::string input;
        std::cin >> input;
        try
        {
            cantidad = std::stoi(input);                    // Si no convierte dispara el catch
            this->aumentarInventario(nombre, cantidad);     // Llamada a la funcion privada para aumentar el inventario
        }
        catch(const std::exception& e)
        {
            std::cout << "Entrada no valida. Por favor, ingrese un numero valido." << std::endl;
        }
        
        
    }

    /**
     * @brief Metodo para mostrar el inventario por categoria
     * 
     */
    void mostrarInventario() const { // Funcion para mostrar inventario por categoria
        // Mostrar las categorias
        std::cout << "REVISION DE INVENTARIO" << std::endl;
        std::cout << " " << std::endl;

        std::cout << "Categorias: " << std::endl;
        std::cout << " " << std::endl;

        std::cout << "1. Chasis" << std::endl;
        std::cout << "2. Mecanica" << std::endl;
        std::cout << "3. Electrica" << std::endl;
        std::cout << "4. Acabados" << std::endl;
        std::cout << " " << std::endl;

        std::cout << "Ingrese la categoria: ";

        int eleccion;
        std::string categoria;
        std::string input;
        std::cin >> input;
        try
        {
            eleccion = std::stoi(input); // Si no convierte dispara el catch
            if (eleccion == 1)
            {
                categoria = "Chasis";
            }
            else if (eleccion == 2)
            {
                categoria = "Mecanica";
            }
            else if (eleccion == 3)
            {
                categoria = "Electrica";
            }
            else if (eleccion == 4)
            {
                categoria = "Acabados";
            }
            else
            {   
                std::system("cls");      // Limpiar la pantalla
                std::cout << "Opcion invalida" << std::endl;
                return;
            }
        }
        catch(const std::exception& e)
        {   
            std::system("cls");      // Limpiar la pantalla
            std::cout << "Entrada no valida. Por favor, ingrese un numero valido." << std::endl;
            return;
        }
        


        std::system("cls");      // Limpiar la pantalla

        // Formato para mostrar el inventario
        std::cout << "Inventario de la categoria: " << categoria << std::endl;
        std::cout << " " << std::endl;

        // Mostrar el inventario
        Objeto* actual = primero;
        while (actual) {
            if (actual->getCategoria() == categoria) {
                std::cout << "Nombre: " << actual->getNombre() << ", Cantidad: " << actual->getCantidad() << std::endl;   
            }
            actual = actual->getSiguiente();
        }
    }

private:
    Objeto* primero;

    /**
     * @brief Metodo privado para aumentar el inventario de un objeto ya existente
     * 
     * @param nombre 
     * @param cantidad 
     */
    void aumentarInventario(const std::string& nombre, int cantidad) { // Funcion privada para aumentar el inventario ya existente
        Objeto* actual = primero;
        while (actual) {
            if (actual->getNombre() == nombre) {                       // Si el nombre del objeto es igual al nombre ingresado
                actual->setCantidad(actual->getCantidad() + cantidad); // Aumentar la cantidad
                // Mostrar la cantidad actualizada
                std::cout << " " << std::endl;
                std::cout << "Cantidad actualizada correctamente" << std::endl;
                std::cout << " " << std::endl;
                std::cout << "Nombre: " << actual->getNombre() << ", Cantidad: " << actual->getCantidad() << std::endl;
                return;
            }
            actual = actual->getSiguiente();                           // Siguiente objeto
        }
    }

};

Inventario inventario; // Instancia de la clase Inventario

/**
 * @brief Funcion para cargar el inventario con objetos
 * 
 */
void cargarInventario(){ // Funcion para cargar el inventario con objetos

    // Agregar objetos al inventario (Estructuracion del chasis)
    inventario.agregarObjeto("Puertas", "Chasis", 0);
    inventario.agregarObjeto("Largueros", "Chasis", 0);
    inventario.agregarObjeto("Travesanos", "Chasis", 10);
    inventario.agregarObjeto("Laterales", "Chasis", 8);
    inventario.agregarObjeto("Refuerzos", "Chasis", 0);

    // Agregar objetos al inventario (Implementacion Mecanica)
    inventario.agregarObjeto("Motor", "Mecanica", 5);
    inventario.agregarObjeto("Transmision", "Mecanica", 4);
    inventario.agregarObjeto("Suspension", "Mecanica", 12);
    inventario.agregarObjeto("Frenos", "Mecanica", 6);
    inventario.agregarObjeto("Direccion", "Mecanica", 5);
    inventario.agregarObjeto("Ruedas", "Mecanica", 22);
    inventario.agregarObjeto("Escape", "Mecanica", 7);

    // Agregar objetos al inventario (Implementacion Electrica)
    inventario.agregarObjeto("Bateria", "Electrica", 5);
    inventario.agregarObjeto("Alternador", "Electrica", 8);
    inventario.agregarObjeto("Luces", "Electrica", 35);
    inventario.agregarObjeto("Computadora", "Electrica", 6);
    inventario.agregarObjeto("Cables", "Electrica", 80);
    inventario.agregarObjeto("Radio", "Electrica", 8);
    inventario.agregarObjeto("Altavoces", "Electrica", 23);

    // Agregar objetosal inventario (Implementaciones Acabados)
    inventario.agregarObjeto("Asientos", "Acabados", 15);
    inventario.agregarObjeto("Volante", "Acabados", 7);
    inventario.agregarObjeto("Tablero", "Acabados", 6);
    inventario.agregarObjeto("Pintura-Roja", "Acabados", 12);
    inventario.agregarObjeto("Pintura-Negra", "Acabados", 12);
    inventario.agregarObjeto("Pintura-Azul", "Acabados", 12);
    inventario.agregarObjeto("Cristales", "Acabados", 20);
    inventario.agregarObjeto("Espejos", "Acabados", 16);
}

/**
 * @brief Funcion para restar objetos del inventario
 * 
 * @param inventario 
 * @param nombre 
 * @param cantidadUtilizada 
 * @return bool
 */
bool cantidadObjeto(Inventario& inventario, const std::string& nombre, int cantidadUtilizada) { // Funcion para restar objetos del inventario
    Objeto* actual = inventario.primero;
    while (actual) {
        if (actual->getNombre() == nombre) { 
            if (actual->getCantidad() >= cantidadUtilizada) {
                actual->setCantidad(actual->getCantidad() - cantidadUtilizada);
                std::cout << "Se gastaron " << cantidadUtilizada << " " << nombre << std::endl;
                return true; // Se restó la cantidad con éxito
            } else {
                int faltantes = cantidadUtilizada - actual->getCantidad();
                int faltantesAbs = std::abs(faltantes);
                std::cout << "Falta " << faltantesAbs << " " << nombre << std::endl;
                return false; // No se pudo restar debido a cantidad insuficiente
            }
        }
        actual = actual->getSiguiente();
    }
    std::cout << "No se encontro " << nombre << std::endl;
    return false; // El objeto no se encontró en la lista
}

/**
 * @brief Funcion para validar si hay suficientes objetos en el inventario
 * 
 * @param inventario 
 * @param nombre 
 * @param cantidad 
 * @return bool
 */
bool estadoInventario(Inventario& inventario, const std::string& nombre, int cantidad) { // Funcion para restar objetos del inventario
    Objeto* actual = inventario.primero;
    while (actual) {
        if (actual->getNombre() == nombre) { 
            if (actual->getCantidad() >= cantidad) {
                return true; // Si hay suficientes objetos
            } else {
                return false; // No  hay suficientes objetos
            }
        }
        actual = actual->getSiguiente();
    }
    return false; // El objeto no se encontró en la lista
}

/**
 * @brief Menu secundario para mostrar las opciones del inventario
 * 
 */
void mainInventario(){// Menu de opciones para el inventario
    bool salir = false;

    do
    {
        int opcion;
        std::cout << "========================================" << std::endl;
        std::cout << "|    MENU DE OPCIONES DE INVENTARIO    |" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << " " << std::endl;

        std::cout << "1. Agregar un nuevo objeto" << std::endl;
        std::cout << "2. Aumentar inventario" << std::endl;
        std::cout << "3. Mostrar inventario" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std ::cout << " " << std::endl;

        std::cout << "Ingrese la opcion: ";
        std::string input;
        std::cin >> input;

        // Limpiar la pantalla
        std::system("cls");

        try
        {   opcion = std::stoi(input); // Si no convierte dispara el catch

            if (opcion == 1)
            {   
                // Variables locales para la crear un nuevo objeto
                std::string nombre;
                std::string categoria;
                int cantidad;

                std::cout << "Ingrese el nombre del objeto: ";
                std::cin.ignore();                                     // Ignora el carácter de nueva línea anterior

                std::getline(std::cin, nombre);                        // Leer linea completa
                std::cout << "Ingrese la categoria: ";
                std::cin >> categoria;                                 // Leer categoria

                // Validar que la categoria exista
                if (categoria != "Chasis" && categoria != "Mecanica" && categoria != "Electrica" && categoria != "Acabados") {
                    std::cout << "La categoria no existe" << std::endl;
                    return;
                }

                std::cout << "Ingrese la cantidad: ";
                std::string input;
                std::cin >> input;
                try
                {   
                    cantidad = std::stoi(input); // Si no convierte dispara el catch
                    inventario.agregarObjeto(nombre, categoria, cantidad); // Llamada a la funcion para agregar un nuevo objeto
                    std::cout << " " << std::endl;
                    std::cout << "Objeto agregado correctamente" << std::endl;
                }
                catch(const std::exception& e)
                {
                    std::cout << "Entrada no valida. Por favor, ingrese un numero valido." << std::endl;
                } 
            }
            else if (opcion == 2)
            {
                inventario.aumentarInventario();                       // Llamada a la funcion para aumentar el inventario
            }
            else if (opcion == 3)
            {
                inventario.mostrarInventario();                        // Llamada a la funcion para mostrar el inventario
            }
            else if (opcion == 4)
            {
                salir = true;                                          // Salir del menu
            }
            else
            {   
                std::system("cls");      // Limpiar la pantalla
                std::cout << "Opcion invalida" << std::endl;
            }
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Entrada no valida. Por favor, ingrese un numero valido." << std::endl;
        }
        
    } while (!salir);
    
}
