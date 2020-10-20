#include <iostream>
#include <math.h>

using namespace std;
#define PI 3.14159265

void llenar_datos(float *datos, float numero);
bool golpear(float *datosC1, float *datosC2);
void modificar_datos(float *datos, float numero);
bool lanzamiento(float *datosC1, float *datosC2);


int main()
{
    //altura, eje x. angulo, vel inicial
    float datosC1[4];
    float datosC2[4];

    cout << "Vamos a inicializar datos del canion ofensivo:"<<endl;
    llenar_datos(&datosC1[0], 1);
    cout <<endl<< "agregado canion ofensivo con exito"<<endl;

    cout << "Vamos a inicializar datos del canion defensivo:"<<endl;
    llenar_datos(datosC2, 2);
    cout <<endl<< "Agregado canion defensivo con exito"<<endl;

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
    if(altura>=0 && altura<99){
        datos[0]=altura;
        if(numero==1){
            datos[1] = 0;
            datos[2] = 0;
            datos[3] = 0;
        }else if(numero==2){
            cout << "distancia del origen en eje X, distancia entre ambos caniones: ";
            cin >> ejex;
            if(ejex>=0 && ejex<100){
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

    //modificar_datos(datosC2, 2);
    cout << "Vamos a generar 3 disparos"<<endl<<endl;
    for(int i=0; i<3; i++){
        modificar_datos(datosC1, 1);
        destruido = lanzamiento(datosC1, datosC2);
        if(destruido==true){
            cout << "se procede a prevenir el impacto con la defensa"<<endl<<endl;
            break;
        }
    }


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

    float altura_maxima = (v0*v0*sin((angulo*angulo)*PI/180))/(2*9.81);

    //encontramos la altura exacta que debe descender el objeto para impactar
    altura_maxima += (datosC1[0]-datosC2[0]);

    //tiempo el alcanzar dicha altura

    float velocidad_ascenso = datosC1[3]*sin((datosC1[2])*PI/180);

    float tiempo_ascenso = velocidad_ascenso/9.8;

    //vel final descenso

    float velocidad_descenso = sqrt(pow(velocidad_ascenso,2)+2*9.8*datosC1[0]);

    float tiempo_descenso = velocidad_descenso/9.8;
    float tiempo_de_vuelo = tiempo_ascenso+tiempo_descenso;

    float velocidad_x = v0*cos((angulo)*PI/180);


    float distancia = tiempo_de_vuelo*velocidad_x;

    //cerificamos si la explocion alcanza o impactara con el canion defensivo
    if(distancia<(datosC2[1]+0.05*distancia) && distancia>(datosC2[1]-0.05*distancia)){
        cout << "Impactara el proyectil, se procede a la defensa"<<endl<<endl<<endl;
        cout << "--- Datos --- "<<endl;
        cout << "Distancia maxima del proyectil: " << distancia;
        cout << "Tiempo en detonar: " << tiempo_de_vuelo <<endl;
        return true;
    }else {
        cout << "no hay necesidad de defensa"<<endl;
        cout << "--- Datos --- "<<endl;
        cout << "Distancia maxima del proyectil: " << distancia<< " metros ";
        cout << " Tiempo: " << tiempo_de_vuelo <<" segundos"<<endl;
        if(distancia<datosC2[1]){
            cout << "Impacto antes"<<endl<<endl<<endl;
        }else if(distancia>datosC2[1]){
            cout << "Impacto mas lejos"<<endl<<endl<<endl;
        }
    }
    return false;
}














