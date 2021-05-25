 
#include<iostream>
#include<math.h>
 
using namespace std;
 
//to find gcd or greatest common divisor
int gcd(int first, int second)
{
    int temp;
    while(1)
    {
        temp = first%second;
        if(temp==0)
        return second;
        first = second;
        second = temp;
    }
}
 
int main()
{
    //2 random prime numbers
    double prime1 = 3;
    double prime2 = 7;
    double n=prime1*prime2;
    double count;
    double totient = (prime1-1)*(prime2-1);
 
    //public key
    double encrypt=2;
 
    //for checking co-prime which satisfies encrypt>1
    while(encrypt<totient){
    count = gcd(encrypt,totient);
    if(count==1)
        break;
    else
        encrypt++;
    }
 
    //private key
    double decrypt;
 
    //arbitrary value
    double arbitrary = 2;
 
    // choosing decrypt such that it satisfies 
    // decrypt*encrypt = 1 + arbitrary * totient
    decrypt = (1 + (arbitrary*totient))/encrypt;
    double msg = 12;
    double c = pow(msg,encrypt);
    double m = pow(c,decrypt);
    c=fmod(c,n);
    m=fmod(m,n);
 
    cout<<"Message data = "<<msg;
    cout<<"\n"<<"prime1 = "<<prime1;
    cout<<"\n"<<"prime2 = "<<prime2;
    cout<<"\n"<<"n = pq is "<<n;
    cout<<"\n"<<"totient = "<<totient;
    cout<<"\n"<<"encrypt = "<<encrypt;
    cout<<"\n"<<"decrypt = "<<decrypt;
    cout<<"\n"<<"Encrypted data = "<<c;
    cout<<"\n"<<"Original Message = "<<m;
 
    return 0;
}
