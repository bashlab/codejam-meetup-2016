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

// O(N * log(N))
func runtest() (result int) {
    var N int
    var P int64
    var B []int64
    var sum []int64

    fmt.Scanf("%d %d", &N, &P)

    B = make([]int64, N+1)
    B[0] = 0
    for i := 1; i <= N; i++ {
        var b int64
        fmt.Scanf("%d", &b)
        B[i] = b
    }

    // sum up first
    sum = make([]int64, N+1)
    sum[0] = int64(0)
    for i := 1; i <= N; i++ {
        sum[i] = sum[i-1] + B[i]
    }

    // for each box
    for i := 1; i <= N; i++ {
        b := B[i]
        c := sum[i]
        // do binary search
        if b <= P {
            x := c - b + P
            itar, imin, imax := i, i, N

            for true {
                imid := (imin + imax)/2
                if sum[imid] > x {
                    if imid - 1 < imin {
                        itar = imid - 1
                        break
                    } else {
                        imax = imid - 1
                    }
                } else if sum[imid] < x {
                    if imax < imid +1 {
                        itar = imid
                        break
                    } else {
                        imin = imid + 1
                    }
                } else {
                    itar = imid
                    break
                }
            }
            result += itar - i + 1
        }
    }
    return
}
