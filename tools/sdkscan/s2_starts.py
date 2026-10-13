"""Stage 2: function starts per region, our names, our src/game file per address. -> starts.pkl"""
import sys,os,re,glob,json,pickle
import os; R = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))).replace(chr(92), '/')
sys.path.insert(0,R+'/tools')
import ovstats, sdkobj as so
regs=so.regions()
listing={'arm9':'asm/arm9/main.s','arm9_autoload0_ITCM':'asm/arm9/itcm.s','arm9_autoload1_MAIN_TWL':'asm/arm9/autoload1_main_twl.s',
 'arm9_autoload2_MAIN_TWL':'asm/arm9/autoload2_main_twl.s','arm9_autoload3_VRAM_LCDC':'asm/arm9/vram_lcdc.s','twl':'asm/twl/twl.s'}
for n in regs:
    if n.startswith('ov'): listing[n]='asm/overlays/%s.s'%n
fsmap={'arm9_main':'arm9','arm9_itcm':'arm9_autoload0_ITCM'}
starts={r:{} for r in regs}   # region -> addr -> source tags
def add(r,a,src):
    if r not in regs: return
    reg=regs[r]
    if not (reg.base<=a<reg.base+len(reg.data)): return
    starts[r].setdefault(a,set()).add(src)
for r,p in listing.items():
    fp=os.path.join(R,p)
    if not os.path.exists(fp): print('no listing',r); continue
    head,labels,insns=ovstats.scan_listing(fp)
    for a,l in labels: add(r,a,'L')
for l in open(R+'/layout/function_starts.txt'):
    m=re.match(r'(\S+)\s+0x([0-9A-Fa-f]+)',l)
    if not m: continue
    rn=m.group(1); r=fsmap.get(rn) or ('ov%03d'%int(rn[8:]) if rn.startswith('overlay_') else rn)
    add(r,int(m.group(2),16),'F')
names={}
for p in glob.glob(R+'/layout/matched/**/*.json',recursive=True):
    sh=json.load(open(p))
    def walk(ents):
        for f in ents or []:
            if isinstance(f,dict) and f.get('address'):
                r=str(f.get('region') or sh.get('region')).lower() if False else (f.get('region') or sh.get('region'))
                a=int(f['address'],16)
                names[(r,a)]=f['name']
                add(r,a,'M')
            if isinstance(f,dict) and f.get('functions'): walk(f['functions'])
    walk(sh.get('functions') or sh.get('entries'))
# our src/game files
rev={}
for (r,a),n in names.items(): rev[(r,n)]=a
sdk=json.load(open(R+'/layout/symbols_sdk.json'))['symbols']
for s in sdk: rev.setdefault((s['region'],s['name']),s['address'])
file_of={}; unres=0; nfiles=0
fre=re.compile(r'^\s*\*\s*(\w+):\s*(.*)$')
for fp in glob.glob(R+'/src/game/**/*.c',recursive=True):
    rel=os.path.relpath(fp,R).replace(chr(92),'/')
    lines=open(fp,encoding='utf-8',errors='replace').read().split('\n')[:400]
    reg=None; fn=''; infn=False
    for ln in lines:
        if ln.strip().startswith('*/'): break
        m=fre.match(ln)
        if m:
            infn = m.group(1)=='function'
            if infn: fn=m.group(2)
            if m.group(1)=='region': reg=m.group(2).strip()
            continue
        if infn and re.match(r'^\s*\*\s{3,}\S',ln): fn+=' '+ln.split('*',1)[1].strip()
        else: infn=False
    if reg is None: reg=rel.split('/')[2]
    nfiles+=1
    for n in [x.strip() for x in fn.split(',') if x.strip()]:
        m=re.fullmatch(r'(?:func|sub)_([0-9A-Fa-f]{8})',n)
        a=int(m.group(1),16) if m else rev.get((reg,n))
        if a is None: unres+=1; continue
        file_of[(reg,a)]=rel
        add(reg,a,'S')
print('files',nfiles,'unresolved fn names',unres,'mapped',len(file_of))
for r in starts:
    if starts[r]: print(r,len(starts[r]))
codesz={}
for r,p in listing.items():
    fp=os.path.join(R,p)
    if not os.path.exists(fp): continue
    head,labels,insns=ovstats.scan_listing(fp)
    ccb=ovstats.code_bytes_from(insns,sorted(starts[r]))
    for a in starts[r]: codesz[(r,a)]=ccb.get(a,0)
pickle.dump((starts,names,file_of,codesz),open('starts.pkl','wb'))
