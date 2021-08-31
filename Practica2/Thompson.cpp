#include <iostream>
#include <array>
#include <algorithm>
#include <string>
using namespace std;

class AFD{

    protected:
        int Num_estados;
        string Alfabeto;
        string Estado_ini;
        string Estados_fin[MAX];
        string Funcion_transicion[MAX][MAX];

    //Constructor
    public:
        AFN(int num_estados, string alfabeto, string estado_ini, string estados_fin, string funcion_transicion){

        }

        void Tabla_Transicion(){
            cout << "\n TABLA DE TRANSICIONES \n";
            for(int i = 0; i < Num_estados; i++){
                for(int j = 0; j < Alfabeto.size(); j++){
                    cout << "\t" << Funcion_transicion[i][j];
                }
                cout << "\n";
            }
            cout << "\n" << endl;
        }

        void ValidarCadena(string cadena){

        }

};

int main(){
    AFN afn1 = AFN(3,"a,b","0","1,2,2","1,1,{1,2},1,{0,1},2");
    afn1 -> Tabla_Transicion();
    afn1 -> ValidarCadena("abbb");

}