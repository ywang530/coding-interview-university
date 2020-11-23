#include <stdio.h>
#include <math.h>


int integrate(int a, int b, float* coeff, int coeff_len){
    int power[coeff_len];
    int result = 0;

    for(int i=0; i< coeff_len; i++){
        power[i] = coeff_len - i;
        // *(coeff+i) = *(coeff+i) / power[i];
        coeff[i] /= power[i];
        // printf("power %d, coeff %f\n", power[i], *(coeff+i));
    }

    int result1 = 0;
    int result2 = 0;
    for(int i=0; i<coeff_len; i++){
        result1 += pow(b, power[i])*coeff[i];
        result2 += pow(a, power[i])*coeff[i];
    }
    
    return result1 - result2;
}

int main(){

    // f(x) = x^2 + 2x
    // integrate f(x) over [1, 10]
    // float coeff[] = {1, 2, 0};
    // int coeff_len = 3;

    float coeff[] = {4, 3, 2, 1};
    int coeff_len = 4;

    int a = 1, b = 10;

    float integral = integrate(a, b, coeff, coeff_len);

    printf("%6.1f\n", integral);

    return 0;
}