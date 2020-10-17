#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

//Estructuran Publica
struct Canion{
    int altura;
    int cord_x;
    int angulo=0;
};

map<string,Canion> cargar_datos(map<string,Canion> contenedor);

int main()
{

    //Vamos a agregar los datos de entrada de ambos caniones
    map<string,vector<Canion>> canion; //mapa se llama canion, esta vacio.
    canion=cargar_datos(canion); //Agregamos los datos

    while(true){
        //Atacaremos

    }

    return 0;
}



map<string,Canion> cargar_datos(map<string,Canion> contenedor){
    Canion canion;

    //Datos de caniones
    bool datos[3]={false,false};
    int altura=0, corx=0;

    cout << "Canion ofensivo DO"<<endl;
    while(datos[0]==false){
        cout<<endl<<"Agregar la altura: ";
        cin >>altura;
        if(altura>=0 && altura<100){
            canion.altura = altura;
            datos[0]=true;
            canion.cord_x = 0;

            contenedor["DO"].push_back(canion);
            cout << "Creacion de segundo canion, defensivo exitoso"<<endl<<endl;
        }else {
            cout<<"Agrega un valor de altura entre 0m y 99m";
        }
    }

    cout << "Canion defensivo DD"<<endl;
    altura=0, corx=0;

    while(datos[0]==false){
        cout<<endl<<"Agregar la altura: ";
        cin >>altura;
        if(altura>=0 && altura<100){
            canion.altura = altura;
            datos[0]=true;

            cout<<endl<<"Agregar cordenada en X: ";
            cin >>corx;

            if(corx >=0 && corx<100){
                canion.cord_x = corx;
                canion.angulo += 90;
                datos[1]=true;
                contenedor["DD"].push_back(canion);
                cout << "Creacion de primer canion, ofensivo exitoso"<<endl<<endl;
            }else {
                cout<<"Agrega una cordenada entre 0m y 99m";
            }
        }else {
            cout<<"Agrega un valor de altura entre 0m y 99m";
        }
    }




/*
    canion.altura=0;
    canion.cord_x=0;
    contenedor["DO"].push_back(canion);

    canion.altura=0;
    canion.cord_x=0;
    contenedor["DD"].push_back(canion);
*/

    return contenedor;
}
