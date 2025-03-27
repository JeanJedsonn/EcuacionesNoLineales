double f(double x);
double g(double x);

double f(double x) 
{   
    return x-tan(x);
}

double g(double x) 
{   
    double term = 1.0/cos(x);
    term = term*term;
    return 1.0 - term;
}