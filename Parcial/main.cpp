#include <iostream>
#include <math.h>

using namespace std;


void llenar_datos(int *datos, int);
bool golpear(int *datosC1, int *datosC2);
void modificar_datos(int *datos, int numero);
bool lanzamiento(int *datosC1, int *datosC2);


int main()
{
    //altura, eje x. angulo, vel inicial
    int datosC1[4];
    int datosC2[4];

    llenar_datos(&datosC1[0], 1);
    cout <<endl<< "agregado ofensivo con exito"<<endl;

    llenar_datos(datosC2, 2);
    cout <<endl<< "Agregado defensivo con exito"<<endl;

    bool derribado=false;

    while (derribado==false) {
        derribado = golpear(datosC1, datosC2);
    }

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

bool golpear(int *datosC1, int *datosC2){
    bool destruido = false;
    modificar_datos(datosC1, 1);
    modificar_datos(datosC2, 2);

    lanzamiento(datosC1, datosC2);

    return destruido;
}

void modificar_datos(int *datos, int numero){
    int angulo, vel_inicial;
    while(numero==1){
        cout <<"que angulo de tiro sera para A, de 1 hasta 89 grados"<<endl;
        cin >> angulo;
        if(angulo>1 && angulo<90){
            datos[2] = angulo;
            cout <<"Que velocidad inicial tiene el canion"<<endl;
            cin >> vel_inicial;
            if(vel_inicial>0){
                datos[3] = vel_inicial;
            }else{
                cout <<"Error: velocidad inicial erronea, debe ser mayor a 0"<<endl;
            }
        }else{
            cout <<"Error, Agrega un valor valido"<<endl;
        }
    }

    while(numero==1){
        cout <<"que angulo de tiro sera para A, de 1 hasta 89 grados"<<endl;
        cin >> angulo;
        if(angulo>1 && angulo<90){
            datos[2] = angulo+90;
            cout <<"Que velocidad inicial tiene el canion"<<endl;
            cin >> vel_inicial;
            if(vel_inicial>0){
                datos[3] = vel_inicial;
            }else{
                cout <<"Error: velocidad inicial erronea, debe ser mayor a 0"<<endl;
            }
        }else{
            cout <<"Error, Agrega un valor valido"<<endl;
        }
    }

}

bool lanzamiento(int *datosC1, int *datosC2){
    //calcularemos el alcance maximo del proyectil del primer canion ofensivi
    //si se aproxima al canion defensivo efectuara su defensa, si no
    // se avisara que el lanzamiento no fue eficiente

    //Calculamos la distancia del lanzamiento
    float distancia_maxima;









}














