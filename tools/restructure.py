#!/usr/bin/env python3
"""restructure.py: merge the one-function matched files into translation units.

src/matched/ holds one function per file (or one small unit per file), each
verified byte-exact on its own.  The original game was built from source
files, each compiled as one translation unit (TU).  This tool writes those
TUs into a separate tree (src/game/ by default) and leaves src/matched/
untouched, so the per-function matches stay as the verified record.

Input
  A TU list: tools/tuboundary.py's tu_proposal.tsv (region, start, end,
  functions, name, confidence, ...).  Each row is one TU: every listing
  function label in [start, end) of that region.

Merge, per TU
  1. Members: the source file of every function in the range, from the
     EXACT/EXACT* shard entries (layout/matched/<region>/*.json).  A unit
     file that defines several functions is one member.
  2. Compile settings (compiler, flags, -lang, isa) must be the same for every
     member, since one TU is compiled once.  A mixed TU is refused.
  3. Text: each member is split into top-level items.  Types (typedef,
     struct/union/enum definitions and forward declarations), #include lines
     and function prototypes go to one block at the top, each once: an
     identical repeat is dropped, a different text under the same name is a
     conflict.  A prototype of a function the TU defines is replaced by that
     definition's own prototype.  Everything else (statics, globals,
     #pragma/#define lines, function definitions) stays in member order, which
     is address order.
  4. A header comment lists the TU's functions, settings and the union of the
     members' symbols: rows (the relocation witnesses match.py reads).

Verification
  Each TU is compiled once and its .text compared with the original bytes from
  the TU start (match.py run_tu, the `tu` command), in the TU's -lang and, for
  c99 TUs, also without -lang as the per-function checks do.  The report says
  which TUs reproduce, which conflict, and why.

usage
  python tools/restructure.py --proposal TSV [--names a.c,b.c] [--regions ov021,...]
                              [--confidence proven,likely] [--out DIR] [--no-verify]
"""
import argparse
import collections
import csv
import glob
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import protofix as pf  # noqa: E402
import fnaddr  # noqa: E402  (function addresses whatever the name)

ROOT = os.path.dirname(HERE)
SETTINGS = ('compiler', 'flags', 'lang', 'isa')


# ---------------------------------------------------------------------------
# inputs
# ---------------------------------------------------------------------------

def shard_index():
    """{(region, address): (source, entry)} of every EXACT/EXACT* shard entry."""
    import match
    out = {}
    files = match.shard_files_stamped()
    # parsed through match.py's stamp cache (build/cache/shards.pkl); an
    # unparseable shard is skipped
    docs = match.shard_docs(files, on_error=lambda _t, _e: None)
    fnaddr.prefetch_layouts(e for d in docs.values() for e in d.get('functions', [])
                            if isinstance(e, dict) and str(e.get('status', '')).startswith('EXACT'))
    for sp in (t[1] for t in files):
        d = docs.get(sp)
        if not isinstance(d, dict):
            continue
        for e in d.get('functions', []):
            if not isinstance(e, dict) or not str(e.get('status', '')).startswith('EXACT'):
                continue
            try:
                a = int(str(e.get('address')), 16)
            except ValueError:
                continue
            reg = e.get('region') or d.get('region')
            out.setdefault((reg, a), (e.get('source'), e))
            if str(e.get('kind', '')).endswith('_unit') or os.path.basename(e.get('source') or '').startswith('unit_'):
                # the listed members, by address (tools/fnaddr.py: the entry's
                # `addresses`, a func_XXXXXXXX name, or the unit's compiled layout)
                if str(e.get('kind', '')).endswith('_unit'):
                    listed = fnaddr.member_addresses(e)
                else:
                    listed = [(n, fnaddr.name_address(n)) for n in e.get('functions', [])]
                for mname, ma in listed:
                    if ma is not None:
                        out.setdefault((reg, ma), (e.get('source'), dict(e, name=mname)))
                # every function the unit file defines is covered by the unit's
                # check: names ending in an address, and every function symbol of
                # the compiled unit placed from its header address (any name)
                names = []
                try:
                    raw = open(os.path.join(ROOT, e.get('source')), encoding='latin1').read()
                    msk = pf.mask(raw)
                    names += [mm.group(3) for mm in pf.DECL_RE.finditer(msk) if mm.group(5) == '{']
                except (OSError, TypeError):
                    pass
                for mname in names:
                    mm = re.search(r'([0-9A-Fa-f]{8})$', str(mname))
                    if mm:
                        out.setdefault((reg, int(mm.group(1), 16)), (e.get('source'), dict(e, name=mname)))
                for ma, mname in sorted(fnaddr.defined_addresses(e).items()):
                    out.setdefault((reg, ma), (e.get('source'), dict(e, name=mname)))
    return out


def listing_functions(region):
    """Sorted function label addresses of a region's listing (match.py's view)."""
    import match
    return sorted(match.scan_listing(region))


def safe_remove(path):
    """Remove a file; a file locked by another process (a sync client, a virus
    scanner) is retried, then left for the end-of-run cleanup."""
    import time
    for _ in range(10):
        try:
            os.remove(path)
            return True
        except FileNotFoundError:
            return True
        except PermissionError:
            time.sleep(0.5)
    return False


