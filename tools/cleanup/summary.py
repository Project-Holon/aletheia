import csv,collections,re
import os; R=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))).replace(chr(92),'/')+'/src/game/'
rows=list(csv.DictReader(open('census.tsv'),delimiter='\t'))
keep=[x for x in rows if not x['skip']]
sk=collections.Counter(x['skip'].split('(')[0] for x in rows if x['skip'])
S=lambda k,l=keep:sum(int(x[k]) for x in l)
o=[]
o.append(f"files total {len(rows)}; skipped {sum(sk.values())} {dict(sk)}; in scope {len(keep)}")
o.append(f"in scope: game functions {S('game')} (plus {S('sdk')} sdk-named functions inside {S('mixed')} mixed files), est code bytes {S('bytes')} (gap-to-next-function estimate, cap 8192), body lines {S('lines')}")
o.append(f"struct views {S('views')}, raw offset casts {S('raw')}, fn-ptr casts {S('fnptr')}, stand-in comments {S('standin')}, volatile non-hw lines {S('volatile_other')}, asm bodies {S('asm')}, distinct func_/sub_ refs (sum per file) {S('func_refs')}, defined func_ names {S('func_names')}")
L=list(csv.DictReader(open('lanes.tsv'),delimiter='\t'))
L2=list(csv.DictReader(open('lanes_T110.tsv'),delimiter='\t'))
o.append(f"lanes (target effort 75, avg {S('game')/len(L):.0f} fns/lane): {len(L)} lanes = {-(-len(L)//20)} waves of 20; lanes_T110.tsv (avg {S('game')/len(L2):.0f} fns/lane): {len(L2)} lanes = {-(-len(L2)//20)} waves")
o.append("oversize lanes (>2.5x target, single file or cluster, cannot split without breaking whole-file rule): "+str(sum(1 for l in L if l['note'].startswith('OVERSIZE'))))
# per region
reg=collections.OrderedDict()
for x in keep:
    r=reg.setdefault(x['region'],[0,0,0,0,0])
    r[0]+=1;r[1]+=int(x['game']);r[2]+=int(x['views']);r[3]+=int(x['standin']);r[4]+=int(x['raw'])
o.append("\nregion\tfiles\tfns\tviews\tstandins\traw")
for k,v in sorted(reg.items(),key=lambda kv:(not kv[0].startswith('arm9'),kv[0])): o.append(k+'\t'+'\t'.join(map(str,v)))
# region -> lanes
rl=collections.defaultdict(list)
for l in L:
    for r in l['regions'].split(','): rl[r].append(l['lane'])
o.append("\nregions split over several lanes (lane ids; their lanes must not create/edit a common header, see rule):")
for r,ls in sorted(rl.items()):
    if len(ls)>1:
        ws=collections.Counter((int(x[1:])-1)//20+1 for x in ls)
        o.append(f"{r}: {ls[0]}..{ls[-1]} ({len(ls)} lanes; waves {dict(ws)})")
o.append(chr(10)+"wave table (wave: lane range, regions):")
for w in range(1,-(-len(L)//20)+1):
    ll=[l for l in L if int(l['wave'])==w]
    rs=[]
    for l in ll:
        for r in l['regions'].split(','):
            if r not in rs: rs.append(r)
    o.append(f"wave {w}: {ll[0]['lane']}-{ll[-1]['lane']} fns {sum(int(l['game_fns']) for l in ll)}  {rs[0]} .. {rs[-1]}")
o.append(chr(10)+"oversize lanes (lane, file(s), fns, effort):")
for l in L:
    if l['note'].startswith('OVERSIZE'): o.append(f"{l['lane']}	{l['files'][:100]}	{l['game_fns']}	{l['effort']}")
# headers
import os
hd=collections.defaultdict(list)
for x in keep:
    for h in x['hdrs'].split(','):
        if h: hd[h].append(x['file'])
lane_of={}
for l in L:
    for f in l['files'].split(): lane_of[f]=l['lane']
o.append("\nshared headers in src/game (header: includers in scope, lanes owning them); all includers of a header are in one lane:")
allh=[]
for dp,dn,fn in os.walk(R):
    for f in fn:
        if f.endswith('.h'): allh.append(os.path.join(dp,f).replace(chr(92),'/')[len(R):])
for h in sorted(allh):
    inc=hd.get(h,[])
    ln=sorted({lane_of[f] for f in inc if f in lane_of})
    o.append(f"{h}\tincluders {len(inc)}\tlanes {','.join(ln) or 'none in scope'}")
bad=[h for h,l in hd.items() if len({lane_of.get(f) for f in l})>1]
o.append(f"headers whose includers span more than one lane: {bad}")
open('summary.txt','w').write('\n'.join(o)+'\n')
print('\n'.join(o))
