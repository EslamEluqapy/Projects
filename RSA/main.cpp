#include <iostream>
#include <cmath>
#include<vector>
#include <bitset>
#include <sstream>
#include <cstring>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>

using namespace std;
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

bool Chk=false;

void primaryCheck(unsigned P, unsigned Q)
{
    vector<unsigned> pFactor;
    for(unsigned  i=2;i<=static_cast<unsigned>(sqrt(P));i++)
    {
        if(P%i==0)
        {
            pFactor.push_back(i);
            pFactor.push_back(P/i);
        }
    }
    vector<unsigned> qFactor;
    for(unsigned  i=2;i<=static_cast<unsigned>(sqrt(Q));i++)
    {
        if(Q%i==0)
        {
            qFactor.push_back(i);
            qFactor.push_back(Q/i);
        }
    }
    if(pFactor.size()!=0 || qFactor.size()!=0 ||P==1 ||Q==1)
    {
        cout<<"non prime numbers please Enter two prime numbers : "<<endl;
        Chk=true;

    }
    else
        Chk=false;


}
 long S_M( long x,  long H,  long n){

	long h;
	unsigned long long r;
	int bin[32];
	int i;

	//r = x;
	i = 0;

	if(H==-1)
    {
        for(int i=1;i<100;i++)
        {
            if((i*x)%n==1)
                H=1;
                x=i;
                r=i;
        }
    }


	while( H > 0 ){

		if (H % 2 == 0){
			bin[i] = 0;
		}else{
			bin[i] = 1;
		}

		H = H/2;
		i++;

	}

	i--; //t-1

	while(i>0){

		r = (r * r) % n;

		if( bin[--i] == 1 ){
			r = (r * x) % n;
		}

	}

	return r;

}
string STB(string PT)
{
    string data="";
    for(int i=0;PT[i]!='\0';i++)
    {

        int c=PT[i];
        for(int j=7;j+1>0;j--)
        {
            if(c>=(1<<j))
            {
                c=c-(1<<j);
                data+="1";
            }
            else
                data+="0";
        }
    }
    return data;
}
string convertDecimalToBinary(int decimal)
{
	string binary;
    while(decimal != 0) {
		binary = (decimal % 2 == 0 ? "0" : "1") + binary;
		decimal = decimal/2;
	}
	while(binary.length() < 4){
		binary = "0" + binary;
	}
    return binary;
}
int convertBinaryToDecimal(string binary)
{
    int decimal = 0;
	int counter = 0;
	int size = binary.length();
	for(int i = size-1; i >= 0; i--)
	{
    	if(binary[i] == '1'){
        	decimal += pow(2, counter);
    	}
    counter++;
	}
	return decimal;
}
string BTS(string binaryString) {
    string text = "";
    stringstream sstream(binaryString);
    while (sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        text += char(bits.to_ulong());
    }
    return text;
}


int power(long long x, unsigned int y, int p)
{
    int res = 1;

    x = x % p;


    if (x == 0) return 0;

    while (y > 0)
    {

        if (y % 2)          // if Y =odd
            res = (res*x) % p;

        y = y/2;
        x = (x*x) % p;
    }
    return res;
}





long int Dcalculator(unsigned long long int E, unsigned long long int PHI)
{
    unsigned long long int D;
    for(int i=0;i<1000;i++)
    {
        if((i*E)%PHI==1)
            {
                D=i;
                break;
            }
    }
    return D;








}
long int en[100],temp[100];
void encrypt(char PT[],unsigned E,unsigned n)
{

    long int pt, ct, k, len;
    int i = 0;
    len = strlen(PT);
    while (i != len)
    {
        pt = PT[i];
        pt = pt - 96;
        k = 1;
        for (int  j = 0; j < E; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "\nTHE ENCRYPTED MESSAGE IS\n";
    for (i = 0; en[i] != -1; i++)
        printf("%c", en[i]);
}
void decrypt(unsigned D,unsigned n)
{
    long int pt, ct, k,m[100];
  int  i = 0;
    while (en[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (int j = 0; j < D; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    cout << "\nTHE DECRYPTED MESSAGE IS\n";
    for (i = 0; m[i] != -1; i++)
        printf("%c", m[i]);
}

int main()
{
    unsigned long long int P,Q,N,PHI,E,D;
    int m;
    cout<<"Enter two primary number P & Q :"<<endl;
    cin>>P>>Q;
    primaryCheck(P,Q);
    while(Chk!=false)
    {
       cin>>P>>Q;
       primaryCheck(P,Q);
    }
    N=P*Q;
    PHI=(P-1)*(Q-1);
    unsigned i=2;
    while(gcd(i,PHI)!=1)
        i++;
    E=i;
    //D=calcD(E,PHI);
    //D=S_M(E,-1,PHI);
    //D=power(E,-1,PHI);
    D=Dcalculator(E,PHI);
    cout<<"E = "<<E<<endl;
    cout<<"D = "<<D<<endl;
    cout<<"N = "<<N<<endl;
    cout<<"PHI = "<<PHI<<endl;
    char PT[100],CT[100],OT[100];
   // string PT,CT,OT;
    long int pT,msg,C;
    unsigned long long int  Y,Xe,X;
    string Pt,Ct ,Ot;
    cout<<"Enter plainText :"<<endl;
    cin>>PT;


    encrypt(PT,E,N);
    decrypt(D,N);





    //cout<<"Encrypted message = "<<CT<<endl;
   // cout<<"Decrypted message = "<<OT<<endl;
    /*msg=convertBinaryToDecimal(STB(PT));
    cout<<msg<<endl;
    Y=power(msg,E,N);
    cout<<"Y= "<<Y<<endl;
    string lol=convertDecimalToBinary(Y);

    CT=BTS(lol);
    cout<<"Encrypted message = "<<CT<<endl;
    X=power(Y,D,N);
    cout<<"X= "<<X<<endl;
    OT=BTS(convertDecimalToBinary(X));
    cout<<"Decrypted message = "<<OT<<endl;*/
   /* int O=0;
    for(O=0;PT[O]!='\0';O++)
    {
        msg=(int)PT[O];
    long int z=1;
    for(int i=0;i<E;i++)
    {
        z=z*msg;
        z=z%N;
    }
    C=z;
    CT[O]=(char)C;
    ///////////////////////////////


     z=1;
    for(int i=0;i<D;i++)
    {
        z=z*C;
        z=z%N;
    }
    msg=z;

    OT[O]=(char)msg;

    }

    CT[O]=-1;
    OT[O]=-1;
    cout<<"Encrypted message = "<<endl;
    for(int i=0;CT[i]!=-1;i++)
    {
        cout<<CT[i];
    }
    cout<<endl;
    cout<<"Decrypted message = "<<endl;
    for(int i=0;OT[i]!=-1;i++)
    {

        cout<<OT[i];
    }
    cout<<endl;*/



    return 0;
}



