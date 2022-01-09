#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static double const epsilon = 1.0e-9;

double derivative(double F(double), double x){
    double x_h = x+epsilon;
    double result = (F(x_h)+F(x))/epsilon;
    return result;
}

int main( int argc, char* argv[]){
    double answer = derivative(sin, 0);
    printf("%.12f\n", answer);
}
