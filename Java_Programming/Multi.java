import java.util.Scanner;

public class Multi{
    void mul(int n){
        for(int i=1;i<=10;i++){
            System.out.println(n +"*"+ i+"="+(i*n));

        }
    }
    public static void main(String[] args){
        Scanner sc =new Scanner(System.in);
        Multi m =new Multi();
        System.out.println("Enter the number of multiplication table");
        int num=sc.nextInt();
        System.out.println("Multipliaction table of"+num);
        m.mul(num);
        sc.close();
    }

}