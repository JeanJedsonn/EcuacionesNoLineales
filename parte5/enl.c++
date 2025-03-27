/*
Alumno: Jeanmarco Alarcon
Curso: Calculo Computacional
Fecha: 26-03-2025
Descripción: [Ecuaciones No Lineales, parte 5]
*/
#include "iostream"
#include "math.h"
#include "vector"
#include "funciones5.h"
using namespace std;


int secante(double x1, double x2);
int falsaPosicion(double x1, double x2);

int main()
{
    double x1,x2;
    double E = 1;

    cout<<"Enter a:\n";
    cin>>x1;
    cout<<"Enter b:\n";
    cin>>x2;

    printf("\nStep\tx0\t\tx1\t\tx2\t\tf(x0)\t\tf(x1)\t\tf(x2)\n");
    //cout << f(x0) << endl;
    secante(x1,x2);
    printf("\n\n\nStep\tx0\t\tx1\t\tx2\t\tf(x0)\t\tf(x1)\t\tf(x2)\n");
    falsaPosicion(x1,x2);

    return 0;
}

 
int secante(double x1, double x2) {
    double E = 0.0000001;
    int i = 0;
    double x0;    //1er extremo
    //x1          //2do extremo
    //x2          //corte de la secante

    do {
        x0=x1;      //se reasignan los valores
        x1=x2;      //para liberar a x2
        x2 = x1 - (x1-x0) * f(x1) / (f(x1) - f(x0));

        printf("%d\t%.7f\t%.7f\t%.7f\t%.7f\t%.7f\t%.7f\n",i,x0,x1,x2,f(x0),f(x1),f(x2));
        i++;
    } while ( i < 250 && fabs (f(x2)) > E && x1 != x2); 
    
    if (i == 250 || x1 == x2) {
        printf("Solution does not Converge.\n");
    }
    return 0;
}

int falsaPosicion(double x1, double x2) {
    double E = 0.0000001;
    int i = 0;
    double x0;    //1er extremo
    //x1          //2do extremo
    //x2          //corte de la secante

    double fx0 = f(x1);
    double fx1 = f(x2);
    double fx2;

    x0=x1;      //se reasignan los valores
    x1=x2;      //para liberar a x2

    do
    {
        x2 = x1 - (x1-x0) * f(x1) / (f(x1) - f(x0));
        fx2 = f(x2);
        printf("%d\t%.7f\t%.7f\t%.7f\t%.7f\t%.7f\t%.7f\n",i,x0,x1,x2,fx0,fx1,fx2);

        if (fx0 * fx2 < 0) {
            x1 = x2;
            fx1 = fx2;
        } else {
            x0 = x2;
            fx0 = fx2;
        }
        
        i++;
    } while ( i < 250 && fabs (fx2) > E);
    
    if (i == 250) {
        printf("Solution does not Converge.\n");
    }
    return 0;
}