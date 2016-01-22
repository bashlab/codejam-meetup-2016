T = int(raw_input().strip())

def dis(p1, p2):
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1])

for case in xrange(T):
    ans = 0

    N = int(raw_input().strip())
    # [ [0, 0], [1, 1]
    PTS = [map(int, raw_input().strip().split(' ')) for i in xrange(N)]
    ZODIAC = {}

    # print 'start loop 1'

    for p1 in PTS:
        ZODIAC[str(p1)] = [
            dis(p1, p2) for p2 in PTS if p1 != p2
        ]

        v = sorted(ZODIAC[str(p1)])

        # print 'start loop 2'

        d1 = v[0]
        rep = 1
        for i in xrange(1, N - 1):
            d2 = v[i]

            if d1 == d2:
                rep = rep + 1
            else:
                d1 = d2
                ans = ans + rep * (rep - 1) / 2
                rep = 1

        ans = ans + rep * (rep - 1) / 2

    print 'Case #%d: %d' % (case + 1, ans)
