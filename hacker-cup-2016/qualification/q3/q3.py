import fileinput
import math
from operator import attrgetter

lines = []

for line in fileinput.input():
    line = line.rstrip('\n')
    lines.append(line)

T = int(lines[0])
lines.pop(0)

class Node(object):
    def __init__(self):
        self.index = -1
        self.fromIndex = -1
        self.toIndex = -1
        self.sum = -1
        self.l = None
        self.r = None

    def __str__(self):
        return 'idx (%10d) from (%10d) to (%10d) val (%10d)' % (
            self.index,
            self.fromIndex,
            self.toIndex,
            self.sum
        )


class Tree(object):
    def __init__(self, root):
        self.root = root

    def dumpTree(self, n):
        l = n.l
        r = n.r
        if l and r:
            print l.sum, r.sum
            print l, r
        elif l:
            print l.sum
            print l

        if l:
            self.dumpTree(l)
        if r:
            self.dumpTree(r)

    def getNodeCount(self, node):
        # Myself
        ret = 1

        if node.l:
            ret = ret + self.getNodeCount(node.l)

        if node.r:
            ret = ret + self.getNodeCount(node.r)

        return ret

    def getNodeSmallerThan(self, node, val):
        nodes = []

        if node.sum <= val:
            nodes.append(node)

        if node.l:
            l = self.getNodeSmallerThan(node.l, val)
            nodes = nodes + l
        if node.r:
            r = self.getNodeSmallerThan(node.r, val)
            nodes = nodes + r

        return nodes

    def query(self, fromIndex, toIndex, n=None, L=None, R=None):
        n = n or self.root
        L = L or n.fromIndex
        R = R or n.toIndex
        # print 'from', fromIndex, 'to', toIndex, 'L', L, 'R', R
        # print n

        if fromIndex > R or toIndex < L:
            return -1

        # Return if match range
        if (L >= fromIndex and toIndex >= R):
            return n.sum

        # print 'left'
        s1 = self.query(fromIndex, toIndex, n.l, L, (L + R) / 2)
        # print 'right'
        s2 = self.query(fromIndex, toIndex, n.r, (L + R) / 2 + 1, R)

        # print 'get s1', s1, 's2', s2

        if s1 == -1:
            return s2
        if s2 == -1:
            return s1

        return s1 + s2


def binarySearchMaxIndex(base, lowerBound, upperBound, t, P):
    while ((abs(upperBound - lowerBound) != 1) and (lowerBound != upperBound)):
        M = (lowerBound + upperBound) / 2
        s = t.query(base, M)
        # print 's', s, 'm', M
        if s <= P:
            lowerBound = M
        else:
            upperBound = M

    s = t.query(base, upperBound)
    if s <= P:
        ret = upperBound
    else:
        ret = lowerBound

    # print 'ret', ret

    return ret

def buildSegmentTree(nodes, Bs):
    n = len(Bs)
    node = Node()

    if n == 1:
        node.index = len(nodes)
        node.fromIndex = node.index
        node.toIndex = node.index
        node.sum = Bs[0]
        nodes.append(node)
        return node

    M = n / 2

    if n % 2 == 0:
        lN = M
        rN = M
    else:
        lN = M + 1
        rN = M + 1

    leftNode = buildSegmentTree(nodes, Bs[0:lN])
    rightNode = buildSegmentTree(nodes, Bs[rN:n])

    node.l = leftNode
    node.r = rightNode
    node.sum = leftNode.sum + rightNode.sum
    node.fromIndex = node.l.index if node.l.index != -1 else node.l.fromIndex
    node.toIndex = node.r.index if node.r.index != -1 else node.r.toIndex

    return node

def computeNumberOfSequence(Bs, N, t, root, P):

    # Make sure there are nodes to do work
    groundNodes = []
    for i in range(0, N):
        if Bs[i] <= P:
            groundNodes.append(i)

    numOfNodes = len(groundNodes)

    if numOfNodes == 0:
        return numOfNodes

    lowerBound = groundNodes[0]
    for i in groundNodes:
        lowerBound = binarySearchMaxIndex(i, lowerBound, N - 1, t, P)

        if lowerBound != i:
            numOfNodes = numOfNodes + (lowerBound - i)

    # for n in nodes:
    #     print n

    return numOfNodes

for i in range(0, int(T)):
    tokens = lines[0].split(' ')
    N = int(tokens[0])
    P = int(tokens[1])
    lines.pop(0)

    ans = 0
    Bs = [int(x) for x in lines.pop(0).split(' ')]
    # print 'Bs', Bs

    nodes = []
    root = buildSegmentTree(nodes, Bs)
    tree = Tree(root)
    # print root.sum
    # tree.dumpTree(root)
    ans = computeNumberOfSequence(Bs, N, tree, root, P)

    # print 'query'
    # print tree.query(1, 2)

    print 'Case #%d: %d' % (i + 1, ans)
    # break
