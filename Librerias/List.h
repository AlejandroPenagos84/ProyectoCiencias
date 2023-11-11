//
// Created by Alejandro Penagos on 13/10/2023.
//

#ifndef LIST_H
#define LIST_H
#include <iostream>
/**
 * Estructura de Nodo
 *
 * Esta estructura se utiliza para crear los nodos de la lista enlazada.
 * Cada nodo contiene un dato de tipo 'T' y un puntero al siguiente nodo.
 *
 * @tparam T Tipo de dato que se almacena en el nodo.
 */
template <class T>
struct Node
{
    T data;         // Almacena el dato de tipo 'T' en el nodo.
    Node<T> *next;  // Puntero al siguiente nodo en la lista.
};

/**
 * Declaraci�n de la clase 'List'.
 * En esta secci�n se describen los m�todos de la clase y las estructuras de control utilizadas:
 *
 * M�todos: <br><br>
 * - List() : Constructor <br><br>
 * - int getSize() : Devuelve el tama�o de la lista <br><br>
 * - void addDirectly(T) : Agrega un elemento directamente (ubicaci�n autom�tica) <br><br>
 * - void addFirst(T) : Agrega un elemento al principio de la lista <br><br>
 * - void addLast(T) : Agrega un elemento al final de la lista <br><br>
 * - void addPos(T, int) : Agrega un elemento en una posici�n espec�fica <br><br>
 * - void removePos(int) : Elimina un elemento en una posici�n espec�fica <br><br>
 * - void removeData(T) : Elimina un elemento por su valor <br><br>
 * - void setPos(int, T) : Establece el valor de un elemento en una posici�n espec�fica <br><br>
 * - void setData(T, T) : Reemplaza un elemento con un valor por otro <br><br>
 * - T getData(int) : Obtiene el valor de un elemento en una posici�n espec�fica<br><br>
 * <br><br>
 *
 * Estructuras de Control: <br><br>
 * - header: Nodo que marca el inicio de la lista <br><br>
 * - z: Nodo que marca el final de la lista <br><br>
 * - sentinel: Nodo que guarda la direcci�n del �ltimo elemento <br><br>
 *
 * <br><br>
 *
 * Size: Guarda el tama�o de la lista
 *
 * @tparam T Tipo de dato que se utilizar� en la lista.
 */
template <class T>
class List
{
private:
    Node<T> *header, *z, *sentinel;
    int size;

public:
    /*
    Este es el destructor, pero est� comentado, pq o si no la multilista
    no sirve xd
    virtual ~List()
    {
        Node<T> *temp = header;

        while (temp != z)
        {
            header = temp;
            temp = temp->next;
            delete header;
        }
        delete z;
    }
     */
    List();
    int getSize();
    void addDirectly(T newData);
    void addFirst(T newData);
    void addLast(T newData);
    void addPos(T newData, int pos);
    void removePos(int pos);
    void removeData(T data);
    void setPos(int pos, T newData);
    void setData(T data, T newData);
    T getData(int pos);
};

/**
 * Constructor
 *
 * Se inicializan las estructuras de control.
 *
 * Header apunta a z y z a s� mismo.
 * Sentinel se inicializa con un valor null.
 * Size se inicializa con valor 0.
 *
 * @tparam T Tipo de dato que se utilizar� en la lista.
 */
template<class T>
List<T>::List() {
    // Instancia de ambas estructuras de control
    header = new Node<T>;
    z = new Node<T>;
    // Inicializaci�n de sentinel como NULL
    sentinel = NULL;
    size = 0;

    // Header apunta a z
    header->next = z;

    // z apunta a s� mismo
    z->next = z;

    // Se declaran los datos de header y z como nulos
    header->data = T();
    z->data = T();
}

/**
 * Devuelve el tama�o de la lista
 * @tparam T Tipo de dato que se utilizar� en la lista.
 * @return Tama�o de la lista
 */
template <class T>
int List<T>::getSize() { return size; }

/**
 * A�ade un elemento al principio de la lista.
 *
 * @tparam T Tipo de dato que se utilizar� en la lista.
 * @param newData El nuevo elemento que se agregar� al principio de la lista.
 */
