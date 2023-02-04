// Implement program for hashing values using Fold Boundary.

#include<iostream>
#include <math.h>
using namespace std;

int count_digits(int key);
int fold_boundary(int key, int size);
int reversDigits(int num);

int count_digits(int key)
{
    int count=0;
    while(key != 0)
    {
        key /= 10;
        ++count;
    }

    return count;
}

int fold_boundary(int key, int size)
{
    int key_roll=key;
    int key_sum=0;
    int key_frac=0;
    int middle=0;
    int left=0;
    int right=0;
    int digits=0;
    int key_length=0;
    int fraction = size;

    key_length = count_digits(key_roll);

    key_frac = key_roll / (int)pow(10, (key_length - fraction));        // start digit

    left=reversDigits(key_frac);

    key_roll = key_roll % (int)pow(10,3);

    right=reversDigits(key_roll);

    digits = (int)log10(key) + 1;

    middle= (int)(key / pow(10, digits/ 2)) % 10;

    key_sum = left +middle+ right;

    return (key_sum % (int)pow(10, (fraction)));      //ignore carry
}

int reversDigits(int num)
{
    int rev_num = 0;
    while (num > 0)
    {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }

    return rev_num;
}

int main()
{
    cout<<endl<<"3347878 key would be hashed at location "<<fold_boundary(3347878, 3);
    cout<<endl<<"1234678 key would be hashed at location "<<fold_boundary(1234678, 3);
    
    return 0;
}
