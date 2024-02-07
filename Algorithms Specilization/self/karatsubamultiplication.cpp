#include <iostream>
#include <math.h>

int basicCompute(int,int);
int karatsubaCompute(int, int);
int size_base10(int);
int max(int,int);

int main()
{
    int num1, num2;

    std::cout << "num1: "; std::cin >> num1;
    std::cout << "num2: "; std::cin >> num2;

    std::cout << "Basic Compute: " << basicCompute(num1, num2) << std::endl;
    std::cout << "Karatsuba Compute: " << karatsubaCompute(num1, num2) << std::endl;

    return 0;
}

/**
 * Basic recursion to calculate sum of two numbers
*/
int basicCompute(int num1, int num2)
{
    if (num2 == 0)
    {
        return 0;
    }
    return num1+basicCompute(num1, num2-1);
}

/**
 * Karatsuba method to calculate sum of two numbers
*/
int karatsubaCompute(int num1, int num2) //x*y = 10^(n)ac+10^(n/2)(ad+bc)+bd
{
    if (num1 < 10 && num2 < 10)
        return num1*num2;

    int s = max(size_base10(num1), size_base10(num2));
    int s2 = (s % 2 == 0) ? s/2 : (s/2)+1; 
    int s2_pow10 = (int)pow(10, s2);

    int a = num1 / s2_pow10;
    int b = num1 % s2_pow10;
    int c = num2 / s2_pow10;
    int d = num2 % s2_pow10;

    int ac = karatsubaCompute(a,c);
    int bd = karatsubaCompute(b,d);
    int adbc = karatsubaCompute((a+b), (c+d));

    int gauss = adbc - bd - ac;
    int ret = (ac * pow(10, 2*s2)) + (gauss * s2_pow10) + bd; //O(n^2) -> O(n^log3)
    return ret;
}

int size_base10(int num)
{
    int remain = 1;
    int pow = 1;
    int count = 0;

    do
    {
        remain = num/pow;
        count++;
        pow *= 10;
    }while(remain >= 10);

    return count;
}

int max(int num1, int num2)
{
    if (num1 > num2)
        return num1;

    return num2;
}