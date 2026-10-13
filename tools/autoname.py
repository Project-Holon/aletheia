#!/usr/bin/env python3
"""autoname.py: propose names for game functions by machine.

Reads src/game, layout/ and extract/ (read only) and writes one TSV row per
game function.  It never edits a file; cleanup lanes confirm or fix the
proposals.  The naming standard is docs/NAMING.md: game functions are
`MODULE_VerbObject`, the module is the source file name in upper case with
its underscores kept, SDK names stay real.  The output holds addresses and
names only (and assert text, which comes from tools/assertnames.py), so keep
it out of git like the assert table.

usage
  python tools/autoname.py --out autoname.tsv [--asserts FILE] [--region R]
                           [--stats]
  --asserts  a TSV written by tools/assertnames.py; without it the tool runs
             assertnames.py into the scratch directory first.

Output columns (tab separated, one header line):
  address  region  file  current  proposed  confidence  evidence

Determinism: inputs are read in sorted order, ties break on address, and no
rule uses randomness or dict order.  Two runs on the same tree give the same
file.

Which functions get a row
  Every top-level definition in src/game/<region>/**/*.c whose name is an
  address name (func_XXXXXXXX or sub_XXXXXXXX).  Left out, and only counted:
  * SDK functions: the address is in layout/symbols_sdk.json or
    layout/sdk_class.json (real names, never renamed);
  * the twl region (TwlSDK code);
  * library code: a file group built with a compiler other than 1.1p1 that
    has no `__FILE__` anchor (NitroSystem and vendor objects), a group whose
    only anchors are vendor names (dwc_*), and a group in which most
    functions already are SDK functions.
  A "file group" is one source file of src/game: name_p01.c, name_p02.c and
  the member folder name/ count as one.

Module (the part before the CamelCase word)
  M1 anchor function   the function itself references a `__FILE__` string
                       (layout/file_anchors.txt): that file.            high
  M2 anchor bracket    the nearest anchors before and after it, by address
                       in the same file group, name the same file.      high
  M3 anchor nearest    otherwise the anchor before it in the file group
                       (the next one when none precedes).  Merged groups can
                       hold several original files, so this is a guess.
                                                                       medium
  M4 file name         the group is named after an anchor file but holds no
                       anchor of its own: that name.                   medium
  M5 callers           NAMING.md rule 3: the module most of its callers have
                       (callees when it has no caller), same region, counting
                       only modules from M1 to M4.                        low
  M6 placeholder       nothing above: the group's file name, unit_X -> UNIT_X,
                       other names get the region in front.               low
  net.c and net_*.c use GFL_NET and GFL_NET_* (NAMING.md rule 6).  A module
  whose first token is also an SDK prefix (snd_mic.c -> SND_) loses one level
  and the evidence says so.

Verb and object (the CamelCase part).  Rules run in this order; the first
that fires wins.  The row's confidence is the lower of module and verb.
  Discovered library roles (no hard-coded addresses): the allocator is the
  callee that receives the `__FILE__` string in 5 or more anchor functions
  and has 4+ parameters and a pointer result (the assert hook also receives
  the file but fails that shape); the release function is the 1-parameter
  function with the most callers in the allocator's file group.
  V2  proc table       a run of words after the region's last function holds
                       function pointers in groups of three, each int-
                       returning with 2 to 4 parameters, at least one with 4
                       (GFL_PROC_DATA shape): Init, Main, Exit.        medium
  V3  constructor      calls the allocator and returns a pointer: Create.
                       high when the function is the anchor itself (it hands
                       its own `__FILE__` to the allocator), else      medium
  V4  destructor       1 parameter, void, last call is the release
                       function, no allocation: Delete.                medium
  V5  work size        no calls, returns an expression, and some caller passes
                       its result to the allocator: GetWorkSize.       medium
  V6  accessor         one statement, no call:
                         return p->f;              Get<F>
                         return &p->f; / p + K     Get<F>Ptr
                         return p->f == k; / !p->f Is<F>
                         p->f = v;                 Set<F>
                         p->f += v; -= |= &=       Add/Sub/SetFlag/ClearFlag<F>
                         p->f++; p->f--;           Inc/Dec<F>
                       several stores of constants to fields: Init.
                       F is the field name; offset-style names (unk0C, f1C,
                       h1a4, raw offsets, p[i]) give Field<hex offset>.
                       medium for a real field name, low for an offset.
                       p->f = call(...) gives Set<F>, low.
  V7  memory           only MI_CpuClear*/MI_CpuFill* calls: Init; only
                       MI_CpuCopy*: Copy.                              medium
  V8  SDK wrapper      one call to an SDK function that passes on only its
                       parameters and constants: the SDK name without its
                       prefix (FS_ReadFile -> ReadFile).               medium
                       arguments picked from fields or globals:           low
  V9  SDK family       calls only SDK functions of one family (GX/G2/G3 ->
                       Graphics, FS -> File, SND -> Sound, OS -> System, MI
                       -> Memory, MTX/VEC/FX -> Calc ...): the shared plain
                       verb (Set, Get, Init ...) or Setup, then the family.
                                                                          low
  V10 game wrapper     one call to a game function that already has a
                       behaviour verb (V2 to V11): its CamelCase part, one
                       level below it (low when arguments come from fields);
                       4 rounds, so wrapper chains resolve.
  V11 note             the first descriptive sentence of the comment above
                       the definition (matching-lane notes; metadata lines
                       such as "extent:" or "Lever:" are skipped) starts with
                       a verb from a fixed table (Stops -> Stop, Returns ->
                       Get, Releases -> Delete ...) and up to two following
                       nouns give the object; or it holds a role word
                       (constructor, teardown, getter, setter).           low
  V15 boolean          every return is 0, 1, TRUE, FALSE or a comparison:
                       Check<addr low 4 hex>.                             low
  V12 empty            empty body: Dummy.                                 low
  V13 callback         its address is passed as an argument to another
                       function: Task (void, 2 parameters, receiver takes 3+
                       arguments: the GFL_TCB shape) or Callback.        low
  V16 phase            exactly one calling function, whose verb is Init,
                       Create, Exit, Delete, Main, Update, Draw or Print:
                       Setup, Cleanup, Update or Draw, plus <addr low 4 hex>.
                       3 rounds, so a helper of a helper inherits the phase.
                                                                          low
  V17 callee verbs     2 or more game callees with behaviour verbs, a strict
                       majority of them share one verb (getters and checks do
                       not count: calling a getter does not make a getter):
                       that verb, the module it calls into most, <addr4>. low
  V14 fallback         Func<addr low 4 hex>; the evidence lists the modules
                       and SDK prefixes it calls into most.               low
  V1  assert           applied last: a function with an assert expression
                       (tools/assertnames.py) keeps its verb, the evidence
                       gets the expression, and when no rule fired the name
                       is Check<first asserted field>.                 medium

Duplicates: the lowest address keeps a name; a later row with the same name
gets _<addr low 4 hex> (then the full address) and drops one level.

Evidence column: module rule and verb rule with their concrete reason (anchor
file and address, table address, callee, field, assert string address), ';'
separated.  --stats prints counts per rule and confidence.
"""
import argparse
import bisect
import collections
import json
import os
import re
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
TREE = os.path.join(ROOT, 'src', 'game')
LAYOUT = os.path.join(ROOT, 'layout')
EXTRACT = os.path.join(ROOT, 'extract')

