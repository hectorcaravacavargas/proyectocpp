#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

// NOMBRE DE LA EMPRESA: LuxeHeJos SA

struct ConsultarSalario { // Estrucutra para consultar el salario
    int horasLaboradas, diasTrabajados;
    bool feriados, turnoEspecial, horarioRegular;
    std::string categoria, tipoContrato;

    // CONSTRUCTOR DE LA ESTRUCTURA CONSULTARSALARIO
    ConsultarSalario(int _horasLaboradas, int _diasTrabajados, bool _feriados, bool _turnoEspecial, bool _horarioRegular, std::string _categoria, std::string _tipoContrato) {
        horasLaboradas = _horasLaboradas;
        feriados = _feriados;
        turnoEspecial = _turnoEspecial;
        categoria = _categoria;
        diasTrabajados = _diasTrabajados;
        horarioRegular = _horarioRegular;
        tipoContrato = _tipoContrato;
    }
};

class Empleado { // Clase Empleado
private:
    // ATRIBUTOS BASICOS DEL EMPLEADO
    std::string nombre, apellido, tipoContrato; // TIPO DE CONTRATO PUEDE SER HORA O JORNADA COMPLETA
    int edad;

    // ATRIBUTOS PARA EL CALCULO DEL SALARIO
    float salarioBase, complementosSalariales;

    // ATRIBUTOS RELACIONADOS CON EL TRABAJO
    std::string categoria, sector;

    // PUNTERO JEFE
    Empleado *jefe;
    Empleado *inicio;

public:
    // CONSTRUCTOR
    Empleado(std::string _nombre, std::string _apellido, int _edad, std::string _tipoContrato, float _salarioBase,
    float _complementosSalariales, std::string _categoria, std::string _sector, Empleado* _jefe) {

        nombre = _nombre;
        apellido = _apellido;
        edad = _edad;
        tipoContrato = _tipoContrato;
        salarioBase = _salarioBase;
        complementosSalariales = _complementosSalariales;
        categoria = _categoria;
        sector = _sector;
        jefe = _jefe;
        inicio = nullptr; // ASIGNAR INICIO A NULL
    }

    // METODOS GETTERS
    std::string getNombre() const {
        return nombre;
    }

    std::string getApellido() const {
        return apellido;
    }

    int getEdad() const {
        return edad;
    }

    std::string getTipoContrato() const {
        return tipoContrato;
    }

    float getSalarioBase() const {
        return salarioBase;
    }

    float getComplementosSalariales() const {
        return complementosSalariales;
    }

    std::string getCategoria() const {
        return categoria;
    }

    std::string getSector() const {
        return sector;
    }

    Empleado* getJefe() const {
        return jefe;
    }

    Empleado* getInicio() const {
        return inicio;
    }

    Empleado* getSig() const {
        return sig;
    }

    Empleado* getAnterior() const {
        return ant;
    }

    // METODOS SETTERS
    void setNombre(const std::string& _nombre) {
        nombre = _nombre;
    }

    void setApellido(const std::string& _apellido) {
        apellido = _apellido;
    }

    void setEdad(int _edad) {
        edad = _edad;
    }

    void setTipoContrato(const std::string& _tipoContrato) {
        tipoContrato = _tipoContrato;
    }

    void setSalarioBase(float _salarioBase) {
        salarioBase = _salarioBase;
    }

    void setComplementosSalariales(float _complementosSalariales) {
        complementosSalariales = _complementosSalariales;
    }

    void setCategoria(const std::string& _categoria) {
        categoria = _categoria;
    }

    void setSector(const std::string& _sector) {
        sector = _sector;
    }

    void setJefe(Empleado* _jefe) {
        jefe = _jefe;
    }

    void setInicio(Empleado* _inicio) {
        inicio = _inicio;
    }

    void setSig(Empleado* _sig) {
        sig = _sig;
    }

    void setAnterior(Empleado* _ant) {
        ant = _ant;
    }