def safe_replace(src, dst):
    import time
    for _ in range(10):
        try:
            os.replace(src, dst)
            return True
        except PermissionError:
            time.sleep(0.5)
    import shutil
    shutil.copyfile(src, dst)
    safe_remove(src)
    return True


def read_proposal(path):
    with open(path, newline='', encoding='utf-8') as f:
        return list(csv.DictReader(f, delimiter='\t'))


# ---------------------------------------------------------------------------
# splitting a file into top-level items
# ---------------------------------------------------------------------------

class Item:
    __slots__ = ('kind', 'key', 'text', 'norm')

    def __init__(self, kind, key, text):
        self.kind, self.key, self.text = kind, key, text
        self.norm = re.sub(r'\s+', ' ', pf.mask(text)).strip()


_HDR = re.compile(r'\A\s*/\*.*?\*/\s*', re.S)
_FUNC_HEAD = re.compile(r'([A-Za-z_]\w*)\s*\(([^;{}]*)\)\s*$', re.S)


def comment_mask(text):
    """text with every comment replaced by spaces (newlines kept); strings and
    character constants are left alone, so a '#' that survives is code."""
    out, i, n = [], 0, len(text)
    nl = chr(10)
    while i < n:
        c = text[i]
        if text.startswith('/*', i):
            j = text.find('*/', i + 2)
            j = n if j < 0 else j + 2
            out.append(''.join(ch if ch == nl else ' ' for ch in text[i:j]))
            i = j
        elif text.startswith('//', i):
            j = text.find(nl, i)
            j = n if j < 0 else j
            out.append(' ' * (j - i))
            i = j
        elif c in (chr(34), chr(39)):
            j = i + 1
            while j < n and text[j] != c and text[j] != nl:
                j += 2 if text[j] == chr(92) else 1
            out.append(text[i:j + 1])
            i = j + 1
        else:
            out.append(c)
            i += 1
    return ''.join(out)


def split_items(raw):
    """Header comment dropped; the rest as a list of Item in text order."""
    m = _HDR.match(raw)
    body = raw[m.end():] if m else raw
    msk = pf.mask(body)
    cm = comment_mask(body)
    items, i, n = [], 0, len(body)
    depth = 0
    start = 0
    while i < n:
        c = msk[i]
        line_start = body.rfind(chr(10), 0, i) + 1
        if depth == 0 and cm[i] == '#' and msk[start:i].strip() == '' and body[line_start:i].strip() == '':
            # a preprocessor line (with backslash continuations)
            j = i
            while True:
                e = body.find('\n', j)
                if e < 0:
                    e = n
                    break
                if body[e - 1:e] == '\\' or body[e - 2:e] == '\\\r':
                    j = e + 1
                    continue
                break
            # classify by the directive itself; a comment before it travels with it
            it = classify(body[i:e + 1], msk[i:e + 1])
            items.append(Item(it.kind, it.key, body[start:e + 1]))
            i = start = e + 1
            continue
        if c in '({[':
            if c == '{' and depth == 0:
                head = msk[start:i]
                hm = _FUNC_HEAD.search(head)
                if hm and '=' not in head and not re.search(r'\b(struct|union|enum)\b[^()]*$', head):
                    # function definition: up to the matching brace
                    j = pf_matching(msk, i)
                    e = j + 1
                    nl = body.find('\n', e)
                    e = n if nl < 0 else nl + 1
                    items.append(Item('func', hm.group(1), body[start:e]))
                    i = start = e
                    continue
            depth += 1
        elif c in ')}]':
            depth -= 1
        elif c == ';' and depth == 0:
            e = i + 1
            nl = body.find('\n', e)
            # a comment after the ';' stays with this item; other code starts a new one
            e = n if nl < 0 else (e if msk[e:nl].strip() else nl + 1)
            items.append(classify(body[start:e], msk[start:e]))
            i = start = e
            continue
        i += 1
    if body[start:].strip():
        items.append(Item('other', None, body[start:]))
    return items


def pf_matching(s, i):
    o = s[i]
    c = {'(': ')', '[': ']', '{': '}'}[o]
    d = 0
    for j in range(i, len(s)):
        if s[j] == o:
            d += 1
        elif s[j] == c:
            d -= 1
            if d == 0:
                return j
    return len(s) - 1