ADDR_NAME = re.compile(r'^(?:func|sub)_([0-9A-Fa-f]{8})$')
GAME_COMPILERS = {'1.1p1', 'dsi/1.1p1'}
LEVELS = ['low', 'medium', 'high']

# ---------------------------------------------------------------------------
# text helpers
# ---------------------------------------------------------------------------

_MASK_RE = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|'
                      r'^[ \t]*#(?:[^\n]*\\\n)*[^\n]*', re.S | re.M)


def mask(s):
    """Blank comments, strings, chars and preprocessor lines, same length."""
    return _MASK_RE.sub(lambda m: re.sub(r'[^\n]', ' ', m.group(0)), s)


DEF_RE = re.compile(r'(?:^|(?<=[;}/]))[ \t]*((?:(?:static|inline|__inline|asm|extern)\s+)*)'
                    r'([A-Za-z_][\w\s\*]*?)\b([A-Za-z_]\w*)\s*\(([^;{}()]*(?:\([^;{}()]*\)[^;{}()]*)*)\)\s*\{',
                    re.M)
KEYWORDS = {'if', 'while', 'for', 'switch', 'return', 'sizeof', 'else', 'do', 'case',
            'goto', 'void', 'int', 'char', 'short', 'long', 'unsigned', 'signed',
            'const', 'volatile', 'struct', 'union', 'enum', 'static', 'u8', 'u16', 'u32',
            's8', 's16', 's32', 'BOOL', 'fx32', 'fx16', 'asm', 'register'}


def level_min(a, b):
    return LEVELS[min(LEVELS.index(a), LEVELS.index(b))]


def level_down(a):
    return LEVELS[max(0, LEVELS.index(a) - 1)]


def camel(s):
    """field or identifier -> CamelCase word (unk0C -> Field0C)."""
    m = UNK_FIELD.match(s)
    if m:
        return 'Field%02X' % int(m.group(1) or m.group(2) or m.group(3), 16)
    parts = re.split(r'[_\W]+', s)
    out = ''
    for p in parts:
        if not p:
            continue
        out += p[0].upper() + p[1:]
    return out or 'X'


UNK_FIELD = re.compile(r'^(?:(?i:unk|field|off|pad|[a-z]{1,2}|_)_?((?=[0-9A-Fa-f]*\d)[0-9A-Fa-f]+)'
                       r'|[a-z]{1,2}_?([0-9A-F]+)|f([0-9a-f]+))$')


def is_unk_field(s):
    return bool(UNK_FIELD.match(s)) or bool(re.match(r'^[a-z]$', s))


# ---------------------------------------------------------------------------
# inventory
# ---------------------------------------------------------------------------

class Func:
    __slots__ = ('callees', 'name', 'addr', 'region', 'rel', 'group', 'stem', 'compiler', 'params',
                 'nparams', 'ret', 'body', 'rawbody', 'note', 'calls', 'refs', 'strings',
                 'module', 'mconf', 'mev', 'verb', 'vconf', 'vev', 'skip', 'anchor')

    def __init__(self):
        self.calls = []
        self.refs = []
        self.strings = []
        self.module = None
        self.verb = None
        self.skip = None
        self.anchor = None


def header_field(raw, key):
    m = re.search(r'^\s*\*\s*' + key + r':\s*(.*)$', raw[:20000], re.M)
    return m.group(1).strip() if m else ''


def file_group(rel):
    """src/game/ov021/field_effect_p01.c and src/game/ov021/field_effect/x.c
    -> (ov021, field_effect)."""
    parts = rel.split('/')
    region = parts[2]
    if len(parts) > 4:
        stem = parts[3]
    else:
        stem = os.path.splitext(parts[3])[0]
    stem = re.sub(r'_p\d\d$', '', stem)
    return region, stem


def matching_brace(m, start):
    d = 0
    for i in range(start, len(m)):
        c = m[i]
        if c == '{':
            d += 1
        elif c == '}':
            d -= 1
            if d == 0:
                return i
    return len(m) - 1


def preceding_note(raw, pos):
    """Comment text directly above a definition (blank lines allowed)."""
    i = pos
    out = []
    while True:
        seg = raw[:i].rstrip()
        if seg.endswith('*/'):
            j = seg.rfind('/*')
            if j < 0:
                break
            line_start = seg.rfind('\n', 0, j) + 1
            if seg[line_start:j].strip():
                # comment shares the line with code; take it only if it is the
                # trailing part of a one-line comment run
                out.append(seg[j:])
                break
            out.append(seg[j:])
            i = line_start
            continue
        break
    txt = ' '.join(reversed(out))
    txt = re.sub(r'/\*|\*/|^\s*\*', ' ', txt, flags=re.M)
    return re.sub(r'\s+', ' ', txt).strip()


def load_tree(regions=None):
    funcs = []
    for region in sorted(os.listdir(TREE)):
        rdir = os.path.join(TREE, region)
        if not os.path.isdir(rdir) or (regions and region not in regions):
            continue
        for dp, dn, fn in os.walk(rdir):
            dn.sort()
            for f in sorted(fn):
                if not f.endswith('.c') or f.startswith('_'):
                    continue
                p = os.path.join(dp, f)
                rel = os.path.relpath(p, ROOT).replace(os.sep, '/')
                funcs.extend(parse_file(p, rel, region))
    return funcs


def parse_file(path, rel, region):
    raw = open(path, 'rb').read().decode('latin1').replace('\r\n', '\n')
    m = mask(raw)
    compiler = header_field(raw, 'compiler')
    _, stem = file_group(rel)
    out = []
    pos = 0
    depth_ok = depth_index(m)
    for mm in DEF_RE.finditer(m):
        name = mm.group(3)
        if name in KEYWORDS:
            continue
        rt = mm.group(2).split()
        if not rt or any(t in ('return', 'else', 'typedef', 'case') for t in rt):
            continue
        if depth_ok(mm.start(3)) != 0:
            continue
        ob = mm.end() - 1
        cb = matching_brace(m, ob)
        fn = Func()
        fn.name = name
        am = ADDR_NAME.match(name)
        fn.addr = int(am.group(1), 16) if am else None
        fn.region = region
        fn.rel = rel
        fn.group = (region, stem)
        fn.stem = stem
        fn.compiler = compiler
        fn.params = split_params(mm.group(4))
        fn.nparams = len(fn.params)
        fn.ret = ' '.join(rt + (['*'] if '*' in mm.group(2) else []))
        fn.body = m[ob + 1:cb]
        fn.rawbody = raw[ob + 1:cb]
        line_start = raw.rfind('\n', 0, mm.start(2)) + 1
        fn.note = preceding_note(raw, line_start)
        fn.strings = re.findall(r'"((?:\\.|[^"\\\n])*)"', fn.rawbody)
        for cm in re.finditer(r'\b([A-Za-z_]\w*)\s*\(', fn.body):
            if cm.group(1) not in KEYWORDS:
                fn.calls.append(cm.group(1))
        for rm in re.finditer(r'\b([A-Za-z_]\w*)\b(?!\s*\()', fn.body):
            nm = rm.group(1)
            if ADDR_NAME.match(nm):
                fn.refs.append(nm)
        out.append(fn)
    return out


