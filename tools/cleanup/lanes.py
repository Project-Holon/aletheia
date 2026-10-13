import csv,re,os,collections,sys
rows=[x for x in csv.DictReader(open('census.tsv'),delimiter='\t')]
keep=[x for x in rows if not x['skip'] and int(x['game'])>0]
dropped0=[x for x in rows if not x['skip'] and int(x['game'])==0]
def eff(x):
    return int(x['game'])+1.5*int(x['views'])+0.5*int(x['raw'])+int(x['fnptr'])+10*int(x['standin'])+0.5*int(x['volatile_other'])+3*int(x['asm'])+int(x['lines'])/100
for x in keep: x['effort']=round(eff(x),1)
byfile={x['file']:x for x in keep}
# union-find
par={f:f for f in byfile}
def find(a):
    while par[a]!=a: par[a]=par[par[a]]; a=par[a]
    return a
def uni(a,b):
    a,b=find(a),find(b)
    if a!=b: par[a]=b
stem=collections.defaultdict(list)
for f in byfile:
    d,b=os.path.split(f); s=re.sub(r'_p\d+\.c$','.c',b)
    stem[d+'/'+s].append(f)
for l in stem.values():
    for f in l[1:]: uni(l[0],f)
hdr=collections.defaultdict(list)
for f,x in byfile.items():
    for h in x['hdrs'].split(','):
        if h: hdr[h].append(f)
for h,l in hdr.items():
    for f in l[1:]: uni(l[0],f)
cl=collections.defaultdict(list)
for f in byfile: cl[find(f)].append(f)
def rkey(r):
    m=re.match(r'ov(\d+)$',r)
    return (1,int(m.group(1))) if m else (0,{'arm9':0,'arm9_autoload0_ITCM':1}.get(r,2))
clusters=[]
for k,l in cl.items():
    l.sort()
    regs=sorted({byfile[f]['region'] for f in l},key=rkey)
    clusters.append(dict(files=l,regs=regs,eff=sum(byfile[f]['effort'] for f in l),game=sum(int(byfile[f]['game']) for f in l)))
clusters.sort(key=lambda c:(rkey(c['regs'][0]),c['files'][0]))
TARGET=float(sys.argv[1]) if len(sys.argv)>1 else 110
lanes=[];cur=None
def new():
    global cur
    cur=dict(cl=[],eff=0,game=0);lanes.append(cur)
new()
for c in clusters:
    # close lane if adding exceeds target (and lane nonempty), or if region changes and lane already >= 60% target
    cr=c['regs'][0]
    lastr=cur['cl'][-1]['regs'][-1] if cur['cl'] else None
    if cur['cl'] and (cur['eff']+c['eff']>TARGET*1.15 or (lastr!=cr and cur['eff']>=TARGET*0.6)):
        new()
    cur['cl'].append(c);cur['eff']+=c['eff'];cur['game']+=c['game']
tot=sum(c['eff'] for c in clusters)
out=open('lanes.tsv' if len(sys.argv)<3 else sys.argv[2],'w')
out.write('lane\twave\tregions\tfiles\tgame_fns\tbytes\tviews\tstandins\teffort\tnote\n')
for i,l in enumerate(lanes,1):
    fl=[f for c in l['cl'] for f in c['files']]
    regs=[]
    for c in l['cl']:
        for r in c['regs']:
            if r not in regs: regs.append(r)
    g=lambda k:sum(int(byfile[f][k]) for f in fl)
    note=[]
    if len(fl)==1 and l['eff']>TARGET*2.5: note.append('OVERSIZE single file; needs in-file split or Opus lane')
    elif l['eff']>TARGET*2.5: note.append('OVERSIZE cluster (shared headers or _pNN parts)')
    if any(len(c['regs'])>1 for c in l['cl']): note.append('cross-region header cluster')
    out.write('\t'.join([f'L{i:03d}',str((i-1)//20+1),','.join(regs),' '.join(fl),str(g('game')),str(g('bytes')),str(g('views')),str(g('standin')),f"{l['eff']:.0f}",'; '.join(note)])+'\n')
n=len(lanes)
print('lanes',n,'waves',-(-n//20),'total effort',round(tot),'files',len(keep),'dropped0game',len(dropped0))
big=[l for l in lanes if l['eff']>TARGET*2.5];print('oversize',len(big))
