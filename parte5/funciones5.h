double f(double x);

double f(double x) 
{   
    double p1 = 2.0* (x*x*x);
    double p2 = -1.0 * ( (34.0/7.0) * x*x );
    double p3 = (209.0/49.0)*x;
    double c = -1.0 * (173.0/343.0);
    return p1 + p2 + p3 + c;
}
