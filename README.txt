sbt clean package && $SPARK_HOME/bin/spark-submit --class "SparkPi" target/scala-2.11/spark-meme_2.11-1.0.jar 2 
9 Time: 402.451816785 s

javac Jpi.java && java Jpi
9  3.141632672   Time: 3.590125666
11 3.14159618904 Time: 359.160012844

runghc hspi.hs
mermoy leak

go run gopi.go
9  3.141758292 2m18.763387519s

kotlinc -jvm-target 1.8 ktpi2.kt -d  ktpi2.jar && kotlin -classpath ktpi2.jar Ktpi2Kt
9  3.141626684  Time: 3.612536581
10 3.1415933416 Time: 36.826661784

scalac ScalaPi2.scala && scala ScalaPi2
or scala scalapi.scala
OutOmMemoryError by 10^8

cd pimc/
cargo build --release && cargo run --release
9 3.141585792 Time: 29.12

node
9 3.141584332 'Time:' 31

pypy
9 3.141525904 Time: 0:00:39.799005

g++ -std=c++14 -o cpppi cpppi.cpp && ./cpppi
9 3.14159 Time: 3.46114
g++ -std=c++14 -o cpppi2 cpppi2.cpp && ./cpppi2
9 3.14159e+09 Time: 293.627

elixir elixirpi.exs   
memory leak

cd cljpi/
lein uberjar && java -jar target/uberjar/cljpi-0.1.0-SNAPSHOT-standalone.jar
9 3.1415853 Time: 119.215570998
