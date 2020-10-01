#include<stdio.h>
#include<cs50.h>
#include<math.h>

long number;
int checksum(long ccn, long CCN);
bool is_valid(long cc);
void print_cc_type(long ccn);
int find_length(long n);

int  main(void)
{
    //Taking user's credit card number
    do
    {
        number = get_long("Credit Card Number:");
    }
    while (number < 0);
    //printing output
    if (is_valid(number))
    {
        print_cc_type(number);
    }
    else
    {
        printf("INVALID\n");
    }
    
    
}
//finding the length of credit card number
int find_length(long n)
{
    int len;
    for (len = 0; n != 0; n = n / 10)
    {
        len++;
    }
    return len;
}
//checking the validity of credit  card number
bool is_valid(long cc)
{
    int csum = checksum(cc, cc);
    int l = find_length(cc);
    return ((l == 13 || l == 15 || l == 16) && csum == 0);
        
}
//calculatig check sum
int checksum(long ccn, long CCN)
{
    int csum;
    int sum1;
    int sum2;

    for (sum1 = 0; ccn != 0 ; ccn = ccn / 100)
    {
        int products =  2 * ((ccn % 100) / 10); 
        sum1 = sum1 + products / 10 + (products % 10);
    }
    for (sum2 = 0; CCN != 0; CCN = CCN / 100)
    {
        sum2 = sum2 + (CCN % 10);
    }
    csum = (sum1 + sum2) % 10;
    return csum;
}
//checking credit card's type
void print_cc_type(long ccn)
{
    //checking for VISA
    if ((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
    {
        printf("VISA\n");
    }
    //checking for MASTERCARD
    else if (ccn >= 51e14 && ccn < 56e14)
    {
        printf("MASTERCARD\n");
    }
    //checking for AMERICAN EXPRESS
    else if ((ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
