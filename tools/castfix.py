#!/usr/bin/env python3
"""castfix.py FILE-LIST: convert the stale externs of callers to header includes, adding pointer
casts (or old-type function pointer calls) where the new prototypes reject a call.  A file is kept
only if it compiles and is EXACT."""
import os, re, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__))).replace(os.sep, '/')
sys.path.insert(0, ROOT + '/tools')
import mkheaders as mk
import placeholdernames as ph

PTR_CAST = re.compile(r'^\(\s*(?:const\s+|volatile\s+)*(?:struct\s+|union\s+|enum\s+)?\w+(?:\s+\w+)*\s*\*+\s*(?:const\s*)?\)\s*')
SIMPLE = re.compile(r'[&*]?[A-Za-z_]\w*(?:\s*(?:\.|->)\s*\w+|\s*\[[^\[\]]*\]|\s*\((?:[^()]|\([^()]*\))*\))*')
TYPES = None


def split_args(text, lp):
    d = 0
    i = lp
    start = lp + 1
    args = []
    while i < len(text):
        c = text[i]
        if c in '([{':
            d += 1
        elif c in ')]}':
            d -= 1
            if d == 0:
                args.append((start, i))
                return args, i
        elif c == ',' and d == 1:
            args.append((start, i))
            start = i + 1
        elif c == '"':
            i += 1
            while i < len(text) and text[i] != '"':
                i += 2 if text[i] == chr(92) else 1
        elif c == "'":
            i += 1
            while i < len(text) and text[i] != "'":
                i += 2 if text[i] == chr(92) else 1
        i += 1
    return None, -1


def param_types(d):
    ps = []
    t = d.ptext.strip()
    if t in ('', 'void'):
        return ps
    for p in mk.pn.split_params(t):
        if '(' in p:
            m = re.search(r'\(\s*\*\s*\w*\s*\)', p)
            if m and not re.search(r'\(\s*\*[^)]*\)\s*\(.*\(', p):
                ps.append(' '.join(p[:m.start()].split()) + ' (*)' + p[m.end():].strip())
            else:
                ps.append(None)
            continue
        toks = mk.strip_name(p)
        if '*' in toks:
            ps.append(' '.join(toks).replace('* *', '**'))
        else:
            nm = [x for x in toks if x not in ('const', 'volatile')]
            res = TYPES.alias.get(nm[-1]) if (nm and TYPES) else None
            ps.append(' '.join(toks) if res and any(('@fnptr' in r or '*' in r) for r in (res if isinstance(res, (set, list, tuple)) else [res])) else None)
    return ps


def norm_t(s):
    return re.sub(r'\s+', '', s)


def cast_calls(text, ln_lo, ln_hi, fn_defs, done):
    lines = text.split('\n')
    off = sum(len(l) + 1 for l in lines[:ln_lo])
    end = sum(len(l) + 1 for l in lines[:ln_hi])
    edits = []
    for fn, d in fn_defs.items():
        pts = param_types(d)
        for m in re.finditer(r'\b%s\s*\(' % re.escape(fn), text[off:end]):
            lp = off + m.end() - 1
            args, rp = split_args(text, lp)
            if args is None:
                continue
            if len(args) != len(pts) and not (len(pts) == 0 and len(args) == 1 and not text[args[0][0]:args[0][1]].strip()):
                continue
            for i, (a, b) in enumerate(args):
                if i >= len(pts) or pts[i] is None:
                    continue
                s = text[a:b]
                st = s.strip()
                if not st or st == '0' or st == 'NULL' or re.fullmatch(r'\(\s*void\s*\*\s*\)\s*0', st):
                    continue
                lead = len(s) - len(s.lstrip())
                m2 = PTR_CAST.match(st)
                if m2:
                    cur = m2.group(0).strip()[1:-1]
                    if norm_t(cur) == norm_t(pts[i]):
                        continue
                    body = st[m2.end():]
                    if not SIMPLE.fullmatch(body):
                        new = '(%s)(%s)' % (pts[i], st)
                    else:
                        new = '(%s)%s' % (pts[i], body)
                else:
                    if SIMPLE.fullmatch(st):
                        new = '(%s)%s' % (pts[i], st)
                    else:
                        new = '(%s)(%s)' % (pts[i], st)
                if new != st:
                    edits.append((a + lead, b - (len(s) - len(s.rstrip())), new))
    edits = sorted(set(edits), reverse=True)
    out = text
    last = None
    n = 0
    for a, b, new in edits:
        if last is not None and b > last:
            continue
        out = out[:a] + new + out[b:]
        last = a
        n += 1
    return out, n


