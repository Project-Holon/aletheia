import os
import json
from collections import Counter, defaultdict
reg=json.load(open(os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))), 'layout/data_objects.json')))['regions']
own={k:set(v) for k,v in json.load(open('owners.json')).items()}
direct={k:set(v) for k,v in own.items()}
# pointer edges: referrer -> target object key
starts=defaultdict(list)
for rg,R in reg.items():
  for o in R['objects']: starts[rg].append((int(o['addr'],16),o['size']))
import bisect
def obj_at(rg,a):
  l=starts[rg]; i=bisect.bisect_right([x[0] for x in l],a)-1
  if i>=0 and l[i][0]<=a<l[i][0]+max(l[i][1],1): return '%s:%08X'%(rg,l[i][0])
  return None
refby=defaultdict(set)
for rg,R in reg.items():
  for o in R['objects']:
    src='%s:%08X'%(rg,int(o['addr'],16))
    for t in o.get('targets',[]) or []:
      if not t: continue
      k=obj_at(rg,int(t,16)&~1)
      if k and k!=src: refby[k].add(src)
changed=True
while changed:
  changed=False
  for rg,R in reg.items():
    prev=None
    for o in R['objects']:
      k='%s:%08X'%(rg,int(o['addr'],16))
      if not own[k]:
        u=set()
        for s in refby.get(k,()): u|=own[s]
        if not u and o['ev']=='str' and prev: u=set(own[prev])
        if u: own[k]=u; changed=True
      prev=k
tot=Counter(); per={}
for rg,R in reg.items():
  c=per.setdefault(rg,Counter())
  for o in R['objects']:
    k='%s:%08X'%(rg,int(o['addr'],16)); n=len(own[k])
    cl='one' if n==1 else 'none' if n==0 else 'many'
    c[cl]+=1; c[cl+'_b']+=o['size']; tot[cl]+=1; tot[cl+'_b']+=o['size']
    # overlay vs arm9 split
    grp='arm9' if rg=='arm9' else 'ov'
    tot[grp+'_'+cl]+=1; tot[grp+'_'+cl+'_b']+=o['size']
print(dict(tot))
json.dump({k:sorted(v) for k,v in own.items()},open('owners2.json','w'))
json.dump({k:dict(v) for k,v in per.items()},open('per2.json','w'))
# contiguity check: for overlays with all objects single-owned, count owner runs vs files
runs=Counter()
for rg,R in reg.items():
  seq=[]
  for o in R['objects']:
    k='%s:%08X'%(rg,int(o['addr'],16))
    if len(own[k])==1:
      f=next(iter(own[k]))
      if not seq or seq[-1]!=f: seq.append(f)
  nf=len(set(seq))
  runs['regions']+=1
  if len(seq)==nf: runs['one_run_per_file']+=1
  elif len(seq)<=2*nf: runs['<=2 runs per file']+=1
  else: runs['more']+=1
print(runs)
