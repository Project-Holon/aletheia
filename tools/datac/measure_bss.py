import json, bisect, os, sys
from collections import Counter, defaultdict
ROOT=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0,ROOT+"/tools"); sys.path.insert(0,os.path.dirname(os.path.abspath(__file__)))
import datareg
exec(open(os.path.join(os.path.dirname(os.path.abspath(__file__)),'measure.py')).read().split("# objects to classify")[0])
hdr_refs = defaultdict(set)
for a_, rg_, rel_, da_ in files:
    for x_ in da_:
        hdr_refs[x_].add((rg_, rel_))
hdr_sorted = sorted(hdr_refs)
lay=datareg.load_layout()
regs={"arm9":(0x020A9E80,0x021542C0)}
for o in lay["overlays"]:
    if o["bss_size"]: regs["ov%03d"%o["id"]]=(o["bss_start"],o["bss_end"])
tot=Counter(); rows=[]
for rg,(a,b) in regs.items():
    lo=bisect.bisect_left(wvals,a); hi=bisect.bisect_left(wvals,b)
    tg=defaultdict(set)
    for v,wr,site in words[lo:hi]:
        if rg!="arm9" and wr not in (rg,"arm9","itcm"): continue
        if rg=="arm9" and wr!="arm9" and wr!="itcm":
            f=file_of(wr,site); tg[v].add(f or "?"+wr); continue
        f=file_of(wr,site)
        tg[v].add(f or "?")
    # header refs
    for x in hdr_sorted[bisect.bisect_left(hdr_sorted,a):bisect.bisect_left(hdr_sorted,b)]:
        for fr,rel in hdr_refs[x]:
            if rg!="arm9" and fr not in (rg,"arm9","itcm"): continue
            tg[x].add(rel)
    n=len(tg); one=sum(1 for v in tg.values() if len(v)==1 and not next(iter(v)).startswith("?"))
    many=sum(1 for v in tg.values() if len(v)>1)
    rows.append((rg,b-a,n,one,many))
    tot["bytes"]+=b-a; tot["starts"]+=n; tot["one"]+=one; tot["many"]+=many
    if rg=="arm9": print("arm9 bss",b-a,n,one,many)
print("all bss regions",len(regs),dict(tot))