    /**
     * @brief Metodo para imprimir la informacion de un empleado
     * 
     */
    void imprimirInformacion() {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Apellido: " << apellido << std::endl;
        std::cout << "Edad: " << edad << std::endl;
        std::cout << "Tipo de Contrato: " << tipoContrato << std::endl;
        std::cout << "Salario Base: $" << salarioBase << std::endl;
        std::cout << "Complementos Salariales: $" << complementosSalariales << std::endl;
        std::cout << "Categoria: " << categoria << std::endl;
        std::cout << "Sector: " << sector << std::endl;
        if (jefe != nullptr) {
            std::cout << "Jefe: " << jefe->nombre << std::endl;
        } else {
            std::cout << "No tiene jefe." << std::endl;
        }
    }

    /**
     * @brief Metodo para actualizar la informacion de un empleado
     * 
     * @param nuevoEmpleado 
     * Esta funcion es usado en las funciones de ordenar las listas
     */
    void actualizarEmpleado(const Empleado& nuevoEmpleado) {

        nombre = nuevoEmpleado.nombre;
        apellido = nuevoEmpleado.apellido;
        edad = nuevoEmpleado.edad;
        tipoContrato = nuevoEmpleado.tipoContrato;
        salarioBase = nuevoEmpleado.salarioBase;
        complementosSalariales = nuevoEmpleado.complementosSalariales;
        categoria = nuevoEmpleado.categoria;
        sector = nuevoEmpleado.sector;
        jefe = nuevoEmpleado.jefe;
    }

    // PUNTERO SIGUIENTE Y PUNTERO ANT, INICIALIZADOS EN NULL;
    Empleado *sig = nullptr;
    Empleado *ant = nullptr;
};

class ListEmpleados { // Clase Lista Empleados
private:
    Empleado* inicio;
    Empleado* fin;

public:
    ListEmpleados() : inicio(nullptr), fin(nullptr) {}

    /**
     * @brief Metodo para agregar empleados a la lista
     * 
     * @param nombre 
     * @param apellido 
     * @param _edad 
     * @param _tipoContrato 
     * @param _salarioBase 
     * @param _complementosSalariales 
     * @param _categoria 
     * @param _sector 
     * @param _jefe 
     */
    void agregarEmpleados(std::string nombre, std::string apellido, int _edad, std::string _tipoContrato, float _salarioBase,
        float _complementosSalariales, std::string _categoria, std::string _sector, Empleado* _jefe) {

        Empleado* nuevo = new Empleado("", "", 0, "", 0.0, 0.0, "", "", nullptr); // Crear una instancia de Empleado

        // USAR SETTERS PARA ASIGNAR LOS VALORES
        nuevo->setNombre(nombre);
        nuevo->setApellido(apellido);
        nuevo->setEdad(_edad);
        nuevo->setTipoContrato(_tipoContrato);
        nuevo->setSalarioBase(_salarioBase);
        nuevo->setComplementosSalariales(_complementosSalariales);
        nuevo->setCategoria(_categoria);
        nuevo->setSector(_sector);
        nuevo->setJefe(_jefe);

        if (inicio == nullptr) {
            inicio = nuevo;
        } else {
            Empleado* aux = inicio;
            while (aux->getSig() != nullptr) {
                aux = aux->getSig();
            }
            aux->setSig(nuevo);
        }
    }

    // IMPRIMIR INFORMACION DE LA LISTA DE EMPLEADOS;
    void imprimirInformacion() {
        Empleado* aux = inicio;
        while (aux != nullptr) {
            aux->imprimirInformacion();
            aux = aux->sig;
            std::cout << "\n";
        }
    }

    // METODOS PARA MODIFICAR EMPLEADOS;

    Empleado* buscarEmpleadoPorNombreApellido(std::string nombre, std::string apellido) {
        Empleado* aux = inicio;
        while (aux != nullptr) {
            if (aux->getNombre() == nombre.c_str() && aux->getApellido() == apellido) {
                return aux; // Devuelve el puntero si se encuentra el empleado encontrado
            }
            aux = aux->getSig();
        }
        return nullptr; // No se encontró ningún empleado con el nombre y apellido proporcionados
    }

