import java.util.Scanner;

public class Parking{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int rep = in.nextInt();
        for(int i = 0; i < rep; i++){
            int numOfStores = in.nextInt();
            int [] coords = new int [numOfStores];
            int ttl = 0;
            for(int j = 0; j < numOfStores; j++){
                coords[j] = in.nextInt();
                ttl += coords[j];
            }
            int med = ttl/numOfStores, dist = 0;
            for(int j = 0; j < numOfStores; j++){
                dist += Math.max(coords[j], med) - Math.min(coords[j], med);
            }
            System.out.println(dist);
        }
    }
}