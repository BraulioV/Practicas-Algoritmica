#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;


//******************************************************************************
// Estructura de datos para almacenar toda la información del objeto
//******************************************************************************


struct Elemento{
    int beneficio;
    int peso;
    double beneficio_unidad_peso;
    bool operator < (const Elemento & b){
        return (*this).beneficio < b.beneficio && (*this).peso < b.peso;
    }
    bool operator > (const Elemento & b){
        return !((*this)<b);
    }
    bool operator == (const Elemento & b){
        return ((*this).beneficio == b.beneficio && (*this).peso == b.peso);
    }
    bool operator != (const Elemento & b){
        return !((*this)==b);
    }
    Elemento & operator = (const Elemento & b){
        if(this != &b){
            beneficio = b.beneficio;
            peso = b.peso;
            beneficio_unidad_peso = (double)b.beneficio/peso;
        }
        return (*this);
    }

    Elemento(int b, int p) : beneficio(b), peso(p){
        beneficio_unidad_peso = ((double)beneficio/(double)peso);
    }

    Elemento() : beneficio(0), peso(0), beneficio_unidad_peso(0.0) {}

    Elemento(const Elemento & e) : beneficio(e.beneficio), peso(e.peso), 
        beneficio_unidad_peso((double)e.beneficio_unidad_peso) {}
};

ostream & operator << (ostream & os, const vector< vector<int> > & v){
    os << "---------------------------------------------------" << endl;
    os << 'v' << setw(2) << '|';
    for(unsigned i = 0; i < v[0].size(); i++)
        os << setw(2) << i << setw(2) << '|';
    os << endl << "---------------------------------------------------" << endl;
    for(unsigned i = 0; i < v.size(); i++){
        os << i << setw(2) << '|';
        for(unsigned j = 0; j < v[i].size(); j++)
            os << setw(2) << v[i][j] << setw(2) << '|';

        os << endl << "---------------------------------------------------" << endl;
    }
    os << endl;
    return os;
}

ostream & operator << (ostream & os, const vector<Elemento> & v){
    for(unsigned i = 0; i < v.size(); i++)
        os << setw(4) << "Peso=" << v[i].peso 
            << " Beneficio=" << v[i].beneficio << endl;
    os << endl;

    return os;
}

ostream & operator << (ostream & os, const Elemento & v){
    os << '[' << v.peso << ", " << v.beneficio << ']';
    return os;
}

ostream & operator << (ostream & os, const vector<int> & v){
    for(unsigned i = 0; i < v.size(); i++)
        os << setw(4) << v[i];

    os << endl;

    return os;
}

int max(int i, int j){
    if(i > j)
        return i;
    else
        return j;
}

//******************************************************************************
// Algoritmo de la mochila. En el se rellena la tabla con la que más adelante
// se recompone la solución.
//******************************************************************************

void Mochila(vector< vector <int> > & tabla, const vector<Elemento> & elementos){
    for(unsigned i = 1; i < tabla.size(); i++){
        for(unsigned j = 1; j < tabla[i].size(); j++){
            Elemento k_i = elementos[i -1];
            if(j - k_i.peso < 0){
              tabla[i][j] = tabla[i-1][j];
            }
            else{
                tabla[i][j] = max(tabla[i-1][j], 
                    k_i.beneficio + tabla[i-1][j-k_i.peso]);
            }
        }
    } 
}

//******************************************************************************
// Algoritmo para recomponer la solución
//******************************************************************************

void recomponer(const vector< vector <int> > & tabla, const vector<Elemento> & elementos,
    vector<int> & sol){
    int j = tabla[0].size()-1;
    for(unsigned i = tabla.size()-1; i>=1; i--)
        if(tabla[i][j] == tabla[i-1][j])
            sol[i-1] = 0;       // tabla[i][j] == tabla[i-1][j-p_i + b]
        else{
            sol[i-1] = 1;
            j -= elementos[i-1].peso;
        }
}


int main(int argc, char **argv){

    if (argc < 2) {
        cerr << "ERROR: falta la multiseta de beneficios-pesos" <<
            " y el peso de la mochila" << endl;
        exit(1);
    }

    if (argc%2 != 0) {
        cerr << "ERROR: argumentos incorrectos: beneficio-peso pesomochi" << endl;
        exit(2);
    }

    int num_objetos = (argc-2)/2,
        peso_mochila = atoi(argv[argc-1]);

    vector<Elemento> elementos(num_objetos);

    for (int i=1, j = 0; i<argc-1; i+=2, j++) {
        int b = atoi(argv[i]); int p = atoi(argv[i+1]);
        Elemento obj (b, p);
        elementos[j] = obj;
    }

    cout << "Elementos a escoger" << endl;
    cout << elementos;
    cout << "Peso de la mochila " << peso_mochila << endl;
    cout << endl << "Tabla:" << endl << endl;

    vector< vector <int> > tabla((num_objetos+1));

    for(int i = 0; i < num_objetos + 1; i++){
        tabla[i].resize(peso_mochila + 1);
        tabla[i][0] = tabla[0][i] = 0;  
    }
    struct timespec cgt1, cgt2, cgt3, cgt4;
    clock_gettime(CLOCK_REALTIME,&cgt1);
    Mochila(tabla, elementos);
    clock_gettime(CLOCK_REALTIME,&cgt2);
    vector<int> sol(num_objetos,0);
    clock_gettime(CLOCK_REALTIME,&cgt3);
    recomponer(tabla, elementos, sol);
    clock_gettime(CLOCK_REALTIME,&cgt4);

    cout << tabla;
    
    double ncgt;

    ncgt=(double)(cgt2.tv_sec-cgt1.tv_sec)+
        (double)((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
    ncgt+=(double)(cgt4.tv_sec-cgt3.tv_sec)+
        (double)((cgt4.tv_nsec-cgt3.tv_nsec)/(1.e+9));

    cout << "Elementos escogidos: " << setw(5);
    for(unsigned i = 0; i < elementos.size(); i++){
        if(sol[i] == 1)
            cout << elementos[i] << setw(5);
    }

    cout << endl;

    printf("\nTiempo (seg.) = %11.9f\n", ncgt);
    
    return 0;
}