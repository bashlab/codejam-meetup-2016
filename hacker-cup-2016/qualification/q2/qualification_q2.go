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

func isBlocked(idx int, N int, ary []bool) bool {
    return idx < 0 || idx >= N || ary[idx]
}

// O(N)
func runtest() (result int) {
    // Scan input
    var N int
    fmt.Scanf("%d", &N)

    cell := [][]bool {
        make([]bool, N),
        make([]bool, N),
    }

    for i := 0; i < 2; i++ {
        var row string
        fmt.Scanf("%s", &row)

        for j, v := range row {
            c := string(v)
            cell[i][j] = c == "X"
        }
    }

    // find solution
    for i := 0; i < 2; i++ {
        canSave := false
        prevBlocked, curBlocked, nextBlocked := true, true, true
        curBlocked = isBlocked(0, N, cell[i])

        for j := 0; j < N; j++ {
            nextBlocked = isBlocked(j+1, N, cell[i])

            if prevBlocked && !curBlocked {
                result++
                canSave = true
            } else if curBlocked {
                canSave = false
            }

            if canSave {
                oppI := (i+1)%2
                if isBlocked(j-1, N, cell[oppI]) &&
                  !isBlocked(j  , N, cell[oppI]) &&
                   isBlocked(j+1, N, cell[oppI]) {

                    result--
                    canSave = false

                    if i == 0 && prevBlocked && !curBlocked && nextBlocked {
                        result++
                    }
                }
            }

            prevBlocked, curBlocked = curBlocked, nextBlocked
        }
    }
    return
}
