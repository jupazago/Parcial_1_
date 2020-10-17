#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


void llenar_datos(int *datos, int);


int main()
{
    //altura, eje x. angulo, vel inicial
    int datosC1[4];
    int datosC2[4];

    llenar_datos(&datosC1[0], 1);
    cout <<endl<< "agregado ofensivo con exito"<<endl;
    llenar_datos(&datosC2[0], 2);
    cout <<endl<< "Agregado defensivo con exito"<<endl;


    return 0;
}

void llenar_datos(int *datos, int numero){
    int altura, ejex;
    cout << "Agregar los datos del canion"<<endl<<endl;
    cout << "altura: ";
    cin >> altura;
    if(altura>0 && altura<99){
        datos[0]=altura;
        if(numero==1){
            datos[1] = 0;
            datos[2] = 0;
            datos[3] = 0;
        }else{
            cout << "distancia del origen en eje X: ";
            cin >> ejex;
            if(ejex>1 && ejex<100){
                datos[1] = ejex;
                datos[2] = 0;
                datos[3] = 0;
            }else{
                cout << "distancia del origen en eje X erronea"<<endl;
            }
        }
    }
}







