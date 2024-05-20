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

Rust:
cd pimc/
cargo build --release && cargo run --release
10^9 3.141585792 Time: 29.12

node
10^9 3.141584332 'Time:' 31

pypy  # doesn't work with numpy (monte.py)
10^9 3.141525904 Time: 0:00:39.799005



===============================================

g++ -std=c++14 -o cpppi cpppi.cpp && ./cpppi
g++ -std=c++20 -o cpppi cpppi.cpp && ./cpppi
# g++ -std=c++14 -o cpppi3 cpppi3.cpp && ./cpppi3
g++ -std=c++20 -pthread -O3 cpppi -c cpppi.cpp && ./cpppi
10^9 3.14159 Time: 2.45827
g++ -std=c++20 -pthread -O3 cpppi3 -c cpppi3.cpp && ./cpppi3
10^9 3.14159 Time: 3.46114
g++ -std=c++14 -o cpppi2 cpppi2.cpp && ./cpppi2
10^9 3.14159e+09 Time: 293.627
--------
gcc-13/  - Dockerfile


/usr/local/bin/cmake -DCMAKE_BUILD_TYPE=Release -G "CodeBlocks - Unix Makefiles" -S /tmp/tmp.Z2ozByJYmW -B /tmp/tmp.Z2ozByJYmW/cmake-build-release-gcc-11
/usr/local/bin/cmake --build /tmp/tmp.Z2ozByJYmW/cmake-build-release-gcc-11 --target pi_test -- -j 19

pi_te:
Calculated pi = 3.1415927
Real pi       = 3.1415927
Error         = -9.9548725e-10
Time          = 382ms
Threads       = 6
Iterations    = 1000000000

pi_test   works in docker, without libs

для pi_te
В CMakeList.txt добавть строчку:
target_link_libraries(pi_test -static)
после add_executable(pi_test main.cpp)

========================================

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
10^9
Time taken: 188.018512425
In quarter sector = 785397243 / 1000000000
Estimated Pi: 3.141588972

python3 pypi3.py   # 3.11 better than 3.8
10^9
3.141532232 Time: 0:05:19.728765

graalpython pypi3.py
10^9
3.141606092 Time: 0:01:04.195000

NumPy 10^9:
python3 monte.py 
3.141607268 Time: 0:00:18.843590

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

Fortran:
gfortran fort_pi.f90 -o fort_pi && ./fort_pi
   3.14162755    
Time = 11.949 seconds.

Lua:
lua lualua.lua 
memory leak (?)

Pytorch:
python monte_torch.py
better than NumPy (~17)

Tensorflow:
python monte_tf.py 
tf.Tensor(3.141583524, shape=(), dtype=float64) Time: 0:00:08.490882
with cuda - OOM
10^7 - cuda ok
export CUDA_VISIBLE_DEVICES=""
unset CUDA_VISIBLE_DEVICES

Bash:
./bash_monte3.sh 
10**5
pi = 3.1405600000, Time: 637005.54 ms

Tcl:
tclsh tcl_monte.tcl
10**9 
pi = 3.141582964, Time: 1244 seconds


php php.php 
10**9
3.141614756 Time: 179.21562719345 seconds
