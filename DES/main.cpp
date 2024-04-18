#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <bitset>





using namespace std;


string HTS(string sHex)
		{
			string sReturn = "";
			for (int i = 0; i < sHex.length (); ++i)
			{
				switch (sHex [i])
				{
					case '0': sReturn.append ("0000"); break;
					case '1': sReturn.append ("0001"); break;
					case '2': sReturn.append ("0010"); break;
					case '3': sReturn.append ("0011"); break;
					case '4': sReturn.append ("0100"); break;
					case '5': sReturn.append ("0101"); break;
					case '6': sReturn.append ("0110"); break;
					case '7': sReturn.append ("0111"); break;
					case '8': sReturn.append ("1000"); break;
					case '9': sReturn.append ("1001"); break;
					case 'A': sReturn.append ("1010"); break;
					case 'B': sReturn.append ("1011"); break;
					case 'C': sReturn.append ("1100"); break;
					case 'D': sReturn.append ("1101"); break;
					case 'E': sReturn.append ("1110"); break;
					case 'F': sReturn.append ("1111"); break;
				}
			}
			return sReturn;
		}
string STH( const string input )
{
	const char* lut = "0123456789ABCDEF";
	size_t len = input.length();
	string output = "";

	output.reserve( 2 * len );

	for ( size_t i = 0; i < len; i++ )
	{
		const unsigned char c = input[i];
		output.push_back( lut[c >> 4] );
		output.push_back( lut[c & 15] );
	}

	return output;
}
string GetHexFromBin(string sBinary)
{
	string rest("0x"),tmp,chr = "0000";
	int len = sBinary.length()/4;
	chr = chr.substr(0,len);
	sBinary = chr+sBinary;
	for (int i=0;i<sBinary.length();i+=4)
	{
		tmp = sBinary.substr(i,4);
		if (!tmp.compare("0000"))
		{
			rest = rest + "0";
		}
		else if (!tmp.compare("0001"))
		{
			rest = rest + "1";
		}
		else if (!tmp.compare("0010"))
		{
			rest = rest + "2";
		}
		else if (!tmp.compare("0011"))
		{
			rest = rest + "3";
		}
		else if (!tmp.compare("0100"))
		{
			rest = rest + "4";
		}
		else if (!tmp.compare("0101"))
		{
			rest = rest + "5";
		}
		else if (!tmp.compare("0110"))
		{
			rest = rest + "6";
		}
		else if (!tmp.compare("0111"))
		{
			rest = rest + "7";
		}
		else if (!tmp.compare("1000"))
		{
			rest = rest + "8";
		}
		else if (!tmp.compare("1001"))
		{
			rest = rest + "9";
		}
		else if (!tmp.compare("1010"))
		{
			rest = rest + "A";
		}
		else if (!tmp.compare("1011"))
		{
			rest = rest + "B";
		}
		else if (!tmp.compare("1100"))
		{
			rest = rest + "C";
		}
		else if (!tmp.compare("1101"))
		{
			rest = rest + "D";
		}
		else if (!tmp.compare("1110"))
		{
			rest = rest + "E";
		}
		else if (!tmp.compare("1111"))
		{
			rest = rest + "F";
		}
		else
		{
			continue;
		}
	}
	return rest;
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




string shiftonce(string keyCOD){
    string shifted="";
        for(int i = 1; i < 28; i++){
            shifted += keyCOD[i];
        }
        shifted += keyCOD[0];
    return shifted;
}

string shifttwice(string keyCOD){
    string shifted="";
    for(int i = 0; i < 2; i++){
        for(int j = 1; j < 28; j++){
            shifted += keyCOD[j];
        }
        shifted += keyCOD[0];
        keyCOD= shifted;
        shifted ="";
    }
    return keyCOD;
}
string shiftonceR(string keyCOD){
    string shifted="";
        shifted += keyCOD[27];
        for(int i = 0; i < 28-1; i++){
            shifted += keyCOD[i];
        }

    return shifted;
}

string shifttwiceR(string keyCOD){
    string shifted="";
    for(int i = 0; i < 2; i++){
            shifted += keyCOD[27];
        for(int j = 0; j < 28-1; j++){
            shifted += keyCOD[j];
        }

        keyCOD= shifted;
        shifted ="";
    }
    return keyCOD;
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
string Xor(string a, string b){
	string result = "";
	int size = b.size();
	for(int i = 0; i < size; i++){
		if(a[i] != b[i]){
			result += "1";
		}
		else{
			result += "0";
		}
	}
	return result;
}
string Function(string L,string R,string sixteenkeys[])
{
int expansion[48] = {
	32,1,2,3,4,5,4,5,
	6,7,8,9,8,9,10,11,
	12,13,12,13,14,15,16,17,
	16,17,18,19,20,21,20,21,
	22,23,24,25,24,25,26,27,
	28,29,28,29,30,31,32,1
	};

	int s_box[8][4][16]=
	{{
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    },
    {
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    },
    {
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    },
    {
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    },
    {
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    },
    {
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    },
    {
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    },
    {
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    }};

	int permutation[32] = {
	16,7,20,21,29,12,28,17,
	1,15,23,26,5,18,31,10,
	2,8,24,14,32,27,3,9,
	19,13,30,6,22,11,4,25
	};
	for(int i=0; i<16; i++) {
    	string Rexpanded = "";

    	for(int i = 0; i < 48; i++) {
      		Rexpanded += R[expansion[i]-1];
    };
		string xored = Xor(sixteenkeys[i], Rexpanded);
		string res = "";

		for(int i=0;i<8; i++){

      		string Row= xored.substr(i*6,1) + xored.substr(i*6 + 5,1);
      		int row = convertBinaryToDecimal(Row);
      		string Col = xored.substr(i*6 + 1,1) + xored.substr(i*6 + 2,1) + xored.substr(i*6 + 3,1) + xored.substr(i*6 + 4,1);;
			int col = convertBinaryToDecimal(Col);
			int val = s_box[i][row][col];
			res += convertDecimalToBinary(val);
		}

		string perm ="";
		for(int i = 0; i < 32; i++){
			perm += res[permutation[i]-1];
		}
		xored = Xor(perm, L);
		L = xored;
		if(i < 15){
			string temp = R;
			R = xored;
			L = temp;
		}
	}
	return (L+R);
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

/////////////////////////////////////////////////////////////////////////////////////////////////////




int main()
{
cout<<"1-ENCRYPTION "<<endl;
cout<<"2-DECRYPTION "<<endl;
int choice;
cin>>choice;

	///////////////////////////////////////////////////////
	if(choice==1)
    {
        int pc1[56] = {
	57,49,41,33,25,17,9,
	1,58,50,42,34,26,18,
	10,2,59,51,43,35,27,
	19,11,3,60,52,44,36,
	63,55,47,39,31,23,15,
	7,62,54,46,38,30,22,
	14,6,61,53,45,37,29,
	21,13,5,28,20,12,4
	};


	string Key;
	cout<<"ENTER KEY: "<<endl;
	cin.ignore();
	getline(cin,Key);
	string KEY=HTS(Key);
	string keypc="";
    string sixteen_keys[16];

	for(int i=0;i<56;i++)
    {   int Val=pc1[i]-1;
        keypc+=KEY[Val];

    }

    string C= keypc.substr(0, 28);
	string D= keypc.substr(28, 28);

	int pc2[48] = {
	14,17,11,24,1,5,
	3,28,15,6,21,10,
	23,19,12,4,26,8,
	16,7,27,20,13,2,
	41,52,31,37,47,55,
	30,40,51,45,33,48,
	44,49,39,56,34,53,
	46,42,50,36,29,32
	};

	for(int i=0; i<16; i++){

		if(i == 0 || i == 1 || i==8 || i==15 ){
			C= shiftonce(C);
			D= shiftonce(D);
		}

		else{
			C= shifttwice(C);
			D= shifttwice(D);
		}

	string Mixedkey = C + D;
	string S16_key = "";

	for(int i = 0; i < 48; i++){
            int Val2=pc2[i]-1;
		S16_key += Mixedkey[Val2];
	}
	sixteen_keys[i] = S16_key;


	}



        int ip[64] = {
        58,50,42,34,26,18,10,2,
        60,52,44,36,28,20,12,4,
        62,54,46,38,30,22,14,6,
        64,56,48,40,32,24,16,8,
        57,49,41,33,25,17,9,1,
        59,51,43,35,27,19,11,3,
        61,53,45,37,29,21,13,5,
        63,55,47,39,31,23,15,7
        };
        int Fpermutation[64]= {
        40,8,48,16,56,24,64,32,
        39,7,47,15,55,23,63,31,
        38,6,46,14,54,22,62,30,
        37,5,45,13,53,21,61,29,
        36,4,44,12,52,20,60,28,
        35,3,43,11,51,19,59,27,
        34,2,42,10,50,18,58,26,
        33,1,41,9,49,17,57,25
        };
        string plaintext;
        cout<<"ENTER PLAINTEXT : "<<endl;
        getline(cin,plaintext);

        string PT= STB(plaintext);
        cout<<"plaintext in binary :"<<endl;
        cout<<PT<<endl;
        string Iperm = "";
        for(int i = 0; i < 64; i++){
                int Val3=ip[i]-1;
            Iperm += PT[Val3];
        }
        string left = Iperm.substr(0, 32);
        string right = Iperm.substr(32, 32);
        string Text=Function(left,right,sixteen_keys);
        string ciphertext ="";
        for(int i = 0; i < 64; i++){
            int Val4=Fpermutation[i]-1;
            ciphertext+= Text[Val4];
        }
        cout<<"CIPHER TEXT : "<<endl;
        cout<<ciphertext<<endl;
        cout<<"CIPHER IN HEXADECIMAL : "<<endl;
        cout<<GetHexFromBin(ciphertext)<<endl;
    }
    else if(choice==2)
    {

        int ip[64] = {
        58,50,42,34,26,18,10,2,
        60,52,44,36,28,20,12,4,
        62,54,46,38,30,22,14,6,
        64,56,48,40,32,24,16,8,
        57,49,41,33,25,17,9,1,
        59,51,43,35,27,19,11,3,
        61,53,45,37,29,21,13,5,
        63,55,47,39,31,23,15,7
        };
        int Fpermutation[64]= {
        40,8,48,16,56,24,64,32,
        39,7,47,15,55,23,63,31,
        38,6,46,14,54,22,62,30,
        37,5,45,13,53,21,61,29,
        36,4,44,12,52,20,60,28,
        35,3,43,11,51,19,59,27,
        34,2,42,10,50,18,58,26,
        33,1,41,9,49,17,57,25
        };
       int pc1[56] = {
	57,49,41,33,25,17,9,
	1,58,50,42,34,26,18,
	10,2,59,51,43,35,27,
	19,11,3,60,52,44,36,
	63,55,47,39,31,23,15,
	7,62,54,46,38,30,22,
	14,6,61,53,45,37,29,
	21,13,5,28,20,12,4
	};


	string Key;
	cout<<"ENTER KEY: "<<endl;
	cin.ignore();
	getline(cin,Key);
	string KEY=HTS(Key);
	string keypc="";
    string sixteen_keys[16];

	for(int i=0;i<56;i++)
    {   int Val=pc1[i]-1;
        keypc+=KEY[Val];

    }

    string C= keypc.substr(0, 28);
	string D= keypc.substr(28, 28);

	int pc2[48] = {
	14,17,11,24,1,5,
	3,28,15,6,21,10,
	23,19,12,4,26,8,
	16,7,27,20,13,2,
	41,52,31,37,47,55,
	30,40,51,45,33,48,
	44,49,39,56,34,53,
	46,42,50,36,29,32
	};

	for(int i=0; i<16; i++){

		if(i == 0 || i == 1 || i==8 || i==15 ){
			C= shiftonce(C);
			D= shiftonce(D);
		}

		else{
			C= shifttwice(C);
			D= shifttwice(D);
		}

	string Mixedkey = C + D;
	string S16_key = "";

	for(int i = 0; i < 48; i++){
            int Val2=pc2[i]-1;
		S16_key += Mixedkey[Val2];
	}
	sixteen_keys[i] = S16_key;


	}

        cout<<"ENTER CIPHER TEXT BINARY "<<endl;
	string CT;
	cin.ignore();
	getline(cin,CT);

	int i = 15;
	int j = 0;
	while(i > j)
	{
		string temp = sixteen_keys[i];
		sixteen_keys[i] = sixteen_keys[j];
		sixteen_keys[j] = temp;
		i--;
		j++;
	}

        string perm = "";
        for(int i = 0; i < 64; i++){
                int Val3=ip[i]-1;
            perm += CT[Val3];
        }
        string left = perm.substr(0, 32);
        string right = perm.substr(32, 32);
        string CText=Function(left,right,sixteen_keys);
        string plaintext ="";
        for(int i = 0; i < 64; i++){
            int Val4=Fpermutation[i]-1;
            plaintext+= CText[Val4];
        }
        cout<<"PLAIN TEXT : "<<endl;
        cout<<plaintext<<endl;

        cout<<BinaryStringToText(plaintext)<<endl;


    }



    return 0;
}
