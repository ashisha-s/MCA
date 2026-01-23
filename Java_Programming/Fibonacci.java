import java.util.Scanner;

public class Fibonacci {
    static int findFib(int n){
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        else 
            return findFib(n-1)+findFib(n-2);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number:");
        int num = sc.nextInt();        
        System.out.println(num+"th Fibonacci number:"+findFib(num));
        
        sc.close();
    }
}
