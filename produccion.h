#include <iostream>
#include <string>


class Carro { 
private:
   private:
    int numero_chasis;
    std::string etapa;
    int puertas;
    std::string color;
    

    public:
        Carro(int numero_chasis, const std::string& etapa, int puertas, const std::string& color)
            : numero_chasis(numero_chasis), etapa(etapa), puertas(puertas), color(color) {}

    void IniciarEtapaChasis() {
        // Implementa el código para iniciar la etapa del chasis aquí
    }

    int getNumeroChasis() const { // Método para obtener el número de chasis
        return numero_chasis;
    }

    std::string getEtapa() const { // Método para obtener la etapa
        return etapa;
    }

    std::string getColor() const { // Método para obtener el color
        return color;
    }

    int getPuertas() const { // Método para obtener el número de puertas
        return puertas; 
    }

    void setEtapa(std::string etapa) { // Método para cambiar la etapa
        this->etapa = etapa;
    }


    friend class ListaCircularCarros; // Permitir a ListaCircularCarros acceder a miembros privados
};

struct nodo { 
    Carro* carro;
    nodo* sig;
    
    nodo(Carro* carro) : carro(carro), sig(NULL) {}
};

class ListaCircularCarros { // Clase para la lista circular de carros
private:
    nodo* primero = NULL;

public:
    void agregar_carro(Carro* nuevo_carro) { // Metodo para agregar un nuevo carro a la lista
        nodo* nuevo_nodo = new nodo(nuevo_carro);

        if (primero == NULL) {
            primero = nuevo_nodo;
            nuevo_nodo->sig = primero;
        } else {
            nodo* ultimo = primero;
            while (ultimo->sig != primero) {
                ultimo = ultimo->sig;
            }
            ultimo->sig = nuevo_nodo;
            nuevo_nodo->sig = primero;
        }
    }

    void mostrarCarros() { // Metodo para mostrar todos los carros de la lista
        if (primero == NULL) {
            std::cout << "La lista de carros está vacía." << std::endl;
            return;
        }

        std::cout << "========================================" << std::endl;
        std::cout << "|            Lista de carros           |" << std::endl;
        std::cout << "========================================" << std::endl;
        nodo* actual = primero;
        do {
            std::cout << "Numero de chasis: " << actual->carro->getNumeroChasis() << ", Etapa: " << actual->carro->getEtapa() << ", Puertas: " << actual->carro->getPuertas() << ", Color: " << actual->carro->getColor() << std::endl;
            actual = actual->sig;
        } while (actual != primero);
    }

    void crearCarro() { // Metodo para crear un nuevo carro en etapa 0
        int numero_chasis;
        int numero_puertas;
        int color;
        std::string colorSeleccionado;

        std::cout << "Ingrese el numero de chasis: ";
        std::cin >> numero_chasis;
        std::cout << " " << std::endl;

        std::cout << "Ingrese el numero de puertas: ";
        std::cin >> numero_puertas;
        std::cout << " " << std::endl;

        std::cout << "Seleccione un color: " << std::endl;
        std::cout << " " << std::endl;

        bool colorCorrecto = false;
        while (!colorCorrecto)
        {
            
            std::cout << "1. Rojo" << std::endl;
            std::cout << "2. Azul" << std::endl;
            std::cout << "3. Negro" << std::endl;
            std::cout << " " << std::endl;

            std::cin >> color;

            switch (color) {
            case 1:
                colorSeleccionado = "Rojo";
                colorCorrecto = true;
                break;

            case 2:
                colorSeleccionado = "Azul";
                colorCorrecto = true;
                break;

            case 3:
                colorSeleccionado = "Negro";
                colorCorrecto = true;
                break;

            default:
                std::cout << "Ingrese una opcion valida" << std::endl;
                break;
            }

        }

        Carro* nuevoCarro = new Carro(numero_chasis, "Sin iniciar", numero_puertas, colorSeleccionado);
        agregar_carro(nuevoCarro);
        std::cout << "Carro con chasis " << numero_chasis << " 'CREADO EXITOSAMENTE'" << std::endl;
    }

    int buscarPuertas(int numeroChasis){ // Metodo que retorna la cantidad de puertas del auto
        nodo* actual = primero;
        do {
            if (actual->carro->getNumeroChasis() == numeroChasis)
            {   
                return actual->carro->getPuertas();
            }
            
            actual = actual->sig;
        } while (actual != primero);
        return 0;
    }

    std::string busarColor(int numeroChasis){ // Metodo que retorna el color del auto
        nodo* actual = primero;
        do {
            if (actual->carro->getNumeroChasis() == numeroChasis)
            {   
                return actual->carro->getColor();
            }
            
            actual = actual->sig;
        } while (actual != primero);
        return 0;
    }

