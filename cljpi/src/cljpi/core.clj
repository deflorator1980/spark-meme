(ns cljpi.core
  (:gen-class))

(defn -main
  [& args]
  (def sum 0)
  (def n (Math/pow 10 9))
  (def start (System/nanoTime))
  (dotimes [i n] (if (<= (+ (Math/pow (- (rand) 1) 2) (Math/pow (- (rand) 1) 2)) 1) (def sum (inc sum))))
  (def stop (System/nanoTime))
  (def pi (/ (* 4 sum) n))
  (println pi)
  (println (/ (- stop start)(Math/pow 10 9))))
