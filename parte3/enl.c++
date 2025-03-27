/*
Alumno: Jeanmarco Alarcon
Curso: Calculo Computacional
Fecha: 26-03-2025
Descripción: [Ecuaciones No Lineales, parte 3]
*/
#include "iostream"
#include "math.h"
#include "vector"
#include "funciones3.h"
using namespace std;


int calc(double x0, double E);

double raiz = 0;

int main()
{
    double x0;
    double E = 1;

   // cout<<"Enter initial guess:\n";
    //cin>>x0;
    cout<<"Enter Presicion:\n";
    cin>>E;
    E = 1/(pow(10,E)); //que tan cerca esta Y de 0

    printf("\nStep\t\tx0\t\tf(x0)\t\tg(x0)\t\tinicio\n");
    calc(M_PI,E);

    printf("\nStep\t\tx0\t\tf(x0)\t\tg(x0)\t\tinicio\n");
    calc(5*M_PI,E);

    printf("\nStep\t\tx0\t\tf(x0)\t\tg(x0)\t\tinicio\n");
    calc(10*M_PI,E);
    
    return 0;
}



int calc(double x0, double E) {
    int i = 0;                  //iteracion antes de la divergencia
    double x1;                  //punto de corte de la tangente
    double fx0 = f(x0);         //altura Y en el punto x0
    double gx0;                 //pendiente de la tangente
    double error = fabs( fx0 );
    double inicio = x0;
    bool bandera = false;

    while( error > E && !bandera && i < 250)
    {
        gx0 = g(x0);                        //pendiente de la tangente de f(x0)
        bandera = (gx0 == 0.0);             //no existe la pendiente
        if(bandera)
        {
            cout<<"Mathematical Error" << i << endl;
        }

        x1 = x0 - fx0/gx0;      //x1 es el punto de corte de la recta calculada
        x0 = x1;                //x0 sera el nuevo punto de corte
        fx0 = f(x0);            //altura Y en el nuevo punto x0

        printf("%d\t\t%.7f\t%.7f\t%.7f\t%.7f\n",i,x0,fx0,gx0,inicio);
        error = fabs( fx0 );    //altura positiva
        i++;
    }
    
    if (i == 250) {
        printf("Solution does not Converge.\n");
    }
    return 0;
}