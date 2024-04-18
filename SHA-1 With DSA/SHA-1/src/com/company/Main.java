package com.company;

import java.util.Scanner;

public class Main {

    public static String Padding(String input) {

        StringBuilder result = new StringBuilder();
        char[] chars = input.toCharArray();
        for (char aChar : chars) {
            result.append(
                    String.format("%8s", Integer.toBinaryString(aChar))   // char -> int, auto-cast
                            .replaceAll(" ", "0")                         // zero pads
            );
        }
        int Olength;
        Olength= result.length();
        result.append(1);
        int length;
        length= result.length();
        //System.out.println(length);
        int zAppend=448-length;
        for(int i=0;i<zAppend;i++)
        {
            result.append(0);
        }
        length= result.length();
        //System.out.println(length);
        int  blength=(Integer.toBinaryString(Olength)).length();
        int remaind=64-blength;
        for(int i=0;i<remaind;i++)
        {
            result.append(0);
        }
        result.append(Integer.toBinaryString(Olength));
        length= result.length();
        //System.out.println(length);


        return result.toString();

    }


    public static String[] Words16(String padded){
        String[] Words = new String[16];

        int R=32,k=0,j;
        char[] chars = padded.toCharArray();
        for(int i=0;i<16;i++)
        {
            StringBuilder result = new StringBuilder();
            for( j=k;j<R;j++)
            {
                result.append(chars[j]);
            }
            k=k+32;
            R=R+32;
            Words[i]= String.valueOf(result);
        }

        return  Words;
    }
    static String  xoring(String a, String b, int n){
        String ans = "";


        for (int i = 0; i < n; i++)
        {

            if (a.charAt(i) == b.charAt(i))
                ans += "0";
            else
                ans += "1";
        }
        return ans;
    }
    public static String[] Words80(String[] Words){
        String[] Words80 = new String[80];
        for(int i=0;i<16;i++)
        {
            Words80[i]=Words[i];
        }
        //i =16
        //w[i]=w[i-3] xor w[i-8] xor w[i-14] xor w[i-16]
        String one,two ,result;
        for(int j=16;j<80;j++)
        {
            one=xoring(Words80[j-3],Words80[j-8],32);
            two=xoring(Words80[j-14],Words80[j-16],32);
            result=xoring(one,two,32);
            StringBuffer s = new StringBuffer(result);
            char c = s.charAt(0);
            s.append(c);
            s.deleteCharAt(0);
            String R1 = s.toString();
            Words80[j]=R1;
            //result = 00100010000000100001000100001001
            //wanted = 01000100000001000010001000010010

        }


        return Words80;

    }

    public static String leftrotate(String str, int d)
    {
        String ans = str.substring(d) + str.substring(0, d);
        return ans;
    }
    public static String AND(String s1, String s2)
    {
        StringBuilder Res = new StringBuilder();
        char[] S1 = s1.toCharArray();
        char[] S2= s2.toCharArray();
        System.out.println(S1[0]);
        System.out.println(S2[1]);
        for(int i=0;i<32;i++)
        {
            //"01100111010001010010001100000001","11101111110011011010101110001001"
            if(S1[i]=='1' && S2[i]=='1')
            {
                    Res.append(1);
            }
            else
            {
                Res.append(0);
            }
        }
        String Result=Res.toString();

        return Result;
    }
    public static String OR(String s1, String s2)
    {
        StringBuilder Res = new StringBuilder();
        char[] S1 = s1.toCharArray();
        char[] S2= s2.toCharArray();
        for(int i=0;i<32;i++)
        {
            if(S1[i]=='1' || S2[i]=='1')
            {
                Res.append(1);
            }
            else
            {
                Res.append(0);
            }
        }
        String Result=Res.toString();

        return Result;
    }
    public static String NOT(String s1)
    {
        StringBuilder Res = new StringBuilder();
        char[] S1 = s1.toCharArray();

        for(int i=0;i<32;i++)
        {
            if(S1[i]=='1')
            {
                Res.append(0);
            }
            else
            {
                Res.append(1);
            }
        }
        String Result=Res.toString();

        return Result;
    }

