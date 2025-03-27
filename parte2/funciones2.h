double f(double x);
double g(double x);

double f(double x) 
{   
    double term = (7.0/2.0) * x;
    term = atan( term );
    term = term -1.0;
    return ( term );
}

double g(double x) 
{   
    double term = ( 49.0*(x*x) )+ 4.0;
    term = 14.0/term;
    return term;
}