def split_params(txt):
    out, d, cur = [], 0, ''
    for c in txt:
        if c == '(':
            d += 1
        elif c == ')':
            d -= 1
        if c == ',' and d == 0:
            out.append(cur)
            cur = ''
        else:
            cur += c
    out.append(cur)
    out = [re.sub(r'\s+', ' ', x).strip() for x in out]
    return [x for x in out if x and x != 'void']


def param_name(ptxt):
    m = re.search(r'\(\s*\*\s*(\w+)\s*\)', ptxt)
    if m:
        return m.group(1)
    m = re.search(r'(\w+)\s*(?:\[[^\]]*\])*\s*$', ptxt)
    return m.group(1) if m else ''


def depth_index(m):
    pos, dep = [], []
    d = 0
    for i, c in enumerate(m):
        if c == '{':
            d += 1
            pos.append(i)
            dep.append(d)
        elif c == '}':
            d -= 1
            pos.append(i)
            dep.append(d)

    def at(p):
        i = bisect.bisect_left(pos, p)
        return dep[i - 1] if i else 0
    return at



# ---------------------------------------------------------------------------
# layout inputs
# ---------------------------------------------------------------------------

def norm_region(s):
    if s == 'arm9_main':
        return 'arm9'
    if s.startswith('overlay_'):
        return 'ov' + s[8:]
    return s


def load_sdk():
    """({(region, addr): name}, set of names) of SDK functions."""
    addrs, names = {}, set()
    d = json.load(open(os.path.join(LAYOUT, 'symbols_sdk.json')))
    for x in d['symbols']:
        addrs.setdefault((norm_region(x['region']), x['address']), x['name'])
        names.add(x['name'])
    p = os.path.join(LAYOUT, 'sdk_class.json')
    if os.path.exists(p):
        d = json.load(open(p))
        for r, tab in sorted(d['regions'].items()):
            for a, x in sorted(tab.items()):
                addrs.setdefault((norm_region(r), int(a, 16)), x['name'])
                names.add(x['name'])
    return addrs, names


def resolve_calls(ix, sdk_addrs, sdk_names):
    """f.callees: one entry per call in body order, an SDK name (str), a
    game Func, or None when the callee is not known."""
    for f in ix.funcs:
        if f.addr is None:
            continue
        out = []
        for c in f.calls:
            out.append(callee_of(ix, f.region, c, sdk_addrs, sdk_names))
        f.callees = out


def callee_of(ix, region, c, sdk_addrs, sdk_names):
    if c in sdk_names:
        return c
    g = ix.resolve(region, c)
    if g is None:
        m = ADDR_NAME.match(c)
        if m:
            a = int(m.group(1), 16)
            for r in (region, 'arm9', 'arm9_autoload0_ITCM'):
                if (r, a) in sdk_addrs:
                    return sdk_addrs[(r, a)]
        return None
    if (g.region, g.addr) in sdk_addrs:
        return sdk_addrs[(g.region, g.addr)]
    return g


def load_anchors():
    """{(region, func addr): file name}"""
    out = {}
    for line in open(os.path.join(LAYOUT, 'file_anchors.txt')):
        if line.startswith('#') or not line.strip():
            continue
        site, fn, reg, sa, name = line.split()[:5]
        out[(norm_region(reg), int(fn, 16))] = name
    return out


def scratch():
    try:
        import env
        return env.scratch_dir()
    except Exception:  # noqa: BLE001
        import tempfile
        d = os.path.join(tempfile.gettempdir(), 'aletheia')
        os.makedirs(d, exist_ok=True)
        return d


def load_asserts(path):
    """{(region, addr): [(string addr, expression)]}"""
    if not path:
        path = os.path.join(scratch(), 'autoname_asserts.tsv')
        subprocess.run([sys.executable, os.path.join(HERE, 'assertnames.py'), '--out', path],
                       check=True, stdout=subprocess.DEVNULL)
    out = collections.defaultdict(list)
    for line in open(path, encoding='latin1'):
        f = line.rstrip('\n').split('\t')
        if len(f) < 4 or f[0] == 'region':
            continue
        m = ADDR_NAME.match(f[2])
        if m:
            out[(f[0], int(m.group(1), 16))].append((f[1], f[3]))
    return out


def load_images():
    """[(region, base, bytes)] of the arm9 static module and every decompressed
    overlay; read only, nothing of it is written out."""
    lay = json.load(open(os.path.join(LAYOUT, 'layout.json')))
    out = []
    p = os.path.join(EXTRACT, 'arm9_dec.bin')
    if os.path.exists(p):
        st = lay['arm9']['static']
        out.append(('arm9', st['ram_start'], open(p, 'rb').read()[:st['size']]))
    for o in lay['overlays']:
        p = os.path.join(EXTRACT, o['decompressed_file'].replace('/', os.sep))
        if os.path.exists(p):
            out.append(('ov%03d' % o['id'], o['ram_start'], open(p, 'rb').read()))
    return out


# ---------------------------------------------------------------------------
# index and call graph
# ---------------------------------------------------------------------------

class Index:
    def __init__(self, funcs):
        self.funcs = funcs
        self.by = {}
        self.byaddr = collections.defaultdict(list)
        for f in funcs:
            if f.addr is not None:
                self.by[(f.region, f.addr)] = f
                self.byaddr[f.addr].append(f)

    def resolve(self, region, name):
        """Callee of `name` seen from `region`: own region, then arm9, then
        ITCM, then the one overlay that defines the address."""
        m = ADDR_NAME.match(name)
        if not m:
            return None
        a = int(m.group(1), 16)
        for r in (region, 'arm9', 'arm9_autoload0_ITCM'):
            f = self.by.get((r, a))
            if f:
                return f
        c = self.byaddr.get(a, [])
        return c[0] if len(c) == 1 else None


def build_graph(ix):
    callers = collections.defaultdict(list)
    for f in ix.funcs:
        if f.addr is None:
            continue
        seen = set()
        for c in f.calls:
            g = ix.resolve(f.region, c)
            if g is not None and id(g) not in seen:
                seen.add(id(g))
                callers[id(g)].append(f)
    return callers


# ---------------------------------------------------------------------------
# skip and module rules
# ---------------------------------------------------------------------------

def module_of_file(name):
    stem = name[:-2] if name.endswith('.c') else name
    if stem == 'net' or stem.startswith('net_'):
        return 'GFL_' + stem.upper()
    return re.sub(r'[^A-Za-z0-9_]', '_', stem).upper()


def assign_skip(funcs, sdk_addrs, sdk_names, anchors):
    groups = collections.defaultdict(list)
    for f in funcs:
        groups[f.group].append(f)
    for g in sorted(groups):
        fl = groups[g]
        names = {anchors[(f.region, f.addr)] for f in fl if (f.region, f.addr) in anchors}
        sdkdefs = sum(1 for f in fl if f.addr is None and f.name in sdk_names)
        sdkaddr = sum(1 for f in fl if f.addr is not None and (f.region, f.addr) in sdk_addrs)
        comp = fl[0].compiler if fl else ''
        why = None
        if g[0] == 'twl':
            why = 'twl region (TwlSDK)'
        elif names and all(n.startswith('dwc_') for n in names):
            why = 'vendor anchor ' + ','.join(sorted(names))
        elif not names and comp and comp not in GAME_COMPILERS:
            why = 'library compiler %s, no game anchor' % comp
        elif (sdkdefs + sdkaddr) * 2 > len(fl):
            why = 'file mostly SDK (%d of %d)' % (sdkdefs + sdkaddr, len(fl))
        for f in fl:
            if f.addr is None:
                f.skip = 'named'
            elif (f.region, f.addr) in sdk_addrs:
                f.skip = 'SDK address'
            elif why:
                f.skip = why