    /**
     * @brief Metodo para modificar los datos de un empleado
     * 
     * @param nombre 
     * @param apellido 
     * @param edad 
     * @param tipoContrato 
     * @param salarioBase 
     * @param complementosSalariales 
     * @param categoria 
     * @param sector 
     * @param jefe 
     */
    void modificarEmpleado(std::string nombre, std::string apellido, int edad, std::string tipoContrato, float salarioBase,
                      float complementosSalariales, std::string categoria, std::string sector, Empleado* jefe) {
        Empleado* aux = inicio;
            aux->setNombre(nombre);
            aux->setApellido(apellido);
            aux->setEdad(edad);
            aux->setTipoContrato(tipoContrato);
            aux->setSalarioBase(salarioBase);
            aux->setComplementosSalariales(complementosSalariales);
            aux->setCategoria(categoria);
            aux->setSector(sector);
            aux->setJefe(jefe);

            std::cout << "Empleado " << nombre << " " << apellido << " modificado exitosamente." << std::endl;
            return;
    }

    /**
     * @brief Metodo para asignar un jefe a un empleado
     * 
     * @param nombreEmpleado 
     * @param apellidoEmpleado 
     * @param nombreJefe 
     * @param apellidoJefe 
     *
     * Recibe por strings los nombres y los busca en la lista
     */
    void asignarJefe(std::string nombreEmpleado, std::string apellidoEmpleado, std::string nombreJefe, std::string apellidoJefe) {
        // BUSCAR EL EMPLEADO POR NOMBRE Y APELLIDO PARA VERIFICAR CON MAYOR SEGURIDAD SI ESTA ESTA PERSONA;
        Empleado* empleado = buscarEmpleadoPorNombreApellido(nombreEmpleado, apellidoEmpleado);

        if (empleado == nullptr) {
            // SI NO EXISTE EL EMPLEADO SE MUESTRA A CONTINUACION
            std::cout << "El empleado " << nombreEmpleado << " " << apellidoEmpleado << " no se encuentra en la lista." << std::endl;
            return;
        }

        // AL IGUAL, SE BUSCA EL JEFE POR EL NOMBRE Y EL APELLIDO PARA TENER MAYOR CERTEZA;
        Empleado* jefe = buscarEmpleadoPorNombreApellido(nombreJefe, apellidoJefe);

        // SI EL JEFE NO EXISTE, ENTONCES SE INDICA A CONTINUACION;
        if (jefe == nullptr) {
            std::cout << "El jefe " << nombreJefe << " " << apellidoJefe << " no se encuentra en la lista." << std::endl;
            return;
        }

        // EN CASO DE QUE SI EXISTA, SE ASIGNA EL JEFE A LA PERSONA;
        empleado->setJefe(jefe);
        std::cout << "Se ha asignado a " << nombreEmpleado << " " << apellidoEmpleado << " el jefe " << nombreJefe << " " << apellidoJefe << "." << std::endl;
    }

    /**
     * @brief Metodo para eliminar un empleado de la lista
     * 
     * @param nombre 
     * @param apellido 
     */
    void eliminarEmpleado(std::string nombre, std::string apellido) {
        Empleado* aux = inicio;

        while (aux != nullptr) {
            int val = aux->getNombre().compare(nombre); // SE USA LA FUNCION COMPARE PARA TENER CERTEZA
            int val2 = aux->getApellido().compare(apellido);

            if (val == 0 && val2 == 0) {
                // SI SE ENCUENTRA EL EMPLEADO, SE ELIMINA DE LA LISTA
                Empleado* anterior = aux->getAnterior();
                Empleado* siguiente = aux->getSig();

                if (anterior != nullptr) {
                    anterior->setSig(siguiente);
                } else {
                    inicio = siguiente;
                }

                if (siguiente != nullptr) {
                    siguiente->setAnterior(anterior);
                }

                std::cout << "Empleado " << nombre << " " << apellido << " eliminado exitosamente." << std::endl;

                // Eliminar la instancia de empleado para liberar memoria
                delete aux;
                return;
            }

            aux = aux->getSig();
        }

        std::cout << "Empleado con nombre " << nombre << " y apellido: " << apellido << " no encontrado." << std::endl;
    }

