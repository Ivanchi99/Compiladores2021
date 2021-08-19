#include <iostream>
#include <array>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 50

class AFD{

    protected:
        int Num_estados;
        string Alfabeto;
        string Estado_ini;
        string Estados_fin[MAX];
        string Funcion_transicion[MAX][MAX];

    //Constructor
    public:
        AFD(int num_estados, string alfabeto, string estado_ini, string estados_fin, string funcion_transicion){
            Num_estados = num_estados;
            Alfabeto = alfabeto;    
            Estado_ini = estado_ini;

            for (int i = 0; i < estados_fin.size(); i++){
                int ei = 0;
                if(estados_fin[i] != ',')
                    Estados_fin[ei]= estados_fin[i];   
                    ei++;
            }
            
            int x = 0, y = 0;
            int abrir = 0, cerrar = 0;
            for (int i = 0; i < funcion_transicion.size(); i++){
                if(funcion_transicion[i] != ',' && funcion_transicion[i] != '{' && funcion_transicion[i] != '}'){
                    Funcion_transicion[y][x] = funcion_transicion[i];
                    if(x < Alfabeto.size()-1)
                        x++;
                    else{
                        x = 0;
                        if(y < Num_estados-1)     
                            y++;
                        else
                        y = 0;
                    }
                }
                else if(funcion_transicion[i] == '{'){
                    abrir = i;
                    cerrar = 0;
                }
                else if(funcion_transicion[i] == '}'){
                    cerrar = i;
                    Funcion_transicion[y][x] = funcion_transicion.substr(abrir,cerrar);
                    abrir = 0;
                }          
            }
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

class AFN : public AFD{

    //Constructor
    public:
        AFN(int num_estados, string alfabeto, string estado_ini, string estados_fin, string funcion_transicion)
        :AFD(num_estados,alfabeto,estado_ini,estados_fin,funcion_transicion){

        }
    
        void ValidarCadena(string cadena){

        }


};


int main(){
    AFD afd1 = AFD(3,"ab","0","1","1,2,2,1,2,2");
    afd1.Tabla_Transicion();
    afd1.ValidarCadena("abbb");

    AFN afn1 = AFN(3,"a,b","0","1,2,2","1,1,{1,2},1,{0,1},2");
    AFN *afn0 = &afn1;
    afn0 -> Tabla_Transicion();
    afn0 -> ValidarCadena("abbb");

}