def assign_modules(ix, anchors, callers):
    groups = collections.defaultdict(list)
    for f in ix.funcs:
        if f.addr is not None:
            groups[f.group].append(f)
    for g in sorted(groups):
        fl = sorted(groups[g], key=lambda f: f.addr)
        an = [(f.addr, anchors[(f.region, f.addr)]) for f in fl if (f.region, f.addr) in anchors]
        addrs = [a for a, _ in an]
        for f in fl:
            k = (f.region, f.addr)
            if k in anchors:
                f.anchor = anchors[k]
                f.module, f.mconf, f.mev = module_of_file(anchors[k]), 'high', 'M1 anchor %s' % anchors[k]
                continue
            if not an:
                continue
            i = bisect.bisect_right(addrs, f.addr)
            prev = an[i - 1] if i else None
            nxt = an[i] if i < len(an) else None
            if prev and nxt and prev[1] == nxt[1]:
                f.module, f.mconf, f.mev = module_of_file(prev[1]), 'high', \
                    'M2 between anchors of %s (%08X, %08X)' % (prev[1], prev[0], nxt[0])
            elif prev:
                f.module, f.mconf, f.mev = module_of_file(prev[1]), 'medium', \
                    'M3 after anchor %s at %08X' % (prev[1], prev[0]) + \
                    (' (next anchor %s at %08X)' % (nxt[1], nxt[0]) if nxt else '')
            else:
                f.module, f.mconf, f.mev = module_of_file(nxt[1]), 'medium', \
                    'M3 before anchor %s at %08X' % (nxt[1], nxt[0])
    anchored = {module_of_file(n) for n in anchors.values()}
    for f in ix.funcs:
        if f.addr is None or f.module:
            continue
        if module_of_file(f.stem) in anchored:
            f.module, f.mconf, f.mev = module_of_file(f.stem), 'medium', 'M4 file name %s.c' % f.stem
    # M5: callers, then callees, counting only anchor-derived modules
    for f in sorted(ix.funcs, key=lambda f: (f.region, f.addr or 0)):
        if f.addr is None or f.module:
            continue
        c = collections.Counter(g.module for g in callers.get(id(f), [])
                                if g.module and g.region == f.region and g.mev[:2] in ('M1', 'M2', 'M3', 'M4'))
        how = 'callers'
        if not c:
            for n in f.calls:
                g = ix.resolve(f.region, n)
                if g is not None and g.module and g.region == f.region and \
                        g.mev[:2] in ('M1', 'M2', 'M3', 'M4'):
                    c[g.module] += 1
            how = 'callees'
        if c:
            best = sorted(c.items(), key=lambda kv: (-kv[1], kv[0]))[0]
            f.module, f.mconf, f.mev = best[0], 'low', 'M5 %s: %s %d of %d' % (
                how, best[0], best[1], sum(c.values()))
        else:
            ph = f.stem if f.stem.startswith('unit_') else f.region + '_' + f.stem
            f.module, f.mconf, f.mev = re.sub(r'\W', '_', ph).upper(), 'low', \
                'M6 placeholder from file %s' % f.stem


# ---------------------------------------------------------------------------
# verb rules
# ---------------------------------------------------------------------------

CAST = re.compile(r'\(\s*(?:const\s+|volatile\s+)*(?:struct\s+|union\s+|unsigned\s+|signed\s+)?'
                  r'[A-Za-z_]\w*(?:\s+[A-Za-z_]\w*)?\s*(?:\*\s*)*\)(?=\s*[\w\(&\*])')
ELEM = {'u8': 1, 's8': 1, 'char': 1, 'u16': 2, 's16': 2, 'short': 2}


def strip_casts(e):
    prev = None
    while prev != e:
        prev = e
        e = CAST.sub('', e).strip()
        e = re.sub(r'^\(([^()]*)\)$', r'\1', e).strip()
    return e


def statements(body):
    s = re.sub(r'\s+', ' ', body).strip()
    return [x.strip() for x in s.split(';') if x.strip()]


def elem_size(f, var):
    for p in f.params:
        if param_name(p) == var:
            t = p.replace('*', ' * ').split()
            base = [x for x in t if x not in ('const', 'volatile', 'unsigned', 'signed', 'struct')]
            if p.count('*') >= 2:
                return 4
            if base and base[0] in ELEM:
                return ELEM[base[0]]
            if 'char' in t:
                return 1
            if 'short' in t:
                return 2
            return 4
    return None


def field_of(f, e):
    """(Word, named) of a field access expression, or None."""
    e = strip_casts(e)
    e = e.lstrip('&').strip()
    e = strip_casts(e)
    m = re.match(r'^\(?\s*\**\s*[A-Za-z_]\w*\s*\)?\s*((?:(?:->|\.)\s*\w+\s*(?:\[[^\]]*\])*\s*)+)$', e)
    if m:
        last = re.findall(r'(?:->|\.)\s*(\w+)', m.group(1))[-1]
        return camel(last), not is_unk_field(last)
    m = re.match(r'^\*\s*\(\s*\(?\s*([A-Za-z_]\w*)\s*\)?\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)$', e)
    if m:
        return 'Field%02X' % int(m.group(2), 0), False
    m = re.match(r'^([A-Za-z_]\w*)\s*\[\s*(0x[0-9A-Fa-f]+|\d+)\s*\]$', e)
    if m and elem_size(f, m.group(1)):
        return 'Field%02X' % (int(m.group(2), 0) * elem_size(f, m.group(1))), False
    m = re.match(r'^\*\s*([A-Za-z_]\w*)$', e)
    if m and elem_size(f, m.group(1)):
        return 'Field00', False
    return None


def sdk_base(sdkname):
    """(VerbObject, Verb) of an SDK name: FS_ReadFile -> (ReadFile, Read)."""
    base = re.sub(r'^[A-Z0-9]+i?_', '', sdkname)
    base = base[:1].upper() + base[1:]
    m = re.match(r'[A-Z][a-z0-9]*', base)
    return base, (m.group(0) if m else base)


SDK_FAMILY = {'GX': 'Graphics', 'GXS': 'Graphics', 'G2': 'Graphics', 'G2S': 'Graphics',
              'G3': 'Graphics', 'G3X': 'Graphics', 'G3i': 'Graphics', 'FS': 'File',
              'SND': 'Sound', 'CARD': 'Card', 'RTC': 'Rtc', 'TP': 'TouchPanel', 'MATH': 'Calc',
              'FX': 'Calc', 'VEC': 'Calc', 'MTX': 'Calc', 'CP': 'Calc', 'OS': 'System',
              'PAD': 'Key', 'WM': 'Wireless', 'MI': 'Memory'}
PLAIN_VERBS = {'Set', 'Get', 'Init', 'Load', 'Reset', 'Clear', 'Start', 'Stop', 'Read',
               'Write', 'Wait', 'Is', 'Check', 'Open', 'Close', 'Enable', 'Disable'}


def has_call(s):
    for m in re.finditer(r'\b([A-Za-z_]\w*)\s*\(', CAST.sub('', s)):
        if m.group(1) not in KEYWORDS:
            return True
    return False


