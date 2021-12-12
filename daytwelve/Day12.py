from collections import defaultdict
adj = defaultdict(list)
ans = 0
cur = 0
mp = defaultdict(int)

def bad_path(path):
    return path == 'start,b,d,b,A,c,A,' or path == 'start,b,d,b,A,' or path == 'start,A,c,A,c,A,b,'

def dfs(node: str, vis=dict(), twice=False, path=''):
    if ord(node[0]) >= 97 and node in vis and vis[node] == 2:
        return
    if (node == 'start' or node == 'end') and node in vis:
        return
    if twice and ord(node[0]) >= 97 and node in vis:
        return
    path += node + ','
    

    if node in vis: vis[node] += 1
    else: vis[node] = 1

    if vis[node] == 2 and ord(node[0]) >= 97:
        twice = True
    if node == 'end':
        #print(path)
        global ans
        ans += 1
        return
    for neighbor in adj[node]:
        if ord(neighbor[0]) >= 97 and neighbor in vis and vis[neighbor] == 1:
            if twice:
                continue
            dfs(neighbor, dict(vis), True, path)
        dfs(neighbor, dict(vis), twice, path)

lines = open('Day12.in').read().split('\n')
for line in lines:
    tmp = line.split('-')
    if len(tmp) != 2:
        continue
    if tmp[0] not in mp:
        mp[tmp[0]] = cur
        cur += 1
    if tmp[1] not in mp:
        mp[tmp[1]] = cur
        cur += 1
    adj[tmp[0]].append(tmp[1])
    adj[tmp[1]].append(tmp[0])

dfs("start", dict(), False, '')
print(mp)
print(ans)