def old_cast_type(old):
    t = ' '.join(old.replace('extern', ' ').split()).rstrip(';').strip()
    m = re.match(r'^(.*?)\b(\w+)\s*\((.*)\)\s*$', t)
    if not m:
        return None
    ret = m.group(1).strip()
    inner = m.group(3).strip()
    ps = []
    if inner and inner != 'void':
        for p in mk.pn.split_params(inner):
            if '(' in p:
                return None
            toks = mk.strip_name(p)
            ps.append(' '.join(toks).replace('* *', '**'))
    return '%s (*)(%s)' % (ret, ', '.join(ps) if ps else ('void' if inner == 'void' else ''))


DECL = re.compile(r'\s*(?:(?:const|static|extern|struct|union|enum|unsigned|signed|volatile)\s+)*\w+[\s\*]+')


def fp_calls(text, fn, ctype):
    out = []
    for m in re.finditer(r'(?<![\w.>])%s\s*\(' % re.escape(fn), text):
        ls = text.rfind(chr(10), 0, m.start()) + 1
        pre = text[ls:m.start()]
        if re.search(r'\b(extern|static)\b', pre):
            continue
        if DECL.fullmatch(pre) and not re.match(r'\s*(return|else|case|do)\b', pre):
            continue
        out.append((m.start(), m.end() - 1))
    for s, lp in sorted(out, reverse=True):
        text = text[:s] + '((%s)%s)(' % (ctype, fn) + text[lp + 1:]
    return text, len(out)


EXTRA = set()


def build_ok(f, idx, hdrs, plan, fn_defs, excluded, log, olds, fpd):
    text = mk.apply_plan(idx, hdrs, plan, skip_owners=sorted(excluded), inject=True, extra=sorted(EXTRA))[0]
    for fn in sorted(fpd):
        text, _n = fp_calls(text, fn, fpd[fn])
    for it in range(30):
        mk.write(f, text)
        errs = mk.compile_errors(f)
        if not errs:
            return text
        dropped = 0
        need = set()
        for ln, msg, w in errs:
            m = re.match(r"identifier '(\w+)\(", msg)
            if m and 'redeclared' in msg:
                fn = m.group(1)
                t2 = re.sub(r'(?m)^[ \t]*extern[^;{}]*?\b%s\s*\([^;{}]*\)\s*;[ \t]*\n?' % re.escape(fn), '', text)
                if t2 != text:
                    text = t2
                    dropped += 1
                    log.append('%s: dropped stale extern %s' % (mk.rel(f), fn))
            m = re.search(r"undefined identifier '(\w+)'", msg)
            if m:
                nm = m.group(1)
                if nm in idx.tindex.base:
                    need.add(nm)
                elif nm in idx.tindex.typedef_in:
                    h = mk.pick_header(idx.tindex.typedef_in[nm], f, mk.include_closure(f))
                    if h:
                        need.add("inc:" + os.path.abspath(h).replace(os.sep, "/"))
        need -= EXTRA
        if need:
            EXTRA.update(need)
            return 'retry'
        if dropped:
            continue
        lines_of = [(ln, msg) for ln, msg, w in errs if ln > 0 and re.search(
            r"implicit conversion|does not match|illegal operands|argument|cannot convert|incompatible", msg)]
        changed = 0
        nt = text
        for ln, msg in sorted(set(lines_of), reverse=True):
            if 'does not match' in msg or 'illegal operands' in msg:
                continue
            fd = {k: v for k, v in fn_defs.items() if v.file not in excluded and k not in fpd}
            win = chr(10).join(nt.split(chr(10))[max(0, ln - 3):ln])
            for nm in set(re.findall(r'\b([A-Za-z_]\w*)\s*\(', win)):
                if nm not in fd and nm not in fn_defs and nm not in fpd:
                    try:
                        dd, _w = idx.owner(f, nm)
                    except Exception:
                        dd = None
                    if dd is not None and dd.file != f:
                        fd[nm] = dd
            nt2, n = cast_calls(nt, max(0, ln - 3), ln, fd, set())
            if n:
                nt = nt2
                changed += n
        if changed:
            text = nt
            continue
        funcs = [k for k, v in fn_defs.items() if v.file not in excluded and k not in fpd]
        cul = {}
        L2 = text.split(chr(10))
        for ln, msg, w in errs:
            if ln <= 0:
                continue
            for lo in (ln - 1, max(0, ln - 3)):
                win = chr(10).join(L2[lo:ln])
                hit = [fn for fn in funcs if re.search(r'\b%s\s*\(' % re.escape(fn), win)]
                if hit:
                    for fn in hit:
                        cul.setdefault(fn, msg)
                    break
        if not cul:
            for ln, msg, w in errs[:3]:
                log.append('%s: unexplained %d %s | %s' % (mk.rel(f), ln, msg[:110], L2[ln - 1].strip()[:110] if ln > 0 else w))
            return None
        for k, v in cul.items():
            ct = old_cast_type(olds.get(k, ''))
            if ct:
                fpd[k] = ct
                log.append('%s: %s called through its old type (%s)' % (mk.rel(f), k, v[:60]))
            else:
                excluded.add(fn_defs[k].file)
                log.append('%s: %s kept (%s)' % (mk.rel(f), k, v[:70]))
        return 'retry'
    return None


