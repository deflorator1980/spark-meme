sbt clean package && $SPARK_HOME/bin/spark-submit --class "SparkPi" target/scala-2.11/spark-meme_2.11-1.0.jar 2 
10^9 Time: 402.451816785 s

'javac Jpi.java && java Jpi' or on 14+: 'java Jpi.java' 
10^9  3.141632672   Time: 3.590125666
10^11 3.14159618904 Time: 359.160012844
parallel:
10^11 3.14158935176 Time: 182.412453207
graal:
10^9  3.141592744 Time: 1.677379474
10^11 3.14159017888 Time: 112.82083289
graal-native:
javac Jpi.java && native-image Jpi && ./jpi
10^9: 3.141549432 Time: 4.601393145


haskell_correct:
if folder: stack run
10^9   Time: 23.3 

runghc hspi.hs
mermoy leak

go run gopi.go
10^9  3.141758292 2m18.763387519s

kotlinc -jvm-target 1.8 ktpi2.kt -d  ktpi2.jar && kotlin -classpath ktpi2.jar Ktpi2Kt
10^9  3.141626684  Time: 3.612536581
10 3.1415933416 Time: 36.826661784

scalac ScalaPi2.scala && scala ScalaPi2
or scala scalapi.scala
OutOmMemoryError by 10^8

cd pimc/
cargo build --release && cargo run --release
10^9 3.141585792 Time: 29.12

node
10^9 3.141584332 'Time:' 31

pypy
10^9 3.141525904 Time: 0:00:39.799005

g++ -std=c++14 -o cpppi cpppi.cpp && ./cpppi
10^9 3.14159 Time: 3.46114
g++ -std=c++14 -o cpppi2 cpppi2.cpp && ./cpppi2
10^9 3.14159e+09 Time: 293.627

elixir elixirpi.exs   
memory leak

cd cljpi/
lein uberjar && java -jar target/uberjar/cljpi-0.1.0-SNAPSHOT-standalone.jar
10^9 3.1415853 Time: 119.215570998

nim c -d:release montecarlo.nim
10^9
Time taken: 11.735782188
In quarter sector = 785398770 / 1000000000
Estimated Pi: 3.14159508

nimpy:
nim c --threads:on --app:lib --out:monte.so monte.nim 
python3 monte.py
10^9
Time taken: 188.018512425
In quarter sector = 785397243 / 1000000000
Estimated Pi: 3.141588972

python3 pypi3.py
10^9
3.141532232 Time: 0:05:19.728765

graalpython pypi3.py
10^9
3.141606092 Time: 0:01:04.195000

NumPy 10^9:
python3 monte.py 
3.141553172 Time: 0:21:06.646030

R < rpi.r --no-save
GraalVM
10^9
3.14163304314163 Time: 351.484999895096
R
3.141609 Time: 2638.914

julia julia-pi.jl
10^9
3.141547816
 60.449131 seconds (3.00 G allocations: 59.631 GiB, 0.64% gc time)

pynumba.py
10^9
3.141477828 Time: 0:00:08.933649

groovy pigroovy.groovy
3.141596212 1 minutes, 54.274 seconds