"""Stage 3: match every start against every vendor function (relocation fields masked). -> hits.pkl"""
import sys,pickle,time,collections
import os; R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))).replace(chr(92), '/')
sys.path.insert(0,R+'/tools')
import sdkobj as so
t0=time.time()
V=pickle.load(open('vendor.pkl','rb'))
starts,names,file_of,codesz=pickle.load(open('starts.pkl','rb'))
regs=so.regions()
S=[]  # (region, addr, avail, data offset)
for r in sorted(starts):
    if not starts[r]: continue
    reg=regs[r]
    for a in sorted(starts[r]):
        off=a-reg.base
        S.append((r,a,off))
print(len(S),'starts',len(V),'vendor funcs',flush=True)
DATA={r:bytes(regs[r].data) for r in {s[0] for s in S}}
W=8
idx={}
def index(k,w):
    d=idx.get((k,w))
    if d is None:
        d={}
        for i,(r,a,off) in enumerate(S):
            dd=DATA[r]
            if off+k+w<=len(dd):
                d.setdefault(dd[off+k:off+k+w],[]).append(i)
        idx[(k,w)]=d
    return d
def probes(mask):
    n=len(mask); runs=[]; i=0
    while i<n:
        if mask[i]:
            j=i
            while j<n and mask[j]: j+=1
            if j-i>=4: runs.append((i,j))
            i=j
        else: i+=1
    if not runs: return None,0
    conc=sum(mask)
    ps=[]
    r0=runs[0]; ps.append((r0[0],min(W,r0[1]-r0[0])))
    r1=runs[-1]; w=min(W,r1[1]-r1[0]); p=(r1[1]-w,w)
    if p not in ps: ps.append(p)
    rm=max(runs,key=lambda r:r[1]-r[0]); w=min(W,rm[1]-rm[0]); p=(rm[0],w)
    if p not in ps: ps.append(p)
    return ps,conc
hits=collections.defaultdict(list)   # start idx -> [(mis, vendor idx)]
nskip=0
for vi,e in enumerate(V):
    rel,mem,sym,bind,cm,th,shndx,val,sz,body,mask,funcs=e
    ps,conc=probes(mask)
    if ps is None: nskip+=1; continue
    lists=[index(k,w).get(body[k:k+w],()) for k,w in ps]
    lists.sort(key=len)
    cand=set(lists[0])
    if len(lists)>1: cand.update(lists[1])
    if not cand: continue
    lim=max(4,sz//16) if sz>=32 else 0
    mint=int.from_bytes(bytes(0xFF if m else 0 for m in mask),'little')
    bint=int.from_bytes(body,'little')
    for si in cand:
        r,a,off=S[si]
        dd=DATA[r]
        if off+sz>len(dd): continue
        x=(int.from_bytes(dd[off:off+sz],'little')^bint)&mint
        if x==0: mis=0
        else:
            mis=sz-x.to_bytes(sz,'little').count(0)
            if mis>lim: continue
        hits[si].append((mis,vi))
    if vi%20000==0: print(vi,len(hits),time.time()-t0,flush=True)
print('skip all-masked',nskip,'starts hit',len(hits),time.time()-t0)
pickle.dump((S,dict(hits)),open('hits.pkl','wb'),protocol=4)
