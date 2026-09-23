#!/bin/zsh
# fold-in: refresh figures, rebuild ROM, regenerate maps, print sharded/unsharded untracked sources
set -e
cd <home>/Documents/aletheia
S=${ALETHEIA_SCRATCH:-/private/tmp/claude-501/-Users-ilias-Documents-aletheia/0da4c159-a458-434b-9491-68afdc3fd61a/scratchpad}
python3 tools/worklist.py --refresh 2>&1 | tail -1
python3 $S/promote_fast.py --dry 2>&1 | tail -1
python3 $S/pending_pct.py 2>&1 | tail -2
python3 tools/build.py --split --pack 2>&1 | tail -1
python3 tools/ndsrom.py build extract -o build/pokeblack.nds --override build/pack 2>&1 | grep sha1
python3 tools/coveragemap.py 2>&1 | tail -1
python3 - <<'PY'
import json,glob,subprocess
sharded={}
for f in glob.glob('layout/matched/arm9/pkt_*.json'):
    for e in json.load(open(f))['functions']: sharded[e['source']]=f
st=subprocess.run(['git','status','--short'],capture_output=True,text=True).stdout.splitlines()
unt=[l[3:] for l in st if l.startswith('?? src/matched/')]
print('INCLUDE', ' '.join(u for u in unt if u in sharded)); print('HOLD', ' '.join(u for u in unt if u not in sharded))
PY
git status --short | grep "^?? layout" || true