def process(f, idx, hdrs, log):
    plan = mk.plan_caller(idx, hdrs, f)
    if not plan.removals:
        return 'nothing'
    orig = plan.raw
    owners = sorted({r[3].file for r in plan.removals})
    fn_defs = {r[2]: r[3] for r in plan.removals}
    olds = {r[2]: r[4] for r in plan.removals}
    fpd = {}
    excluded = set()
    EXTRA.clear()
    for rnd in range(60):
        if len(excluded) >= len(owners):
            break
        res = build_ok(f, idx, hdrs, plan, fn_defs, excluded, log, olds, fpd)
        if res == 'retry':
            continue
        if res is None:
            break
        good, msg = mk.verify_file(f)
        if good:
            return 'ok' + (' (kept %d groups)' % len(excluded) if excluded else '') + (' fp=%d' % len(fpd) if fpd else '')
        bad = False
        for of in owners:
            if of in excluded:
                continue
            e2 = set(o for o in owners if o != of)
            r2 = build_ok(f, idx, hdrs, plan, fn_defs, e2, log, olds, dict(fpd))
            if r2 in (None, 'retry'):
                excluded.add(of)
                bad = True
                continue
            if not mk.verify_file(f)[0]:
                bad = True
                moved = 0
                for r in plan.removals:
                    if r[3].file == of and r[2] not in fpd:
                        if mk.norm_proto(r[4]) != mk.norm_proto(r[3].proto):
                            ct = old_cast_type(r[4])
                            if ct:
                                fpd[r[2]] = ct
                                moved += 1
                if moved:
                    log.append('%s: %d functions of %s called through their old types' % (mk.rel(f), moved, os.path.basename(of)))
                else:
                    excluded.add(of)
                    log.append('%s: bytes differ for header %s' % (mk.rel(f), os.path.basename(of)))
        if not bad:
            break
    mk.write(f, orig)
    return 'failed'


def main():
    global TYPES
    files = [os.path.normpath(os.path.join(ROOT, l.strip())) for l in open(sys.argv[1]) if l.strip()]
    allf = sorted(ph.files_under([mk.GAME]))
    idx = mk.Index(allf)
    hdrs = mk.build_headers(idx)
    TYPES = idx.tindex.types
    log = []
    for f in files:
        st = process(f, idx, hdrs, log)
        print('%-14s %s' % (st, mk.rel(f)), flush=True)
    print('\n'.join(log))


if __name__ == '__main__':
    main()