def classify(text, msk):
    rt = text.strip()
    if rt.startswith('#'):
        im = re.match(r'#\s*include\s*["<]([^">]+)[">]', rt)
        if im:
            return Item('include', im.group(1), text)
        return Item('pp', None, text)
    t = re.sub(r'\s+', ' ', msk).strip()
    if not t:
        return Item('blank', None, text)
    if t.startswith('#'):
        im = re.match(r'#\s*include\s*["<]([^">]+)[">]', t)
        if im:
            return Item('include', im.group(1), text)
        return Item('pp', None, text)
    if t.startswith('typedef'):
        nm = re.findall(r'([A-Za-z_]\w*)\s*(?:\[[^\]]*\])*\s*;$', t)
        fp = re.search(r'\(\s*\*\s*([A-Za-z_]\w*)\s*\)', t)
        bm = re.match(r'^typedef\s+(?:struct|union|enum).*\}\s*([A-Za-z_]\w*)\s*;$', t)
        key = bm.group(1) if bm else (fp.group(1) if fp else (nm[-1] if nm else t))
        return Item('type', 'typedef ' + key, text)
    sm = re.match(r'^(?:(?:const|volatile)\s+)?(struct|union|enum)\s+([A-Za-z_]\w*)\s*(\{|;)', t)
    if sm and (sm.group(3) == ';' or t.endswith('};')):
        if sm.group(3) == ';':
            return Item('fwd', '%s %s' % (sm.group(1), sm.group(2)), text)
        return Item('type', '%s %s' % (sm.group(1), sm.group(2)), text)
    if re.match(r'^(?:extern\s+)?[^=]*\b([A-Za-z_]\w*)\s*\([^()]*(?:\([^()]*\)[^()]*)*\)\s*;$', t) \
            and not t.startswith('static') and '=' not in t:
        fm = re.search(r'([A-Za-z_]\w*)\s*\((?:[^()]|\([^()]*\))*\)\s*;$', t)
        if fm and not re.search(r'\(\s*\*', t[:fm.start()]):
            return Item('proto', fm.group(1), text)
    dm = re.match(r'^extern\s+[^(=]*?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\])*\s*;$', t)
    if dm:
        return Item('data', dm.group(1), text)
    return Item('other', None, text)


def local_type_names(items):
    """Names of the types a member defines: 'struct X' tags and typedef names."""
    out = set()
    for it in items:
        if it.kind == 'type':
            k = it.key.split(' ', 1)
            out.add(k[1])
    return out


def rename_types(items, names, suffix):
    """Rename the member's own types `names` to name_suffix in every item."""
    rx = re.compile(r'(?<![\w])(%s)(?![\w])' % '|'.join(re.escape(n) for n in sorted(names, key=len, reverse=True)))
    out = []
    for it in items:
        t = rx.sub(lambda m: m.group(1) + '_' + suffix, it.text)
        if t != it.text:
            n = Item(it.kind, it.key, t)
            if it.kind == 'type':
                kk = it.key.split(' ', 1)
                n.key = kk[0] + ' ' + (kk[1] + '_' + suffix if kk[1] in names else kk[1])
            out.append(n)
        else:
            out.append(it)
    return out


# ---------------------------------------------------------------------------
# merging
# ---------------------------------------------------------------------------

def header_fields(raw):
    return pf.parse_header(raw)


def proto_key(text, td):
    """Type key of a prototype text (protofix's normal form), or None."""
    m = pf.DECL_RE.search(pf.mask(text))
    if not m:
        return None
    try:
        ret, pl, _n = pf.resolve_proto(text[m.start(2):m.end(2)], text[m.start(4):m.end(4)], td)
    except pf.Unrep:
        return None
    return pf.norm_key(ret, pl)


def data_key(text, td):
    """Type key of an extern data declaration, or None."""
    t = re.sub(r'\s+', ' ', pf.mask(text)).strip().rstrip(';')
    t = re.sub(r'^extern\s+', '', t)
    t = re.sub(r'\[[^\]]*\]', '[]', t)
    m = re.match(r'^(.*?)([A-Za-z_]\w*)\s*(\[\])*$', t)
    if not m:
        return None
    try:
        toks = pf.resolve(pf.tokens(m.group(1)), td, set())
    except pf.Unrep:
        return None
    return pf.norm_toks(toks) + ('[]' if m.group(3) else '')


INCLUDE_DIR = os.path.join(ROOT, 'src', 'matched', 'include')


_ROW_TOKENS = ('ov230d', 'twl', 'arm9')


def _row_region(row, region):
    """The region whose listing knows this row's address: the row's own
    overlay/twl token, else the file's region."""
    for tok in row.split()[3:]:
        if re.match(r'^(ov\d{3}|ov230d|twl)$', tok):
            return tok
    return region


def fix_symbol_row(row, region, fallback=None):
    """-> (row the parser accepts, or None, note).  A `code` kind becomes
    thumb or arm: the listing label of the address says which, else the
    fallback rows (same name, kind thumb|arm|data, from other members)."""
    import match
    parts = row.split()
    if len(parts) >= 3 and not re.match(r'^0[xX][0-9A-Fa-f]+$', parts[1]):
        # a mangled address (`0xfunc_0216EC84`) on an address-bearing name
        nm = re.match(r'^(?:func|sub|ov\d+_func)_([0-9A-Fa-f]{8})$', parts[0])
        if nm and parts[1].lower().endswith(nm.group(1).lower()):
            parts[1] = '0x' + nm.group(1)
            row = ' '.join(parts)
    if len(parts) >= 3 and parts[2] == 'code':
        isa = None
        try:
            addr = int(parts[1], 16)
        except ValueError:
            return None, 'bad address'
        for rg in (_row_region(row, region), region, 'arm9'):
            try:
                v = match.scan_listing(rg.replace('ov230d', 'ov230')).get(addr)
            except Exception:
                v = None
            if v is not None:
                isa = 'thumb' if v else 'arm'
                break
        if isa is None:
            # inside a function: the ISA of the label that contains the address
            for rg in (_row_region(row, region), region, 'arm9'):
                try:
                    st_ = match.scan_listing(rg.replace('ov230d', 'ov230'))
                except Exception:
                    continue
                before = [a for a in st_ if a < addr and st_[a] is not None]
                if before and addr - max(before) < 0x400:
                    isa = 'thumb' if st_[max(before)] else 'arm'
                    break
        if isa is None:
            for fb in fallback or ():
                fp = fb.split()
                if len(fp) >= 3 and fp[2] in ('thumb', 'arm') and fp[1].lower() == parts[1].lower():
                    isa = fp[2]
                    break
        if isa is None:
            return None, 'kind code, ISA unknown'
        parts[2] = isa
        row = ' '.join(parts)
    if not match.SYMBOL_RE.match(' *   ' + row):
        return None, 'rejected by match.SYMBOL_RE'
    return row, ''


