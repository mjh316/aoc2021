from sys import stdin

lines = []

for line in stdin: lines.append(line.strip())

r=[]
d= {}
for line in lines:
    for j in range(len(line)):
        if j not in d: d[j] = {}
        if line[j] == '0':
            if '0' in d:
                d[j]['0'] += 1
            else: d[j]['0'] = 1
        else:
            if '1' in d:
                d[j]['1'] += 1
            else: 
                d[j]['1'] = 1
n = len(lines[0])
s = '' # epslilon
e = '' #gamma
for i in range(n):
    if d[i]['0'] < d[i]['1']:
        s += '1'
        e += '0'
    else:
        s += '0'
        e += '1'
print(s, e)
