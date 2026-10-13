import re,os,json,collections,sys
import os; R=os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))).replace(chr(92),'/')
G=R+'/src/game'
sd=json.load(open(R+'/layout/symbols_sdk.json'))
sdk_addr=set();sdk_name=set()
for s in sd['symbols']:
    sdk_addr.add((s['region'],s['address']));sdk_name.add(s['name'])
files=[]
for dp,dn,fn in os.walk(G):
    for f in fn:
        if f.endswith('.c'): files.append(os.path.join(dp,f).replace(chr(92),'/'))
files.sort()
# pass1: parse headers
info={}
alladdr=collections.defaultdict(set)
def hdr(t):
    i=t.find('*/'); h=t[:i] if t.startswith('/*') else ''
    return h,t[i+2:] if h else t
for f in files:
    t=open(f,errors='replace').read()
    h,body=hdr(t)
    rel=f[len(G)+1:]
    reg=rel.split('/')[0]
    m=re.search(r'^ \* function:\s*(.*(?:\n \*\s{8,}.*)*)',h,re.M)
    fnames=re.findall(r'[A-Za-z_]\w*',m.group(1)) if m else []
    comp=(re.search(r'^ \* compiler:\s*(\S+)',h,re.M) or [None,''])[1]
    status=(re.search(r'^ \* status:\s*(\S+)',h,re.M) or [None,''])[1]
    sdkhdr=bool(re.search(r'^ \* sdk:',h,re.M))
    hreg=(re.search(r'^ \* region:\s*(\S+)',h,re.M) or [None,reg])[1]
    info[f]=dict(rel=rel,reg=reg,hreg=hreg,fn=fnames,comp=comp,status=status,sdk=sdkhdr,body=body,t=t,hdr=bool(h))
    for n in fnames:
        m2=re.match(r'(?:ov\d+_)?func_([0-9A-F]{8})$',n)
        if m2: alladdr[reg].add(int(m2.group(1),16))
for s in sd['symbols']:
    alladdr[s['region'].split('_ITCM')[0] if False else s['region']].add(s['address'])
srt={r:sorted(a) for r,a in alladdr.items()}
import bisect
def size(reg,a):
    l=srt.get(reg,[]);i=bisect.bisect_right(l,a)
    if i>=len(l): return 64
    return min(l[i]-a,8192)
addrre=re.compile(r'^(?:Obj\d{3,6}|[A-Za-z]{1,6}_[0-9A-F]{6,8}|[A-Za-z]+[0-9A-F]{8})$')
skipnames=re.compile(r'^(func|sub|d|g|abs_id|pkt|unit|ov\d+_func|ov\d+_d)_')
rawre=re.compile(r'\(\s*(?:u8|s8|char|unsigned char|signed char|void)\s*\*\s*\)\s*\(?\s*\w+\s*\)?\s*\+\s*(?:0x[0-9A-Fa-f]+|\d+)')
fpre=re.compile(r'\(\s*[A-Za-z_][\w ]*\*?\s*\(\s*\*\s*\)\s*\([^()]*\)\s*\)')
rows=[]
for f in files:
    d=info[f];t=d['t'];body=d['body'];rel=d['rel']
    reg=d['reg']
    fn=d['fn']
    game=0;sdkn=0;gsize=0;funcnames=0
    for n in fn:
        m=re.match(r'(?:ov\d+_)?func_([0-9A-F]{8})$',n)
        if m:
            a=int(m.group(1),16)
            issdk=(d['hreg'],a) in sdk_addr or (reg,a) in sdk_addr
            funcnames+=1
        else:
            issdk=n in sdk_name
        if issdk: sdkn+=1
        else:
            game+=1
            if m: gsize+=size(reg,a)
            else: gsize+=size(reg,0) if False else 0
    views=set()
    for m in re.finditer(r'#include\s+"([^"]+)"',body):
        p=m.group(1)
        if 'matched/include/' in p:
            views.add(os.path.basename(p)[:-2])
    for m in re.finditer(r'\bstruct\s+(\w+)|\}\s*(\w+)\s*;|\btypedef\b[^;{]*?\b(\w+)\s*;',body):
        for n in m.groups():
            if n and addrre.match(n) and not skipnames.match(n): views.add(n)
    raw=len(rawre.findall(body)); fp=len(fpre.findall(body))
    stand=len(re.findall(r'stand-in',body,re.I))
    vol=sum(1 for l in body.split('\n') if 'volatile' in l and not re.search(r'0x04[0-9A-Fa-f]{6}|\bREG_|\bHW_|\bREG\b',l))
    body_nc=re.sub(r'/\*.*?\*/','',body,flags=re.S)
    refs=set(re.findall(r'\b(?:func|sub)_[0-9A-F]{8}\b',body_nc))
    asm=len(re.findall(r'^\s*(?:static\s+)?(?:\w+\s+\*?\s*)?asm\s+[\w\s\*]*\w+\s*\(',body_nc,re.M))+len(re.findall(r'\b__asm\b|\basm\s*\{',body_nc))
    lines=body.count(chr(10))
    skip=''
    if rel.startswith('twl/'): skip='twl'
    elif d['sdk']: skip='sdk-header'
    elif fn and game==0: skip='all-sdk'
    elif re.search(r'2\.0|1\.2',d['comp']) and game>=0: skip='lib-compiler('+d['comp']+')'
    loc=[]
    for m in re.finditer(r'#include\s+"([^"]+)"',body):
        p=m.group(1)
        if 'matched/' in p: continue
        q=os.path.normpath(os.path.join(os.path.dirname(f),p)).replace(chr(92),'/')
        if q.startswith(G) and os.path.exists(q): loc.append(q[len(G)+1:])
    rows.append(dict(file=rel,region=reg,compiler=d['comp'],status=d['status'],fns=len(fn),game=game,sdk=sdkn,mixed=(1 if sdkn and game else 0),bytes=gsize,views=len(views),raw=raw,fnptr=fp,standin=stand,volatile_other=vol,func_names=funcnames,func_refs=len(refs),asm=asm,lines=lines,skip=skip,hdrs=','.join(sorted(set(loc)))))
cols=['file','region','compiler','status','fns','game','sdk','mixed','bytes','views','raw','fnptr','standin','volatile_other','func_names','func_refs','asm','lines','skip','hdrs']
with open('census.tsv','w') as o:
    o.write('\t'.join(cols)+'\n')
    for r in rows: o.write('\t'.join(str(r[c]) for c in cols)+'\n')
print(len(rows))