def merge(members, tu_name, region, start, funcs, out_dir=None, reverse=False):
    """-> (text, problems list, settings dict)."""
    problems = []
    settings = None
    top_types, top_seen = [], {}
    protos = collections.OrderedDict()
    includes, inc_seen = [], set()
    fwds, fwd_seen = [], set()
    body = []
    defined = {}
    symbols = collections.OrderedDict()
    parsed = []
    problems_renamed = []
    dropped_rows = []
    datas = collections.OrderedDict()
    tds = {}
    for rel in members:
        raw = open(os.path.join(ROOT, rel), encoding='latin1', newline='').read().replace('\r\n', '\n')
        if raw.startswith('\xef\xbb\xbf'):
            raw = raw[3:]                       # a UTF-8 byte order mark hides the header
        h = header_fields(raw)
        st = {k: (h.get(k) or '').strip() for k in SETTINGS}
        st['compiler'] = st['compiler'].replace('dsi/', '') or '1.1p1'
        # -proc arm946e is the default target, so it changes nothing
        st['flags'] = re.sub(r'\s+', ' ', re.sub(r'-proc\s+arm946e', '', st['flags'] or '')).strip() or '-O4,p'
        st['isa'] = (st['isa'].split() or ['thumb'])[0]
        if settings is None:
            settings = st
        elif {k: v for k, v in st.items() if k != 'lang'} == {k: v for k, v in settings.items() if k != 'lang'} \
                and {st['lang'], settings['lang']} <= {'', 'c99'}:
            settings['lang'] = 'c99'
        elif st != settings:
            problems.append('settings differ: %s has %s, first member %s' % (rel, st, settings))
        hm = re.match(r'\s*/\*.*?\*/', raw, re.S)
        rows = re.findall(r'^\s*\*\s+(\w+\s+0x[0-9A-Fa-f]{8}\s+\w+(?:\s+\w+)*)\s*$', hm.group(0), re.M) if hm else []
        rows += re.findall(r'^ \*   (\S+\s+0x[0-9A-Fa-f]{8}\s+.*)$', raw, re.M)
        raw_rows = rows
        rows = []
        for row in raw_rows:                    # header rows with any indent, then the usual form anywhere
            fb = [x for x in raw_rows if x.split()[0] == row.split()[0]]
            fixed, why = fix_symbol_row(row.rstrip(), region, fb)
            if fixed is None:
                dropped_rows.append((rel, row.rstrip(), why))
                continue
            rows.append(fixed)
        for row in rows:
            nm_ = row.split()[0]
            prev_ = symbols.get(nm_)
            if prev_ is not None and prev_.split()[1].lower() != row.split()[1].lower():
                # two members put one name at different addresses: a member that
                # defines it (not only declares it) knows the right address
                if re.search(r'^(?!\s*extern)[^;\n]*\b%s\s*(\[[^\]]*\]\s*)*=' % re.escape(nm_), raw, re.M):
                    symbols[nm_] = row.rstrip()
                continue
            symbols.setdefault(nm_, row.rstrip())
        items = split_items(raw)
        try:
            tds[rel] = pf.parse_file(os.path.join(ROOT, rel), rel).td
        except Exception:
            tds[rel] = {}
        parsed.append((rel, items))
        for it in items:
            if it.kind == 'func':
                defined[it.key] = it
    # a local type two members define differently: each member keeps its own copy
    # under its own name (TypeName_ADDR), so the merged file compiles; struct
    # unification later replaces them with one shared type
    seen_def = {}
    clash = set()
    for rel, items in parsed:
        for it in items:
            if it.kind == 'type':
                prev = seen_def.get(it.key)
                if prev is not None and prev != it.norm:
                    clash.add(it.key.split(' ', 1)[1])
                seen_def.setdefault(it.key, it.norm)
    if clash:
        new = []
        for rel, items in parsed:
            mine = local_type_names(items) & clash
            if mine:
                # the member's own first function address (a part file's name
                # carries the TU address, which every part shares)
                hdr_addr = re.search(r'^ \* address:\s*0x([0-9A-Fa-f]{8})',
                                     open(os.path.join(ROOT, rel), encoding='latin1').read(), re.M)
                suf = re.search(r'([0-9A-F]{8})', os.path.basename(rel))
                suf = (hdr_addr.group(1).upper() if hdr_addr else (suf.group(1) if suf else str(len(new))))
                items = rename_types(items, mine, suf)
                problems_renamed.append('%s: %s' % (suf, ','.join(sorted(mine))))
            new.append((rel, items))
        parsed = new
    proto_keys, data_keys = {}, {}
    if reverse:
        # the 1.2/2.0 compilers emit a file's functions last-to-first, so the source
        # lists them in descending address order
        parsed = list(reversed(parsed))
    for rel, items in parsed:
        for it in items:
            if it.kind == 'include':
                inc = it.key
                if inc.startswith('../include/') and out_dir:
                    inc = os.path.relpath(os.path.join(INCLUDE_DIR, inc[len('../include/'):]),
                                          out_dir).replace(os.sep, '/')
                if inc not in inc_seen:
                    inc_seen.add(inc)
                    includes.append('#include "%s"\n' % inc)
            elif it.kind == 'type':
                prev = top_seen.get(it.key)
                if prev is None:
                    top_seen[it.key] = it
                    top_types.append(it)
                elif prev.norm != it.norm:
                    problems.append('type %s differs between members (%s)' % (it.key, rel))
            elif it.kind == 'fwd':
                if it.key not in fwd_seen:
                    fwd_seen.add(it.key)
                    fwds.append(it)
            elif it.kind == 'proto':
                if it.key in defined:
                    continue
                if it.key in datas:
                    problems.append('global %s declared as a function (%s)' % (it.key, rel))
                    continue
                prev = protos.get(it.key)
                k = proto_key(it.text, tds.get(rel, {}))
                if prev is None:
                    protos[it.key] = it
                    proto_keys[it.key] = k
                elif prev.norm.replace('extern ', '') != it.norm.replace('extern ', '') and \
                        (k is None or k != proto_keys.get(it.key)):
                    problems.append('prototype of %s differs between members (%s)' % (it.key, rel))
            elif it.kind == 'data':
                prev = datas.get(it.key)
                k = data_key(it.text, tds.get(rel, {}))
                if prev is None:
                    datas[it.key] = it
                    data_keys[it.key] = k
                elif prev.norm != it.norm and (k is None or k != data_keys.get(it.key)):
                    pk = data_keys.get(it.key)
                    if k and pk and '*' in k and pk in _GENERIC and k not in _GENERIC:
                        datas[it.key] = it          # the specific pointer view wins
                        data_keys[it.key] = k
                    problems.append('global %s declared two ways (%s)' % (it.key, rel))
            elif it.kind == 'blank':
                continue
            else:
                if it.kind in ('other', 'func') and it.norm.startswith('static') and any(
                        b.norm == it.norm for b in body if b.kind == it.kind):
                    continue            # the same static object written in two members
                body.append(it)
    # prototypes for the TU's own functions, so a call before the definition sees it
    own = []
    for it in body:
        if it.kind == 'func':
            # the definition's head without the comment the item carries before it
            head = comment_mask(it.text[:pf.mask(it.text).find('{')]).rstrip()
            head = re.sub(r'\s+', ' ', head).strip()
            if not head.startswith('static') and not re.search(r'\binline\b', head):
                own.append(head + ';\n')
    for name in list(symbols):
        if name in defined:
            del symbols[name]
    s = settings or {}
    hdr = ['/*', ' * file:     %s' % tu_name, ' * unit:     yes',
           ' * function: %s' % ', '.join(funcs),
           ' * address:  0x%08X' % start, ' * region:   %s' % region,
           ' * compiler: dsi/%s' % s.get('compiler', '1.1p1'), ' * flags:    %s' % s.get('flags', '-O4,p'),
           ' * lang:     %s' % s.get('lang', ''), ' * isa:      %s' % s.get('isa', 'thumb'),
           ' * status:   EXACT', ' *',
           ' * Merged by tools/restructure.py from the src/matched files of these functions.']
    if symbols:
        hdr += [' *', ' * symbols:'] + [' *   %s' % r for r in symbols.values()]
    hdr += [' */', '']
    parts = ['\n'.join(hdr), ''.join(includes)]
    if includes:
        parts.append('\n')
    # a #define with one text across the members goes to the top (a macro expands
    # where it is used, so defining it early is safe); a name defined two ways
    # stays in member order with an #undef before the second definition
    defs = collections.OrderedDict()
    for it in body:
        dm = re.match(r'\s*#\s*define\s+(\w+)', it.text) if it.kind == 'pp' else None
        if dm:
            defs.setdefault(dm.group(1), []).append(it.text.strip())
    hoisted = set()
    for k, v in defs.items():
        if len({re.sub(r'\s+', ' ', x) for x in v}) == 1:
            hoisted.add(k)
            parts.append(v[0] + '\n')
    for it in fwds:
        parts.append(it.text.strip() + '\n')
    for it in top_types:
        parts.append(it.text.strip() + '\n\n')
    for it in protos.values():
        if it.key in datas:
            continue
        parts.append(it.text.strip() + '\n')
    seen_own = set()
    for o in own:
        if o not in seen_own:
            seen_own.add(o)
            parts.append(o)
    for it in datas.values():
        parts.append(it.text.strip() + '\n')
    parts.append('\n')
    seen_def = set()
    for it in body:
        dm = re.match(r'\s*#\s*define\s+(\w+)', it.text) if it.kind == 'pp' else None
        if dm and dm.group(1) in hoisted:
            continue
        if dm and dm.group(1) in seen_def:
            parts.append('#undef %s\n' % dm.group(1))
        if dm:
            seen_def.add(dm.group(1))
        parts.append(it.text.rstrip() + '\n\n')
    text = ''.join(parts).rstrip() + '\n'
    if out_dir:
        inc = os.path.relpath(INCLUDE_DIR, out_dir).replace(os.sep, '/') + '/'
        text = re.sub(r'(#\s*include\s*")\.\./include/', lambda m: m.group(1) + inc, text)
    for rel_, row_, why_ in dropped_rows:
        print('symbols row dropped (%s): %s: %s' % (why_, rel_, row_), file=sys.stderr, flush=True)
    return text, problems, settings, problems_renamed


