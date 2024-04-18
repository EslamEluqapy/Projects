package elgamal;

import java.util.Random;
import java.util.Scanner;

public class ElGamal {

    static boolean PCheck(double P) {
        boolean prime = true ;

        if (P <= 1) {
            prime = false;

            return prime;
        } else {
            for (int i = 2; i <= P / 2; i++) {
                if ((P % i) == 0) {
                    prime = false;

                    break;
                }
            }

            return prime;
        }
    }

   /* static int privKey(int P) {
        Random rand = new Random();
        int pr = 2 + rand.nextInt(P - 4);
        return pr;
    }*/

    static double Calc(double down, double up, double P) {
        double calc=1;
        for(int i=1;i<=up;++i)
        {
            calc= (calc*down);
        }

        return calc%P;

    }
    static double Calckm(double down, double up, double P) {
        double calc = ((double) Math.pow(down, up));
        double Calc=calc% P;
        return Calc;

    }

    static double Encrypt(double x, double KM, double P) {
        double y = (x * KM) % P;
        return y;
    }
    static double KMinverse(double KM, double P)
    {

        for (int x = 1; x < P; x++)
            if (((KM%P) * (x%P)) % P == 1)
                return x;
        return 1;
    }
    static double Decrypt(double y, double KM,double P) {

        double x = (y * KM) % P;
        return x;
    }

    public static void main(String[] args) {
        //System.out.println(checkForPrime(29));
        //System.out.println(privKey(29));
        //System.out.println(Calc(7,5,29));
        //System.out.println(Encrypt(26,16,29));
        //System.out.println(Decrypt(10,3,29,12));
        double P, Alpha, x;
        int sw;
        System.out.println("1-Encryption***  2-Decryption");
        Scanner sc = new Scanner(System.in);
        sw = sc.nextInt();
        System.out.println("Enter P");
        P = sc.nextDouble();


        switch (sw) {
            case 1:
                boolean check =PCheck(P);
                if(check==false)
                {
                    System.out.println("Please enter a prime number!");
                    break;
                }
                System.out.println("Enter Alpha");
                Alpha = sc.nextDouble();
                System.out.println("enter private key=d ");
                double d = sc.nextDouble();
                double Beta = Calc(Alpha, d, P);
                System.out.print("Beta is equal to ");
                System.out.println(Beta);
                System.out.println("enter your ephemeral=i ");
                double i = sc.nextDouble();
                double KE = Calc(Alpha, i, P);
                System.out.print("KE is equal to ");
                System.out.println(KE);
                double KM = Calckm(Beta, i, P);
                System.out.print("km is equal to ");
                System.out.println(KM);
                System.out.println("Enter your message to encrypt");
                x = sc.nextDouble();
                double y = Encrypt(x, KM, P);
                System.out.print("your cipher text is equal to ");
                System.out.println(y);
                break;
            case 2:
                boolean Check =PCheck(P);
                if(Check==false)
                {
                    System.out.println("Please enter a prime number!");
                    break;
                }

                System.out.println("Enter Alpha");
                Alpha = sc.nextDouble();
                double D,
                        cipher,
                        Ke;
                System.out.println("enter private key=d");
                D = sc.nextDouble();
                System.out.println("enter compute KE");
                Ke = sc.nextDouble();
                double Km=Calc(Ke,D,P);
                double newKM=KMinverse(Km,P);
                System.out.println("km inverse is "+newKM);

                System.out.println("enter your cipher text");
                cipher = sc.nextDouble();
                double ans = Decrypt(cipher, newKM,P);
                System.out.print("your plain text is equal to ");
                System.out.println(ans);

        }



    }



}