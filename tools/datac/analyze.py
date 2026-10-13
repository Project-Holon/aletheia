import json,glob,re,sys
from collections import Counter
res={}
for f in glob.glob(sys.argv[1] if len(sys.argv)>1 else 'batch_c*.json'): res.update(json.load(open(f)))
c=Counter(); why=Counter(); st=Counter(); bl=Counter()
passed=[]
for rg,r in sorted(res.items()):
    s=r['stage']; ok=r.get('ok')
    c[(s,ok)]+=1
    if s=='data' and ok:
        passed.append(rg)
        for k,v in r['stats'].items(): st[k]+=v
        for b in r['blockers']:
            b=re.sub(r'[0-9A-F]{8}','X',b); b=re.sub(r'\[\d+\]','[n]',b); b=re.sub(r'\b[A-Za-z_]\w*_X\b','NAME',b)
            bl[b[:80]]+=1
        st['gap_bytes']+=sum(int(b,16)-int(a,16) for a,b in r['gaps'])
        st['absolute']+=r['absolute'] or 0
    else:
        w=r.get('why') or str(r.get('diffs'))[:100]
        w=re.sub(r'ov\d{3}','ovN',w); w=re.sub(r'[0-9A-F]{8}','X',w); w=re.sub(r'0x[0-9a-f]+','A',w)
        why[(rg, w[:160])]+=1
print(dict(c)); print('PASS', len(passed)); print(dict(st))
for b,n in bl.most_common(15): print(' blocker',n,b)
for (rg,w),n in sorted(why.items()): print(' FAIL',rg,w.replace('\n',' ')[:220])
