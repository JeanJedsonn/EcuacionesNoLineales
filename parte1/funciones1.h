double f(double x);
double g(double x);
double e_arg_1(double x);
double e_arg_2(double x);

double e_arg_1(double x) { return ( -x*x + 12.15*x - 36.875); }
double e_arg_2(double x) { return ( -x*x + 7.4*x - 13.2); }

double f(double x) 
{   
    double e_1 = exp(e_arg_1(x));
    double e_2 = exp(e_arg_2(x));
    return 1-e_1-e_2;
}
double g(double x) 
{   
    double e_1 = exp(e_arg_1(x));
    double e_2 = exp(e_arg_2(x));

    return (2*x + 12.15*e_1 + 2*x + 7.4*e_2);
}