import os
exec(open(os.path.join(os.path.dirname(os.path.abspath(__file__)),'measure.py')).read().split("rows = {}")[0])
from collections import Counter
rows=[]
for line in open(ROOT + "/layout/data_objects.txt", encoding="utf-8"):
    if line.startswith("#") or not line.strip(): continue
    p=line.split()
    if len(p)>=3 and p[1].startswith("0x") and p[0]=="arm9" and p[2]!="range":
        rows.append((int(p[1],16),p[2]))
rows=sorted(set(rows))
c=Counter(); 
for i,(a,k) in enumerate(rows):
    nxt=rows[i+1][0] if i+1<len(rows) else a+4
    size=min(nxt-a,4096)
    zone="tail" if 0x0209D86C<=a<0x020A9E80 else "itcm/dtcm" if a<0x02000000 or a>=0x027E0000 else "bss" if 0x020A9E80<=a<0x021542C0 else "in-code"
    o=owners("arm9",a,size)
    cl="one" if len(o)==1 else "none" if not o else "many"
    c[(zone,cl)]+=1; c[(zone,"all")]+=1
for k in sorted(c): print(k,c[k])
