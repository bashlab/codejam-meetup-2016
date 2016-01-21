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

// O(N)
func runtest() (result int) {
    var N int
    var d []int

    fmt.Scanf("%d", &N)

    d = make([]int, N)
    for i := 0; i < N; i++ {
        var di int
        fmt.Scanf("%d", &di)
        d[i] = di
    }

    // special case: N = 1
    if N == 1 {
        return 3
    }

    c := 1
    for i := 1; i < N; i++ {
        if c != 0 {
            cur := d[i]
            prev := d[i-1]
            insert := 0

            if cur <= prev {
                insert = 4 - c
            } else {
                diff := cur - prev
                if diff > 10 {
                    lvl := (diff - 1) / 10
                    maxLvl := 4 - c
                    if lvl > maxLvl {
                        insert = maxLvl
                    } else {
                        insert = lvl
                    }
                }
            }

            c = (c + insert) % 4
            result += insert
        }

        c = (c + 1) % 4
    }

    if c != 0 {
        result += 4 - c
    }

    return
}
