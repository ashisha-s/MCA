import java.util.Scanner;

public class Prime {
    void checkPrime(int n){
        if(n<=1){
            System.out.println("Not prime number");
            return;
        }
        for(int i=2;i<=Math.sqrt(n);i++){
            if(n%i==0){
                System.out.println("Not prime number");
                return;
            }
        }
        System.out.println("Prime Number");
        return;

    }
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        Prime p =new Prime();
        System.out.println("Enter the number ");
        int num=sc.nextInt();
        p.checkPrime(num);
        sc.close();
        
    }
}