    std::string busarEtapa(int numeroChasis){ // Metodo que retorna la etapa del auto
        nodo* actual = primero;
        do {
            if (actual->carro->getNumeroChasis() == numeroChasis)
            {   
                return actual->carro->getEtapa();
            }
            
            actual = actual->sig;
        } while (actual != primero);
        return 0;
    }

    void cambiarDetapa(int numeroChasis, std::string etapa){ // Metodo para cambiar la etapa de un auto
        nodo* actual = primero;
        do {
            if (actual->carro->getNumeroChasis() == numeroChasis)
            {   
                actual->carro->setEtapa(etapa);
            }
            
            actual = actual->sig;
        } while (actual != primero);
    }

    void verEtapa(){ // Metodo para ver la etapa de un auto en especifico por numero de chasis
        int numeroChasis;
        bool encontrado = false;

        if (primero == NULL) {
                std::cout << "No existe ningun auto en producion" << std::endl;
                return;
            }

        std::cout << "========================================" << std::endl;
        std::cout << "|           Todos los chasis           |" << std::endl;
        std::cout << "========================================" << std::endl;
        nodo* actual = primero;
        do {
            std::cout << "Numero de chasis: " << actual->carro->getNumeroChasis() << std::endl;
            actual = actual->sig;
        } while (actual != primero);

        std::cout << " " << std::endl;
        std::cout << "Ingrese el numero de chasis: ";
        std::cin >> numeroChasis;
 
        do
        {
            if (actual->carro->getNumeroChasis() == numeroChasis)
            {
                std::cout << "El auto con chasis " << numeroChasis << " esta en la etapa: " << actual->carro->getEtapa() << std::endl;
                encontrado = true;
                return;
            }
            actual = actual->sig;
        } while (actual != primero);

        if (!encontrado)
        {
            std::cout << "No se encontro el auto con chasis " << numeroChasis << std::endl;
            std::cout << "Por favor ingrese correctamente el numero de chasis" << std::endl;
        }   
        std::cout << " " << std::endl;
    };

};

void elementoIsufisintes(){ // Funcion para mostrar que no se puede avanzar a la siguiente etapa
    std::cout << " " << std::endl;
    std::cout << "No se puede avanzar a la siguiente etapa" << std::endl;
    std::cout << "Faltan elementos para poder avanzar" << std::endl;
    std::cout << " " << std::endl;
};

void etapaChasis(int puertas){ // Funcion para pasar un auto a la etapa de chasis 
    if (!cantidadObjeto(inventario, "Refuerzos", 2)){   
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if(!cantidadObjeto(inventario, "Laterales",2)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if(!cantidadObjeto(inventario, "Travesanos",4)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if(!cantidadObjeto(inventario, "Largueros",4)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Puertas", puertas)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
}
    
void etapaMecanica(){ // Funcion para pasar un auto a la etapa de mecanica
    if (!cantidadObjeto(inventario, "Motor", 1)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Transmision", 1)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Suspension", 4)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Frenos", 4)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Direccion", 1)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Ruedas", 5)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Escape", 5)){
       elementoIsufisintes();
        inventario.aumentarInventario();
    }
};

void etapaElectrica(){ // Funcion para pasar un auto a la etapa de electrica
    if (!cantidadObjeto(inventario, "Bateria", 1)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Alternador", 1)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Luces", 4)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Radio", 1)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Altavoces", 8)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }

    if (!cantidadObjeto(inventario, "Computadora", 1)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }

    if (!cantidadObjeto(inventario, "Cables", 30)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
};

void etapaAcabado(std::string color){ // Funcion para pasar un auto a la etapa de acabados
    if (!cantidadObjeto(inventario, "Asientos", 5)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Volante", 1)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Tablero", 1)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Espejos", 2)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (!cantidadObjeto(inventario, "Cristales", 5)){
        elementoIsufisintes();
        inventario.aumentarInventario();
    }
    if (color == "Rojo"){
        if (!cantidadObjeto(inventario, "Pintura-Roja", 1)){
            elementoIsufisintes();
            inventario.aumentarInventario();
        }
    }
    else if (color == "Azul")
    {
        if (!cantidadObjeto(inventario, "Pintura-Roja", 1)){
            elementoIsufisintes();
            inventario.aumentarInventario();
        }  
    }
    else
    {
        if (!cantidadObjeto(inventario, "Pintura-Roja", 1)){
            elementoIsufisintes();
            inventario.aumentarInventario();
        }
    }     
};