# ---------------------------------------------------------------------------
# verification
# ---------------------------------------------------------------------------

def write_folder(out, region, name, members, problems, verdict, funcs, r):
    """Fallback for a TU that does not merge: src/game/<region>/<tu>/ with the member
    files and MERGE.md."""
    d = os.path.join(out, region, name[:-2] if name.endswith('.c') else name)
    os.makedirs(d, exist_ok=True)
    inc = os.path.relpath(INCLUDE_DIR, d).replace(os.sep, '/') + '/'
    for rel in members:
        with open(os.path.join(ROOT, rel), 'rb') as f:
            t = f.read()
        t = t.replace(b'"../include/', b'"' + inc.encode())
        with open(os.path.join(d, os.path.basename(rel)), 'wb') as f:
            f.write(t)
    lines = ['# %s (%s)' % (name, region), '',
             'Translation unit %s..%s, %d functions, confidence %s (tools/tuboundary.py).'
             % (r['start'], r['end'], len(funcs), r['confidence']), '',
             'The member files below each match on their own. Merging them into one',
             '`%s` is blocked by:' % name, '']
    lines += ['- ' + p for p in problems] or ['- the merged file does not compile or match: ' + verdict]
    if verdict and problems:
        lines += ['', 'Merged-file check: ' + verdict]
    lines += ['', 'Members, in address order:', ''] + ['- `%s`' % os.path.basename(m) for m in members]
    lines += ['', 'To merge: give each listed global and function one declaration that every',
              'member compiles against byte-exact, then run',
              '`python tools/restructure.py --proposal <tsv> --names %s` again.' % name]
    with open(os.path.join(d, 'MERGE.md'), 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(lines) + '\n')
    return d


