lines = open('Day22.in', 'r').read().strip().split('\n')
n = 101
cu = [[[0 for i in range(n)] for i in range(n)] for i in range(n)]
for line in lines:
    cmd, coords = line.split(' ')
    coords = coords.split(',')
    coords = list(x.split('=')[1] for x in coords)
    x = list(map(int, coords[0].split('..')))
    y = list(map(int, coords[1].split('..')))
    z = list(map(int, coords[2].split('..')))
    x[0] += 50
    x[1] += 50
    y[0] += 50
    y[1] += 50
    z[0] += 50
    z[1] += 50
    print(cmd)
    if x[0] <= 100 and x[1] >= 0 and y[0] <= 100 and y[1] >= 0 and z[0] <= 100 and z[1] >= 0:
        for i in range(max(x[0], 0), min(101, x[1]+1)):
            for j in range(max(y[0], 0), min(101, y[1]+1)):
                for k in range(max(z[0], 0), min(101, z[1]+1)):
                    if cmd == 'on':
                        cu[i][j][k] = 1
                    else:
                        cu[i][j][k] = 0
ans = 0
for row in cu:
    for col in row:
        ans += sum(col)
print(ans)
