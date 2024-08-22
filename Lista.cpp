#include "Lista.h"

void Lista::Insert(Contacto* persona) {
    Nodo* temp_p;
    Nodo* curr_p = *head;
    if (*head == NULL)
    {
        temp_p = new Nodo(persona);
        *head = temp_p;
        cout << "Contacto ingresado. Ahora es el primer contacto\n\n";
    }
    else {
    switch (flag) {

    case 1:
        //Nodo* temp_p;
        //Nodo* curr_p = *head;

        while (curr_p->getContacto()->getTelefono() < persona->getTelefono() && curr_p->getNext() != NULL) {
            curr_p = curr_p->getNext();
        }

        if (curr_p->getNext() == NULL && curr_p->getContacto()->getTelefono() < persona->getTelefono()) {
            temp_p = new Nodo(persona);
            curr_p->setNext(temp_p);
            temp_p->setPred(curr_p);
            curr_p->getNext()->setPred(curr_p);
            temp_p->getPred()->setNext(temp_p);
            cout << "El contacto fue ingresado." << endl;
        }
        else if (curr_p->getPred() == NULL && curr_p->getContacto()->getTelefono() > persona->getTelefono()) {
            temp_p = new Nodo(persona);
            temp_p->setNext(curr_p);
            curr_p->setPred(temp_p);
            temp_p->getNext()->setPred(temp_p);
            curr_p->getPred()->setNext(curr_p);
            cout << "El valor fue ingresado. Ahora es el primer valor" << endl;
            *head = temp_p;
        }
        else if (curr_p->getPred() == NULL && curr_p->getContacto()->getTelefono() < persona->getTelefono()) {
            temp_p = new Nodo(persona);
            curr_p->setNext(temp_p);
            temp_p->setPred(curr_p);
            curr_p->getNext()->setPred(curr_p);
            temp_p->getPred()->setNext(temp_p);
            cout << "El valor fue ingresado." << endl;
        }
        else if (curr_p->getContacto()->getTelefono() == persona->getTelefono()) {
            cout << "Valor a ingresar ya se encuentra. No se pudo ingresar\n";
            return;
        }
        else {
            temp_p = new Nodo(persona);
            temp_p->setNext(curr_p);
            temp_p->setPred(curr_p->getPred());
            curr_p->getPred()->setNext(temp_p);
            curr_p->setPred(temp_p);
            cout << "El valor fue ingresado." << endl;

        }

        break;//FIN CASO BUBBLE SORT

    case 2:

        break;

    case 3:

        break;

    }
    }
}

void Lista::Impresion(){
    Nodo* contador = *head;
    int i = 1;
    cout << "Lista de Contactos actuales:\n\n";
    while (contador != NULL) {
        cout << "Nodo " << i<<"\n\n";
        cout << "Nombre: " << contador->getContacto()->getNombres() << "\n";
        cout << "Apellidos: " << contador->getContacto()->getApellidos() << "\n";
        cout << "DNI: " << contador->getContacto()->getDNI() << "\n";
        cout << "Dirección: " << contador->getContacto()->getDireccion() << "\n";
        cout << "Teléfono Móvil: " << contador->getContacto()->getTelefono() << "\n";
        cout << "Teléfono Residencial: " << contador->getContacto()->getResidencia() << "\n\n";
        contador = contador->getNext();
        i++;
    }
}

int Lista::isEmpty(){
    if (*head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void Lista::guardarArchivo()
{
}
