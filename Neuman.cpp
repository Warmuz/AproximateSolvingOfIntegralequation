#include <iostream>
#include <cmath>
using namespace std;
double K(double x)
{
    return exp(-2*x);
}
double f(double x)
{
    return exp(3*x);
}

int main()
{
    double b = 10;
    double a = 0;
    
    double y[10000] = {1};
    double xj = a;
    double xi = a;
    double lambda = 2;
    double yn = 0;
    
    double numberIterations = 8;
    int num = 10;
    double step = (b-a)/num;
    
    for(int n = 0; n<numberIterations; n++)
    {
        for(int i = 0; i<num;i++)
        {
            for(int j = 0; j<i; j++)
            {
                yn = K(xj) * y[j-1] * step;
                xj += step;
            }
            y[i-1] = lambda * yn + f(xi);
            xi += step;
            cout << xi  << endl;
        }
        xi = 0;
        cout << "      n = " << n << endl;
    }
}