template <class T>
void List<T>::addFirst(T newData) {
    Node<T> *newNode, *aux; // Declaraci�n de dos estructuras, newNode y aux.

    // Instancia del nuevo nodo y asignaci�n de su valor.
    newNode = new Node<T>;
    newNode->data = newData;

    // Guarda la direcci�n del nodo al que apunta 'header' en la estructura aux.
    aux = header->next;

    // Hace que 'header' apunte al nuevo nodo.
    header->next = newNode;

    // El nuevo nodo apunta al nodo que anteriormente estaba despu�s de 'header'.
    newNode->next = aux;

    // Si es el primer elemento agregado, el puntero 'sentinel' guarda la direcci�n de este nuevo nodo.
    sentinel = (newNode->next == z) ? newNode : sentinel; // Operador ternario que verifica si es el primer elemento.

    // Aumenta el tama�o de la lista.
    size++;
}


/**
 * Agrega un elemento al final de la lista.
 *
 * @tparam T Tipo de dato que se utilizar� en la lista.
 * @param newData El nuevo elemento que se agregar� al final de la lista.
 */
template <class T>
void List<T>::addLast(T newData) {
    Node<T> *newNode, *aux;  // Declaraci�n de dos estructuras, newNode y aux.

    // Instancia del nuevo nodo y asignaci�n de su valor.
    newNode = new Node<T>;
    newNode->data = newData;

    // Si el sentinela es nulo, eso significa que no se ha agregado ning�n elemento,
    // por lo tanto, se llama al m�todo 'addFirst'.
    if (sentinel == NULL) {
        addFirst(newData);
        size--;
    } else {
        // De lo contrario,

        // Aux tendr� la direcci�n del nodo al que apunta sentinel.
        aux = sentinel->next;

        // Sentinel ahora apunta al nuevo nodo.
        sentinel->next = newNode;

        // El nuevo nodo apunta al nodo al que apuntaba 'sentinel'.
        newNode->next = aux;

        // Sentinel pasa a ser igual al nuevo nodo.
        sentinel = newNode;
    }
    size++;
}


/**
 * Agrega un elemento directamente en la lista, es decir en la posici�n que le corresponde.
 *
 * @tparam T Tipo de dato que se utilizar� en la lista.
 * @param newData El nuevo elemento que se agregar�.
 */
template <class T>
void List<T>::addDirectly(T newData)
{
    // Declaraci�n de un nuevo nodo, as� como nodos temporales auxiliares.
    Node<T> *newNode, *temp, *aux;

    // Creaci�n de un nuevo nodo y asignaci�n del nuevo dato.
    newNode = new Node<T>;
    newNode->data = newData;

    // Inicializaci�n de un nodo temporal con la cabecera (header).
    temp = header;

    // Recorrer la lista mientras el nodo siguiente no sea el nodo final (z)
    // y el dato en el nodo siguiente sea menor o igual al nuevo dato.
    while (temp->next != z && temp->next->data <= newData)
        temp = temp->next;

    // Conectar el nuevo nodo en la lista:
    // 1. El nodo temporal apunta al nuevo nodo.
    // 2. El nuevo nodo apunta al nodo que originalmente estaba despu�s del nodo temporal.
    aux = temp->next;
    temp->next = newNode;
    newNode->next = aux;

    // Si el nuevo nodo es el �ltimo de la lista, actualiza el sentinela.
    sentinel = (newNode->next == z) ? newNode : sentinel;

    // Incrementa el tama�o de la lista.
    size++;
}


/**
 * Obtiene el dato de una posici�n espec�fica.
 *
 * La primera posici�n es 1.
 *
 * @tparam T Tipo de dato que se utilizar� en la lista.
 * @param pos La posici�n en la lista.
 * @return El dato de la posici�n dada.
 */
template <class T>
T List<T>::getData(int pos)
{
    // Se declara un nodo temporal que recorrer� la lista hasta la posici�n dada.
    Node<T> *temp = header->next;
    for (int i = 1; i < pos; i++)
        temp = temp->next;

    // Devuelve el dato.
    return temp->data;
}

/**
 * Cambia el dato en una posici�n dada.
 *
 * @tparam T Tipo de dato que se utilizar� en la lista.
 * @param pos La posici�n de la lista en la que se cambiar� el dato.
 * @param newData El nuevo dato.
 */
