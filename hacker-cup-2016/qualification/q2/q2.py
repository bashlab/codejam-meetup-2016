T = int(raw_input().strip())

for case in xrange(T):
    ans = 0

    N = int(raw_input().strip())
    G0 = raw_input().strip()
    G1 = raw_input().strip()

    isS0Segment = False
    isS1Segment = False

    for i in xrange(N):
        g00 = G0[i]
        g10 = G1[i]

        if g00 == 'X':
            if isS0Segment:
                isS0Segment = False
        else:
            if not isS0Segment:
                ans = ans + 1
                isS0Segment = True

        if g10 == 'X':
            if isS1Segment:
                isS1Segment = False
        else:
            if not isS1Segment:
                ans = ans + 1
                isS1Segment = True
        # print 'i', i, 'ans', ans

    isS0Segment = False
    isS1Segment = False
    isS0SegmentCount = False
    isS1SegmentCount = False
    for i in xrange(N):
        # 0 1 2
        g01 = G0[i]
        g11 = G1[i]

        if g01 == 'X':
            if isS0Segment:
                isS0Segment = False
        else:
            if not isS0Segment:
                isS0Segment = True
                isS0SegmentCount = False

        if g11 == 'X':
            if isS1Segment:
                isS1Segment = False
        else:
            if not isS1Segment:
                isS1Segment = True
                isS1SegmentCount = False

        if i - 1 >= 0:
            g00 = G0[i - 1]
            g10 = G1[i - 1]
        else:
            g00 = 'X'
            g10 = 'X'

        if i + 1 < N:
            g02 = G0[i + 1]
            g12 = G1[i + 1]
        else:
            g02 = 'X'
            g12 = 'X'

        if (
            g01 == '.' and g00 == 'X' and g02 == 'X' and
            g11 == '.' and g10 == 'X' and g12 == 'X'
        ) :
            ans = ans - 1
        else:
            if (
                g01 == '.' and g00 == 'X' and g02 == 'X' and
                g11 == '.'
            ) :
                if isS1Segment and not isS1SegmentCount:
                    ans = ans - 1
                    isS1SegmentCount = True

            if (
                g11 == '.' and g10 == 'X' and g12 == 'X' and
                g01 == '.'
            ) :
                if isS0Segment and not isS0SegmentCount:
                    ans = ans -1
                    isS0SegmentCount = True

        # print 'i', i, 'ans', ans, g00, g01, g02, g10, g11, g12, isS0Segment, isS0SegmentCount, isS1Segment, isS1SegmentCount

    print 'Case #%d: %d' % (case + 1, ans)
