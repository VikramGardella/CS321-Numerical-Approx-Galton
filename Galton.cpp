#include <iostream>
#include <cstdlib>
#include "math.h"

using namespace std;

//f(x) = x^2 + 3*x - 4
//f'(x) = 2*x + 3
//xn+1 = xn - f(xn)/f'(xn)
//x0 = 1.5 because f(1.5) = 6.75 - 4 > 0
float newtonsA(float xzero){
    float r = xzero;
    for(int i=0; i<20; i++){
        r = r - (r*r + 3*r - 4)/(2*r + 3);
    }
    return r;
}

//f(x) = 3*x^3 - 10
//f'(x) = 9*x^2
//x0 = 1.5 because f(1.5) = 10.125 - 10 > 0
float newtonsB(float xzero){
    float r = xzero;
    for(int i=0; i<20; i++){
        r = r - (3*r*r*r - 10)/(9*r*r);
    }
    return r;
}

//f(x) = 6*sin(x)
//f'(x) = 6*cos(x)
//xn+1 = xn - [6*sin(x)]/[6*cos(x)] = xn - tan(x)
//x0 = pi/8 because sin(pi/8) is close to sin(0) and that's where f(x) = 0
float newtonsC(float xzero){
    float r = xzero;
    for(int i=0; i<20; i++){
        r = r - tanf(r);
    }
    return r;
}

int factorial(int x){
    int result = 1;
    for(int i=x; i>1; i--){
        result*=i;
        cout << i << endl;
    }
    return result;
}

int main(){
   // cout << "10! = " << factorial(10) << endl;


    cout << "A: f(x) = x^2 + 3*x - 4 with x0 = 1.5" << endl;
    float a = newtonsA(1.5);
    cout << "xn after 20 iterations of Newton's Method: "  << a << endl;
    cout << "True error: |r-xn| = " << (1-a) << endl << endl;

    cout << "B: f(x) = 3*x^3 - 10 with x0 = 1.5" << endl;
    float b = newtonsB(1.5);
    cout << "xn after 20 iterations of Newton's Method: " << b << endl;
    cout << "True error: |r-xn| = " << (1.48-b) << endl << endl;

    cout << "C: f(x) = 6*sin(x) with x0 = pi/8" << endl;
    float c = newtonsC(3.14/8);
    cout << "xn after 20 iterations of Newton's Method: " << c << endl;
    cout << "True error: |r-xn| = " << (0-c) << endl << endl;


}
