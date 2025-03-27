double f(double x);
double g(double x);

double f(double x) 
{   
    double term = (x*x) / 4.0;
    term = term - ( x*sin(x) ); 
    term = term - ( 1.0/2.0 * cos(2.0*x) );
    term = term + 1.0/2.0;
    return ( term );
}

double g(double x) 
{   
    double term = (1.0/2.0) * x;
    term = sin(2.0*x) - sin(x) -x*cos(x) + x/2.0;
    return term;
}