#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

//Estructuran Publica
struct Canion{
    int altura;
    int cord_x;
    int cord_y;
};

map<string,vector<Canion>> cargar_datos(map<string,vector<Canion>> contenedor);

int main()
{
    bool menus[3]={false,false,false};
    while (menus[0]==false) {
        //Vamos a agregar los datos de entrada de ambos cañones
        map<string,vector<Canion>> canion; //mapa se llama canion, está vacio.
        canion=cargar_datos(canion); //Agregamos los datos


    }
    return 0;
}



map<string,vector<Canion>> cargar_datos(map<string,vector<Canion>> contenedor){
    Canion canion;

    //Datos de caniones
    bool datos[3]={false,false,false};
    int altura, corx, cory;

    cout << "Canion ofensivo DO"<<endl;

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
                datos[1]=true;
                while (datos[1]==true && datos[1]==true) {

                }
            }else {
                cout<<"Agrega una cordenada entre 0m y 99m";
            }


        }else {
            cout<<"Agrega un valor de altura entre 0m y 99m";
        }
    }


    canion.altura=0;
    canion.cord_x=0;
    canion.cord_y=0;
    contenedor["DO"].push_back(canion);

    canion.altura=0;
    canion.cord_x=0;
    canion.cord_y=0;
    contenedor["DD"].push_back(canion);


    return contenedor;
}