def verify(path, region, start, settings):
    import match
    out = {}
    flags = settings['flags'].split() if settings['flags'] else ['-O4,p']
    thumb = settings['isa'] == 'thumb'
    langs = [settings['lang'] or None]
    if settings['lang'] == 'c99':
        langs.append(None)
    for lang in langs:
        try:
            r, _tl = match.run_tu(path, start, settings['compiler'], flags, thumb, lang, region=region)
            note = ''
            if r.status == 'CCERR':
                errs = [re.sub(r'^.*?\.c:', 'line ', l.strip()) for l in (r.log or '').splitlines()
                        if re.search(r'\.c:\d+:', l)]
                note = ': ' + ' | '.join(errs[:3])[:300] if errs else ': ' + (r.note or '')[:160]
            if r.status.startswith('EXACT') and r.func is not None:
                bare = match.unattested_names(r.func, match.declared_symbols(match.read_header(path)))
                if bare:
                    out[lang or 'nolang'] = 'MATCH (unattested: %s: no symbols row)' % ', '.join(bare[:6])
                    continue
            out[lang or 'nolang'] = r.status + note
        except (Exception, SystemExit) as e:
            out[lang or 'nolang'] = 'ERROR %r' % (e,)
    return out


_GENERIC = {'void*', 'char*', 'u8*', 's8*', 'const void*', 'const char*', 'const u8*'}


def tu_members(region, fs, idx, allf):
    """(member source files, function names, missing addresses) of the functions fs."""
    members, funcs, missing = [], [], []
    for x in fs:
        src = idx.get((region, x))
        if src is None:
            pos = allf.index(x)
            for y in reversed(allf[:pos]):
                if (region, y) in idx:
                    e = idx[(region, y)]
                    if str(e[1].get('kind', '')).endswith('_unit') or os.path.basename(
                            e[0] or '').startswith('unit_'):
                        src = e
                    break
            if src is None:
                missing.append('%08X' % x)
                continue
            if src[0] not in members:
                members.append(src[0])
            funcs.append('func_%08X' % x)
            continue
        if src[0] not in members:
            members.append(src[0])
        funcs.append(src[1].get('name') or 'func_%08X' % x)
    return members, funcs, missing


def lang_ok(v, settings):
    """The TU matches in its own -lang mode (the mode its header names)."""
    key = settings.get('lang') or 'nolang'
    st = v.get(key, '')
    return st.startswith('EXACT') or st.startswith('MATCH')


