package main
import "fmt"
import "math"
import "math/rand"
import "time"

func main() {
	p := fmt.Println
	sum := 0.0
	n := math.Pow(10,9)
	s1 := rand.NewSource(time.Now().UnixNano())
    r1 := rand.New(s1)
	start := time.Now()
	for i := 0; i < int(n); i++ {
		if math.Pow((r1.Float64()-1), 2) + math.Pow((r1.Float64()-1), 2) <=1 {
			sum++
		}
	}
	pi := 4.0 * sum / n
	stop := time.Now()
	p(stop.Sub(start))
	p(pi)

}