def store_call(f, s):
    """V6: `p->f = call(...)`: Set<F> (low, the value comes from a call)."""
    m = re.match(r'^([^=()]+?|[^=]*?->\s*\w+)\s*=\s*([^=].*)$', s)
    if m and not m.group(1).strip().startswith('return'):
        fo = field_of(f, m.group(1))
        if fo:
            return 'Set' + fo[0], False, 'V6 stores a call result to field %s' % fo[0]
    return None


def accessor(f):
    """V6: one-statement leaf that reads, tests or stores one field."""
    st = statements(f.body)
    if len(st) != 1 or '{' in f.body:
        return None
    s = st[0]
    if has_call(s):
        return store_call(f, s)
    m = re.match(r'^return\s+(.*)$', s)
    if m:
        e = strip_casts(m.group(1))
        cm = re.match(r'^\(?\s*(.*?)\s*(==|!=)\s*(?:0x[0-9A-Fa-f]+|\d+|NULL|TRUE|FALSE|[A-Z_][A-Z0-9_]*)\s*\)?$', e) \
            or re.match(r'^!\s*\(?(.*?)\)?$', e)
        if cm:
            fo = field_of(f, cm.group(1))
            if fo:
                return 'Is' + fo[0], fo[1], 'V6 returns a test of field %s' % fo[0]
            return None
        pm = re.match(r'^\(?\s*([A-Za-z_]\w*)\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)?$', e)
        if pm and elem_size(f, pm.group(1)):
            off = int(pm.group(2), 0) * elem_size(f, pm.group(1))
            return 'GetField%02XPtr' % off, False, 'V6 returns parameter + 0x%X' % off
        fo = field_of(f, e)
        if fo:
            ptr = e.startswith('&')
            return 'Get' + fo[0] + ('Ptr' if ptr else ''), fo[1], \
                'V6 returns %sfield %s' % ('the address of ' if ptr else '', fo[0])
        return None
    m = re.match(r'^(.+?)\s*(\+|-|\||&)?=\s*([^=].*)$', s)
    if m:
        fo = field_of(f, m.group(1))
        if fo:
            verb = {'+': 'Add', '-': 'Sub', '|': 'SetFlag', '&': 'ClearFlag'}.get(m.group(2), 'Set')
            return verb + fo[0], fo[1], 'V6 stores field %s' % fo[0]
        return None
    m = re.match(r'^(.+?)\s*(\+\+|--)$', s) or re.match(r'^(?:\+\+|--)\s*(.+)$', s)
    if m:
        fo = field_of(f, m.group(1))
        if fo:
            verb = 'Inc' if '++' in s else 'Dec'
            return verb + fo[0], fo[1], 'V6 %s field %s' % (verb.lower() + 'rements', fo[0])
    return None


def bool_shape(f):
    """Every return gives 0, 1, TRUE, FALSE or a comparison, and the type is
    an integer."""
    r = f.ret.split()
    if '*' in f.ret or not r or r[-1] not in ('int', 'BOOL', 'u8', 'u16', 'u32', 's32', 'char', 'bool'):
        return False
    rets = re.findall(r'\breturn\b\s*([^;]*);', f.body)
    if not rets:
        return False
    cmp = 0
    for e in rets:
        e = strip_casts(e.strip())
        if re.match(r'^(?:0|1|TRUE|FALSE)$', e):
            continue
        if re.search(r'==|!=|<=|>=|(?<![-<])<(?!<)|(?<![->])>(?!>)|^!|&&|\|\|', e):
            cmp += 1
            continue
        return False
    return cmp > 0 or len(rets) >= 2


def multi_store_init(f):
    st = statements(f.body)
    if len(st) < 2 or '{' in f.body or has_call(f.body):
        return False
    for s in st:
        m = re.match(r'^(.+?)\s*=\s*(-?\s*(?:0x[0-9A-Fa-f]+|\d+)|NULL|FALSE|TRUE)$', s)
        if not m or not field_of(f, m.group(1)):
            return False
    return True


def forward_call(f, loose=False):
    """Callee name when the body is one call that passes on only parameters
    and constants.  loose: arguments may also be fields of a parameter or
    globals (a thin wrapper that picks its arguments out of a work struct)."""
    st = statements(f.body)
    if len(st) != 1 or '{' in f.body:
        return None
    s = strip_casts(re.sub(r'^return\s+', '', st[0]))
    m = re.match(r'^([A-Za-z_]\w*)\s*\((.*)\)$', s)
    if not m or m.group(1) in KEYWORDS:
        return None
    pn = {param_name(p) for p in f.params}
    for a in split_params(m.group(2)):
        a = strip_casts(a)
        if a in pn or re.match(r'^-?(0x[0-9A-Fa-f]+|\d+)[uU]?$', a) or a in ('NULL', 'TRUE', 'FALSE'):
            continue
        if loose and not has_call(a) and (field_of(f, a) or re.match(r'^&?\s*[A-Za-z_]\w*$', a)):
            continue
        return None
    return m.group(1)


NOTE_SKIP = re.compile(r'^(?:lever|extent|note|addresses|unlabelled|verified|generated|emitted|'
                       r'volatile|trailing|prototype|promoted|interface|follower|tail|blocked|evidence|'
                       r'abi|file|tu|closed|unblocked|parked|exact\*?|matching|byte-correct|part|'
                       r'pattern-generated|\d{4}-\d\d-\d\d|p\d+|leaf witness|previously|a whole)\b', re.I)