    public static String[] Function1(String B,String C,String D)
    {
        String[] F_K = new String[2];
        String F,K,V1,V2,Not;
        V1=AND(B,C);
        Not=NOT(B);
        V2=AND(Not,D);
        F=OR(V1,V2);
        K="01011010100000100111100110011001";
        F_K[0]=F;
        F_K[1]=K;

        return F_K;
    }
    public static String[] Function2(String B,String C,String D)
    {
        String K="01101110110110011110101110100001";
        String[] F_K = new String[2];
        String V1,F;
        V1=xoring(B,C,32);
        F=xoring(V1,D,32);
        F_K[0]=F;
        F_K[1]=K;
        return F_K;
    }
    public static String[] Function3(String B,String C,String D)
    {   String K="10001111000110111011110011011100";
        String[] F_K = new String[2];
        String F,V1,V2,V3,Y1;
        V1=AND(B,C);
        V2=AND(B,D);
        V3=AND(C,D);
        Y1=OR(V1,V2);
        F=OR(Y1,V3);
        F_K[0]=F;
        F_K[1]=K;
        return F_K;
    }

    public static String[] Function4(String B,String C,String D)
    {
        String K="11001010011000101100000111010110";
        String[] F_K = new String[2];
        String F,V1;
        V1=xoring(B,C,32);
        F=xoring(V1,D,32);
        F_K[0]=F;
        F_K[1]=K;
        return F_K;
    }
    public static String addBinary(String s1, String s2) {
        StringBuilder sb = new StringBuilder();
        int i = s1.length() - 1, j = s2.length() -1, carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (j >= 0) sum += s2.charAt(j--) - '0';
            if (i >= 0) sum += s1.charAt(i--) - '0';
            sb.append(sum % 2);
            carry = sum / 2;
        }
        if (carry != 0) sb.append(carry);
        return sb.reverse().toString();
    }

    public static String CF(String[] Words80)
    {
        String[] Hashed = new String[5];
        String TEMP;
        String h0 = "01100111010001010010001100000001";
        String h1 = "11101111110011011010101110001001";
        String h2 = "10011000101110101101110011111110";
        String h3 = "00010000001100100101010001110110";
        String h4 = "11000011110100101110000111110000";
        String A=h0,B=h1,C=h2,D=h3,E=h4;
        for(int i=0;i<20;i++)
        {
            String[] F_K= Function1(B,C,D);
            String V1,V2,V3;
           V1=addBinary(leftrotate(A,5),F_K[0]);
           V2=addBinary(E,F_K[1]);
            V3=addBinary(V1,V2);
            TEMP=addBinary(V3,Words80[i]);
            StringBuffer s = new StringBuffer(TEMP);
            while(s.length()>32)
            {

               s.deleteCharAt(0);
            }
            TEMP=s.toString();

            E=D;
            D=C;
            C=leftrotate(B,30);
            B=A;
            A=TEMP;
        }
        for(int i=20;i<40;i++)
        {
            String[] F_K= Function2(B,C,D);
            String V1,V2,V3;
            V1=addBinary(leftrotate(A,5),F_K[0]);
            V2=addBinary(E,F_K[1]);
            V3=addBinary(V1,V2);
            TEMP=addBinary(V3,Words80[i]);
            StringBuffer s = new StringBuffer(TEMP);
            while(s.length()>32)
            {

                s.deleteCharAt(0);
            }
            TEMP=s.toString();

            E=D;
            D=C;
            C=leftrotate(B,30);
            B=A;
            A=TEMP;


        }
        for(int i=40;i<60;i++)
        {
            String[] F_K= Function3(B,C,D);
            String V1,V2,V3;
            V1=addBinary(leftrotate(A,5),F_K[0]);
            V2=addBinary(E,F_K[1]);
            V3=addBinary(V1,V2);
            TEMP=addBinary(V3,Words80[i]);
            StringBuffer s = new StringBuffer(TEMP);
            while(s.length()>32)
            {

                s.deleteCharAt(0);
            }
            TEMP=s.toString();

            E=D;
            D=C;
            C=leftrotate(B,30);
            B=A;
            A=TEMP;


        }
        for(int i=60;i<80;i++)
        {
            String[] F_K= Function4(B,C,D);
            String V1,V2,V3;
            V1=addBinary(leftrotate(A,5),F_K[0]);
            V2=addBinary(E,F_K[1]);
            V3=addBinary(V1,V2);
            TEMP=addBinary(V3,Words80[i]);
            StringBuffer s = new StringBuffer(TEMP);
            while(s.length()>32)
            {

                s.deleteCharAt(0);
            }
            TEMP=s.toString();

            E=D;
            D=C;
            C=leftrotate(B,30);
            B=A;
            A=TEMP;


        }
        h0=addBinary(h0,A);
        StringBuffer s = new StringBuffer(h0);
        while(s.length()>32)
        {

            s.deleteCharAt(0);
        }
        h0=s.toString();
        h1=addBinary(h1,B);

         s = new StringBuffer(h1);
        while(s.length()>32)
        {

            s.deleteCharAt(0);
        }
        h1=s.toString();
        h2=addBinary(h2,C);
        s = new StringBuffer(h2);
        while(s.length()>32)
        {

            s.deleteCharAt(0);
        }
        h2=s.toString();
        h3=addBinary(h3,D);
        s = new StringBuffer(h3);
        while(s.length()>32)
        {

            s.deleteCharAt(0);
        }
        h3=s.toString();
        h4=addBinary(h4,E);
        s = new StringBuffer(h4);
        while(s.length()>32)
        {

            s.deleteCharAt(0);
        }
        h4=s.toString();
        StringBuilder Res = new StringBuilder();
        Res.append(h0);
        Res.append(h1);
        Res.append(h2);
        Res.append(h3);
        Res.append(h4);
        String HASHED=Res.toString();

        return HASHED;
    }
    public static String bitsToHexConversion(String bitStream){

        int byteLength = 4;
        int bitStartPos = 0, bitPos = 0;
        String hexString = "";
        int sum = 0;

        // pad '0' to make input bit stream multiple of 4

        if(bitStream.length()%4 !=0){
            int tempCnt = 0;
            int tempBit = bitStream.length() % 4;
            while(tempCnt < (byteLength - tempBit)){
                bitStream = "0" + bitStream;
                tempCnt++;
            }
        }

        // Group 4 bits, and find Hex equivalent

        while(bitStartPos < bitStream.length()){
            while(bitPos < byteLength){
                sum = (int) (sum + Integer.parseInt("" + bitStream.charAt(bitStream.length()- bitStartPos -1)) * Math.pow(2, bitPos)) ;
                bitPos++;
                bitStartPos++;
            }
            if(sum < 10)
                hexString = Integer.toString(sum) + hexString;
            else
                hexString = (char) (sum + 55) + hexString;

            bitPos = 0;
            sum = 0;
        }
        return hexString;
    }
    public static int binaryTodecimal(String s){
        int i= -1;
        char[] str = s.toCharArray();
        int dec_val= 0;

        for (int j=str.length-1; j>=0 ;j-- ){
            int k= Integer.valueOf(str[j]) - '0';
            i = i+1;
            dec_val += k*(Math.pow(2, i));

        }
        return dec_val;
    }

    public static double[] ARRofHashed(String Hashed)
    {
        double[] IntArr = new double[10];
        int k=0,R=16;
        char[] chars = Hashed.toCharArray();
        for(int i=0;i<10;i++)
        {
            StringBuilder result = new StringBuilder();
            for(int j=k;j<R;j++)
            {
                result.append(chars[j]);
            }
            k=k+16;
            R=R+16;
            IntArr[i]=binaryTodecimal(String.valueOf(result)) ;
        }
        return IntArr;

    }
    public static boolean checkForPrime(double P) {
        boolean isItPrime = true ;

        if (P <= 1) {
            isItPrime = false;

            return isItPrime;
        } else {
            for (int i = 2; i <= P / 2; i++) {
                if ((P % i) == 0) {
                    isItPrime = false;

                    break;
                }
            }

            return isItPrime;
        }
    }
    public static double Calc(double down, double up, double P) {
        double calc = ((double) Math.pow(down, up));
        double Calc=calc% P;
        return Calc;

    }
    public static double modInverse(double KE, double P)
    {

        for (int x = 1; x < P; x++)
            if (((KE%P) * (x%P)) % P == 1)
                return x;
        return 1;
    }


    public static void main(String[] args) {
	// write your code here
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Text you want to be Hashed by SHA-1 ? ");
        String input = sc.nextLine();
        System.out.println("Generating code please wait .....");
        String result = Padding(input);
        String[] Words = Words16(result);
        String[] Words80=Words80(Words);
        String Hashed=CF(Words80);
        String HexHash=bitsToHexConversion(Hashed);
        System.out.println("..........................................");
        System.out.println("******************************************");
        System.out.println("..........................................");
        System.out.println("..........................................");
        System.out.println("******************************************");
        System.out.println("..........................................");
        System.out.println("Generating code please wait .....");
        System.out.println("Code Generated Thanks for Waiting..");
        System.out.println("How do you want your Hashed SHA-1 Value :-");
        System.out.println("1-Binary                   2-Hexadecimal");
        int C=sc.nextInt();
        if(C==1)
        {
            System.out.println(Hashed);
        }
        else
        {
            System.out.println(HexHash);
        }
        double[] SHA1ARR=ARRofHashed(Hashed);


        double P,q,Alpha,d,B,Ke,r,KeInv;
        double[] s=new double[10];
        double[] w=new double[10];
        double[] u1=new double[10];
        double[] u2=new double[10];
        double[] Alu1=new double[10];
        double[] Bu2=new double[10];
        double[] v=new double[10];

        System.out.println("Enter your Prime number");
        P=sc.nextDouble();
        boolean A=checkForPrime(P);
        if(A==false)
            System.out.println("Please enter a Prime number");
        while(A==true)
        {
            System.out.println("Enter Q");
            q=sc.nextDouble();
            System.out.println("Enter Alpha");
            Alpha=sc.nextDouble();
            System.out.println("Enter Private Key=d");
            d=sc.nextDouble();
            B=Calc(Alpha,d,P);
            System.out.println("B equal");
            System.out.println(B);
            System.out.println("Enter KE");
            Ke=sc.nextDouble();
            KeInv=modInverse(Ke,q);
            r=(Calc(Alpha,Ke,P))%q;
            System.out.println("r equal");
            System.out.println(r);
            for(int i=0;i<10;i++)
            {
                s[i]=((SHA1ARR[i]+(d*r))*KeInv)%q;
            }

            System.out.println("s equal");
            for(int i=0;i<10;i++)
            {
                System.out.println(s[i]);
            }

            for(int i=0;i<10;i++)
            {
                w[i]=modInverse(s[i],q);
            }
            System.out.println("w equal");
            for(int i=0;i<10;i++)
            {
                System.out.println(w[i]);
            }

            for(int i=0;i<10;i++)
            {
                u1[i]=(w[i]*SHA1ARR[i])%q;
            }


            System.out.println("u1 equal");
            for(int i=0;i<10;i++)
            {
                System.out.println(u1[i]);
            }

            for(int i=0;i<10;i++)
            {
                u2[i]=(w[i]*r)%q;
            }
            System.out.println("u2 equal");
            for(int i=0;i<10;i++)
            {
                System.out.println(u2[i]);
            }
            for(int i=0;i<10;i++)
            {
                Alu1[i]=Calc(Alpha,u1[i],P);
            }

            for(int i=0;i<10;i++)
            {
                Bu2[i]=Calc(B,u2[i],P);
            }
            for(int i=0;i<10;i++)
            {
                v[i]=((Alu1[i] * Bu2[i])%P)%q;
            }



            System.out.println("v equal");

                System.out.println(v[0]);
                if(v[0]==r)
                {
                    System.out.println("Valid");
                }
                else
                    System.out.println("Invalid");



            A=false;

        }






    }
}
