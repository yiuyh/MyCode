import java.util.*;
import java.math.BigInteger;

import java.util.*;

import java.math.BigInteger;

public class Main {
    static Scanner s=new Scanner(System.in);
    public static  BigInteger binary_find(BigInteger n){
        BigInteger l = new BigInteger("1");
        BigInteger two = new BigInteger("2");
        BigInteger r = new BigInteger("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
        BigInteger mid;
        while (l.compareTo(r) != 1) {
            mid = l.add(r);
            mid = mid.shiftRight(1);
//                System.out.println(mid);
            BigInteger ss = mid.multiply(mid);
            if (ss.compareTo(n) == -1) {
                l = mid.add(BigInteger.ONE);
            } else {
                r = mid.subtract(BigInteger.ONE);
            }
        }
        return l;
    }
    public static void main(String[] args){
        int T=s.nextInt();
        while (T>0) {
            T--;
            BigInteger n = s.nextBigInteger();
            if(n.equals(BigInteger.ONE)){
                System.out.println("Arena of Valor");
                continue;
            }
//            System.out.println(l);
            boolean e=false,f=false;
            BigInteger i=binary_find(n);
            if(i.multiply(i).equals(n)) e=true;
            i=binary_find(n.multiply(n.subtract(BigInteger.ONE)).divide(BigInteger.valueOf(2)));
            if(i.multiply(i).equals(n.multiply(n.subtract(BigInteger.ONE)).divide(BigInteger.valueOf(2)))) f=true;
            if(e && f) {
                System.out.println("Arena of Valor");
            } else if (e) {
                System.out.println("Hearth Stone");
            } else if (f) {
                System.out.println("Clash Royale");
            } else {
                System.out.println("League of Legends");
            }
        }
    }
}
