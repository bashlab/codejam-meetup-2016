package main

import (
    "fmt"
)

func main(){
    var T int
    fmt.Scanf("%d", &T)
    for t := 1; t <= T; t++ {
        fmt.Printf("Case #%d: %d\n", t, runtest())
    }
}

// O(N^3)
// can finish in around 2-3 min
func runtest() (result int) {
    var N int
    fmt.Scanf("%d", &N)

    X := make([]int, N)
    Y := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scanf("%d %d", &X[i], &Y[i])
    }

    for i := 0; i < N; i++ {
        for j := 0; j < N; j++ {
            if i != j {
                dx := X[i] - X[j]
                dy := Y[i] - Y[j]
                dist := dx * dx + dy * dy
                for k := j+1; k < N; k++ {
                    if i != k {
                        dx2 := X[i] - X[k]
                        dy2 := Y[i] - Y[k]
                        dist2 := dx2 * dx2 + dy2 * dy2
                        if dist == dist2 {
                            result++
                        }
                    }
                }
            }
        }
    }
    return
}
