with open('Day6.in') as f:
    a = list(map(int, list(map(str.strip, f.read().split(',')))))
    cnt = [0 for i in range(9)]
    for i in a:
        cnt[i] += 1
    d = 0
    while d != 256:
        tmp = [0 for i in range(9)]
        for i in range(8, 0, -1):
            tmp[i-1] += cnt[i]
        tmp[8] += cnt[0]
        tmp[6] += cnt[0]
        cnt = tmp
        print(cnt)
        d += 1
    print(sum(cnt))