template <class T>
void List<T>::setPos(int pos, T newData)
{
    // Se declara un nodo temporal que recorrer� la lista hasta la posici�n dada.
    Node<T> *temp = header->next;

    for (int i = 1; i < pos; i++)
        temp = temp->next;

    // Se cambia el dato.
    temp->data = newData;
}

/**
 * Agrega un nuevo elemento en la posici�n dada.
 *
 * @tparam T Tipo de dato que se utilizar� en la lista.
 * @param newData El nuevo dato que se agregar�.
 * @param pos La posici�n donde se agregar�.
 */
template <class T>
void List<T>::addPos(T newData, int pos)
{
    // Se declaran un nodo temporal y uno auxiliar.
    Node<T> *newNode, *temp, *aux;

    // Inicializaci�n de un nuevo nodo y asignaci�n del nuevo dato.
    newNode = new Node<T>;
    newNode->data = newData;

    // Asignaci�n del nodo al que apunta la cabecera.
    temp = header->next;

    // Recorrido de toda la lista hasta una posici�n antes de la posici�n dada.
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    // El nodo auxiliar guarda la direcci�n del nodo al que apunta el nodo temporal.
    aux = temp->next;

    // El nodo temporal, que est� una posici�n antes de la dada, apunta al nuevo nodo.
    temp->next = newNode;

    // El nuevo nodo apunta a aux.
    newNode->next = aux;

    // Si el nuevo nodo se agrega en la �ltima posici�n, se actualiza el sentinela.
    sentinel = (newNode->next == z) ? newNode : sentinel;
    size++;
}

/**
 * Elimina un nodo en la posici�n dada.
 * @tparam T Tipo de dato que se utilizar� en la lista.
 * @param pos La posici�n del nodo que se eliminar�.
 */
template <class T>
void List<T>::removePos(int pos)
{
    // Declaraci�n de nodos temporales y auxiliares.
    Node<T> *temp, *aux, *deleted;

    // Inicializar temp con la direcci�n de la cabecera.
    temp = header;

    // Recorrer la lista hasta llegar a la posici�n anterior a la posici�n dada.
    for (int i = 1; i < pos; i++)
        temp = temp->next;

    // Guardar la direcci�n del nodo siguiente al que se eliminar�.
    aux = temp->next->next;

    // Guardar la direcci�n del nodo que se eliminar�.
    deleted = temp->next;

    // Conectar el nodo anterior directamente con el nodo siguiente, eliminando el nodo actual.
    temp->next = aux;

    // Liberar la memoria del nodo eliminado.
    delete deleted;

    // Decrementar el tama�o de la lista.
    size--;
}

/**
 * Cambia el dato de un nodo que coincide con el dato especificado.
 * @tparam T Tipo de dato que se utilizar� en la lista.
 * @param data El dato que se desea cambiar.
 * @param newData El nuevo dato que reemplazar� al dato especificado.
 */
template <class T>
void List<T>::setData(T data, T newData)
{
    Node<T> *temp = header->next;

    // Recorrer la lista mientras no se llegue al nodo final (z) y el dato no coincida.
    while (temp->next != z && temp->data != data)
        temp = temp->next;

    // Verificar si se encontr� un nodo con el dato especificado.
    if (temp->data == data)
    {
        // Cambiar el dato del nodo encontrado por el nuevo dato.
        temp->data = newData;
    }
}

/**
 * Elimina un nodo que contiene el dato especificado.
 * @tparam T Tipo de dato que se utilizar� en la lista.
 * @param data El dato que se desea eliminar.
 */
template <class T>
void List<T>::removeData(T data)
{
    Node<T> *temp, *aux, *deleted;

    temp = header->next;

    // Recorrer la lista mientras no se llegue al nodo final (z) y el dato en el siguiente nodo no coincida.
    while (temp->next != z && temp->next->data != data)
        temp = temp->next;

    // Verificar si se encontr� un nodo cuyo dato coincida con el dato a eliminar.
    if (temp->next->data == data)
    {
        // Guardar la direcci�n del nodo siguiente al que se eliminar�.
        aux = temp->next->next;

        // Guardar la direcci�n del nodo que se eliminar�.
        deleted = temp->next;

        // Conectar el nodo anterior directamente con el nodo siguiente, eliminando el nodo actual.
        temp->next = aux;

        // Liberar la memoria del nodo eliminado.
        delete deleted;

        // Decrementar el tama�o de la lista.
        size--;
    }
}

#endif