def process(a, region, start, end, name, conf, idx, labels, report, prow, allow_folder=True):
    """Merge, write and verify one TU.  Returns the report row."""
    allf = labels[region]
    fs = [x for x in allf if start <= x < end]
    members, funcs, missing = tu_members(region, fs, idx, allf)
    row = {'region': region, 'name': name, 'start': '%08X' % start, 'functions': len(fs),
           'members': len(members), 'confidence': conf}
    if missing or not members:
        row.update(status='skipped', detail=('no EXACT entry for ' + ','.join(missing[:5])) if missing
                   else 'no matched function in range')
        return row, members, funcs, []
    d = os.path.join(a.out, region)
    text, problems, settings, renamed = merge(members, name, region, start, funcs, d)
    row['renamed'] = len(renamed)
    os.makedirs(d, exist_ok=True)
    path = os.path.join(d, name)
    with open(path, 'w', encoding='latin1', newline='\n') as f:
        f.write(text)
    if any(p.startswith('settings differ') for p in problems):
        safe_remove(path)
        row.update(status='conflict', detail='; '.join(problems[:3]), verdict='')
        return row, members, funcs, problems
    if a.no_verify:
        row.update(status='written', detail='; '.join(problems[:3]))
        return row, members, funcs, problems
    v = verify(path, region, start, settings)
    row['verdict'] = ' '.join('%s=%s' % kv for kv in v.items())
    if lang_ok(v, settings):
        # a declaration difference the compiler accepts and the bytes confirm is fine
        row.update(status='ok', detail=('accepted: ' + '; '.join(problems[:3])) if problems else '')
    else:
        safe_remove(path)
        row.update(status='conflict' if problems else 'fail', detail='; '.join(problems[:3]))
    return row, members, funcs, problems


def read_fragments(path):
    out = collections.defaultdict(list)
    if not path:
        return out
    with open(path, newline='', encoding='utf-8') as f:
        for r in csv.DictReader(f, delimiter='\t'):
            out[(r['region'], int(r['tu_start'], 16))].append((int(r['start'], 16), int(r['end'], 16)))
    return out


def member_groups(region, fs, idx, allf):
    """[(member source, [function addresses])] in address order, plus missing."""
    order, addrs, missing = [], collections.OrderedDict(), []
    for x in fs:
        src = idx.get((region, x))
        if src is None:
            missing.append(x)
            continue
        addrs.setdefault(src[0], []).append(x)
    return list(addrs.items()), missing


def try_merge(a, region, group, name):
    """Merge the members of group [(src, [addr])] into out/<region>/<name>, verify.
    Returns (ok, row)."""
    members = [m for m, _x in group]
    start = min(x for _m, xs in group for x in xs)
    funcs = ['func_%08X' % x for _m, xs in group for x in xs]
    d = os.path.join(a.out, region)
    ok, row, problems = _try_merge(a, region, members, start, funcs, name, d, False)
    if not ok and row.get('compiler', '1.1p1') != '1.1p1' and not any(
            p.startswith('settings differ') for p in problems):
        ok2, row2, problems2 = _try_merge(a, region, members, start, funcs, name, d, True)
        if ok2:
            return ok2, row2, problems2
    return ok, row, problems


def _try_merge(a, region, members, start, funcs, name, d, reverse):
    text, problems, settings, renamed = merge(members, name, region, start, funcs, d, reverse)
    row = {'region': region, 'name': name, 'start': '%08X' % start, 'functions': len(funcs),
           'members': len(members), 'renamed': len(renamed),
           'compiler': (settings or {}).get('compiler', '1.1p1')}
    if any(p.startswith('settings differ') for p in problems):
        row.update(status='conflict', detail='; '.join(problems[:3]), verdict='')
        return False, row, problems
    os.makedirs(d, exist_ok=True)
    path = os.path.join(d, name)
    with open(path, 'w', encoding='latin1', newline='\n') as f:
        f.write(text)
    if a.no_verify:
        row.update(status='written')
        return True, row, problems
    v = verify(path, region, start, settings)
    row['verdict'] = ' '.join('%s=%s' % kv for kv in v.items())
    if lang_ok(v, settings):
        row.update(status='ok', detail=('accepted: ' + '; '.join(problems[:3])) if problems else '')
        return True, row, problems
    safe_remove(path)
    row.update(status='conflict' if problems else 'fail', detail='; '.join(problems[:3]))
    return False, row, problems


def split_merge(a, region, group, base, out_parts, blockers, depth=0):
    """Merge group if it verifies, else split it in two halves (at a member
    boundary) and recurse; one member alone is kept as it is."""
    if len(group) == 1:
        out_parts.append(('single', group, None))
        return
    ok, row, problems = try_merge(a, region, group, '_try_%s.c' % base)
    tmp = os.path.join(a.out, region, '_try_%s.c' % base)
    if ok:
        out_parts.append(('merged', group, row))
        if os.path.exists(tmp):
            safe_replace(tmp, tmp + '.ok%d' % len(out_parts))
        return
    blockers.append('%s..%s: %s' % (os.path.basename(group[0][0]), os.path.basename(group[-1][0]),
                                    (row.get('detail') or row.get('verdict') or '')[:200]))
    h = len(group) // 2
    split_merge(a, region, group[:h], base, out_parts, blockers, depth + 1)
    split_merge(a, region, group[h:], base, out_parts, blockers, depth + 1)


