import java.util.stream.IntStream;
import java.util.stream.LongStream;

import static java.lang.Math.*;
import static java.util.concurrent.ThreadLocalRandom.*;

public class Jpi {

  public static void main(String[] args) {
   long n = (long)pow(10,9);
   long start = System.nanoTime();
    double pi = LongStream.range(0, n)
        .map((a) -> (pow(current().nextDouble() - 1 , 2)  + pow(current().nextDouble() - 1 , 2)) <= 1 ? 1 : 0)
        .parallel()
        .sum() * 4.0 / n;
    long stop = System.nanoTime();
    System.out.println(pi +  " Time: " + (stop - start)/pow(10, 9));
  }

}
