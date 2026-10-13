"""vendorscan.py: match every twl function start against every vendor function.

Scans asm/twl/twl.s (labels plus twl rows of layout/function_starts.txt and
layout/matched/twl names), compares the image bytes at each start with each
function symbol of every vendor object under sdk/ (relocation fields masked),
and pickles (starts, names, code bytes, hits, extents) to OUT.  hits maps an
address to its candidates: (mismatches, size, archive, member, symbol,
binding, .comment, DWARF source, thumb, section, value, object function list).

    python tools/vendorscan.py OUT.pkl
"""
import sys,os,re,glob,json,collections
import argparse
_ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
_ap.add_argument('out', help='pickle file to write (the scan takes minutes)')
ARGS = _ap.parse_args()
R = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0,R+'/tools')
import sdkobj as so, ovstats
from libmatch import read_archive, Obj, find_archives
head,labels,insns=ovstats.scan_listing(R+'/asm/twl/twl.s')
starts=sorted(set(a for a,_ in labels))
name={a:l for a,l in labels}
for l in open(R+'/layout/function_starts.txt'):
    m=re.match(r'twl\s+0x([0-9A-Fa-f]+)',l)
    if m: 
        a=int(m.group(1),16)
        if a not in name: starts.append(a); name[a]='func_%08X'%a
for f in glob.glob(R+'/layout/matched/twl/*.json'):
    for x in json.load(open(f))['functions']:
        a=int(x['address'],16)
        if a not in name: starts.append(a); name[a]=x['name']
starts=sorted(set(starts))
print(len(starts),'twl starts')
ccb=ovstats.code_bytes_from(insns,starts)
END=0x02732DA0
img={}
for i,a in enumerate(starts):
    nx=starts[i+1] if i+1<len(starts) else END
    img[a]=(so.image_bytes('twl',a,min(nx-a,4096)),nx-a)
hits=collections.defaultdict(list)  # addr -> list
arcs=find_archives(include_demos=True)
sdkroot=R+'/sdk/'
for arch in arcs:
    try:
        mem=[(os.path.basename(arch),open(arch,'rb').read())] if arch.endswith('.o') else list(read_archive(arch))
    except Exception: continue
    for n,b in mem:
        try:
            o=Obj(n,b)
            if not o.ok: continue
            v=so.ObjView(o)
        except Exception: continue
        cands=None
        for s in v.syms:
            if s[3]!=so.STT_FUNC or s[2]<4: continue
            try: body,mask,rels,th=so.extract(v,s)
            except Exception: continue
            sz=s[2]
            if sz>4096: continue
            # first unmasked run for prefilter
            for a in starts:
                ib,avail=img[a]
                if avail<sz or ib is None or len(ib)<sz: continue
                # prefilter on first 4 unmasked bytes
                mis=0; lim=max(4,sz//16) if sz>=32 else 0
                for i in range(sz):
                    if mask[i] and body[i]!=ib[i]:
                        mis+=1
                        if mis>lim: break
                if mis<=lim:
                    if cands is None:
                        cm=v.comment()
                        try:
                            d=so.dwarf_of(v); src=None
                            for t in d.top:
                                if t.tag==0x11 and 3 in t.attrs: src=t.attrs[3]; break
                        except Exception: src=None
                        cands=(cm,src)
                    hits[a].append((mis,sz,arch.replace(chr(92),'/')[len(sdkroot):],n,s[0],'global' if s[4]==1 else ('weak' if s[4]==2 else 'static'),cands[0],cands[1],th,s[5],s[1],[(q[5],q[1],q[0]) for q in v.syms if q[3]==so.STT_FUNC and q[2]]))
import pickle
pickle.dump((starts,name,ccb,hits,{a:img[a][1] for a in starts}),open(ARGS.out,'wb'))
print(len(hits))
