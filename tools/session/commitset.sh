#!/bin/zsh
# usage: commitset.sh "<label>" <prev_exact> <prev_repro>   (run after foldin.sh)
set -e
cd <home>/Documents/aletheia
S=${ALETHEIA_SCRATCH:-/private/tmp/claude-501/-Users-ilias-Documents-aletheia/0da4c159-a458-434b-9491-68afdc3fd61a/scratchpad}
LABEL="$1"; PEX="$2"; PRP="$3"
OUT=$(python3 $S/pending_pct.py 2>&1 | tail -2)
EX=$(echo "$OUT" | grep '^exact' | sed -E 's/.* ([0-9]+\.[0-9]{2})[0-9]*%.*/\1/')
RP=$(echo "$OUT" | grep '^reproduced' | sed -E 's/.* ([0-9]+\.[0-9]{2})[0-9]*%.*/\1/')
NF=$(echo "$OUT" | grep '^exact' | sed -E 's/.*, ([0-9]+) functions.*/\1/')
if [ -z "$EX" ] || [ -z "$RP" ] || [ -z "$NF" ]; then echo "figures missing: $OUT"; exit 1; fi
python3 - "$EX" "$NF" <<'PY'
import re,sys
ex,nf=sys.argv[1],sys.argv[2]
p='README.md'; s=open(p).read()
s2=re.sub(r'\d*\.?\d*% of ARM9 game code ships as verified C \(\d* functions', f'{ex}% of ARM9 game code ships as verified C ({nf} functions', s)
assert s2!=s or f'{ex}% of ARM9' in s, 'README pattern not found'
open(p,'w').write(s2)
PY
DEX=$(python3 -c "print(f'{float('$EX')-float('$PEX'):+.2f}')")
DRP=$(python3 -c "print(f'{float('$RP')-float('$PRP')-(float('$EX')-float('$PEX')):+.2f}')")
python3 - <<'PY' > $S/inc.txt
import json,glob,subprocess
sharded={}
for f in glob.glob('layout/matched/arm9/pkt_*.json'):
    for e in json.load(open(f))['functions']: sharded[e['source']]=f
st=subprocess.run(['git','status','--short'],capture_output=True,text=True).stdout.splitlines()
for l in st:
    if l.startswith('?? src/matched/') and l[3:] in sharded: print(l[3:])
PY
N=$(wc -l < $S/inc.txt | tr -d ' ')
git add -u
git add README.md layout/matched docs/families docs/notes docs/idioms src/pending 2>/dev/null || true
if [ "$N" -gt 0 ]; then xargs git add < $S/inc.txt; fi
git commit -q -m "$LABEL: $N functions exact, exact coverage $EX percent ($DEX); reproduced coverage $RP percent (pending part $DRP)"
git push -q origin main
git log --oneline -1
echo "$EX $RP $NF"