NOTE_VERBS = {
    'stop': 'Stop', 'stops': 'Stop', 'start': 'Start', 'starts': 'Start', 'store': 'Set',
    'stores': 'Set', 'set': 'Set', 'sets': 'Set', 'read': 'Get', 'reads': 'Get', 'return': 'Get',
    'returns': 'Get', 'picks': 'Get', 'pick': 'Get', 'look': 'Get', 'looks': 'Get', 'maps': 'Get',
    'allocate': 'Create', 'allocates': 'Create', 'build': 'Create', 'builds': 'Create',
    'release': 'Delete', 'releases': 'Delete', 'free': 'Delete', 'frees': 'Delete',
    'destroy': 'Delete', 'destroys': 'Delete', 'run': 'Main', 'runs': 'Main', 'count': 'Count',
    'counts': 'Count', 'fill': 'Init', 'fills': 'Init', 'clear': 'Clear', 'clears': 'Clear',
    'reset': 'Reset', 'resets': 'Reset', 'draw': 'Draw', 'draws': 'Draw', 'print': 'Print',
    'prints': 'Print', 'load': 'Load', 'loads': 'Load', 'check': 'Check', 'checks': 'Check',
    'test': 'Check', 'tests': 'Check', 'copy': 'Copy', 'copies': 'Copy', 'update': 'Update',
    'updates': 'Update', 'wait': 'Wait', 'waits': 'Wait', 'send': 'Send', 'sends': 'Send',
    'play': 'Play', 'plays': 'Play', 'sort': 'Sort', 'sorts': 'Sort', 'compare': 'Compare',
    'compares': 'Compare', 'find': 'Search', 'finds': 'Search', 'search': 'Search',
    'searches': 'Search', 'add': 'Add', 'adds': 'Add', 'remove': 'Remove', 'removes': 'Remove',
    'move': 'Move', 'moves': 'Move', 'convert': 'Convert', 'converts': 'Convert',
    'register': 'Add', 'registers': 'Add', 'unregister': 'Remove', 'init': 'Init',
    'initialise': 'Init', 'initialize': 'Init', 'initialises': 'Init', 'initializes': 'Init',
    'setup': 'Setup', 'sets up': 'Setup', 'apply': 'Apply', 'applies': 'Apply', 'open': 'Open',
    'opens': 'Open', 'close': 'Close', 'closes': 'Close', 'enable': 'Enable', 'enables': 'Enable',
    'disable': 'Disable', 'disables': 'Disable', 'write': 'Write', 'writes': 'Write',
    'decode': 'Decode', 'decodes': 'Decode', 'encode': 'Encode', 'encodes': 'Encode',
    'calculate': 'Calc', 'calculates': 'Calc', 'compute': 'Calc', 'computes': 'Calc',
    'show': 'Show', 'shows': 'Show', 'hide': 'Hide', 'hides': 'Hide', 'push': 'Push',
    'pushes': 'Push', 'pop': 'Pop', 'pops': 'Pop', 'advance': 'Advance', 'advances': 'Advance',
    'poll': 'Update', 'polls': 'Update', 'tick': 'Update', 'ticks': 'Update', 'step': 'Update',
    'steps': 'Update', 'scroll': 'Scroll', 'scrolls': 'Scroll', 'select': 'Select',
    'selects': 'Select', 'change': 'Change', 'changes': 'Change', 'swap': 'Swap', 'swaps': 'Swap',
    'insert': 'Insert', 'inserts': 'Insert', 'delete': 'Delete', 'deletes': 'Delete',
    'create': 'Create', 'creates': 'Create', 'make': 'Make', 'makes': 'Make', 'tear': 'Delete',
    'tears': 'Delete', 'teardown': 'Delete',
}
NOTE_DET = {'the', 'a', 'an', 'its', 'this', 'that', 'one', 'every', 'all', 'each', 'both', 'two',
            'three', 'four', 'their', 'his', 'her', 'own', 'given', 'current', 'caller', "caller's",
            'up', 'down', 'out', 'back'}
NOTE_STOP = {'for', 'from', 'to', 'into', 'in', 'on', 'at', 'of', 'with', 'by', 'and', 'or',
             'then', 'when', 'if', 'as', 'via', 'off', 'over', 'under', 'onto', 'is', 'are',
             'that', 'which', 'while', 'than', 'but', 'so', 'unless', 'after', 'before'}


def note_object(words):
    out = []
    for w in words:
        lw = w.lower().rstrip("'s").rstrip("'")
        if lw in NOTE_STOP or not re.match(r"^[a-z][a-z'-]*$", w.lower()):
            break
        if not out and lw in NOTE_DET:
            continue
        if lw in NOTE_DET:
            break
        out.append(re.sub(r"'s?$", '', lw))
        if len(out) == 2:
            break
    return ''.join(camel(x.replace('-', '_')) for x in out)


NOTE_RULES = [
    (re.compile(r'\bconstructor\b|\bcreates?\b', re.I), 'Create'),
    (re.compile(r'\bdestructor\b|\bdestroys?\b|\bteardown\b|\btears?\b.*\bdown\b', re.I), 'Delete'),
    (re.compile(r'\bsetter\b', re.I), 'Set'),
    (re.compile(r'\bgetter\b|\baccessor\b|^returns\b|\blookup\b', re.I), 'Get'),
    (re.compile(r'^(?:clears?|zero(?:es|s)?|resets?|initiali[sz]es?)\b', re.I), 'Init'),
    (re.compile(r'^(?:draws?|prints?|renders?)\b', re.I), 'Draw'),
    (re.compile(r'^(?:loads?)\b', re.I), 'Load'),
    (re.compile(r'^(?:checks?|tests?)\b', re.I), 'Check'),
    (re.compile(r'^(?:copies|copy)\b', re.I), 'Copy'),
]


def note_verb(f):
    """V11: (VerbObject, evidence) from the first descriptive sentence of the
    note above the definition."""
    if not f.note:
        return None
    for sent in re.split(r'(?<=[.;/])\s+', f.note)[:4]:
        sent = re.sub(r'^(?:[\w]+\.c\S*\s+)', '', sent.strip())
        if not sent or NOTE_SKIP.match(sent):
            continue
        words = re.findall(r"[A-Za-z][A-Za-z'-]*|\S", sent)
        if not words:
            continue
        w0 = words[0].lower()
        if w0 in NOTE_VERBS:
            return NOTE_VERBS[w0] + note_object(words[1:]), 'V11 note "%s"' % sent[:60]
        for rx, verb in NOTE_RULES:
            if rx.search(sent):
                return verb, 'V11 note "%s"' % sent[:60]
        return None
    return None


def proc_shape(fns):
    if len({id(g) for g in fns}) != 3:
        return False
    for g in fns:
        r = g.ret.split()
        if '*' in g.ret or not r or r[-1] not in ('int', 'u32', 's32', 'BOOL') or not 2 <= g.nparams <= 4:
            return False
    return max(g.nparams for g in fns) == 4


def find_proc_tables(ix, images):
    """{id(func): (slot, table addr, region)} for GFL_PROC_DATA-shaped triples
    in the data after a region's last function."""
    out = {}
    byreg = collections.defaultdict(dict)
    for f in ix.funcs:
        if f.addr is not None:
            byreg[f.region][f.addr] = f
    arm9 = byreg.get('arm9', {})
    for reg, base, data in images:
        own = byreg.get(reg, {})
        if not own:
            continue
        start = (max(own) - base + 3) & ~3
        n = (len(data) - start) // 4
        if n <= 0:
            continue
        words = struct.unpack_from('<%dI' % n, data, start)

        def res(w):
            a = w & ~1
            return own.get(a) or arm9.get(a)
        i = 0
        while i < n:
            if not res(words[i]):
                i += 1
                continue
            j = i
            while j < n and res(words[j]):
                j += 1
            if (j - i) % 3 == 0:
                for k in range(i, j, 3):
                    fns = [res(w) for w in words[k:k + 3]]
                    if proc_shape(fns):
                        for slot, g in zip(('Init', 'Main', 'Exit'), fns):
                            out.setdefault(id(g), (slot, base + start + 4 * k, reg))
            i = j
    return out


def discover_heap(ix, anchors, callers):
    """Callees that receive the __FILE__ string in 5 or more anchor functions.
    Those with 4+ parameters and a pointer result are allocators; the others
    (the assert hook) are left out.  The release function is the 1-parameter
    function with the most callers in the main allocator's file group."""
    cnt = collections.Counter()
    for (r, a), name in sorted(anchors.items()):
        f = ix.by.get((r, a))
        if not f:
            continue
        for m in re.finditer(r'\b(\w+)\s*\(([^;]*)\)\s*;', f.rawbody):
            if name in m.group(2) or re.search(r'_File\b', m.group(2)):
                g = ix.resolve(r, m.group(1))
                if g is not None:
                    cnt[(g.region, g.addr)] += 1
    ranked = [k for k, v in sorted(cnt.items(), key=lambda kv: (-kv[1], kv[0])) if v >= 5]
    allocs = [k for k in ranked if ix.by[k].nparams >= 4 and '*' in ix.by[k].ret]
    freer = None
    if allocs:
        grp = ix.by[allocs[0]].group
        cands = [g for g in ix.funcs if g.group == grp and g.addr is not None and g.nparams == 1]
        cands.sort(key=lambda g: (-len(callers.get(id(g), [])), g.addr))
        if cands:
            freer = (cands[0].region, cands[0].addr)
    return allocs, freer, cnt


