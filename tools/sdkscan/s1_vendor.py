"""Stage 1: extract every vendor function (masked bytes) from every archive under sdk/. -> vendor.pkl"""
import sys,os,pickle,time
import os; R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))).replace(chr(92), '/')
sys.path.insert(0,R+'/tools')
import sdkobj as so
from libmatch import read_archive, Obj, find_archives
SDK=R+'/sdk/'
def work(arch):
    out=[]
    try:
        mem=[(os.path.basename(arch),open(arch,'rb').read())] if arch.endswith('.o') else list(read_archive(arch))
    except Exception:
        return arch,out
    rel=arch.replace(chr(92),'/')[len(SDK):]
    for n,b in mem:
        try:
            o=Obj(n,b)
            if not o.ok: continue
            v=so.ObjView(o)
        except Exception: continue
        cm=v.comment()
        funcs=[(q[5],q[1],q[0]) for q in v.syms if q[3]==so.STT_FUNC and q[2]]
        for s in v.syms:
            if s[3]!=so.STT_FUNC or s[2]<4 or s[2]>16384: continue
            try: body,mask,rels,th=so.extract(v,s)
            except Exception: continue
            out.append((rel,n,s[0],'global' if s[4]==1 else ('weak' if s[4]==2 else 'static'),cm,th,s[5],s[1],s[2],body,bytes(mask),funcs))
    return arch,out
if __name__=='__main__':
    import multiprocessing as mp
    t=time.time()
    arcs=find_archives(include_demos=True)
    allf=[]
    with mp.Pool(11) as p:
        for i,(a,o) in enumerate(p.imap_unordered(work,arcs,chunksize=2)):
            allf.extend(o)
            if i%100==0: print(i,len(allf),time.time()-t,flush=True)
    print(len(allf),time.time()-t)
    pickle.dump(allf,open('vendor.pkl','wb'),protocol=4)
