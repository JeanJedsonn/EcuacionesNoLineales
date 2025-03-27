/*
Alumno: Jeanmarco Alarcon
Curso: Calculo Computacional
Fecha: 26-03-2025
Descripción: [Ecuaciones No Lineales, parte 4]
*/
#include "iostream"
#include "math.h"
#include "vector"
#include "funciones4.h"
using namespace std;


double calc1(double x0, double E);
int calc2(double x0, double E);
vector <double> raices;
vector <double> inicios;
int iter = 0;

int main()
{
    double x0;
    double E = 1;
    double temp = 0;
    double i = 0;
    double raiz = -1;
    int iter_raiz = 0;
    bool bandera = true;

    cout<<"Enter initial guess:\n";
    cin>>x0;
    cout<<"Enter Presicion:\n";
    cin>>E;
    E = 1/(pow(10,E)); //que tan cerca esta Y de 0

    while (iter < 10)
    {
        temp = calc1(x0+i,E);
        if (temp != -1)
        {
            iter_raiz = 0;
            bandera = true;
            while (iter_raiz < raices.size() && bandera)
            {
                bandera = (temp > (raices[iter_raiz]+1) || temp < (raices[iter_raiz]-1));
                iter_raiz++;
            }
            
            //si la raiz esta mas a la derecha o esta mas a la izquierda
            if (bandera)
            {
                raices.push_back(temp);
                inicios.push_back(x0+i);
                iter++;
            }
        }
        i += 0.01;
    }
    
    for (int i = 0; i < raices.size(); i++)
    {
        cout << raices[i] << " " << inicios[i] << endl;
    }

    for (int i = 0; i < raices.size(); i++)
    {
        printf("\nStep\t\tx0\t\tf(x0)\t\tg(x0)\t\tinicio\n");
        calc2(inicios[i],E);
    }
    return 0;
}



double calc1(double x0, double E) {
    int i = 0;                  //iteracion antes de la divergencia
    double x1;                  //punto de corte de la tangente
    double fx0 = f(x0);         //altura Y en el punto x0
    double gx0;                 //pendiente de la tangente
    double error = fabs( fx0 );
    double inicio = x0;
    bool bandera = false;
    double raiz = 0.0;

    while( error > E && !bandera && i < 250)
    {
        gx0 = g(x0);                        //pendiente de la tangente de f(x0)
        bandera = (gx0 == 0.0);
        if(bandera)
        {
            cout<<"Mathematical Error" << i << endl;
        }

        x1 = x0 - fx0/gx0;      //x1 es el punto de corte de la recta calculada
        x0 = x1;                //x0 sera el nuevo punto de corte
        fx0 = f(x0);            //altura Y en el nuevo punto x0
        error = fabs( fx0 );    //altura positiva
        i++;
    }
    
    if (i == 250 || bandera) {
        raiz = -1;
    }
    else {
        raiz = x0;
    }

    return raiz;
}

int calc2(double x0, double E) {
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
        bandera = (gx0 == 0.0);
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
    }else {
        printf("%d\t\t%.7f\t%.7f\t%.7f\t%.7f\n",i,x0,fx0,gx0,inicio);
    }
    return 0;
}