def lang_ok(v, settings):
    """The TU matches in its own -lang mode (the mode its header names)."""
    key = settings.get('lang') or 'nolang'
    st = v.get(key, '')
    return st.startswith('EXACT') or st.startswith('MATCH')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--proposal', required=True)
    ap.add_argument('--names')
    ap.add_argument('--regions')
    ap.add_argument('--confidence', default='proven,likely,weak')
    ap.add_argument('--named-only', action='store_true', help='skip unit_<addr> rows')
    ap.add_argument('--out', default=os.path.join(ROOT, 'src', 'game'))
    ap.add_argument('--report')
    ap.add_argument('--no-verify', action='store_true')
    ap.add_argument('--resume', action='store_true', help='keep the rows of an earlier report, do the rest')
    a = ap.parse_args()
    rows = read_proposal(a.proposal)
    conf = set(a.confidence.split(','))
    rows = [r for r in rows if r['confidence'] in conf]
    done_rows = []
    if a.resume:
        rp0 = a.report or os.path.join(a.out, 'restructure_report.tsv')
        if os.path.exists(rp0):
            with open(rp0, newline='', encoding='utf-8') as f:
                done_rows = list(csv.DictReader(f, delimiter='	'))
        done = {(x['region'], x['start']) for x in done_rows}
        rows = [r for r in rows if (r['region'], '%08X' % int(r['start'], 16)) not in done]
    if a.names:
        want = set(a.names.split(','))
        rows = [r for r in rows if r['name'] in want]
    if a.regions:
        want = set(a.regions.split(','))
        rows = [r for r in rows if r['region'] in want]
    if a.named_only:
        rows = [r for r in rows if not r['name'].startswith('unit_')]
    idx = shard_index()
    labels = {}
    report = list(done_rows)
    for r in rows:
        region, start, end = r['region'], int(r['start'], 16), int(r['end'], 16)
        if region not in labels:
            labels[region] = listing_functions(region)
        allf = labels[region]
        fs = [x for x in allf if start <= x < end]
        name = r['name'] if r['name'].endswith('.c') else r['name'] + '.c'
        base = name[:-2]
        group, missing = member_groups(region, fs, idx, allf)
        row = {'region': region, 'name': name, 'start': '%08X' % start, 'functions': len(fs),
               'members': len(group), 'confidence': r['confidence']}
        if not group:
            row.update(status='skipped', detail='no matched function in range')
            report.append(row)
            continue
        parts, blockers = [], []
        split_merge(a, region, group, base, parts, blockers)
        # name the merged parts in address order; singles go to the TU folder
        merged = [p for p in parts if p[0] == 'merged']
        singles = [p for p in parts if p[0] == 'single']
        d = os.path.join(a.out, region)
        oks = sorted(f for f in os.listdir(d) if f.startswith('_try_%s.c.ok' % base)) if os.path.isdir(d) else []
        oks.sort(key=lambda f: int(f.rsplit('ok', 1)[1]))
        whole = len(merged) == 1 and not singles
        for k, ((_kind, grp, prow), fn) in enumerate(zip(merged, oks), 1):
            pname = name if whole else '%s_p%02d.c' % (base, k)
            text = open(os.path.join(d, fn), encoding='latin1').read()
            text = text.replace(' * file:     _try_%s.c' % base, ' * file:     %s' % pname, 1)
            with open(os.path.join(d, pname), 'w', encoding='latin1', newline='\n') as f:
                f.write(text)
            safe_remove(os.path.join(d, fn))
        if singles or missing or not whole:
            if singles or missing:
                write_folder(a.out, region, name, [g[0] for p in singles for g in p[1]],
                             blockers + (['no verified entry for ' + ', '.join('%08X' % x for x in missing[:8])]
                                         if missing else []), '', ['func_%08X' % x for x in fs], r)
        row.update(status='whole' if whole else ('split' if merged else 'unmerged'),
                   detail='%d merged part(s), %d single member(s), %d missing; %s' % (
                       len(merged), sum(len(p[1]) for p in singles), len(missing), '; '.join(blockers[:2])[:300]),
                   parts=len(merged), single=sum(len(p[1]) for p in singles),
                   merged_fns=sum(len(xs) for p in merged for _m, xs in p[1]))
        report.append(row)
        print('%-8s %-32s %4d fns  %-8s parts %d singles %d' % (region, name, len(fs), row['status'],
                                                              row['parts'], row['single']), flush=True)
        if len(report) % 25 == 0:
            write_report(a, report)
    rp = write_report(a, report)
    c = collections.Counter(x['status'] for x in report)
    fn = sum(int(x.get('merged_fns') or 0) for x in report)
    print('TUs: %d  %s  functions in merged files: %d' % (len(report), dict(c), fn))
    print('report: %s' % rp)


def write_report(a, report):
    rp = a.report or os.path.join(a.out, 'restructure_report.tsv')
    os.makedirs(os.path.dirname(rp), exist_ok=True)
    with open(rp, 'w', newline='', encoding='utf-8') as f:
        cols = ['region', 'name', 'start', 'functions', 'members', 'confidence', 'status', 'parts', 'single',
                'merged_fns', 'renamed', 'verdict', 'detail']
        w = csv.DictWriter(f, cols, delimiter='\t', extrasaction='ignore')
        w.writeheader()
        w.writerows(report)
    return rp


if __name__ == '__main__':
    main()
