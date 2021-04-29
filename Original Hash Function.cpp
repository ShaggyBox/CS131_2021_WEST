//Name: Justin Reyes
//Language: C++
//Project Description: This program acts as a hash function for string inputs. 
//              This is a hash algorithm that I created on my own with a few influences from SHA-256.
//              However, this is definitely nowhere near as complex/secure as other hashing algorithms
//              that already exist, so please don't use this for anything important.

//              This was made to deepen my own understanding of hash functions and is more like a
//              cheap imitation/combination of hashes from things I read online/saw from videos.
//              It works well on the surface level but if you see any problems please point them out!

#include <iostream>
#include <string>

using namespace std;

string binToHex(string b)                                       //converts binary to hexadecimal
{
    reverse(b.begin(), b.end());
    string hex = "";

    int i = 0;
    while (i < b.length())
    {
        string s = b.substr(i, 4);

        if (s == "0000") hex += "0";
        else if (s == "0001") hex += "1";
        else if (s == "0010") hex += "2";
        else if (s == "0011") hex += "3";
        else if (s == "0100") hex += "4";
        else if (s == "0101") hex += "5";
        else if (s == "0110") hex += "6";
        else if (s == "0111") hex += "7";
        else if (s == "1000") hex += "8";
        else if (s == "1001") hex += "9";
        else if (s == "1010") hex += "A";
        else if (s == "1011") hex += "B";
        else if (s == "1100") hex += "C";
        else if (s == "1101") hex += "D";
        else if (s == "1110") hex += "E";
        else hex += "F";
        i += 4;
    }

    return hex;
}

int chartoASCII(string s, int i)                                //converts a character to its ASCII value
{
    int val = int(s[i]);
    return val;
}

int addASCII(string s)                                          //adds up the total ASCII values of every character in a string
{
    int total = 0;
    for (int i = 0; i < s.length(); i++)
    {
        total += chartoASCII(s, i);
    }
    return total;
}

string chartoBinary(int n)                                      //converts a character to its binary value
{
    string r;
    while (n != 0) 
    { 
        r = (n % 2 == 0 ? "0" : "1") + r; 
        n /= 2; 
    }
    return r;
}

string stringtoBinary(string s)                                 //converts an entire string to binary (per character)
{
    string bin = "";
    for (int i = 0; i < s.length(); i++)
    {
        bin += chartoBinary(chartoASCII(s, i));
    }
    return bin;
}

string padBin(string b)                                         //pads a binary value by adding 0 to the end until it has a number of bits equal to a multiple of 32
{
    string pad = b;
    while (pad.length() % 32 != 0)
    {
        pad += "0";
    }
    return pad;
}

void leftRotate(string& s, int d)                               //rotates a string leftwise by d amount
{
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
}

void rightRotate(string& s, int d)                              //rotates a string rightwise by d amount
{
    leftRotate(s, s.length() - d);
}

string XOR(string a, string b, int n)                           //does XOR for two binary values
{                         
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            ans += "0";
        else
            ans += "1";
    }
    return ans;
}

string compressBin(string b)                                    //compresses a binary value to 32 bits by separating it to blocks of 32 bits and using XOR for every block
{
    string comp1 = b.substr(0, 32);
    string comp2 = b.substr(32, 32);
    string compF = XOR(comp1, comp2, 32);
    for (int i = 64; i < b.length(); i+=32)
    {
        comp1 = b.substr(i, 32);
        compF = XOR(comp1, compF, 32);
    }
    return compF;
}

string myHash(string text)                                      //uses previous functions in a certain order to "hash" a string
{
    int t = addASCII(text);                                     //adds up the ASCII values of the string's characters
    string gB1 = padBin(stringtoBinary(text));                  //gets the binary value of the string padded to a multiple of 32

    if (gB1.length() > 32) gB1 = compressBin(gB1);              //if the binary has more than 32 bits (64, 96, 128, etc), then it uses my compression function

    string gB2 = gB1 + "";                                      //assigns the original binary value to another string called gB2
    string gB3 = gB1 + "";                                      //assigns the original binary value to another string called gB3

    rightRotate(gB2, gB2.length() % 3);                         //rotates gB2 by its length % 3
    rightRotate(gB2, t % 5);                                    //rotates gB2 by its ASCII total % 5
    leftRotate(gB3, gB3.length() % 7);                          //rotates gB3 by its length % 7
    leftRotate(gB3, t % 11);                                    //rotates gB3 by its ASCII total % 11           *These values are the first 4 prime numbers following 2

    string gB4 = XOR(gB2, gB3, gB1.length());                   //creates a new binary value that is gB2 XOR gB3 = gB4
    string gB5 = XOR(gB1, gB4, gB4.length());                   //creates a new binary value that is gB4 XOR gB1 = gB5

    string hash = binToHex(gB5);                                //converts the gB5 binary to hexadecimal, which is the final hash returned

    return hash;
}

int main()
{
    string g = "Justin $150.00";
    string h = "Bustin $150.00";
    string i = "Dustin $150.00";
    string j = "Justin Sent $200.00 To Alex";
    string k = "Justin Sent $300.00 To Alex";
    string a = "";

    cout << "Test Cases From Main:\n";
    cout << myHash(g) << "\n";
    cout << myHash(h) << "\n";
    cout << myHash(i) << "\n";
    cout << myHash(j) << "\n";
    cout << myHash(k) << "\n";
    cout << "\n";

    cout << "Enter your own message to be hashed: ";
    cin >> a;
    cout << "Hash: " << myHash(a) << "\n";
}