    /**
     * @brief Metodo para ordenar los empleados por edad, los ordena de menor a mayor, no se imprime la lista
     * 
     */
    void ordenarPorEdad() {
        Empleado* actual = inicio;
        Empleado* siguiente = nullptr;

        if (inicio == nullptr) {
            return;
        }

        bool intercambio = true;

        while (intercambio) {
            intercambio = false;
            actual = inicio;

            while (actual->getSig() != nullptr) {
                siguiente = actual->getSig();

                if (actual->getEdad() > siguiente->getEdad()) {
                    Empleado temp = *actual;  // Copia temporal para el intercambio
                    actual->actualizarEmpleado(*siguiente);
                    siguiente->actualizarEmpleado(temp);

                    intercambio = true;
                }

                actual = siguiente;
            }
        }
    }

    /**
     * @brief Metodo para ordenar los empleados por apellidos, los ordena en orden alfabetico
     * 
     */
    void ordenarPorApellidos() {
        Empleado* actual = inicio;
        Empleado* siguiente = nullptr;

        while (actual != nullptr) {
            siguiente = actual->getSig();

            while (siguiente != nullptr) {
                if (actual->getApellido()[0] > siguiente->getApellido()[0]) {
                    Empleado temp = *actual;  // Copia temporal para el intercambio
                    actual->actualizarEmpleado(*siguiente);
                    siguiente->actualizarEmpleado(temp);
                }
                siguiente = siguiente->getSig();
            }
            actual = actual->getSig();
        }
    }

    /**
     * @brief Metodo para consultar el salario de un empleado
     * 
     * @param consulta 
     */
    void consultarSalario(const ConsultarSalario& consulta) {
        Empleado* aux = inicio;
        while (aux != nullptr) {
            if (aux->getCategoria() == consulta.categoria) {
                float salario = aux->getSalarioBase();

                // CALCULAR SALARIO BASE
                if (consulta.tipoContrato == "Hora") {
                    salario *= consulta.horasLaboradas;
                } else if (consulta.tipoContrato == "Jornada Completa") {
                    salario *= consulta.diasTrabajados;
                }

                // APLICAR FACTORES ADICIONALES
                if (consulta.horasLaboradas > 40) {
                    salario += (consulta.horasLaboradas - 40) * aux->getSalarioBase() * 1.5;
                }

                if (consulta.feriados) {
                    salario *= 2.0; // DOBLE SALARIOS EN FERIADOS
                }

                // IMPRIMIR EL SALARIO CALCULADO
                std::cout << "Salario de " << aux->getNombre() << " " << aux->getApellido() << ": $" << salario << std::endl;
            }
            aux = aux->sig;
        }
    }

};

ListEmpleados listaEmpleados;

/**
 * @brief Funcion para cargar los empleados
 * 
 */
void cargarEmpleados () {
    listaEmpleados.agregarEmpleados("Juan", "Perez", 20, "Horas", 5500.0, 100.0, "Supervisor", "Ventas", nullptr);
    listaEmpleados.agregarEmpleados("Maria", "Gonzalez", 25, "Jornada Completa", 1000.0, 12.0, "Administradora", "Ventas", nullptr);
    listaEmpleados.agregarEmpleados("Pedro", "Gomez", 30, "Horas", 10000.0, 90.0, "Contador", "Ventas", nullptr);
    listaEmpleados.agregarEmpleados("Jose", "Rodriguez", 35, "Jornada Completa", 15000.0, 35.0, "Supervisor", "Marketing", nullptr);
    listaEmpleados.agregarEmpleados("Ana", "Hernandez", 40, "Horas", 21000.0, 70.0, "Administradora", "Marketing", nullptr);
    listaEmpleados.agregarEmpleados("Luis", "Diaz", 45, "Jornada Completa", 11000.0, 47.0, "Contador", "Marketing", nullptr);
}

/**
 * @brief Menu secundario  para mostrar las opciones de los empleados
 * 
 */
