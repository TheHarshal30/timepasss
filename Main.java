import java.util.Scanner;
public class Main{
    static double solve(int x, int a, int t, int v, int i){
            return (0.5 * a * Math.pow(t,2)) + (v*t) + (x*i);
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the value of X: ");
        int x = sc.nextInt();
        System.out.println("Enter the value of A: ");
        int a = sc.nextInt();
        System.out.println("Enter the value of T: ");
        int t = sc.nextInt();
        System.out.println("Enter the value of V: "); 
        int v = sc.nextInt();
        System.out.println("Enter the value of I: "); 
        int i = sc.nextInt();
        double ans = solve(x,a,t,v,i);
        System.out.println("Ans: ");
        System.out.println(ans);
        sc.close();
    }
    
}