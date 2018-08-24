import scala.math.random

import org.apache.spark.sql.SparkSession

/** Computes an approximation to pi */
object SparkPi {
  def main(args: Array[String]) {
    val spark = SparkSession
      .builder
      .appName("Spark Pi")
      .getOrCreate()
    val slices = if (args.length > 0) args(0).toInt else 2
    val n = math.min(Math.pow(10,9) * slices, Int.MaxValue).toInt // avoid overflow
    val start = System.nanoTime
    val count = spark.sparkContext.parallelize(1 until n, slices).map { i =>
      val x = random * 2 - 1
      val y = random * 2 - 1
      if (x*x + y*y <= 1) 1 else 0
    }.reduce(_ + _)
    val stop = System.nanoTime
    println("Pi is roughly " + 4.0 * count / (n - 1))
    println("Time: " + (stop - start)/Math.pow(10,9) + " s")
    spark.stop()
  }
}

