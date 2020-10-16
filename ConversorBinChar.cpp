#include <stdio.h>
#include <iostream>
using namespace std;

#define getbit(by, pos)  ((by >> pos)&0x1)

void byte2bits(char c, char* s)
{
    int i = 7;
    while(i >= 0)
        *s++ = '0' + getbit(c, i--);
    *s = 0;
}

int main(int argc, char* argv[])
{
    char bits[9];
	char c;
    string palavra;
    char pont;
    //pont=(char)palavra;
    
    cout<<("Digite uma frase\n");
    cin>>(pont);
    
    byte2bits(pont, bits);
    cout<< "No sistema binario\n";
	cout<< bits;
    return 0;
}
