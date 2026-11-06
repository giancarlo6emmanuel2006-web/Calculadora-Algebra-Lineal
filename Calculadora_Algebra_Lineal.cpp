#include <iostream>
#include <iomanip>

using namespace std;

const int A = 3;

void menu();
void ingresarDatos(double matriz[A][A]);
void mostrarMatriz(double matriz[A][A]);
double calcularDeterminante(double matriz[A][A]);
void calcularInversa(double matriz[A][A], double inversa[A][A]);

int main() {
    menu();
    cout << "\nPresione Enter para salir...";
    cin.ignore();
    cin.get();
    return 0;
}

void menu() {
    double matriz[A][A], inversa[A][A];
    int opcion;
    do {
        cout << "\n\t\t MATRIZ\n\n";
        cout << "1) Ingresa numeros a la matriz\n";
        cout << "2) Salir\n";
        cout << "\nElija una opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1:
                ingresarDatos(matriz);
        		cout<<endl;
                cout << "\nLa matriz ingresada es:\n";
                mostrarMatriz(matriz);
                double determinante;
                determinante = calcularDeterminante(matriz);
                if (determinante == 0) {
                    cout << "El determinante de la matriz es 0 asi que no tiene inversa.\n";
                } else {
                    calcularInversa(matriz, inversa);
                    cout << "\nLa matriz inversa es:\n";
                    for (int i=0; i<A; i++) {
                        for (int j=0; j<A; j++) {
                            cout << setw(10) << inversa[i][j] << " ";
                        }
                        cout << endl;
                    }
                    cout << "\nEl determinante de la matriz es: " << determinante << endl;
                }
                break;
            case 2:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    } while(opcion != 2);
}

void ingresarDatos(double matriz[A][A]) {
    for (int i=0; i<A; i++) {
        for (int j=0; j<A; j++) {
            cout << "Ingrese los elementos de la matriz 3x3: ";
            cin >> matriz[i][j];
        }
    }
}

void mostrarMatriz(double matriz[A][A]) {
    for (int i=0; i<A; i++) {
        for (int j=0; j<A; j++) {
            cout << setw(10) << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

double calcularDeterminante(double matriz[A][A]) {
    double det;
    det = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) -
          matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0]) +
          matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
    return det;
}

void calcularInversa(double matriz[A][A], double inversa[A][A]) {
    double det = calcularDeterminante(matriz);
    for (int i=0; i<A; i++) {
        for (int j=0; j<A; j++) {
            inversa[j][i] = (
                matriz[(i+1)%3][(j+1)%3] * matriz[(i+2)%3][(j+2)%3] -
                matriz[(i+1)%3][(j+2)%3] * matriz[(i+2)%3][(j+1)%3]
            ) / det;
        }
    }
}