# ---------------------------------------------------------------------------
# driver
# ---------------------------------------------------------------------------

def rule_id(ev):
    """The verb rule of an evidence string (V1 is reported only when it is the
    only rule)."""
    ids = re.findall(r'(?:^|; )(V\d+) ', ev)
    rest = [x for x in ids if x != 'V1']
    return rest[-1] if rest else (ids[-1] if ids else '?')


def run(args):
    funcs = load_tree(set(args.region) if args.region else None)
    ix = Index(funcs)
    sdk_addrs, sdk_names = load_sdk()
    anchors = load_anchors()
    asserts = load_asserts(args.asserts)
    callers = build_graph(ix)
    resolve_calls(ix, sdk_addrs, sdk_names)
    assign_skip(funcs, sdk_addrs, sdk_names, anchors)
    assign_modules(ix, anchors, callers)
    procs = find_proc_tables(ix, load_images())
    allocs, freer, _ = discover_heap(ix, anchors, callers)
    alloc_objs = {id(ix.by[k]) for k in allocs}
    alloc_name = ix.by[allocs[0]].name if allocs else None
    free_obj = ix.by[freer] if freer else None

    worksize = {}
    taken = collections.defaultdict(list)
    for f in funcs:
        if f.addr is None:
            continue
        for m in re.finditer(r'\b(\w+)\s*\(([^;{}]*)\)', f.body):
            cg = callee_of(ix, f.region, m.group(1), sdk_addrs, sdk_names)
            if not isinstance(cg, str) and cg is not None and id(cg) in alloc_objs:
                for c in re.findall(r'\b((?:func|sub)_[0-9A-Fa-f]{8})\s*\(\s*\)', m.group(2)):
                    g = ix.resolve(f.region, c)
                    if g is not None:
                        worksize.setdefault(id(g), f.name)
            for a in re.findall(r'\b(?:func|sub)_[0-9A-Fa-f]{8}\b(?!\s*\()', m.group(2)):
                g = ix.resolve(f.region, a)
                if g is not None and m.group(1) not in KEYWORDS:
                    taken[id(g)].append((m.group(1), len(split_params(m.group(2)))))

    work = [f for f in funcs if f.addr is not None and not f.skip]
    for f in work:
        k = id(f)
        flat = re.sub(r'\s+', ' ', f.body).strip()
        sdk_calls = [c for c in f.callees if isinstance(c, str)]
        game_calls = [c for c in f.callees if c is not None and not isinstance(c, str)]
        calls_alloc = any(id(c) in alloc_objs for c in game_calls)
        acc = accessor(f)
        if k in procs:
            slot, ta, reg = procs[k]
            f.verb, f.vconf, f.vev = slot, 'medium', 'V2 proc table %08X slot %s' % (ta, slot)
        elif calls_alloc and '*' in f.ret and 'return' in flat:
            f.verb, f.vconf, f.vev = 'Create', 'high' if f.anchor else 'medium', 'V3 calls allocator %s, returns a pointer' % alloc_name
        elif free_obj is not None and f.callees and f.callees[-1] is free_obj and f.nparams == 1 and \
                f.ret.strip() == 'void' and not calls_alloc:
            f.verb, f.vconf, f.vev = 'Delete', 'medium', 'V4 ends with the heap release %s' % free_obj.name
        elif k in worksize and not f.calls and re.match(r'^return [^;]*;?$', flat):
            f.verb, f.vconf, f.vev = 'GetWorkSize', 'medium', \
                'V5 result is the allocator size in %s' % worksize[k]
        elif acc:
            word, named, ev = acc
            f.verb, f.vconf, f.vev = word, 'medium' if named else 'low', ev
        elif multi_store_init(f):
            f.verb, f.vconf, f.vev = 'Init', 'medium', 'V6 only stores constants to fields'
        elif sdk_calls and not game_calls and all(re.match(r'MIi?_Cpu(Clear|Fill)', c) for c in sdk_calls):
            f.verb, f.vconf, f.vev = 'Init', 'medium', 'V7 only clears memory (%s)' % sdk_calls[0]
        elif sdk_calls and not game_calls and all(re.match(r'MIi?_CpuCopy', c) for c in sdk_calls):
            f.verb, f.vconf, f.vev = 'Copy', 'medium', 'V7 only copies memory (%s)' % sdk_calls[0]
        else:
            fw = forward_call(f)
            fw = callee_of(ix, f.region, fw, sdk_addrs, sdk_names) if fw else None
            if isinstance(fw, str):
                f.verb, f.vconf, f.vev = sdk_base(fw)[0], 'medium', 'V8 wrapper of SDK %s' % fw
            elif sdk_calls and not game_calls:
                fams, verbs = set(), set()
                for c in sdk_calls:
                    fams.add(SDK_FAMILY.get(c.split('_')[0].rstrip('i') if c.split('_')[0].endswith('i')
                                            else c.split('_')[0]))
                    verbs.add(sdk_base(c)[1])
                if len(fams) == 1 and None not in fams:
                    v = verbs.pop() if len(verbs) == 1 else 'Setup'
                    if v not in PLAIN_VERBS:
                        v = 'Setup'
                    fam = fams.pop()
                    f.verb, f.vconf, f.vev = v + fam, 'low', 'V9 SDK calls only of family %s (%s)' % (
                        fam, ','.join(sorted(set(sdk_calls))[:3]))
    for _ in range(4):
        changed = False
        for f in work:
            if f.verb:
                continue
            for loose in (False, True):
                fw = forward_call(f, loose)
                g = callee_of(ix, f.region, fw, sdk_addrs, sdk_names) if fw else None
                if isinstance(g, str) and loose:
                    f.verb, f.vconf, f.vev = sdk_base(g)[0], 'low', \
                        'V8 wrapper of SDK %s (arguments picked from fields)' % g
                    changed = True
                    break
                if g is not None and not isinstance(g, str) and g is not f and g.verb and \
                        rule_id(g.vev) not in ('V10', 'V14', 'V15', 'V16'):
                    f.verb = g.verb
                    f.vconf = level_down(g.vconf) if not loose else 'low'
                    f.vev = 'V10 wrapper of %s (%s %s%s)' % (g.name, rule_id(g.vev), g.verb,
                                                             ', arguments picked from fields' if loose else '')
                    changed = True
                    break
        if not changed:
            break
    for f in work:
        if f.verb:
            continue
        nv = note_verb(f)
        if nv:
            f.verb, f.vconf, f.vev = nv[0], 'low', nv[1]
        elif bool_shape(f):
            f.verb, f.vconf, f.vev = 'Check%04X' % (f.addr & 0xFFFF), 'low', \
                'V15 returns only 0/1 or a comparison'
        elif not f.body.strip():
            f.verb, f.vconf, f.vev = 'Dummy', 'low', 'V12 empty body'
        elif id(f) in taken:
            recv, nargs = sorted(taken[id(f)])[0]
            if f.nparams == 2 and f.ret.strip() == 'void' and nargs >= 3:
                f.verb, f.vconf, f.vev = 'Task', 'low', 'V13 passed to %s as a callback (task shape)' % recv
            else:
                f.verb, f.vconf, f.vev = 'Callback', 'low', 'V13 passed to %s as a callback' % recv
    # V16 caller context: one calling function whose verb says what phase
    # this helper belongs to
    phase = {'Init': 'Setup', 'Create': 'Setup', 'Setup': 'Setup', 'Exit': 'Cleanup',
             'Delete': 'Cleanup', 'Main': 'Update', 'Update': 'Update', 'Draw': 'Draw',
             'Print': 'Draw'}
    for _ in range(3):
        for f in work:
            if f.verb:
                continue
            cs = {id(g): g for g in callers.get(id(f), []) if g is not f}
            if len(cs) == 1:
                g = list(cs.values())[0]
                gv = re.match(r'[A-Z][a-z]*', g.verb or '')
                if g.verb and gv and gv.group(0) in phase and rule_id(g.vev) not in ('V14', 'V15'):
                    f.verb, f.vconf, f.vev = '%s%04X' % (phase[gv.group(0)], f.addr & 0xFFFF), 'low', \
                        'V16 only caller %s is %s (%s)' % (g.name, g.verb, rule_id(g.vev))
    # V17 callee verbs: most game callees with a behaviour verb agree on it;
    # the object is the module it calls into most (other than its own)
    strong = ('V2', 'V3', 'V4', 'V5', 'V6', 'V7', 'V8', 'V9', 'V10', 'V11')
    for f in work:
        if f.verb:
            continue
        vc, mc = collections.Counter(), collections.Counter()
        for c in f.callees:
            if c is None or isinstance(c, str):
                continue
            if c.verb and rule_id(c.vev) in strong:
                vc[re.match(r'[A-Z][a-z]*', c.verb).group(0)] += 1
            if c.module and c.module != f.module and c.mev[:2] in ('M1', 'M2', 'M3'):
                mc[c.module] += 1
        for w in ('Get', 'Is', 'Check', 'Field'):
            vc.pop(w, None)
        if not vc:
            continue
        v, n = sorted(vc.items(), key=lambda kv: (-kv[1], kv[0]))[0]
        if n < 2 or n * 2 <= sum(vc.values()):
            continue
        obj = ''
        if mc:
            m, k = sorted(mc.items(), key=lambda kv: (-kv[1], kv[0]))[0]
            obj = camel(m.lower())
        verb = {'Get': 'Get', 'Set': 'Set', 'Create': 'Create', 'Delete': 'Delete', 'Init': 'Init',
                'Is': 'Check', 'Check': 'Check', 'Draw': 'Draw', 'Print': 'Print', 'Load': 'Load',
                'Field': 'Get'}.get(v, v)
        f.verb, f.vconf, f.vev = '%s%s%04X' % (verb, obj, f.addr & 0xFFFF), 'low', \
            'V17 %d of %d callees with a verb are %s%s' % (n, sum(vc.values()), v,
                                                          ', calls into %s' % obj if obj else '')
    for f in work:
        if not f.verb:
            f.verb, f.vconf, f.vev = 'Func%04X' % (f.addr & 0xFFFF), 'low', 'V14 no behaviour rule'
            mods = collections.Counter()
            for c in f.callees:
                if isinstance(c, str):
                    mods[c.split('_')[0] + '_'] += 1
                elif c is not None and c.module and c.module != f.module and c.mev[:2] in ('M1', 'M2'):
                    mods[c.module] += 1
            if mods:
                f.vev += ' (calls into %s)' % ', '.join(
                    '%s x%d' % kv for kv in sorted(mods.items(), key=lambda kv: (-kv[1], kv[0]))[:3])
    for f in work:
        a = asserts.get((f.region, f.addr))
        if not a:
            continue
        exprs = sorted({e for _, e in a})
        fields = [x or y for x, y in re.findall(r'->\s*(\w+)|\.\s*(\w+)', ' '.join(exprs))]
        base = rule_id(f.vev)
        head = 'V1 assert at %s "%s"' % (a[0][0], ' | '.join(exprs))
        if base == 'V14' and fields:
            # the assert checks a field before the work: Check<Field>
            f.verb, f.vconf = 'Check' + camel(fields[0]), 'medium'
            f.vev = head + ', object from the asserted field'
        else:
            f.vev = head + '; ' + f.vev
    rows = []
    sdk_prefixes = {n.split('_')[0] for n in sdk_names if '_' in n and n.split('_')[0].isupper()}
    for f in sorted(work, key=lambda f: (f.region, f.addr)):
        conf = level_min(f.mconf, f.vconf)
        if f.module.split('_')[0] in sdk_prefixes:
            conf = level_down(conf)
            f.vev += '; module prefix %s_ is also an SDK prefix' % f.module.split('_')[0]
        rows.append([f, f.module + '_' + f.verb, conf])
    taken_names = set()
    for r in rows:
        name = r[1]
        if name in taken_names:
            name = '%s_%04X' % (r[1], r[0].addr & 0xFFFF)
            if name in taken_names:
                name = '%s_%08X' % (r[1], r[0].addr)
            if name in taken_names:
                name = '%s_%s_%08X' % (r[1], r[0].region.upper(), r[0].addr)
            r[2] = level_down(r[2])
            r[0].vev += '; name taken by a lower address, suffixed'
        taken_names.add(name)
        r[1] = name
    return funcs, rows, dict(allocs=allocs, freer=freer, procs=procs)


