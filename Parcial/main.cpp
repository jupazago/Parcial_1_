#include <iostream>
#include <math.h>

using namespace std;


void llenar_datos(float *datos, float);
bool golpear(float *datosC1, float *datosC2);
void modificar_datos(float *datos, float numero);
bool lanzamiento(float *datosC1, float *datosC2);


int main()
{
    //altura, eje x. angulo, vel inicial
    float datosC1[4];
    float datosC2[4];

    llenar_datos(&datosC1[0], 1);
    cout <<endl<< "agregado ofensivo con exito"<<endl;

    //llenar_datos(datosC2, 2);
    //cout <<endl<< "Agregado defensivo con exito"<<endl;

    bool derribado=false;

    while (derribado==false) {
        derribado = golpear(datosC1, datosC2);
    }

    return 0;
}

void llenar_datos(float *datos, float numero){
    float altura, ejex;
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

bool golpear(float *datosC1, float *datosC2){
    bool destruido = false;
    modificar_datos(datosC1, 1);
    //modificar_datos(datosC2, 2);

    lanzamiento(datosC1, datosC2);

    return destruido;
}

void modificar_datos(float *datos, float numero){
    float angulo, vel_inicial;
    while(numero==1){
        cout <<"que angulo de tiro sera para A, de 1 hasta 89 grados"<<endl;
        cin >> angulo;
        if(angulo>1 && angulo<90){
            datos[2] = angulo;
            cout <<"Que velocidad inicial tiene el canion"<<endl;
            cin >> vel_inicial;
            if(vel_inicial>0){
                datos[3] = vel_inicial;
                break;
            }else{
                cout <<"Error: velocidad inicial erronea, debe ser mayor a 0"<<endl;
            }
        }else{
            cout <<"Error, Agrega un valor valido"<<endl;
        }
    }

    while(numero==2){
        cout <<"que angulo de tiro sera para B, de 1 hasta 89 grados"<<endl;
        cin >> angulo;
        if(angulo>1 && angulo<90){
            datos[2] = angulo+90;
            cout <<"Que velocidad inicial tiene el canion"<<endl;
            cin >> vel_inicial;
            if(vel_inicial>0){
                datos[3] = vel_inicial;
                break;
            }else{
                cout <<"Error: velocidad inicial erronea, debe ser mayor a 0"<<endl;
            }
        }else{
            cout <<"Error, Agrega un valor valido"<<endl;
        }
    }

}

bool lanzamiento(float *datosC1, float *datosC2){
    //calcularemos el alcance maximo del proyectil del primer canion ofensivi
    //si se aproxima al canion defensivo efectuara su defensa, si no
    // se avisara que el lanzamiento no fue eficiente

    //[0] altura
    //[1] eje x
    //[2] angulo
    //[3] vel inicial
    //Calculamos la distancia del lanzamiento

    float v0= datosC1[3];
    float angulo=datosC1[2];

    float altura_maxima = ((v0*v0)*sin(angulo*angulo)) / (2*9.81);
    //altura total
    altura_maxima -= datosC1[0];
    altura_maxima += altura_maxima*2;

    //tiempo el alcanzar dicha altura

    float velocidad_ascenso = datosC1[3]*sin(datosC1[2]);

    float tiempo_ascenso = velocidad_ascenso/9.8;

    //vel final descenso

    float velocidad_descenso = sqrt(pow(velocidad_ascenso,2)+2*9.8*datosC1[0]);

    float tiempo_descenso = velocidad_descenso/9.8;

    cout << "tiempo total: "<<endl;
    cout << tiempo_ascenso+tiempo_descenso<<endl;





}














