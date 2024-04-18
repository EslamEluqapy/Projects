import static com.company.Main.CF;
import static com.company.Main.Padding_convertStringToBinary;
import static com.company.Main.Words16;
import static com.company.Main.Words80;
import static com.company.Main.bitsToHexConversion;
import java.util.Scanner;

public class HMAC {


    public static String convertStringToBinary(String input) { 

        StringBuilder result = new StringBuilder();
        char[] chars = input.toCharArray();
        for (char aChar : chars) {
            result.append(
                    String.format("%8s", Integer.toBinaryString(aChar))   
                            .replaceAll(" ", "0")                         
            );
        }
        return result.toString();

    }

    static int findRandom()
    {
        int num = (1 + (int)(Math.random() * 100)) % 2;
        return num;
    }


    static String generateBinaryString(int N)
    {


        String S = "";

        for(int i = 0; i < N; i++)
        {
            int x = findRandom();
            String s =  String.valueOf(x);
        }

        return S;
    }
    static int iPad()
    {
        String i = "00110110";
         String ipad=i.repeat(20) ;
         int intIpad=-1;
            try {
                intIpad= Integer.parseInt(ipad, 2);
            } catch (NumberFormatException e) {
            }
            
           return intIpad;
        
    }
    static int oPad()
    {
        String o = "01011100";
            String opad=o.repeat(20) ;

            int intOpad=-1;
            try {
                intOpad= Integer.parseInt(opad, 2);
            } catch (NumberFormatException e) {
            }
            return intOpad;
    }
    static int kPlus()
    {
        String kPlus = generateBinaryString(160);
            int intKPlus = -1;
            try {
                intKPlus = Integer.parseInt(kPlus, 2);
            } catch (NumberFormatException e) {
            }
            return intKPlus;
    }

    /**
     *
     * @param args
     */
    public static void main(String[] args) {
        int Kplus,Ipad,Opad,BSi,BSo;   
        String message, binaryMessage,Si,conca, Si_x,So,So_and_Si_X,Cipher,result,res2 ;
        Scanner sc = new Scanner(System.in);
            System.out.println("please enter your message : ");
             message =  sc.next();
             binaryMessage=convertStringToBinary(message);
            Kplus=kPlus();
           Ipad=iPad();
            BSi = Ipad^Kplus;
            Si=Integer.toBinaryString(BSi);
             conca =binaryMessage+Si;
            result= Padding_convertStringToBinary(conca);
            String[] Words = Words16(result);
        String[] Words80=Words80(Words);
         Si_x=CF(Words80);
             Opad=oPad();
            BSo = Opad^Kplus;
             So=Integer.toBinaryString(BSo);
             So_and_Si_X= So + Si_x;
            res2 =Padding_convertStringToBinary(So_and_Si_X);
            String[] Words2 = Words16(res2);
            String[] Words802=Words80(Words2);
            Cipher=CF(Words802);
            System.out.println(bitsToHexConversion(Cipher));
            


        }

}