void mostrarMenu() {
    bool salir = false;

    std::string nombre, apellido, tipoContrato, categoria, sector, nombreJefe, apellidoJefe, input;
    int edad, diasTrabajados, feriado, especial, regular, horas, contrato, jefe, opcion;
    float salarioBase, complementosSalariales;
    bool esFeriado, diaEspecial, diaRegular, tieneJefe;

    // MANEJO EXCEPCIONES;
    bool entradaValida = false;

    Empleado* encontrado = nullptr;

    do
    {
        std::cout << "========================================" << std::endl;
        std::cout << "|             MENU EMPLEADOS           |" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << " " << std::endl;
        std::cout << "1. Agregar Empleado" << std::endl;
        std::cout << "2. Modificar Empleado" << std::endl;
        std::cout << "3. Eliminar Empleado" << std::endl;
        std::cout << "4. Ordenar por Edad" << std::endl;
        std::cout << "5. Ordenar por Apellidos" << std::endl;
        std::cout << "6. Consultar Salario" << std::endl;
        std::cout << "7. Mostrar Informacion de Empleados" << std::endl;
        std::cout << "8. Salir" << std::endl;

        do
        {
            std::cout << "\nIngrese una opcion: "; std::cin >> input;
            std::istringstream stream(input);
            if (stream >> opcion) {
                entradaValida = true;
            } else {
                std::cerr << "Error: debe ingresar un numero";
            }
        } while (!entradaValida);

        switch (opcion) {
            case 1:
                    std::system("cls");      // Limpiar la pantalla
                    std::cout << "Ingrese los datos del empleado:"<<std::endl;
                    std::cout << "Ingrese el nombre: "; std::cin >> nombre;
                    std::cout << "Ingrese el apellido: "; std::cin >> apellido;

                    entradaValida = false; input = "";

                    do {
                        std::cout << "Ingrese la edad: "; std::cin >> input;
                        std::istringstream stream(input);
                        if (stream >> edad) {
                            if (edad <= 0) {
                                std::cerr << "Error: La edad no puede ser negativa." << '\n';
                            } else if (edad < 18) {
                                std::cerr << "Error: La edad debe ser mayor o igual a 18." << '\n';
                            } else if (edad >= 65) {
                                std::cerr << "Error: La edad debe ser menor a 65." << '\n';
                            }
                            else {
                                entradaValida = true;
                            }
                        } else {
                            std::cerr << "Error: La entrada no es un numero valido." << '\n';
                        }

                    } while (!entradaValida);

                    entradaValida = false; input = "";

                    do {
                        std::cout << "\nIngrese el tipo de contrato: \n1. Horas \n2. Jornada completa\nOpcion: "; std::cin >> input;
                        std::istringstream stream(input);
                        if (stream >> contrato) {
                            if (contrato == 1) {
                                tipoContrato = "Horas";
                                entradaValida = true;
                            } else if (contrato == 2) {
                                tipoContrato = "Jornada Completa";
                                entradaValida = true;
                            } else {
                                std::cerr << "Error: Opcion invalida.\n";
                            }
                        } else {
                            std::cerr << "Error: La opcion debe ser un numero.\n";
                        }
                    } while (!entradaValida);

                    entradaValida = false; input = "";
                    do {
                        std::cout << "Ingrese el salario base: "; std::cin >> input;
                        std::istringstream stream(input);
                            if (stream >> salarioBase) {
                                if (salarioBase >= 0.0) {
                                    entradaValida = true;
                                } else {
                                    std::cerr << "Error: El salario base no puede ser negativo." << '\n';
                                }
                            } else {
                                std::cerr << "Error: Ingrese un valor numerico para el salario base." << '\n';
                            }
                    } while (!entradaValida);

                    entradaValida = false; input = "";

                    do {
                        std::cout << "Ingrese los complementos salariales: "; std::cin >> input;
                        std::istringstream stream(input);
                            if (stream >> complementosSalariales) {
                                if (complementosSalariales >= 0.0) {
                                    entradaValida = true;
                                } else {
                                    std::cerr << "Error: Los complementos salariales no pueden ser negativos." << '\n';
                                }
                            } else {
                                std::cerr << "Error: Ingrese un valor numerico para los complementos salariales." << '\n';
                            }
                    } while (!entradaValida);
                    std::cout << "Ingrese la categoria: "; std::cin >> categoria;
                    std::cout << "Ingrese el sector: "; std::cin >> sector;
                    listaEmpleados.agregarEmpleados(nombre, apellido, edad, tipoContrato, salarioBase, complementosSalariales, categoria, sector, nullptr);

                    entradaValida = false; input = "";
                    do {
                        std::cout << "Tiene jefe? \n1. Si\n2. No\nOpcion: "; std::cin >> input;
                        std::istringstream stream(input);
                        if (stream >> jefe) {
                            if (jefe == 1) {
                                tieneJefe = true;
                                entradaValida = true;
                            } else if (jefe == 2) {
                                tieneJefe = false;
                                entradaValida = true;
                            } else {
                                std::cerr << "Error: Opcion invalida.\n";
                            }
                        } else {
                            std::cerr << "Error: La opcion debe ser un numero.\n";
                        }
                    } while (!entradaValida);

                    if (tieneJefe){
                        std::cout << "ASIGNAR JEFE" << std::endl;
                        std::cout << "Ingrese el nombre del empleado: "; std::cin >> nombre;
                        std::cout << "Ingrese el apellido del empleado: "; std::cin >> apellido;
                        std::cout << "Ingrese el nombre del jefe: "; std::cin >> nombreJefe;
                        std::cout << "Ingrese el apellido del jefe: "; std::cin >> apellidoJefe;
                        listaEmpleados.asignarJefe(nombre, apellido, nombreJefe, apellidoJefe);
                    } else {
                        std::cout << "El empleado no tiene jefe." << std::endl;
                    }
                break;

            case 2:
                std::system("cls");      // Limpiar la pantalla
                std::cout << "Digite el nombre de quien desea modificar: " << std::endl;
                std::cin >> nombre;
                std::cout << "Digite el apellido de quien desea modificar: " << std::endl;
                std::cin >> apellido;
                encontrado = listaEmpleados.buscarEmpleadoPorNombreApellido(nombre, apellido);
                if (encontrado == nullptr) {
                    std::cout << "Empleado con nombre " << nombre << " y apellido " << apellido << " no encontrado." << std::endl;
                    break;
                } else {
                    std::cout << "Empleado con nombre " << nombre << " y apellido " << apellido << " encontrado." << std::endl;

                    std::string nuevoNombre, nuevoApellido, nuevoTipoContrato, nuevaCategoria, nuevoSector;
                    int nuevaEdad, nuevoContrato;
                    float nuevoSalarioBase, nuevoComplementosSalariales;

                    // Ingresar los datos del nuevo empleado
                    std::cout << "Ingrese los datos del nuevo empleado:" << std::endl;
                    std::cout << "Ingrese el nombre: "; std::cin >> nuevoNombre;
                    std::cout << "Ingrese el apellido: "; std::cin >> nuevoApellido;

                    entradaValida = false; input = "";
                    do {
                        std::cout << "Ingrese la edad: "; std::cin >> input;
                        std::istringstream stream(input);
                        if (stream >> nuevaEdad) {
                            if (nuevaEdad <= 0) {
                                std::cerr << "Error: La edad no puede ser negativa." << '\n';
                            } else if (nuevaEdad < 18) {
                                std::cerr << "Error: La edad debe ser mayor o igual a 18." << '\n';
                            } else {
                                entradaValida = true;
                            }
                        } else {
                            std::cerr << "Error: La opcion debe ser un numero.\n";
                        }

                    } while (!entradaValida);

                    entradaValida = false; input = "";
                    do {
                        std::cout << "Ingrese el tipo de contrato:\n1. Horas\n2. Jornada Completa\nOpcion: "; std::cin >> input;
                        std::istringstream stream(input);
                        if (stream >> nuevoContrato) {
                            if (nuevoContrato == 1) {
                                nuevoTipoContrato = "Horas";
                                entradaValida = true;
                            } else if (nuevoContrato == 2) {
                                nuevoTipoContrato = "Jornada Completa";
                                entradaValida = true;
                            } else {
                                std::cerr << "Error: Opcion invalida.\n";
                            }
                        } else {
                            std::cerr << "Error: La opcion debe ser un numero.\n";
                        }
                    } while (!entradaValida);

                    entradaValida = false; input = "";
                    do {
                        std::cout << "Ingrese el salario base: "; std::cin >> input;
                        std::istringstream stream(input);
                        if (stream >> nuevoSalarioBase) {
                            if (nuevoContrato < 0.0) {
                                std::cerr << "Error: El salario base no puede ser negativo." << '\n';
                            } else {
                                entradaValida = true;
                            }
                        } else {
                            std::cerr << "Error: La opcion debe ser un numero.\n";
                        }
                    } while (!entradaValida);

                    entradaValida = false; input = "";
                    do {
                        std::cout << "Ingrese los complementos salariales: "; std::cin >> input;
                        std::istringstream stream(input);
                        if (stream >> nuevoComplementosSalariales) {
                            if (nuevoComplementosSalariales < 0.0) {
                                std::cerr << "Error: Los complementos salariales no pueden ser negativos." << '\n';
                            } else {
                                entradaValida = true;
                            }
                        } else {
                            std::cerr << "Error: La opcion debe ser un numero.\n";
                        }
                    } while (!entradaValida);

                    std::cout << "Ingrese la categoria: "; std::cin >> nuevaCategoria;
                    std::cout << "Ingrese el sector: "; std::cin >> nuevoSector;
                    listaEmpleados.modificarEmpleado(nuevoNombre, nuevoApellido, nuevaEdad, nuevoTipoContrato, nuevoSalarioBase, nuevoComplementosSalariales, nuevaCategoria, nuevoSector, nullptr);

                    entradaValida = false; input = "";
                    do {
                        std::cout << "Tiene jefe? \n1. Si\n2. No\nOpcion: "; std::cin >> input;
                        std::istringstream stream(input);
                        if (stream >> jefe) {
                            if (jefe == 1) {
                                tieneJefe = true;
                                entradaValida = true;
                            } else if (jefe == 2) {
                                tieneJefe = false;
                                entradaValida = true;
                            } else {
                                std::cerr << "Error: Opcion invalida.\n";
                            }
                        } else {
                            std::cerr << "Error: La opcion debe ser un numero.\n";
                        }
                    } while (!entradaValida);

                    if (tieneJefe){
                        std::cout << "ASIGNAR JEFE" << std::endl;
                        std::cout << "Ingrese el nombre del empleado: "; std::cin >> nombre;
                        std::cout << "Ingrese el apellido del empleado: "; std::cin >> apellido;
                        std::cout << "Ingrese el nombre del jefe: "; std::cin >> nombreJefe;
                        std::cout << "Ingrese el apellido del jefe: "; std::cin >> apellidoJefe;
                        listaEmpleados.asignarJefe(nombre, apellido, nombreJefe, apellidoJefe);
                    } else {
                        std::cout << "El empleado no tiene jefe." << std::endl;
                    }
                    break;
                }

            case 3:
                std::system("cls");      // Limpiar la pantalla
                std::cout << "Digite el nombre del empleado que desea eliminar: ";
                std::cin >> nombre;
                std::cout << "Digite el apellido del empleado que desea eliminar: ";
                std::cin >> apellido;
                listaEmpleados.eliminarEmpleado(nombre, apellido);
                break;

            case 4:
                std::system("cls");      // Limpiar la pantalla
                listaEmpleados.ordenarPorEdad();
                std::cout << "Empleados ordenados por edad." << std::endl;
                break;

            case 5:
                std::system("cls");      // Limpiar la pantalla
                listaEmpleados.ordenarPorApellidos();
                std::cout << "Empleados ordenados por apellidos." << std::endl;
                break;

            case 6:
                std::system("cls");      // Limpiar la pantalla
                std::cout << "CONSULTAR SALARIO" << std::endl;
                std::cout << "Ingrese la categoria: "; std::cin >> categoria;

                entradaValida = false; input = "";
                do {
                    std::cout << "Ingrese el tipo de contrato: \n1. Horas \n2. Jornada completa\nOpcion: "; std::cin >> input;
                    std::istringstream stream(input);
                    if (stream >> tipoContrato) {
                        if (contrato == 1) {
                            tipoContrato = "Horas";
                            entradaValida = true;
                        } else if (contrato == 2) {
                            tipoContrato = "Jornada Completa";
                            entradaValida = true;
                        } else {
                            std::cerr << "Error: Opcion invalida." << '\n';
                        }
                    } else {
                        std::cerr << "Error: La opcion debe ser un numero." << '\n';
                        std::cin.clear();
                        std::cin.ignore();
                    }
                } while (!entradaValida);

                entradaValida = false; input = "";
                do {
                    std::cout << "Ingrese las horas laboradas: "; std::cin >> input;
                    std::istringstream stream(input);
                    if (stream >> horas) {
                        if (horas < 0) {
                            std::cerr << "Error: Las horas laboradas no pueden ser negativas." << '\n';
                        } else {
                            entradaValida = true;
                        }
                    } else {
                        std::cerr << "Error: Ingrese un valor numerico para las horas laboradas." << '\n';
                        std::cin.clear();
                        std::cin.ignore();
                    }

                } while (!entradaValida);

                entradaValida = false; input = "";
                do {
                    std::cout << "Ingrese los dias trabajados: "; std::cin >> input;
                    std::istringstream stream(input);
                    if (stream >> diasTrabajados) {
                        if (diasTrabajados < 0) {
                            std::cerr << "Error: Los dias trabajados no pueden ser negativos." << '\n';
                        } else {
                            entradaValida = true;
                        }
                    } else {
                        std::cerr << "Error: Ingrese un valor numerico para las horas laboradas." << '\n';
                        std::cin.clear();
                        std::cin.ignore();
                    }

                } while (!entradaValida);

                entradaValida = false; input = "";
                do {
                    std::cout << "Ingrese si es feriado (1 = si, 0 = no): "; std::cin >> input;
                    std::istringstream stream(input);
                    if (stream >> feriado) {
                        if (feriado == 1) {
                            esFeriado = true;
                            entradaValida = true;
                        } else if (feriado == 2) {
                            esFeriado = false;
                            entradaValida = true;
                        } else {
                            std::cerr << "Error: Opcion invalida." << '\n';
                        }
                    } else {
                        std::cerr << "Error: La opcion debe ser un numero." << '\n';
                        std::cin.clear();
                        std::cin.ignore();
                    }

                } while (!entradaValida);

                entradaValida = false; input = "";
                do {
                    std::cout << "Ingrese si es turno especial (1 = si, 0 = no): "; std::cin >> input;
                    std::istringstream stream(input);
                    if (stream >> especial) {
                        if (especial == 1) {
                            diaEspecial = true;
                            entradaValida = true;
                        } else if (especial == 2) {
                            diaEspecial = false;
                            entradaValida = true;
                        } else {
                            std::cerr << "Error: Opcion invalida." << '\n';
                        }
                    } else {
                        std::cerr << "Error: La opcion debe ser un numero." << '\n';
                        std::cin.clear();
                        std::cin.ignore();
                    }

                } while (!entradaValida);

                entradaValida = false; input = "";
                do {
                    std::cout << "Ingrese si es horario regular (1 = si, 0 = no): "; std::cin >> input;
                    std::istringstream stream(input);
                    if (stream >> regular) {
                        if (regular == 1) {
                            diaRegular = true;
                            entradaValida = true;
                        } else if (regular == 2) {
                            diaRegular = false;
                            entradaValida = true;
                        } else {
                            std::cerr << "Error: Opcion invalida." << '\n';
                        }
                    } else {
                        std::cerr << "Error: La opcion debe ser un numero." << '\n';
                        std::cin.clear();
                        std::cin.ignore();
                    }
                } while (!entradaValida);

                listaEmpleados.consultarSalario(ConsultarSalario(horas, diasTrabajados, esFeriado, diaEspecial, diaRegular, categoria, tipoContrato));
                break;

            case 7:
                std::system("cls");      // Limpiar la pantalla
                listaEmpleados.imprimirInformacion();
                break;

            case 8:
                std::system("cls");      // Limpiar la pantalla
                salir = true;
                std::cout << "Saliendo del programa." << std::endl;
                break;

            default:
                std::system("cls");      // Limpiar la pantalla
                std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
                break;
        }
    } while (!salir);
}