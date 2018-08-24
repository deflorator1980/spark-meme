import java.util.stream.LongStream
import java.lang.Math.*
import java.util.concurrent.ThreadLocalRandom.*
import java.lang.* 

fun main(args: Array<String>) {
    val n = pow(10.0, 9.0).toLong()
    val start = System.nanoTime()
    val pi = LongStream.range(0, n)
        .map { _ -> if (pow(current().nextDouble() - 1, 2.0) + pow(current().nextDouble() - 1, 2.0) <= 1) 1 else 0 }
        .parallel()
        .sum() * 4.0 / n
    val stop = System.nanoTime()
    println(pi.toString() + " Time: " + (stop - start) / pow(10.0, 9.0))
}
