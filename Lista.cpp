#include "Lista.h"

Lista::Lista(){
    cargarArchivo();
}

void Lista::Insert(Contacto* persona) {
    Nodo* temp_p;
    Nodo* curr_p = *head;
    if (*head == NULL)
    {
        temp_p = new Nodo(persona);
        *head = temp_p;
        cout << "Contacto ingresado. Ahora es el primer contacto\n\n";
        size++;
    }
    else {
    switch (flag) {

    case 1:


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
            size++;
        }
        else if (curr_p->getPred() == NULL && curr_p->getContacto()->getTelefono() > persona->getTelefono()) {
            temp_p = new Nodo(persona);
            temp_p->setNext(curr_p);
            curr_p->setPred(temp_p);
            temp_p->getNext()->setPred(temp_p);
            curr_p->getPred()->setNext(curr_p);
            cout << "El valor fue ingresado. Ahora es el primer valor" << endl;
            *head = temp_p;
            size++;
        }
        else if (curr_p->getPred() == NULL && curr_p->getContacto()->getTelefono() < persona->getTelefono()) {
            temp_p = new Nodo(persona);
            curr_p->setNext(temp_p);
            temp_p->setPred(curr_p);
            curr_p->getNext()->setPred(curr_p);
            temp_p->getPred()->setNext(temp_p);
            cout << "El valor fue ingresado." << endl;
            size++;
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
            size++;

        }

        break;//FIN CASO

    case 2:
        while (curr_p->getContacto()->getDNI() < persona->getDNI() && curr_p->getNext() != NULL) {
            curr_p = curr_p->getNext();
        }

        if (curr_p->getNext() == NULL && curr_p->getContacto()->getDNI() < persona->getDNI()) {
            temp_p = new Nodo(persona);
            curr_p->setNext(temp_p);
            temp_p->setPred(curr_p);
            curr_p->getNext()->setPred(curr_p);
            temp_p->getPred()->setNext(temp_p);
            cout << "El contacto fue ingresado." << endl;
            size++;
        }
        else if (curr_p->getPred() == NULL && curr_p->getContacto()->getDNI() > persona->getDNI()) {
            temp_p = new Nodo(persona);
            temp_p->setNext(curr_p);
            curr_p->setPred(temp_p);
            temp_p->getNext()->setPred(temp_p);
            curr_p->getPred()->setNext(curr_p);
            cout << "El valor fue ingresado. Ahora es el primer valor" << endl;
            *head = temp_p;
            size++;
        }
        else if (curr_p->getPred() == NULL && curr_p->getContacto()->getDNI() < persona->getDNI()) {
            temp_p = new Nodo(persona);
            curr_p->setNext(temp_p);
            temp_p->setPred(curr_p);
            curr_p->getNext()->setPred(curr_p);
            temp_p->getPred()->setNext(temp_p);
            cout << "El valor fue ingresado." << endl;
            size++;
        }
        else if (curr_p->getContacto()->getDNI() == persona->getDNI()) {
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
            size++;

        }
        break;

    case 3:

        while (curr_p->getContacto()->getApellidos() < persona->getApellidos() && curr_p->getNext() != NULL) {
            curr_p = curr_p->getNext();
        }

        if (curr_p->getNext() == NULL && curr_p->getContacto()->getApellidos() < persona->getApellidos()) {
            temp_p = new Nodo(persona);
            curr_p->setNext(temp_p);
            temp_p->setPred(curr_p);
            curr_p->getNext()->setPred(curr_p);
            temp_p->getPred()->setNext(temp_p);
            cout << "El contacto fue ingresado." << endl;
            size++;
        }
        else if (curr_p->getPred() == NULL && curr_p->getContacto()->getApellidos() > persona->getApellidos()) {
            temp_p = new Nodo(persona);
            temp_p->setNext(curr_p);
            curr_p->setPred(temp_p);
            temp_p->getNext()->setPred(temp_p);
            curr_p->getPred()->setNext(curr_p);
            cout << "El valor fue ingresado. Ahora es el primer valor" << endl;
            *head = temp_p;
            size++;
        }
        else if (curr_p->getPred() == NULL && curr_p->getContacto()->getApellidos() < persona->getApellidos()) {
            temp_p = new Nodo(persona);
            curr_p->setNext(temp_p);
            temp_p->setPred(curr_p);
            curr_p->getNext()->setPred(curr_p);
            temp_p->getPred()->setNext(temp_p);
            cout << "El valor fue ingresado." << endl;
            size++;
        }
        else if (curr_p->getContacto()->getApellidos() == persona->getApellidos()) {
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
            size++;

        }
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

void Lista::Eliminar(string campo){
    Nodo* elim = Busqueda(campo);
    if (elim!=nullptr){
        if (elim->getPred() == NULL)
        {
            elim->getNext()->setPred(NULL);
            *head = elim->getNext();
            delete elim;
        }
        else if (elim->getNext() == NULL)
        {
            elim->getPred()->setNext(NULL);
            delete elim;
        }
        else {
            elim->getNext()->setPred(elim->getPred());
            elim->getPred()->setNext(elim->getNext());
            delete elim;
        }
        cout << "Nodo Eliminado con Éxito\n\n";
    }
    else {
        cout << "Nodo no encontrado\n\n";
    }
    size--;
}

void Lista::Editar(string campo, int x) {
    /*Nodo* edit;
    edit = Busqueda(campo);
    if (edit!=nullptr){
        switch (x)
        {
        case 1:
            cout << "Ingrese nuevo nombre: ";

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 7:

            break;
        default:
            break;
        }
    }*/
}

Nodo* Lista::Busqueda(string campo) {
    if (*head != NULL) {
        Nodo* contador = *head;
        Nodo** arreglo = new Nodo * [size];
        int izquierda = 0;
        int derecha = size - 1;
    switch (flag)
    {
    case 1: 
        for (int i = 0; i < size; i++)
        {
            arreglo[i] = contador;
            contador = contador->getNext();
        }
        while (izquierda <= derecha) {
            int medio = izquierda + (derecha - izquierda) / 2;

            if (to_string(arreglo[medio]->getContacto()->getTelefono()) == campo) {
                return arreglo[medio]; 
            }

            if (to_string(arreglo[medio]->getContacto()->getTelefono()) < campo) {
                izquierda = medio + 1;
            }
            else {
                derecha = medio - 1;
            }
        }

        return nullptr;

        break;

    case 2:
        for (int i = 0; i < size; i++)
        {
            arreglo[i] = contador;
            contador = contador->getNext();
        }
        while (izquierda <= derecha) {
            int medio = izquierda + (derecha - izquierda) / 2;

            if (arreglo[medio]->getContacto()->getDNI() == campo) {
                return arreglo[medio]; 
            }

            if (arreglo[medio]->getContacto()->getDNI() < campo) {
                izquierda = medio + 1;
            }
            else {
                derecha = medio - 1;
            }
        }

        return nullptr;

        break;

    case 3:
        for (int i = 0; i < size; i++)
        {
            arreglo[i] = contador;
            contador = contador->getNext();
        }
        while (izquierda <= derecha) {
            int medio = izquierda + (derecha - izquierda) / 2;

            if (arreglo[medio]->getContacto()->getApellidos() == campo) {
                return arreglo[medio]; 
            }

            if (arreglo[medio]->getContacto()->getApellidos() < campo) {
                izquierda = medio + 1;
            }
            else {
                derecha = medio - 1;
            }
        }

        return nullptr;

        break;

        delete[] arreglo;
    }
    }
    else {
        cout << "Lista vacía\n\n";
    }
    return nullptr;
}

int Lista::isEmpty(){
    if (*head == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void Lista::guardarArchivo(){
    string nombreArchivo = "Agenda.txt";
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        Nodo* contador = *head;
        while (contador!=NULL){
            archivo << contador->getContacto()->getNombres()<<',';
            archivo << contador->getContacto()->getApellidos() << ',';
            archivo << contador->getContacto()->getDNI() << ',';
            archivo << contador->getContacto()->getDireccion() << ',';
            archivo << contador->getContacto()->getTelefono() << ',';
            archivo << contador->getContacto()->getResidencia() << ',';
            contador=contador->getNext();
        }
        archivo.close();
    }
    else {
        cerr << "Error al abrir el archivo." << endl;
    }
}

void Lista::cargarArchivo(){
    string nombreArchivo = "Agenda.txt";
    ifstream archivo(nombreArchivo);
    string linea;
    int campo = 1;
    string dni = "";
    string nombres = "";
    string apellidos = "";
    string direccion = "";
    int residencia = 0;
    int telefono = 0;
    if (archivo.is_open()) {
        while (getline(archivo, linea, ',')) {
            if (campo==1) {
                nombres = linea;
                campo++;
            }
            else if (campo == 2) {
                apellidos = linea;
                campo++;
            }
            else if (campo == 3) {
                dni=linea;
                campo++;
            }
            else if (campo == 4) {
                direccion = linea;
                campo++;
            }
            else if (campo == 5) {
                telefono = stoi(linea);
                campo++;
            }
            else if (campo == 6) {
                residencia = stoi(linea);
                Contacto* p = new Contacto(dni, nombres, apellidos, direccion, residencia, telefono);
                this->Insert(p);
                campo = 1;
            }
           
        }
        archivo.close();
    }
    else {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }

}

int Lista::getSize(){
    return size;
}

void Lista::Bubble(){
    if (*head != NULL) {
        Nodo* contador = *head;
        Nodo** arreglo = new Nodo*[size];
        for (int i = 0; i < size; i++)
        {
            arreglo[i] = contador;
            contador = contador->getNext();
        }
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1 - i; j++) {
                if (arreglo[j]->getContacto()->getDNI() > arreglo[j + 1]->getContacto()->getDNI())
                {
                    Nodo* temp = arreglo[j];
                    arreglo[j] = arreglo[j + 1];
                    arreglo[j + 1] = temp;
                }
            }
        }
        Nodo* curr = *head;
        Nodo* siguiente;
        int mid = (size-1) / 2;
        for (int i = 0; i < size+1; i++){
            if (i==0)
            {
                curr= arreglo[i];
                *head = curr;
                curr->setPred(nullptr);
            }
            else if (i==size)
            {
                    siguiente = nullptr;
                    curr->setNext(siguiente);
            }
            else {
                siguiente = arreglo[i];
                curr->setNext(siguiente);
                curr->getNext()->setPred(curr);
                curr = curr->getNext();
            }
            
        }
        delete[] arreglo;
        }
        else {
            cout << "Lista vacía\n\n";
        }
    flag = 2;
    
}


void Lista::merge(Nodo* arr[], int left,int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Nodo** L = new Nodo * [n1];
    Nodo** R = new Nodo * [n1];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    switch (flag){

    case 1: //SI LA BANDERA ES 1 EL ORDENAMIENTO ES POR TELÉFONO
  
    while (i < n1 && j < n2) {
        if (L[i]->getContacto()->getTelefono() <= R[j]->getContacto()->getTelefono()) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    break;//FIN ORDENAMIENTO TELÉFONO



    case 3: //SI LA BANDERA ES 3 EL ORDENAMIENTO ES POR APELLIDO

        while (i < n1 && j < n2) {
            if (L[i]->getContacto()->getApellidos() <= R[j]->getContacto()->getApellidos()) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
        break; //FIN ORDENAMIENTO APELLIDO 

    }
}

void Lista::mergeSort(Nodo* arr[], int left, int right){
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void Lista::MergeSort(){
    if (*head!=NULL){
        Nodo* contador = *head;
        Nodo** arreglo = new Nodo * [size];
        for (int i = 0; i < size; i++){
            arreglo[i] = contador;
            contador = contador->getNext();
        }
        mergeSort(arreglo, 0, size - 1);
        Nodo* curr = *head;
        Nodo* siguiente;
        for (int i = 0; i < size + 1; i++) {
            if (i == 0)
            {
                curr = arreglo[i];
                *head = curr;
                curr->setPred(nullptr);
            }
            else if (i == size)
            {
                siguiente = nullptr;
                curr->setNext(siguiente);
            }
            else {
                siguiente = arreglo[i];
                curr->setNext(siguiente);
                curr->getNext()->setPred(curr);
                curr = curr->getNext();
            }
        }
        delete[] arreglo;
    }
}

void Lista::setFlag(int f){
    flag = f;
}

int Lista::getFlag()
{
    return flag;
}