def main():
    ap = argparse.ArgumentParser(description='propose names for game functions')
    ap.add_argument('--out', required=True)
    ap.add_argument('--asserts', help='assertnames.py TSV (the tool runs it when missing)')
    ap.add_argument('--region', action='append', help='limit to a region (repeatable)')
    ap.add_argument('--stats', action='store_true')
    a = ap.parse_args()
    funcs, rows, info = run(a)
    with open(a.out, 'w', newline='\n', encoding='latin1') as fh:
        fh.write('address\tregion\tfile\tcurrent\tproposed\tconfidence\tevidence\n')
        for f, name, conf in rows:
            ev = (f.mev + '; ' + f.vev).replace('\t', ' ')
            fh.write('%08X\t%s\t%s\t%s\t%s\t%s\t%s\n' % (f.addr, f.region, f.rel, f.name, name, conf, ev))
    skipped = collections.Counter(f.skip.split(',')[0] for f in funcs if f.addr is not None and f.skip)
    print('rows %d' % len(rows))
    print('confidence', sorted(collections.Counter(r[2] for r in rows).items()))
    print('skipped', sorted(collections.Counter(re.sub(r' \S*\d\S*', '', s) for s in skipped.elements()).items()))
    if a.stats:
        print('allocators', ['%s %08X' % k for k in info['allocs']],
              'release', info['freer'] and '%s %08X' % info['freer'],
              'proc slots', len(info['procs']))
        print('verb rules', collections.Counter(rule_id(r[0].vev) for r in rows).most_common())
        print('module rules', collections.Counter(r[0].mev.split(' ')[0] for r in rows).most_common())
        print('confidence x verb rule', sorted(collections.Counter(
            (r[2], rule_id(r[0].vev)) for r in rows).items()))
        print('confidence x module rule', sorted(collections.Counter(
            (r[2], r[0].mev.split(' ')[0]) for r in rows).items()))


if __name__ == '__main__':
    main()