void enterToExit(){ // Funcion que espera que se presione "ENTER" para continuar
    std::cout << "Presiona Enter para salir..." << std::endl;

    while (true) {
        int caracter = getchar(); // Lee un carácter desde la entrada estándar

        if (caracter == '\n') {
            break; // Sale del bucle cuando se presiona Enter ('\n')
        }
    }
};
ListaCircularCarros lista_carros;

void cargarProduccion(){

    Carro* carro1 = new Carro(123, "Produccion", 4, "Rojo");
    Carro* carro2 = new Carro(456, "Ensamblaje",2 , "Azul");
    Carro* carro3 = new Carro(789, "Acabados", 4, "Negro");

    lista_carros.agregar_carro(carro1);
    lista_carros.agregar_carro(carro2);
    lista_carros.agregar_carro(carro3);

}; 

void mainProduccion() { // Menu de opciones para la produccion
    std::string colorTemp;
    std::string etapaTemp;
    std::string confirmacionTemp = "N";

    bool salir = false;
    do
    {
        int opcion;
        std::cout << "========================================" << std::endl;
        std::cout << "|         FASES DE PRODUCCION          |" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << " " << std::endl;

        std::cout << "1. Crear un nuevo auto" << std::endl;
        std::cout << "2. Consultar la epata de un auto" << std::endl;
        std::cout << "3. Avanzar etapa de un auto" << std::endl;
        std::cout << "4. Mostrar todos los autos" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std ::cout << " " << std::endl;

        std::cout << "Ingrese la opcion: " ;
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            std::system("cls");           // Limpiar la pantalla
            lista_carros.crearCarro();
            std::cin.ignore();            // Ignora el carácter de nueva línea anterior
            enterToExit();                // Espera que se presione "ENTER" para continuar
            std::system("cls");           // Limpiar la pantalla
            break;
        case 2:
            std::system("cls");           // Limpiar la pantalla
            lista_carros.verEtapa();
            std::cin.ignore();            // Ignora el carácter de nueva línea anterior
            enterToExit();                // Espera que se presione "ENTER" para continuar
            std::system("cls");           // Limpiar la pantalla
            break;

        case 3:
            std::system("cls");           // Limpiar la pantalla
            int numeroChasis;
            int cantidadPuertas;

             std::system("cls");           // Limpiar la pantalla
            lista_carros.mostrarCarros(); // Muestra todos los carros
            std::cout << " " << std::endl;

            std::cout << "Ingrese el numero de chasis: ";
            std::cin >> numeroChasis;
            std::system("cls");           // Limpiar la pantalla

            etapaTemp = lista_carros.busarEtapa(numeroChasis);
            std::cout << "El auto con chasis " << numeroChasis << " esta en la etapa: " << etapaTemp << std::endl;
            std::cout << "Quires pasar el auto a la siguiente entapa (Y/N)? ";
            std::cin >> confirmacionTemp;

            if (confirmacionTemp == "Y" || confirmacionTemp == "y"){
                if (etapaTemp == "Sin iniciar")
                {
                    cantidadPuertas = lista_carros.buscarPuertas(numeroChasis);
                    etapaChasis(cantidadPuertas);
                    lista_carros.cambiarDetapa(numeroChasis, "Chasis");
                }
                else if (etapaTemp == "Chasis")
                {
                    etapaMecanica();
                    lista_carros.cambiarDetapa(numeroChasis, "Mecanica");
                }
                else if (etapaTemp == "Mecanica")
                {
                    etapaElectrica();
                    lista_carros.cambiarDetapa(numeroChasis, "Electrica");
                }
                else if (etapaTemp == "Electrica")
                {
                    colorTemp = lista_carros.busarColor(numeroChasis);
                    etapaAcabado(colorTemp);
                    lista_carros.cambiarDetapa(numeroChasis, "Acabados");
                }
                else if (etapaTemp == "Acabados")
                {
                    std::cout << "El auto con chasis " << numeroChasis << " ya esta terminado" << std::endl;
                    std::cout << " " << std::endl;
                    lista_carros.cambiarDetapa(numeroChasis, "Terminado");
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }
            
            std::cin.ignore();            // Ignora el carácter de nueva línea anterior
            enterToExit();                // Espera que se presione "ENTER" para continuar
            std::system("cls");           // Limpiar la pantalla
            break;

        case 4:
            std::system("cls");           // Limpiar la pantalla
            lista_carros.mostrarCarros();
            std::cin.ignore();            // Ignora el carácter de nueva línea anterior
            enterToExit();                // Espera que se presione "ENTER" para continuar
            std::system("cls");           // Limpiar la pantalla
            break;

        case 5:
            salir = true;
            std::system("cls");           // Limpiar la pantalla
            break;

        default:
            std::cout << "Opcion invalida" << std::endl;
            break;
        }

    } while (!salir);
      
}