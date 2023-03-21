/**
 * Using boost multiprecision as an alternative to int[]
*/
#include <iostream>
#include <math.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int512_t karatsubaCompute(int512_t, int512_t);
int512_t size_base10(int512_t);
int512_t max(int512_t,int512_t);
int512_t pow_base10(int512_t);

int main()
{
    int512_t num1, num2;

    std::cout << "num1: "; std::cin >> num1;
    std::cout << "num2: "; std::cin >> num2;

    std::cout << "Karatsuba Compute: " << karatsubaCompute(num1, num2) << std::endl;

    return 0;
}

int512_t karatsubaCompute(int512_t num1, int512_t num2)
{
    if (num1 < 10 && num2 < 10)
        return num1*num2;

    int512_t s = max(size_base10(num1), size_base10(num2));
    int512_t s2 = (s % 2 == 0) ? s/2 : (s/2)+1; 
    int512_t s2_pow10 = pow_base10(s2);

    int512_t a = num1 / s2_pow10;
    int512_t b = num1 % s2_pow10;
    int512_t c = num2 / s2_pow10;
    int512_t d = num2 % s2_pow10;

    int512_t ac = karatsubaCompute(a,c);
    int512_t bd = karatsubaCompute(b,d);
    int512_t adbc = karatsubaCompute((a+b), (c+d));

    int512_t gauss = adbc - bd - ac;
    int512_t ret = (ac * pow_base10(2*s2)) + (gauss * s2_pow10) + bd;
    return ret;
}

int512_t size_base10(int512_t num)
{
    int512_t remain = 1;
    int512_t pow = 1;
    int512_t count = 0;

    do
    {
        remain = num/pow;
        count++;
        pow *= 10;
    }while(remain >= 10);

    return count;
}

int512_t max(int512_t num1, int512_t num2)
{
    if (num1 > num2)
        return num1;

    return num2;
}

int512_t pow_base10(int512_t exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    
    return(10 * pow_base10(exponent-1));
}