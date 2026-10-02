#!/usr/bin/env python3
"""Implicit register arguments in matched C.

A matched function can hand a value to its callee through r0-r3 without the
C naming it: the call passes fewer arguments than the callee's definition
declares, and the register happens to hold the right value already (the
caller's own incoming argument, or the return value of the call before).  The
ARM bytes are the same either way, so match.py cannot see it, but a native
build (eidos) passes garbage.  This tool finds those calls.

How it works
------------
1. Every .c under src/matched is parsed for its definitions (with parameter
   names and types), its prototypes and its calls.  Each called name is
   resolved to its matched definition: a local definition first, then the
   region the file header's symbol table names, then the caller's own region,
   then arm9 / ITCM / twl.  A static definition in another file never
   resolves by name.  When the name finds nothing, the callee is resolved
   by ADDRESS (from the caller's symbols: line, else from a func_/sub_/FUN_
   name) to whatever matched definition sits there, so a caller's
   func_020315D4 finds the definition named sub_020315D4.  Such rows keep
   the caller's spelling in the callee column and say "defined as ...".
2. Each parameter is laid out on r0-r3 the way the compiler does it: one word
   per scalar or pointer, two consecutive words for a 64-bit scalar (no
   even-register alignment: func_0200F43C's u64 key arrives in r1:r2), and
   ceil(size / 4) words for a struct passed by value, with the size computed
   from the struct definition in the callee's own file.
3. For every call that passes fewer arguments than the definition declares,
   the caller's ORIGINAL bytes (match.target_extent / target_bytes) are
   disassembled, a CFG is built, and a reaching-definitions pass finds what
   last wrote each missing argument register at that call.  The pass tracks
   r0-r12, lr and word stack slots, so a value restored from a callee-saved
   copy (`adds r1, r5, #0` where r5 held the incoming r1, or the previous
   return) or from a stack spill (`ldr r1, [sp, #4]` after `str r1, [sp, #4]`)
   is traced back to where it came from instead of counting as a fresh write.
   A call to a function whose definition returns a 64-bit value sets r0 and
   r1 as return halves.  Calls are bl/blx (conditional ones too), a `b` out
   of the function, and register jumps loaded from a literal pool
   (`ldr ip, =g; bx ip`, Thumb `ldr r3, =g; bx r3`): tail-call thunks.
4. The callee side is read the same way (Scanner.reads): from the callee's
   ORIGINAL entry, which of r0-r3 does it read before writing them, on any
   path?  A copy or a spill only moves the value (the copy is followed); a
   value passed on to a call or tail call counts only if that inner callee
   reads it in turn, followed READS_MAX_DEPTH levels deep; at a return, r0 (r1
   for a 64-bit result) counts when the function returns a value.  A row
   whose registers the callee never reads is kind phantom: the callee's C
   declares a parameter its original code ignores, and the caller is fine.
   The ISA of every function followed is its definition's isa: line or
   symbols: row when there is one, else the state the call switches to (bl
   keeps it, blx #imm flips it, bx/blx reg take bit 0), else the listing
   label; an unmatched callee in another overlay is placed by the region
   other files' symbols: rows tag its address with, else by the one overlay
   listing with a label there.  A store of an incoming register to a stack
   slot the function never loads back is an outgoing stack argument (or an
   escaping local) and counts as a read.
   Switch tables are data: a Thumb `add pc, rN` (MWCC's halfword table right
   after it, N+1 entries from the bounding `cmp`) and an ARM `addls pc, pc,
   rN, lsl #2` (its `b case` table) go to their case targets only, and the
   Thumb table is not decoded.  Conditional writes are tracked per edge:
   `movgt r2; bgt L` reaches L with r2 written, `ldrhne r3; ldrheq r3` write
   r3 on both paths, `ldrne r2; cmpne r2, #0; popeq` leaves r2 written past
   the popeq, and a read under the condition a register was just written
   under sees the write.  push and known sp adjustments move the tracked
   stack slots instead of dropping them, so `push {r0-r3}` keeps each
   register in its own slot, and taking one slot's address (`add r3, sp,
   #0x14`) reads that slot only.  A tail jump out of the image, or from DS
   code into the DSi-only TWL region (ov172 func_021B6724's `ldr pc` veneer),
   makes the callee undecidable: its rows are low.
5. The broader check (BROAD_TAG rows): for every call and tail call, the
   registers the callee's original code reads (strictly: anything
   undecidable counts as not read) that the C call does not supply and the
   callee's definition does not declare either, because the definition is
   too short, void, unprototyped, or missing.  Kinds a, b and set as above;
   the detail says "callee definition too short" or "callee not matched".
6. A definition matched as `void f(void) { g(); }` whose original reaches g
   with r0-r3 still holding f's own incoming values is a thunk: one row
   naming the registers forwarded, which of them g reads, and whether g's
   return passes back through f.

Row kinds
---------
  a        function-entry passthrough: the register holds the caller's own
           incoming r0-r3 on every path
  b        return chain: the register holds the return value of an earlier
           call on every path
  set      the register holds a value the caller's own instructions computed
           for something else (func_02062F90's shared `mov r1, #0` reaching
           func_02062D4C's frames), and the callee reads it
  thunk    `void f(void) { g(); }` forwarding r0-r3 (and g's return); one row
           per thunk, replacing the a rows of that call
  c        anything else: clobbered by a call (garbage on the DS too), mixed
           origins, or a stack slot argument
  phantom  the callee's original code never reads the register: not a caller
           bug (the detail keeps the kind the row would have had)
  reverse  a definition declares more parameters than any matched caller
           passes, or declares parameters its original code never reads (one
           row each per definition, caller columns are "*")

Confidence: high when every path agrees and the callee's original code
reads the register.  When the callee's bytes cannot be read (no extent), the
older name test applies: lowered one step when the callee never names the
parameter, raised back when it forwards the register to an a row of its own.
Also lowered when an earlier parameter's size is unknown (the register
placement is then a guess).  --check fails on high a, b, set and thunk rows.
docs/REGARGS.md says how to read and fix rows.

Usage:

    python tools/regargs.py                      report to stdout
    python tools/regargs.py -o FILE.tsv          TSV, columns as below
    python tools/regargs.py --file src/matched/ov/ov021_func_021C2EDC.c
    python tools/regargs.py --summary            counts per kind, confidence, region
    python tools/regargs.py --check --file F.c   exit 1 on a high a/b/set/thunk row in F.c
    python tools/regargs.py selftest

TSV columns: caller_file caller_func callee callee_def_file kind detail
confidence.

The selftest's tree cases run on src/matched exactly as it was at pinned
commits (git_snapshot: every .c, callers and callees alike, none from the
working tree), against the original bytes, so a lane fixing a fixture site
cannot move a case.  It needs git and extract/, and builds one index per
pin, so it takes a few minutes.

Remaining blind spots
---------------------
- Only calls between matched functions are checked.  A matched caller of an
  unmatched callee, an unmatched caller of a matched callee, and calls
  through function pointers are invisible (reverse rows are the only hint,
  and they say so when the address is taken).
- Calls made inside an inline helper are traced through the helper's
  callers' bytes; when the helper is called from several places the sites
  are unioned.
- When a caller has a different number of bl sites to a callee than C calls
  (inlined copies, duplicated tails), the register origins are unioned over
  all sites and the row says "[union over N bl sites]".
- Stack slot tracking assumes a callee only writes at or above a stack
  address the caller passed it: slots at or above the lowest escaped
  sp-relative address are dropped at each call and each store through
  another base register; any sp write drops them all.  Copies through any
  other memory (a global, a struct field) count as fresh writes.
- A function that returns a struct by value takes a hidden pointer in r0;
  that shift is not modelled (no matched definition returns anything wider
  than 8 bytes, or a struct wider than a word, as of 2026-10-02).  Struct
  sizes come from the callee file's own definitions, with approximate
  bitfield packing; a type the file does not define falls back to one word
  and the row says "size of param N unknown".
- The C side is parsed with regular expressions, not a C front end: macros
  that expand to calls, and calls whose name is built by the preprocessor,
  are missed.
- Stack-passed arguments (fifth word onward) are reported at low
  confidence without a trace: the dataflow does not follow the outgoing
  argument area.  The same holds for a call with no bl site in the original
  (tail-merged, veneered, or the extent is unknown).
- The broader check reads strictly, so it misses a read it cannot prove
  (through an unresolved jump, a call cycle, or past the depth cap), and
  it sees only calls written in the caller's own body, not those inside an
  inline helper.
- Callee reads for phantom verdicts err on the side of "read", so a phantom
  verdict is safe and a missed phantom is the failure mode: beyond
  READS_MAX_DEPTH nested calls, in a call cycle, at
  an unresolved register jump, and for a function whose bytes run off the
  end of its extent, every argument counts as read; a store of the value
  to memory counts as a read even when nothing loads it back; a spill to a
  stack slot whose address escapes counts as a read.
- Thunks are recognised only in the exact `g();` / `return g();` body shape
  with no parameters declared; a thunk written with some parameters named
  shows up as ordinary a rows instead.
"""
import argparse
import collections
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

MATCHED = "src/matched"
COLUMNS = ("caller_file", "caller_func", "callee", "callee_def_file", "kind", "detail", "confidence")

KEYWORDS = set("""if while for switch return sizeof do else case goto break continue
typedef struct union enum default asm __asm _Alignof __attribute__ defined""".split())
QUALS = set("const volatile register signed unsigned static extern inline __inline restrict".split())
TAGS = set("struct union enum".split())
BASE_TYPES = set("void char short int long float double signed unsigned _Bool".split())
STATIC_REGIONS = ["arm9", "arm9_autoload0_ITCM", "twl"]
TWL = "twl"
ARGR = ["r0", "r1", "r2", "r3"]

# ---------------------------------------------------------------------------
# C parsing
# ---------------------------------------------------------------------------


_COMMENT_OR_LITERAL = re.compile(r'/\*.*?(?:\*/|\Z)|//[^\n]*|"(?:\\.|[^"\\\n])*"?|' + r"'(?:\\.|[^'\\\n])*'?", re.S)
_PREPROC = re.compile(r"(?m)^[ \t]*#(?:[^\n\\]|\\.)*(?:\\\n(?:[^\n\\]|\\.)*)*")


def _blank(m):
    t = m.group(0)
    if t.startswith("/*"):
        return "\n" * t.count("\n")
    if t.startswith("//"):
        return ""
    return t[0] * 2


def strip_comments(s):
    """Comments removed (newlines kept), string and char literals emptied,
    preprocessor lines dropped."""
    return _PREPROC.sub("", _COMMENT_OR_LITERAL.sub(_blank, s))


_BRACKETS = {"(": re.compile(r"[()]"), "{": re.compile(r"[{}]")}


def match_close(s, i, o="(", c=")"):
    d = 0
    for m in _BRACKETS[o].finditer(s, i):
        if m.group() == o:
            d += 1
        else:
            d -= 1
            if d == 0:
                return m.start()
    return -1


def match_open_back(s, j):
    d = 0
    for i in range(j, -1, -1):
        if s[i] == ")":
            d += 1
        elif s[i] == "(":
            d -= 1
            if d == 0:
                return i
    return -1


def split_top(s, sep=","):
    parts, d, cur = [], 0, []
    for ch in s:
        if ch in "([{":
            d += 1
        elif ch in ")]}":
            d -= 1
        if ch == sep and d == 0:
            parts.append("".join(cur))
            cur = []
        else:
            cur.append(ch)
    parts.append("".join(cur))
    return [p.strip() for p in parts]


def param_name(p):
    m = re.search(r"\(\s*\*\s*(\w+)\s*\)", p)
    if m:
        return m.group(1)
    p = re.sub(r"\[[^\]]*\]", "", p)
    toks = re.findall(r"[A-Za-z_]\w*", p)
    out, skip = [], False
    for t in toks:
        if skip:
            skip = False
            out.append("struct " + t)       # `struct S` is one type token
            continue
        if t in TAGS:
            skip = True
            continue
        if t in ("signed", "unsigned"):
            out.append(t)                   # `unsigned n` names n
            continue
        if t in QUALS:
            continue
        out.append(t)
    if len(out) >= 2 and out[-1] not in BASE_TYPES and not out[-1].startswith("struct "):
        return out[-1]
    return None


def parse_params(s):
    """(count or None for `()`, variadic, names, texts)."""
    s = s.strip()
    if s == "":
        return None, False, [], []
    if s == "void":
        return 0, False, [], []
    ps = split_top(s)
    var = any(p == "..." for p in ps)
    ps = [p for p in ps if p != "..."]
    return len(ps), var, [param_name(p) for p in ps], ps


def decl_from_head(head):
    """head ends with ')': (name, return text, parameter text) or None."""
    head = head.rstrip()
    if not head.endswith(")"):
        return None
    o = match_open_back(head, len(head) - 1)
    if o <= 0:
        return None
    m = re.search(r"([A-Za-z_]\w*)\s*$", head[:o])
    if not m:
        return None
    name = m.group(1)
    if name in KEYWORDS:
        return None
    before = head[:m.start()].rstrip()
    if before.endswith("(") or before.endswith("*)"):
        return None
    return name, head[:m.start()], head[o + 1:-1]


def is_void_ret(ret):
    t = [x for x in re.findall(r"[A-Za-z_]\w*|\*", ret) if x not in QUALS and x not in ("asm", "__asm")]
    return t == ["void"]


# ----------------------------------------------------------------- type sizes

BUILTIN_SIZES = {
    "u8": 1, "s8": 1, "vu8": 1, "vs8": 1, "BOOL8": 1, "bool": 1, "_Bool": 1,
    "u16": 2, "s16": 2, "vu16": 2, "vs16": 2, "fx16": 2, "GXRgb": 2, "wchar_t": 2,
    "u32": 4, "s32": 4, "vu32": 4, "vs32": 4, "fx32": 4, "BOOL": 4, "f32": 4,
    "size_t": 4, "uintptr_t": 4, "intptr_t": 4, "ptrdiff_t": 4,
    "u64": 8, "s64": 8, "vu64": 8, "vs64": 8, "fx64": 8, "f64": 8,
    "OSTick": 8, "OSTime": 8,
}


def _scalar_size(toks):
    if not toks:
        return None
    if toks == ["void"]:
        return 0
    if "float" in toks:
        return 4
    if "double" in toks:
        return 8
    if toks.count("long") >= 2:
        return 8
    if "char" in toks:
        return 1
    if "short" in toks:
        return 2
    if set(toks) <= {"int", "long", "unsigned", "signed"}:
        return 4
    return None


def type_size(text, types, depth=0):
    """(size, align) of a type written without a declarator name, or None."""
    if depth > 20:
        return None
    text = text.strip()
    if "*" in text or "(" in text:
        return 4, 4
    m = re.match(r"^(?:(?:const|volatile)\s+)*(struct|union)\s*(\w*)\s*(\{.*\})?\s*$", text, re.S)
    if m:
        if m.group(3):
            return struct_size(m.group(3)[1:-1], m.group(1) == "union", types, depth + 1)
        return types.get("%s %s" % (m.group(1), m.group(2)))
    if re.match(r"^(?:(?:const|volatile)\s+)*enum\b", text):
        return 4, 4
    toks = [t for t in re.findall(r"[A-Za-z_]\w*", text) if t not in ("const", "volatile", "register", "static", "extern")]
    sz = _scalar_size(toks)
    if sz is not None:
        return sz, min(max(sz, 1), 4)
    if len(toks) == 1:
        t = toks[0]
        if t in types:
            return types[t]
        if t in BUILTIN_SIZES:
            sz = BUILTIN_SIZES[t]
            return sz, min(sz, 4)
    return None


def _declarators(field):
    """[(type text, array product, bitfield width or None)] for one field."""
    field = field.strip()
    if not field:
        return []
    m = re.match(r"^(.*?(?:struct|union)\s*\w*\s*\{.*\})\s*(.*)$", field, re.S)
    if m:
        base, rest = m.group(1), m.group(2)
    else:
        parts = split_top(field)
        first = parts[0]
        mm = re.match(r"^(.*?)([\s*]*)([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)\s*(:\s*\w+)?$", first, re.S)
        if not mm:
            return [(field, 1, None)]
        base, rest = mm.group(1), first[len(mm.group(1)):]
        if len(parts) > 1:
            rest = ",".join([rest] + parts[1:])
    out = []
    for d in split_top(rest) if rest.strip() else [""]:
        ptr = "*" in d or "(" in d
        n = 1
        for dim in re.findall(r"\[([^\]]*)\]", d):
            try:
                n *= int(dim.strip(), 0)
            except ValueError:
                return [(None, 1, None)]
        bf = re.search(r":\s*(\w+)\s*$", d)
        bits = int(bf.group(1), 0) if bf and bf.group(1).isdigit() else None
        out.append((base + (" *" if ptr else ""), n, bits))
    return out


def struct_size(body, union, types, depth=0):
    off = size = 0
    align = 1
    bit_unit = bit_used = 0
    for field in split_top(body, ";"):
        for t, n, bits in _declarators(field):
            if t is None:
                return None
            st = type_size(t, types, depth + 1)
            if st is None or st[0] is None:
                return None
            sz, al = st
            align = max(align, al)
            if bits is not None:
                if bit_unit == sz and bit_used + bits <= sz * 8 and not union:
                    bit_used += bits
                    continue
                bit_unit, bit_used = sz, bits
            else:
                bit_unit = bit_used = 0
            if union:
                size = max(size, sz * n)
            else:
                off = (off + al - 1) // al * al + sz * n
    total = size if union else off
    total = (total + align - 1) // align * align
    return total, align


def add_typedef(stmt, types):
    body = stmt[len("typedef"):].strip()
    if re.match(r"^(?:const\s+)?enum\b", body):
        nm = re.search(r"([A-Za-z_]\w*)\s*$", body)
        if nm:
            types[nm.group(1)] = (4, 4)
        return
    m = re.match(r"^((?:const\s+)?(struct|union)\s*(\w*)\s*\{.*\})\s*(.*)$", body, re.S)
    if m:
        st = type_size(m.group(1), types)
        if m.group(3) and st:
            types["%s %s" % (m.group(2), m.group(3))] = st
        base, decls = m.group(1), m.group(4)
    else:
        mm = re.match(r"^(.*?)([\s*]*)([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)\s*$", body.split(",")[0], re.S)
        if not mm or "(" in body:
            for nm in re.findall(r"\(\s*\*\s*(\w+)\s*\)", body):
                types[nm] = (4, 4)
            return
        base = mm.group(1)
        decls = body[len(base):]
    for d in split_top(decls):
        nm = re.search(r"([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)\s*$", d)
        if not nm:
            continue
        if "*" in d:
            types[nm.group(1)] = (4, 4)
            continue
        st = type_size(base, types)
        if st is None or st[0] is None:
            continue
        n = 1
        for dim in re.findall(r"\[([^\]]*)\]", nm.group(2)):
            try:
                n *= int(dim.strip(), 0)
            except ValueError:
                n = None
                break
        if n is not None:
            types[nm.group(1)] = (st[0] * n, st[1])


def param_words(ptext, types):
    """Registers a parameter takes: (words, size_known, is_64)."""
    p = ptext.strip()
    nm = param_name(p)
    if "(" in p or re.search(r"\[[^\]]*\]\s*$", p) or "*" in p:
        return 1, True, False
    t = p
    if nm:
        t = re.sub(r"\b%s\b\s*$" % re.escape(nm), "", p)
    st = type_size(t, types)
    if st is None and re.search(r"[A-Za-z_]\w*\s*$", p):
        # `unsigned n`, `struct pair v`: param_name() keeps no name for these
        t = re.sub(r"[A-Za-z_]\w*\s*$", "", p)
        st = type_size(t, types) if t.strip() else None
    if st is None or st[0] is None:
        return 1, False, False
    sz = st[0]
    words = max(1, (sz + 3) // 4)
    return words, True, sz == 8 and not re.search(r"\b(struct|union)\b", t) and words == 2


def ret_is_64(ret, types):
    r = re.sub(r"\b(static|extern|inline|__inline|asm|__asm)\b", "", ret)
    if "*" in r:
        return False
    st = type_size(r, types)
    return bool(st and st[0] == 8)


def layout(texts, types):
    """[(first word, words)] per parameter, plus the index of the first parameter
    of unknown size (None when every size is known)."""
    out, w, unknown = [], 0, None
    for i, t in enumerate(texts):
        n, known, _ = param_words(t, types)
        if not known and unknown is None:
            unknown = i
        out.append((w, n))
        w += n
    return out, unknown


# ----------------------------------------------------------------- file parse

_NEXT_PUNCT = re.compile(r"[;{(]")


def parse_file(text):
    s = strip_comments(text)
    defs, protos, types = [], {}, {}
    i, n, cur_start = 0, len(s), 0
    while i < n:
        ch = s[i]
        if ch == ";":
            stmt = s[cur_start:i].strip()
            if stmt.startswith("typedef"):
                try:
                    add_typedef(stmt, types)
                except (ValueError, RecursionError):
                    pass
            else:
                m = re.match(r"^(struct|union)\s+(\w+)\s*(\{.*\})", stmt, re.S)
                if m:
                    st = type_size(m.group(1) + " " + m.group(3), types)
                    if st:
                        types["%s %s" % (m.group(1), m.group(2))] = st
                add_protos(stmt, protos)
            i += 1
            cur_start = i
        elif ch == "{":
            head = s[cur_start:i]
            j = match_close(s, i, "{", "}")
            if j < 0:
                break
            d = decl_from_head(head)
            if d and "=" not in head:
                name, ret, ptxt = d
                body = s[i + 1:j]
                cnt, var, names, texts = parse_params(ptxt)
                defs.append(dict(name=name, ret=ret.strip(), void=is_void_ret(ret), n=cnt,
                                 var=var, pnames=names, ptexts=texts, body=body,
                                 asm=bool(re.search(r"\basm\b|__asm", ret))))
                for st in re.findall(r"\bextern\b[^;{}]*;", body):
                    add_protos(st[:-1], protos)
                i = j + 1
                cur_start = i
            else:
                i = j + 1
        elif ch == "(":
            j = match_close(s, i)
            i = (j + 1) if j > 0 else i + 1
        else:
            m = _NEXT_PUNCT.search(s, i)
            i = m.start() if m else n
    for d in defs:
        d["layout"], d["size_unknown"] = layout(d["ptexts"], types)
        d["words"] = sum(w for _f, w in d["layout"])
        d["ret64"] = ret_is_64(d["ret"], types)
    return s, defs, protos, types


def add_protos(stmt, protos):
    stmt = stmt.strip()
    if not stmt or stmt.startswith("typedef"):
        return
    d = decl_from_head(stmt)
    if not d:
        return
    name, ret, ptxt = d
    if "=" in ret or not re.search(r"[A-Za-z_]", ret):
        return
    cnt, var, _names, _t = parse_params(ptxt)
    protos[name] = dict(n=cnt, var=var, void=is_void_ret(ret), ret=ret.strip())


CALL_RE = re.compile(r"([A-Za-z_]\w*)\s*\(")


def find_calls(body):
    calls = []
    for m in CALL_RE.finditer(body):
        name = m.group(1)
        if name in KEYWORDS:
            continue
        pre = body[max(0, m.start() - 256):m.start()].rstrip()
        if pre.endswith(".") or pre.endswith("->"):
            continue
        t = pre.rstrip(" \t\r\n*")
        j = len(t)
        while j > 0 and (t[j - 1].isalnum() or t[j - 1] == "_"):
            j -= 1
        word = t[j:]
        if word and not word[0].isdigit() and word not in ("return", "else", "case", "do"):
            continue          # a declaration, not a call
        o = m.end() - 1
        c = match_close(body, o)
        if c < 0:
            continue
        a = body[o + 1:c].strip()
        args = [] if a == "" else split_top(a)
        calls.append(dict(name=name, k=len(args), args=args, pos=m.start()))
    return calls


# ----------------------------------------------------------------- headers

HDR = {k: re.compile(r"^ \* %s:\s*(\S+)" % k, re.M) for k in ("function", "address", "region", "isa", "status")}
SYM = re.compile(r"^ \*   ([A-Za-z_]\w*)\s+0x([0-9A-Fa-f]{8})\s+(arm|thumb)(?:\s+(ov\d+|twl|arm9))?\s*$", re.M)


def header(text):
    h = {}
    for k, r in HDR.items():
        m = r.search(text[:4000])
        h[k] = m.group(1) if m else None
    h["syms"] = {m.group(1): (int(m.group(2), 16), m.group(3), m.group(4)) for m in SYM.finditer(text[:20000])}
    return h


ADDR_NAME = re.compile(r"^(?:\w+_)?(?:func|sub|FUN)_[0-9A-Fa-f]{8}$")


def addr_of_name(name):
    m = re.search(r"([0-9A-Fa-f]{8})$", name)
    return int(m.group(1), 16) if m else None


def area_of(path):
    """Top-level directory under src/matched: arm9, arm9_sdk, ov, ov_sdk, twl..."""
    p = path[len(MATCHED) + 1:] if path.startswith(MATCHED + "/") else path
    return p.split("/", 1)[0]


def is_sdk(path):
    return "_sdk/" in path


# ---------------------------------------------------------------------------
# the index of matched C
# ---------------------------------------------------------------------------

class Index:
    def __init__(self, root=ROOT, overrides=None, snapshot=None):
        """overrides: {repo-relative path: text} read instead of the working tree.
        snapshot: {repo-relative path: text} that IS the tree (every .c under
        src/matched at some commit, see git_snapshot()); the working tree is
        not read at all."""
        self.root = root
        overrides = overrides or {}
        self.files = []
        self.defs = {}           # (region, name) -> def
        self.by_addr = {}        # (region, addr & ~1) -> def
        self.sym_region = {}     # addr & ~1 -> Counter of regions symbols: rows tag it with
        paths = []
        if snapshot is not None:
            overrides = snapshot
            paths = list(snapshot)
        else:
            base = os.path.join(root, *MATCHED.split("/"))
            for dp, _dn, fn in os.walk(base):
                for f in fn:
                    if f.endswith(".c"):
                        paths.append(os.path.relpath(os.path.join(dp, f), root).replace("\\", "/"))
        paths.sort()
        for path in paths:
            if path in overrides:
                text = overrides[path]
            else:
                with open(os.path.join(root, path), encoding="utf-8", errors="replace") as fh:
                    text = fh.read()
            h = header(text)
            region = h["region"] or ("twl" if "/twl" in path else "arm9")
            try:
                stripped, defs, protos, types = parse_file(text)
            except RecursionError:
                continue
            for d in defs:
                d["file"] = path
                d["region"] = region
                if d["name"] == h["function"] and h["address"]:
                    d["addr"] = int(h["address"], 16)
                else:
                    d["addr"] = h["syms"].get(d["name"], (addr_of_name(d["name"]),))[0]
                # the ISA as the source states it: the header's isa: line for the file's own
                # function, the symbols: row for any other definition it carries
                if d["name"] == h["function"] and h["isa"]:
                    d["isa"] = "thumb" if h["isa"].startswith("thumb") else "arm"
                elif d["name"] in h["syms"]:
                    d["isa"] = h["syms"][d["name"]][1]
                else:
                    d["isa"] = None
                d["thumb"] = (d["isa"] or "thumb") == "thumb"
                key = (region, d["name"])
                if key not in self.defs or d["name"] == h["function"]:
                    self.defs[key] = d
                if d.get("addr") and not re.search(r"\binline\b|__inline", d["ret"]):
                    ak = (region, d["addr"] & ~1)
                    if ak not in self.by_addr or d["name"] == h["function"]:
                        self.by_addr[ak] = d
            for _nm, (a, _isa, reg) in h["syms"].items():
                if reg:
                    self.sym_region.setdefault(a & ~1, collections.Counter())[reg] += 1
            macros = set(re.findall(r"(?m)^[ \t]*#[ \t]*define[ \t]+([A-Za-z_]\w*)", text))
            self.files.append(dict(path=path, h=h, region=region, defs=defs, protos=protos,
                                   types=types, macros=macros, stripped=stripped))

    def resolve(self, fi, name):
        if name in fi["macros"]:
            return None
        for d in fi["defs"]:
            if d["name"] == name:
                return d
        d = self._resolve(fi, name)
        if d and re.search(r"\bstatic\b", d["ret"]):
            d = None
        return d or self._resolve_addr(fi, name)

    def _resolve_addr(self, fi, name):
        """The matched definition at the address a name stands for, whatever
        the definition is called (a caller's func_020315D4 is the matched
        sub_020315D4).  The address comes from the caller's symbols: table,
        else from a func_/sub_/FUN_ name."""
        sym = fi["h"]["syms"].get(name)
        if sym:
            addr = sym[0]
        elif ADDR_NAME.match(name):
            addr = addr_of_name(name)
        else:
            return None
        if sym and sym[2] and sym[2] != "arm9":
            # static regions too: a few headers tag an arm9 address with an overlay
            # (func_021DEDCC's func_0200781C is marked ov170); static addresses
            # never collide with overlay ones
            regions = [sym[2]] + STATIC_REGIONS
        elif sym and sym[2] == "arm9":
            regions = STATIC_REGIONS
        else:
            regions = [fi["region"]] + STATIC_REGIONS
        for r in regions:
            d = self.by_addr.get((r, addr & ~1))
            if d:
                return d
        return None

    def _resolve(self, fi, name):
        sym = fi["h"]["syms"].get(name)
        if sym and sym[2] and sym[2] != "arm9":
            return self.defs.get((sym[2], name))
        if not sym or not sym[2]:
            # a symbols: row without a region is the caller's own region or a static one
            d = self.defs.get((fi["region"], name))
            if d:
                return d
        for r in STATIC_REGIONS:
            d = self.defs.get((r, name))
            if d:
                return d
        return None

    def def_at(self, region, addr):
        if addr is None:
            return None
        d = self.by_addr.get((region, addr & ~1))
        if d:
            return d
        for r in STATIC_REGIONS:
            d = self.by_addr.get((r, addr & ~1))
            if d:
                return d
        return None

    def name_of(self, region, addr):
        if addr is None:
            return "?"
        d = self.def_at(region, addr)
        return d["name"] if d else "%08X" % addr


# ---------------------------------------------------------------------------
# disassembly and register dataflow
# ---------------------------------------------------------------------------

_CS = {}


def _capstone():
    import capstone
    from capstone import arm as CA
    return capstone, CA


def md(thumb):
    if thumb not in _CS:
        capstone, _CA = _capstone()
        m = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)
        m.detail = True
        _CS[thumb] = m
    return _CS[thumb]


_REGNAME = {}


def regname(r):
    if not _REGNAME:
        _c, CA = _capstone()
        for i in range(13):
            _REGNAME[getattr(CA, "ARM_REG_R%d" % i)] = "r%d" % i
        _REGNAME[CA.ARM_REG_SB] = "r9"
        _REGNAME[CA.ARM_REG_SL] = "r10"
        _REGNAME[CA.ARM_REG_FP] = "r11"
        _REGNAME[CA.ARM_REG_IP] = "r12"
        _REGNAME[CA.ARM_REG_LR] = "lr"
        _REGNAME[CA.ARM_REG_SP] = "sp"
        _REGNAME[CA.ARM_REG_PC] = "pc"
    return _REGNAME.get(r)


TRACK = ["r%d" % i for i in range(13)] + ["lr"]
CONDS = ("eq", "ne", "cs", "cc", "mi", "pl", "vs", "vc", "hi", "ls", "ge", "lt", "gt", "le", "hs", "lo")
BRANCHES = set(["b", "cbz", "cbnz"] + ["b" + c for c in CONDS])
POPS = ("pop", "ldm", "ldmia", "ldmfd")
_COND_BASES = ("blx", "bl", "bx", "pop", "push", "ldmia", "ldmfd", "ldm", "stmdb", "stmfd", "stm", "mov", "ldr",
               "add", "b")


def base_mnemonic(mn):
    """The mnemonic without an ARM condition suffix: blne -> bl, popeq -> pop."""
    for b in _COND_BASES:
        if mn == b or (mn.startswith(b) and mn[len(b):] in CONDS):
            return b
    return mn


def branch_target(ins):
    _c, CA = _capstone()
    for op in ins.operands:
        if op.type == CA.ARM_OP_IMM:
            return op.imm
    return None


def _is_cond(ins):
    _c, CA = _capstone()
    return ins.cc not in (CA.ARM_CC_AL, getattr(CA, "ARM_CC_INVALID", CA.ARM_CC_AL))


def _copy_src(ins):
    """The source register name when ins is a plain register copy, else None."""
    _c, CA = _capstone()
    mn = ins.mnemonic.split(".")[0]
    ops = ins.operands
    if any(getattr(op, "shift", None) and op.shift.type for op in ops):
        return None
    if mn in ("mov", "movs", "cpy") and len(ops) == 2 and ops[0].type == ops[1].type == CA.ARM_OP_REG:
        return regname(ops[1].reg)
    if mn in ("adds", "add", "subs", "sub", "lsls", "lsl", "lsrs", "asrs", "orrs") and len(ops) == 3 \
            and ops[0].type == ops[1].type == CA.ARM_OP_REG and ops[2].type == CA.ARM_OP_IMM and ops[2].imm == 0 \
            and mn not in ("lsrs", "asrs"):
        return regname(ops[1].reg)
    return None


def _sp_mem(ins):
    """(offset) when the memory operand is [sp, #imm] without writeback or index."""
    _c, CA = _capstone()
    for op in ins.operands:
        if op.type == CA.ARM_OP_MEM:
            m = op.mem
            if regname(m.base) == "sp" and m.index == 0 and not ins.writeback:
                return m.disp
            return None
    return None


class Effect:
    __slots__ = ("kind", "cond", "cc", "setflags", "dst", "src", "slot", "lo", "target", "text", "addr", "writes",
                 "taken", "spdelta")


class Insns(list):
    """A function's instructions; jt maps the address of a Thumb `add pc, rN`
    to its switch's case targets (the halfword table after it is data, and is
    not in the list)."""
    jt = None


_COMPLEMENT = None


def complement_cc(cc):
    """The ARM condition that holds exactly when cc does not (eq <-> ne ...)."""
    global _COMPLEMENT
    if _COMPLEMENT is None:
        _c, CA = _capstone()
        pairs = [(CA.ARM_CC_EQ, CA.ARM_CC_NE), (CA.ARM_CC_HS, CA.ARM_CC_LO), (CA.ARM_CC_MI, CA.ARM_CC_PL),
                 (CA.ARM_CC_VS, CA.ARM_CC_VC), (CA.ARM_CC_HI, CA.ARM_CC_LS), (CA.ARM_CC_GE, CA.ARM_CC_LT),
                 (CA.ARM_CC_GT, CA.ARM_CC_LE)]
        _COMPLEMENT = {}
        for a, b in pairs:
            _COMPLEMENT[a], _COMPLEMENT[b] = b, a
    return _COMPLEMENT.get(cc)


def _switch_bound(insns, i):
    """N from the `cmp rX, #N` that bounds the switch dispatched at insns[i]."""
    _c, CA = _capstone()
    for j in range(i - 1, max(-1, i - 10), -1):
        p = insns[j]
        if base_mnemonic(p.mnemonic) == "cmp" and len(p.operands) == 2 and p.operands[1].type == CA.ARM_OP_IMM:
            return p.operands[1].imm
        if base_mnemonic(p.mnemonic) in ("bx", "pop"):
            break                      # a return: past the switch's own setup (a `b default`
                                       # between the bound check and the dispatch is fine)
    return None


def disasm_function(data, base, thumb):
    """Disassemble a function, skipping Thumb switch tables: MWCC's `cmp rX, #N;
    ...; add pc, rM` is followed by N+1 halfword offsets (case = add + 4 +
    offset), which linear decoding would read as instructions."""
    out = Insns()
    out.jt = {}
    pos = 0
    while pos < len(data):
        stop = None
        for ins in md(thumb).disasm(data[pos:], base + pos):
            out.append(ins)
            if thumb and ins.mnemonic == "add" and ins.op_str.startswith("pc, r"):
                n = _switch_bound(out, len(out) - 1)
                if n is None or n > 0x400:
                    continue
                t0 = ins.address + 2 - base
                if t0 + 2 * (n + 1) > len(data):
                    continue
                offs = [int.from_bytes(data[t0 + 2 * k:t0 + 2 * k + 2], "little", signed=True) for k in range(n + 1)]
                out.jt[ins.address] = [ins.address + 4 + o for o in offs]
                stop = t0 + 2 * (n + 1)
                break
        if stop is None:
            break
        pos = stop
    return out


def _effects(insns, ret64):
    """Per instruction: successor list and transfer description."""
    _c, CA = _capstone()
    idx = {ins.address: i for i, ins in enumerate(insns)}
    jt = getattr(insns, "jt", None) or {}
    n = len(insns)
    succ, eff, computed = [], [], []
    esc = None                    # lowest escaped sp offset, if the address of a stack slot is taken
    for ins in insns:
        ops = ins.operands
        if ops and ops[0].type == CA.ARM_OP_REG and regname(ops[0].reg) not in ("sp", "pc"):
            for op in ops[1:]:
                if op.type == CA.ARM_OP_REG and regname(op.reg) == "sp":
                    off = 0
                    if len(ops) == 3 and ops[2].type == CA.ARM_OP_IMM:
                        off = ops[2].imm
                    esc = off if esc is None else min(esc, off)
    for i, ins in enumerate(insns):
        mn = ins.mnemonic.split(".")[0]
        bm = base_mnemonic(mn)
        ops = ins.operands
        cond = _is_cond(ins)
        try:
            _rd, wr = ins.regs_access()
        except Exception:
            wr = []
        wn = set(x for x in (regname(r) for r in wr) if x)
        e = Effect()
        e.cond, e.cc, e.addr, e.text = cond, ins.cc, ins.address, "%s %s" % (ins.mnemonic, ins.op_str)
        e.setflags = bool(getattr(ins, "update_flags", False)) or bm in ("cmp", "cmn", "tst", "teq")
        e.kind, e.writes, e.dst, e.src, e.slot, e.target, e.lo = "other", wn, None, None, None, None, esc
        e.taken = None
        e.spdelta = _sp_delta(ins, bm)
        writes_pc = "pc" in wn or (bm in POPS and "pc" in ins.op_str) or (bm == "mov" and ins.op_str.startswith("pc"))
        s = []
        if bm in ("bl", "blx"):
            # blne / blxeq included: a conditional call is a call on the taken path
            e.kind = "call"
            e.target = branch_target(ins)
            e.slot = ret64(e.target)
            s = [i + 1]
        elif mn in BRANCHES:
            t = branch_target(ins)
            if t in idx:
                s.append(idx[t])
                if cond and idx[t] != i + 1:
                    e.taken = idx[t]
            if mn != "b" or cond:
                s.append(i + 1)
        elif ins.address in jt:
            # Thumb switch: `add pc, rN` goes to the case targets only
            s = [idx[t] for t in jt[ins.address] if t in idx]
            e.writes = set()
        elif bm == "add" and ins.op_str.startswith("pc, pc,") and _switch_bound(insns, i) is not None:
            # ARM switch: `addls pc, pc, rN, lsl #2` lands on the table of `b case`
            # words two instructions on; the fall-through `b default` covers the rest
            nb = _switch_bound(insns, i)
            s = ([i + 1] if cond else []) + [i + 2 + k for k in range(nb + 1)]
            e.kind, e.writes = "nop", set()
        elif bm == "bx" or writes_pc:
            s = [i + 1] if cond else []
            if cond:
                # a conditional return or jump: the fall-through path did not execute it
                e.kind, e.writes = "nop", set()
            if bm != "bx" and bm not in POPS and not (bm == "mov" and "lr" in ins.op_str) \
                    and not (bm == "ldr" and ("[sp]" in ins.op_str or "[pc" in ins.op_str)):
                computed.append(i)
        else:
            s = [i + 1]
            src = _copy_src(ins)
            if src and src in TRACK and regname(ops[0].reg) in TRACK:
                e.kind, e.dst, e.src = "copy", regname(ops[0].reg), src
            elif mn == "ldr" and ops and ops[0].type == CA.ARM_OP_REG and regname(ops[0].reg) in TRACK \
                    and _sp_mem(ins) is not None:
                e.kind, e.dst, e.slot = "ldsp", regname(ops[0].reg), _sp_mem(ins)
            elif mn.startswith("str"):
                off = _sp_mem(ins)
                if off is not None:
                    if mn == "str":
                        e.kind, e.src, e.slot = "stsp", regname(ops[0].reg), off
                    else:
                        e.kind, e.slot = "stsp_part", off
                else:
                    base = [op.mem.base for op in ops if op.type == CA.ARM_OP_MEM]
                    if base and regname(base[0]) == "sp":
                        e.kind = "clear_slots"
                    else:
                        e.kind = "store_other"
            elif mn.startswith("stm") and not (bm in ("stmdb", "stmfd") and "sp!" in ins.op_str):
                e.kind = "store_other"
            elif bm == "push" or (bm in ("stmdb", "stmfd") and "sp!" in ins.op_str):
                # the pushed registers land in stack slots 0, 4, ... of the new sp
                e.kind = "push"
                e.src = [regname(op.reg) for op in ops if op.type == CA.ARM_OP_REG and regname(op.reg) != "sp"]
        if "sp" in wn and e.kind != "nop":
            e.writes = wn | {"sp"}
        succ.append([x for x in s if x < n])
        eff.append(e)
    return succ, eff, computed


def cond_prior(state, loc, cc):
    """When loc was last written under condition cc (no flag change since), the
    value it held before that write; a read under the same cc sees only the
    new value."""
    pend = state.get(("cw", loc))
    if pend is not None and len(pend) == 1:
        pcc, prior = next(iter(pend))
        if pcc == cc:
            return prior
    return None


def refine_edge(state, known):
    """The state on an edge where condition `known` is known to hold.

    A pending conditional write ("cw") under `known` happened on this edge
    (only the new value remains); one under its complement did not (only the
    prior value remains).  A guarded write ("cwg": written under X, then a
    compare also under X, e.g. `ldrne r2; cmpne r2, #0`) happened when X is
    known here, since a skipped compare leaves the flags at not-X."""
    keys = [k for k in state if isinstance(k, tuple) and k[0] in ("cw", "cwg")]
    if not keys:
        return state
    out = dict(state)
    for k in keys:
        tag, loc = k
        pend = state[k]
        if len(pend) != 1 or loc not in state:
            continue
        pcc, prior = next(iter(pend))
        if pcc == known:
            new = state[loc] - prior
            if new:
                out[loc] = new
            del out[k]
        elif tag == "cw" and complement_cc(pcc) == known:
            out[loc] = prior
            del out[k]
    return out


def _sp_address(ins):
    """k when ins computes sp + k into a register other than sp (`add r3, sp, #0x14`,
    `mov r0, sp`), else None."""
    _c, CA = _capstone()
    ops = ins.operands
    if len(ops) < 2 or ops[0].type != CA.ARM_OP_REG or regname(ops[0].reg) in ("sp", "pc"):
        return None
    mn = ins.mnemonic.split(".")[0]
    if mn not in ("add", "adds", "mov", "movs"):
        return None
    if not any(op.type == CA.ARM_OP_REG and regname(op.reg) == "sp" for op in ops[1:]):
        return None
    imm = [op.imm for op in ops[1:] if op.type == CA.ARM_OP_IMM]
    return imm[0] if imm else 0


def _sp_delta(ins, bm):
    """The known change a push / pop / `sub sp` / `add sp` makes to sp, or None."""
    _c, CA = _capstone()
    ops = ins.operands
    regs = [op for op in ops if op.type == CA.ARM_OP_REG and regname(op.reg) != "sp"]
    if bm == "push" or (bm in ("stmdb", "stmfd") and "sp!" in ins.op_str):
        return -4 * len(regs)
    if bm in ("pop", "ldmia", "ldmfd", "ldm") and (bm == "pop" or "sp!" in ins.op_str):
        return 4 * len(regs)
    mn = ins.mnemonic.split(".")[0]
    if mn in ("sub", "add", "subs", "adds") and ops and ops[0].type == CA.ARM_OP_REG and regname(ops[0].reg) == "sp":
        imm = [op.imm for op in ops if op.type == CA.ARM_OP_IMM]
        srcs = [op for op in ops[1:] if op.type == CA.ARM_OP_REG]
        if len(imm) == 1 and all(regname(op.reg) == "sp" for op in srcs):
            return (-imm[0]) if mn.startswith("sub") else imm[0]
    return None


def _apply(state, e):
    out = _apply_writes(state, e)
    if e.kind == "call" or (e.setflags and not e.cond):
        # the flags changed: pending conditional writes can no longer pair up
        for k in [k for k in out if isinstance(k, tuple) and k[0] in ("cw", "cwg")]:
            del out[k]
    elif e.setflags:
        # a compare under condition X: writes made under X stay knowable on an
        # edge where X is known to hold; everything else is lost
        for k in [k for k in out if isinstance(k, tuple) and k[0] in ("cw", "cwg")]:
            pend = out[k]
            keep = len(pend) == 1 and next(iter(pend))[0] == e.cc
            del out[k]
            if keep:
                out[("cwg", k[1])] = pend
    return out


def _apply_writes(state, e):
    out = dict(state)

    def put(loc, val):
        if e.cond and loc in state:
            pend = state.get(("cw", loc))
            if pend is not None and len(pend) == 1:
                pcc, prior = next(iter(pend))
                if complement_cc(pcc) == e.cc:
                    # `ldrhne r3` then `ldrheq r3`: written on both paths, the old value is gone
                    out[loc] = (state[loc] - prior) | val
                    del out[("cw", loc)]
                    return
            out[loc] = state[loc] | val
            out[("cw", loc)] = frozenset([(e.cc, state[loc])])
            out.pop(("cwg", loc), None)
        else:
            out[loc] = val
            out.pop(("cw", loc), None)
            out.pop(("cwg", loc), None)

    def drop_slots(pred):
        for k in [k for k in out if isinstance(k, int) and pred(k)]:
            del out[k]

    if e.kind == "call":
        put("r0", frozenset([("ret", e.addr, e.target)]))
        put("r1", frozenset([("ret1", e.addr, e.target)]) if e.slot else frozenset([("clob", e.addr, e.target)]))
        for r in ("r2", "r3", "r12"):
            put(r, frozenset([("clob", e.addr, e.target)]))
        put("lr", frozenset([("ins", e.addr, e.text)]))
        if e.lo is not None:
            drop_slots(lambda k: k >= e.lo)
        return out
    if e.kind == "copy":
        put(e.dst, state.get(e.src, frozenset([("ins", e.addr, e.text)])))
        return out
    if e.kind == "ldsp":
        put(e.dst, state.get(e.slot, frozenset([("ins", e.addr, e.text)])))
        return out
    if e.kind == "stsp":
        old = state.get(e.slot)
        drop_slots(lambda k: abs(k - e.slot) < 4)
        if e.src in state:
            if not e.cond:
                out[e.slot] = state[e.src]
            elif old is not None:
                out[e.slot] = old | state[e.src]
    elif e.kind == "stsp_part":
        drop_slots(lambda k: abs(k - e.slot) < 4)
    elif e.kind == "clear_slots":
        drop_slots(lambda k: True)
    elif e.kind == "store_other" and e.lo is not None:
        drop_slots(lambda k: k >= e.lo)
    for r in e.writes:
        if r in TRACK:
            put(r, frozenset([("ins", e.addr, e.text)]))
    if "sp" in e.writes:
        if e.spdelta is None or e.cond:
            drop_slots(lambda k: True)
        else:
            # a known sp change: slots keep their values at shifted offsets
            moved = {}
            for k in [k for k in out if isinstance(k, int)]:
                v = out.pop(k)
                if k - e.spdelta >= 0:
                    moved[k - e.spdelta] = v
            out.update(moved)
            if e.kind == "push":
                prologue = "lr" in e.src
                for n_r, r in enumerate(e.src):
                    if prologue and r in ARGR:
                        continue    # `push {r3, lr}`: r3 is alignment padding, its slot a fresh local
                    if r in state:
                        out[4 * n_r] = state[r]
    return out


def _merge(a, b):
    m = {}
    for k in a:
        if k in b:
            v = a[k] | b[k]
            if isinstance(k, tuple) and len(v) > 1:
                # conditional-write records under the same condition: one record whose
                # prior is the union (a loop's iterations differ only in the prior)
                ccs = set(c for c, _p in v)
                if len(ccs) == 1:
                    v = frozenset([(ccs.pop(), frozenset().union(*[p for _c, p in v]))])
            m[k] = v
    return m


def analyze(insns, ret64=lambda t: False):
    """Reaching definitions of r0-r12, lr and word stack slots at each instruction (IN states).

    An origin is ("entry", reg), ("ret", addr, target), ("ret1", addr, target),
    ("clob", addr, target) or ("ins", addr, text).  Register copies and stack
    spill reloads forward their source's origins."""
    n = len(insns)
    if not n:
        return []
    succ, eff, computed = _effects(insns, ret64)
    IN = [None] * n
    IN[0] = {r: frozenset([("entry", r)]) for r in TRACK}
    work = [0]
    seeded = False
    while True:
        while work:
            i = work.pop()
            e = eff[i]
            out = _apply(IN[i], e)
            for j in succ[i]:
                if e.cond and (e.taken is not None or e.kind == "nop"):
                    # the edge tells which way the condition went: `movgt r2; bgt L`
                    # reaches L with r2 written, the fall-through without
                    known = e.cc if j == e.taken else complement_cc(e.cc)
                    out_j = refine_edge(out, known) if known is not None else out
                else:
                    out_j = out
                if IN[j] is None:
                    IN[j] = out_j
                    work.append(j)
                else:
                    nw = _merge(IN[j], out_j)
                    if nw != IN[j]:
                        IN[j] = nw
                        work.append(j)
        if seeded or not computed:
            break
        seeded = True
        st = None
        for j in computed:
            if IN[j] is not None:
                st = dict(IN[j]) if st is None else _merge(st, IN[j])
        if st is None:
            break
        for k in range(n):
            if IN[k] is None:
                IN[k] = st
                work.append(k)
    return IN


# ---------------------------------------------------------------------------
# the scan
# ---------------------------------------------------------------------------

READS_MAX_DEPTH = 12     # nested callees followed when deciding what a function reads


class Scanner:
    def __init__(self, index):
        self.ix = index
        self._ins = {}
        self._an = {}
        self._reads = {}
        self._busy = set()
        self.undecidable = {}    # (region, addr) -> a jump target outside the image
        self._M = None

    def M(self):
        if self._M is None:
            import match
            self._M = match
        return self._M

    def func_insns(self, region, addr, thumb, isa_known=False):
        """(insns, thumb, data, base) of the original function at addr, or None.

        The ISA is the listing label's unless isa_known says the caller already
        knows it (a definition's isa: or symbols: row, or the state a call
        instruction switches to), which wins over the listing.  Without a
        label at addr the extent runs to the next listing label."""
        addr &= ~1
        key = (region, addr, bool(thumb) if isa_known else None)
        if key in self._ins:
            return self._ins[key]
        res = None
        M = self.M()
        try:
            size, th = M.target_extent(addr, region)
            if not isa_known:
                thumb = th
            if thumb is not None:
                if size is None and th is not None:
                    # the last function of a listing has no next label: read to the
                    # region's end (capped); only code reachable from the entry counts
                    r = M.find_region(addr, region)
                    size = min(r.base + len(r.data) - addr, 0x1000)
                elif size is None:
                    nxt = M.next_listing_label(addr, region)
                    size = (nxt - addr) if nxt else None
                if size and size <= 0x4000:
                    _n, data = M.target_bytes(addr, size, region=region)
                    res = (disasm_function(data, addr, thumb), thumb, data, addr)
        except (SystemExit, Exception):
            res = None
        self._ins[key] = res
        return res

    def caller_insns(self, d):
        return self.func_insns(d["region"], d["addr"], d["thumb"], isa_known=d.get("isa") is not None)

    def ret64(self, region):
        def f(t):
            d = self.ix.def_at(region, t)
            return bool(d and d.get("ret64"))
        return f

    def analysis(self, region, addr, fi):
        key = (region, addr, fi[1])
        if key not in self._an:
            self._an[key] = analyze(fi[0], self.ret64(region))
        return self._an[key]

    def jump_target(self, insns, i, data, base, thumb, region):
        """For a register jump or call (`bx ip`, `blx r3`, `mov pc, ip`): the
        address the register was loaded with from a literal pool within the
        last few instructions, or None.  `ldr ip, =g; bx ip` is a tail call.
        Bit 0 of the value is kept: it is the ISA a bx/blx switches to."""
        _c, CA = _capstone()
        ins = insns[i]
        bm = base_mnemonic(ins.mnemonic)
        ops = ins.operands
        if not ops:
            return None
        if bm == "mov":
            if not ins.op_str.startswith("pc,") or len(ops) < 2 or ops[1].type != CA.ARM_OP_REG:
                return None
            rop = ops[1].reg
        elif bm in ("bx", "blx"):
            if ops[0].type != CA.ARM_OP_REG or regname(ops[0].reg) == "lr":
                return None
            rop = ops[0].reg
        else:
            return None
        for j in range(i - 1, max(-1, i - 8), -1):
            pj = insns[j]
            if pj.mnemonic.startswith("ldr") and pj.operands and pj.operands[0].type == CA.ARM_OP_REG \
                    and pj.operands[0].reg == rop and len(pj.operands) > 1 \
                    and pj.operands[1].type == CA.ARM_OP_MEM and pj.operands[1].mem.base == CA.ARM_REG_PC:
                pc = (pj.address + 4) & ~3 if thumb else pj.address + 8
                la = pc + pj.operands[1].mem.disp
                off = la - base
                if 0 <= off <= len(data) - 4:
                    return int.from_bytes(data[off:off + 4], "little")
                try:
                    return int.from_bytes(self.M().target_bytes(la, 4, region=region)[1], "little")
                except BaseException:
                    return None
            try:
                _r, w = pj.regs_access()
            except Exception:
                w = []
            if rop in w:
                return None
        return None

    def call_sites(self, caller, callee_addr):
        fi = self.caller_insns(caller) if caller.get("addr") else None
        if not fi:
            return None
        insns, thumb, data, base = fi
        IN = self.analysis(caller["region"], caller["addr"], fi)
        out = []
        for i, ins in enumerate(insns):
            mn = ins.mnemonic
            bm = base_mnemonic(mn)
            if IN[i] is None:
                continue
            if bm in ("bl", "blx") or mn in BRANCHES:
                t = branch_target(ins)
                if t is not None and (t & ~1) == (callee_addr & ~1):
                    out.append((ins.address, mn, IN[i]))
                    continue
            if bm in ("bx", "blx", "mov"):
                v = self.jump_target(insns, i, data, base, thumb, caller["region"])
                if v is not None and (v & ~1) == (callee_addr & ~1):
                    out.append((ins.address, mn + "-via-ldr", IN[i]))
        return out

    def all_call_sites(self, caller):
        """{target address: [(site address, mnemonic, IN state)]} for every call,
        tail call and pool-loaded register jump in the caller's original."""
        fi = self.caller_insns(caller) if caller.get("addr") else None
        if not fi:
            return None
        insns, thumb, data, base = fi
        IN = self.analysis(caller["region"], caller["addr"], fi)
        idx = set(ins.address for ins in insns)
        out = collections.defaultdict(list)
        for i, ins in enumerate(insns):
            if IN[i] is None:
                continue
            mn = ins.mnemonic
            bm = base_mnemonic(mn)
            t = None
            if bm in ("bl", "blx"):
                t = branch_target(ins)
                if t is None:
                    t = self.jump_target(insns, i, data, base, thumb, caller["region"])
            elif mn in BRANCHES and mn not in ("cbz", "cbnz"):
                t = branch_target(ins)
                if t in idx:
                    t = None
            elif bm in ("bx", "mov"):
                t = self.jump_target(insns, i, data, base, thumb, caller["region"])
            if t is not None:
                out[t & ~1].append((ins.address, mn, IN[i]))
        return out

    # ------------------------------------------------------------ callee side

    def locate(self, addr, region_hint, thumb_hint=None):
        """(region, thumb) of the function that starts at addr, or None.

        The ISA, at every level of a follow: a matched definition's isa: or
        symbols: row first, then the state the call switches to (bl keeps it,
        blx #imm flips it, bx/blx reg take bit 0 of the address), then the
        listing label."""
        if addr is None:
            return None
        addr &= ~1
        d = self.ix.def_at(region_hint, addr)
        isa = None
        if d is not None and d.get("isa"):
            isa = d["isa"] == "thumb"
        elif thumb_hint is not None:
            isa = bool(thumb_hint)
        # an unmatched callee in another overlay (ov043 calling ov021's func_02188D2C):
        # the region other files' symbols: rows tag the address with, else the one
        # overlay whose listing has a label there
        tagged = [r for r, _n in self.ix.sym_region.get(addr, collections.Counter()).most_common()]
        cands = ([d["region"]] if d else []) + [region_hint] + STATIC_REGIONS + tagged
        for r in dict.fromkeys(cands):
            try:
                _size, th = self.M().target_extent(addr, r)
            except (SystemExit, Exception):
                continue
            if th is not None:
                return r, (th if isa is None else isa)
        owners = self.label_owners(addr)
        if len(owners) == 1:
            return owners[0][0], (owners[0][1] if isa is None else isa)
        if isa is not None:
            return (d["region"] if d else region_hint), isa
        return None

    _LABELS = None

    def label_owners(self, addr):
        """[(overlay, thumb)] whose listing has a function label at addr."""
        if Scanner._LABELS is None:
            labels = collections.defaultdict(list)
            M = self.M()
            for p in sorted(glob.glob(os.path.join(ROOT, "asm", "overlays", "ov*.s"))):
                r = os.path.splitext(os.path.basename(p))[0]
                if not re.match(r"^ov\d+$", r):
                    continue
                try:
                    for a, th in M.scan_listing(r).items():
                        if th is not None:
                            labels[a].append((r, th))
                except (SystemExit, Exception):
                    continue
            Scanner._LABELS = labels
        return Scanner._LABELS.get(addr & ~1, [])

    def reads(self, region, addr, depth=0, thumb=None, strict=False):
        """The argument registers r0-r3 a function's original code reads before
        writing them, on any path from its entry.

        A read is any use of a register whose value is still the incoming
        r0-r3 (also after copies and spill reloads), except: a copy or a
        stack spill that is loaded back (the value is followed instead), a
        push, and the arguments of a call or tail call, which count only if
        that callee reads them in turn (followed READS_MAX_DEPTH levels deep).
        A store to a stack slot the function never loads back is an outgoing
        stack argument (or a local whose address escapes) and counts as a
        read.  At a return, r0 (and r1 for a 64-bit result) counts when the
        function returns a value.

        Two modes for what cannot be decided (no bytes, an unresolved jump, a
        cycle, the depth cap, a callee without a definition at its return):
        by default it counts as read and an unknown function gives None (safe
        for phantom verdicts); strict=True counts it as not read (safe for the
        broader passthrough check, which must not invent rows)."""
        unknown = set() if strict else None
        if addr is None:
            return unknown
        if thumb is None and addr & 1:
            thumb = True
        addr &= ~1
        key = (region, addr, thumb, strict)
        if key in self._reads:
            return self._reads[key]
        if key in self._busy or depth > READS_MAX_DEPTH:
            return unknown
        loc = self.locate(addr, region, thumb)
        fi = self.func_insns(loc[0], addr, loc[1], isa_known=True) if loc else None
        if not fi or not fi[0]:
            self._reads[key] = unknown
            return unknown
        self._busy.add(key)
        try:
            res = self._reads_of(loc[0], addr, fi, depth, strict)
        finally:
            self._busy.discard(key)
        self._reads[key] = res
        return res

    def _reads_of(self, region, addr, fi, depth, strict):
        insns, thumb, data, base = fi
        IN = self.analysis(region, addr, fi)
        succ, eff, _computed = _effects(insns, self.ret64(region))
        n = len(insns)
        idx = {ins.address: i for i, ins in enumerate(insns)}
        d = self.ix.def_at(region, addr)
        if d is not None:
            ret_regs = () if d["void"] else (("r0", "r1") if d.get("ret64") else ("r0",))
        else:
            ret_regs = () if strict else ("r0",)
        esc = eff[0].lo
        reloaded = set(e.slot for e in eff if e.kind == "ldsp")
        read = set()

        cur = [None]

        def ent(st, r):
            origins = st.get(r, ())
            e = cur[0]
            if e is not None and e.cond:
                # `ldrne r2, [..]; cmpne r2, #0`: a read under the condition the register
                # was just written under sees that write, not the incoming value
                prior = cond_prior(st, r, e.cc)
                if prior is not None:
                    origins = origins - prior
            return set(o[1] for o in origins if o[0] == "entry" and o[1] in ARGR)

        def pass_args(st, t, t_thumb, tail=False):
            lt0 = self.locate(t, region, t_thumb) if t is not None else None
            if t is not None and (lt0 is None or (lt0[0] == TWL and region != TWL and tail)):
                # a jump out of the image, or from DS code into the DSi-only TWL
                # region (ov172's `ldr pc` veneer to 0x0272FCE0): undecidable
                self.undecidable.setdefault((region, addr), t)
            tr = self.reads(region, t, depth + 1, t_thumb, strict) if t is not None else (set() if strict else None)
            for r in ARGR:
                if tr is None or r in tr:
                    read.update(ent(st, r))

        for i, ins in enumerate(insns):
            st = IN[i]
            if st is None:
                continue
            cur[0] = eff[i]
            if base_mnemonic(ins.mnemonic) == "ldr" and ins.op_str.startswith("pc, [pc"):
                # `ldr pc, =g`: a veneer, a tail call to the literal
                la = (ins.address + 4) & ~3 if thumb else ins.address + 8
                la += ins.operands[1].mem.disp if len(ins.operands) > 1 else 0
                off = la - base
                t = int.from_bytes(data[off:off + 4], "little") if 0 <= off <= len(data) - 4 else None
                pass_args(st, t, None if t is None else bool(t & 1), tail=True)
                continue
            e = eff[i]
            mn = ins.mnemonic.split(".")[0]
            bm = base_mnemonic(mn)
            if i == n - 1 and succ[i] == [] and e.kind not in ("nop",) and not (
                    bm in ("b", "bx") or bm in POPS or "pc" in e.writes):
                return read if strict else None    # runs off the end of the bytes read
            if e.kind == "stsp":
                if esc is None and e.slot in reloaded:
                    continue                       # a spill: the reload is followed
                read.update(ent(st, e.src))        # an outgoing stack argument
                continue
            k_esc = _sp_address(ins)
            if k_esc is not None:
                # `add r3, sp, #0x14`: the slot's address escapes, so its value is read
                # (only that slot: the other pushed registers stay unread)
                for o in st.get(k_esc, ()):
                    if o[0] == "entry" and o[1] in ARGR:
                        read.add(o[1])
                continue
            if e.kind == "copy" or bm == "push" or (bm in ("stmdb", "stmfd") and "sp!" in ins.op_str):
                continue
            if e.kind == "call":
                if e.target is None:
                    t = self.jump_target(insns, i, data, base, thumb, region)
                    pass_args(st, t, None if t is None else bool(t & 1))
                    try:
                        rd, _w = ins.regs_access()
                    except Exception:
                        rd = []
                    for r in (regname(x) for x in rd):
                        if r in TRACK and r not in ARGR:
                            read.update(ent(st, r))
                else:
                    # bl keeps the state, blx #imm switches it
                    pass_args(st, e.target, thumb if bm == "bl" else not thumb)
                continue
            if mn in BRANCHES and mn not in ("cbz", "cbnz"):
                t = branch_target(ins)
                if t is not None and t not in idx:
                    pass_args(st, t, thumb, tail=True)       # a tail call
                continue
            if (bm == "bx" and ins.op_str == "lr") or (bm in POPS and "pc" in ins.op_str) \
                    or (bm == "mov" and ins.op_str.replace(" ", "") == "pc,lr") \
                    or (bm == "ldr" and ins.op_str.startswith("pc, [sp]")):
                for r in ret_regs:
                    read.update(ent(st, r))
                continue
            if bm == "bx" or (bm == "mov" and ins.op_str.startswith("pc,")):
                # `ldr ip, =g; bx ip`: a tail call; bx takes the ISA from bit 0,
                # mov pc stays in the current state
                t = self.jump_target(insns, i, data, base, thumb, region)
                pass_args(st, t, None if t is None else (bool(t & 1) if bm == "bx" else thumb), tail=True)
                continue
            try:
                rd, _w = ins.regs_access()
            except Exception:
                rd = []
            for r in (regname(x) for x in rd):
                if r in TRACK:
                    read.update(ent(st, r))
        return read

    def undecidable_at(self, region, addr):
        """The out-of-image jump target that makes a function's reads undecidable, or None."""
        loc = self.locate(addr, region)
        if loc is None:
            return None
        self.reads(loc[0], addr & ~1, thumb=loc[1])
        return self.undecidable.get((loc[0], addr & ~1))

    def returns_value(self, region, addr):
        """True / False / None: does the function leave a value of its own in
        r0 at every return (the definition decides when there is one)."""
        loc = self.locate(addr, region)
        if not loc:
            return None
        d = self.ix.def_at(loc[0], addr)
        if d is not None:
            return not d["void"]
        fi = self.func_insns(loc[0], addr, loc[1], isa_known=True)
        if not fi or not fi[0]:
            return None
        insns = fi[0]
        IN = self.analysis(loc[0], addr & ~1, fi)
        seen = False
        for i, ins in enumerate(insns):
            if IN[i] is None:
                continue
            bm = base_mnemonic(ins.mnemonic)
            if (bm == "bx" and ins.op_str == "lr") or (bm in POPS and "pc" in ins.op_str):
                seen = True
                if any(o[0] in ("entry", "clob") for o in IN[i]["r0"]):
                    return False
        return True if seen else None

    def sites_for(self, fi, d, callee_addr):
        """bl sites in the original for a call written in def d (inline helpers map to their callers)."""
        if d.get("addr") and not re.search(r"inline", d["ret"]):
            return self.call_sites(d, callee_addr)
        outs = None
        for o in fi["defs"]:
            if o is d or not o.get("addr") or re.search(r"inline", o["ret"]):
                continue
            if re.search(r"\b%s\s*\(" % re.escape(d["name"]), o["body"]):
                r = self.call_sites(o, callee_addr)
                if r is not None:
                    outs = (outs or []) + r
        return outs


def fmt_origins(origins, ix, region):
    out = []
    for o in sorted(origins, key=str):
        if o[0] == "entry":
            out.append("entry %s" % o[1])
        elif o[0] == "ret":
            out.append("ret(%s)" % ix.name_of(region, o[2]))
        elif o[0] == "ret1":
            out.append("ret-hi(%s)" % ix.name_of(region, o[2]))
        elif o[0] == "clob":
            out.append("clobbered-by-bl(%s)" % ix.name_of(region, o[2]))
        else:
            out.append("'%s'@%08X" % (o[2], o[1]))
    return "|".join(out)


def callee_uses(cd, i):
    nm = cd["pnames"][i] if i < len(cd["pnames"]) else None
    if not nm:
        return False
    return re.search(r"\b%s\b" % re.escape(nm), cd["body"]) is not None


def caller_param_of(d, reg):
    """The caller's own parameter that arrives in reg, or None."""
    w = int(reg[1:])
    for i, (first, n) in enumerate(d["layout"]):
        if first <= w < first + n:
            return i
    return None


def classify(ix, d, regs, opr, proto_short):
    """(kind, confidence, detail) for one missing parameter held in regs."""
    allo = set()
    for r in regs:
        allo |= opr[r]
    kinds = set(o[0] for o in allo)
    entry_regs = set(o[1] for o in allo if o[0] == "entry")
    argentry = bool(entry_regs) and entry_regs <= set(ARGR)
    dtxt = fmt_origins(allo, ix, d["region"])
    regtxt = ":".join(regs)
    if kinds == {"entry"} and argentry:
        via = ""
        for r in regs:
            for o in opr[r]:
                if o[1] != r:
                    via = " (restored from a copy of the incoming %s)" % o[1]
        descr = []
        for r in sorted(entry_regs):
            pi = caller_param_of(d, r)
            if pi is not None:
                pv = d["pnames"][pi] if pi < len(d["pnames"]) else None
                descr.append("caller's own param %d '%s'" % (pi, pv))
            else:
                descr.append("caller's incoming %s, which the caller's definition does not declare "
                             "(caller has %s params)" % (r, d["n"]))
        return "a", "high", "%s = %s%s" % (regtxt, "; ".join(descr), via)
    if all(opr[r] and all(o[0] == ("ret" if k == 0 else "ret1") for o in opr[r]) for k, r in enumerate(regs)):
        via = " (restored from a copy)" if regs[0] != "r0" else ""
        return "b", "high", "%s = %s%s" % (regtxt, dtxt.replace("ret(", "return value of ("), via)
    if kinds == {"ins"}:
        # a definite value the caller computed for something else (func_02062F90's
        # shared `mov r1, #0` reaching func_02062D4C's frames)
        return "set", "high", "%s set by the caller's own instruction(s), a value the C does not pass: %s" % (
            regtxt, dtxt)
    if kinds == {"entry", "ret"} and argentry:
        return "a", "med", "%s on different paths: %s" % (regtxt, dtxt)
    if kinds <= {"clob"}:
        return "c", "low", "%s holds garbage (clobbered by earlier bl): %s" % (regtxt, dtxt)
    if kinds == {"entry"} and not entry_regs & set(ARGR):
        return "c", "low", "%s = a callee-saved value of the caller's own caller: %s" % (regtxt, dtxt)
    argin = "entry" in kinds and bool(entry_regs & set(ARGR))
    kind = "c" if proto_short else ("a" if argin else "c")
    conf = "med" if (argin or "ret" in kinds) else "low"
    return kind, conf, "%s set by: %s" % (regtxt, dtxt)


THUNK_BODY = re.compile(r"^\s*(?:return\s+)?(?:\(\s*void\s*\)\s*)?([A-Za-z_]\w*)\s*\(\s*\)\s*;\s*(?:return\s*;\s*)?$")


def find_thunks(ix, sc, scope=None):
    """{(file, func): info} for definitions matched as `void f(void) { g(); }`
    whose original code reaches g with some of r0-r3 still holding f's own
    incoming values: f forwards them (and g's return) without naming them.
    g need not be matched."""
    out = {}
    for fi in ix.files:
        if scope is not None and fi["path"] not in scope:
            continue
        for d in fi["defs"]:
            if d["asm"] or not d.get("addr") or d["n"] not in (0, None) \
                    or re.search(r"\binline\b|__inline", d["ret"]):
                continue
            m = THUNK_BODY.match(d["body"])
            if not m:
                continue
            name = m.group(1)
            cd = ix.resolve(fi, name)
            if cd and cd.get("addr"):
                taddr, treg = cd["addr"], cd["region"]
            else:
                sym = fi["h"]["syms"].get(name)
                taddr = sym[0] if sym else (addr_of_name(name) if ADDR_NAME.match(name) else None)
                treg = d["region"]
            if taddr is None:
                continue
            sites = sc.call_sites(d, taddr)
            if not sites:
                continue
            fwd = [r for r in ARGR if all(s[2].get(r) == frozenset([("entry", r)]) for s in sites)]
            if not fwd:
                continue
            how = "tail call" if all(s[1] not in ("bl", "blx") for s in sites) else "call"
            greads = sc.reads(treg, taddr)
            gret = sc.returns_value(treg, taddr)
            used = sorted(set(fwd) & greads) if greads is not None else None
            if used:
                conf = "high"
            else:
                conf = "med" if greads is None else "low"
            detail = "thunk: forwards %s unchanged to %s (%s); %s reads %s" % (
                ", ".join(fwd), name, how, name,
                "unknown registers" if greads is None else (", ".join(sorted(greads)) or "none of r0-r3"))
            if gret is None:
                detail += "; whether %s returns a value is unknown" % name
            elif gret:
                detail += "; %s returns a value (%s), which the thunk passes back in r0%s" % (
                    name, ("def returns " + cd["ret"]) if cd else "r0 written on every return",
                    " although it is defined void" if d["void"] else "")
            else:
                detail += "; %s returns nothing" % name
            if cd and cd["name"] != name:
                detail += "; defined as %s (resolved by address)" % cd["name"]
            if not cd:
                detail += "; %s is not matched" % name
            und = sc.undecidable_at(treg, taddr)
            if und is not None:
                detail += "; undecidable: %s jumps to 0x%08X, outside the image" % (name, und)
                conf = "low"
            row = dict(caller_file=fi["path"], caller_func=d["name"], callee=name,
                       callee_def=cd["name"] if cd else name, callee_def_file=cd["file"] if cd else "-",
                       kind="thunk", detail=detail, confidence=conf, region=d["region"],
                       area=area_of(fi["path"]), sdk=is_sdk(fi["path"]), arg=0, reg=fwd[0], pos=0)
            out[(fi["path"], d["name"])] = dict(target=taddr, row=row)
    return out


BROAD_TAG = "[broader check]"


def broad_rows(ix, sc, scope, thunks, callers_of):
    """Rows for registers a callee's ORIGINAL code reads that the C call does
    not supply, beyond what the callee's definition declares (a definition
    that is void, too short, unprototyped, or missing altogether).  The
    declared-but-unpassed parameters are the main scan's rows; this adds what
    a too-short definition hides.  Callee reads are strict here: anything
    undecidable counts as not read, so no row rests on a guess."""
    out = []
    callers = []
    for fi in ix.files:
        for d in fi["defs"]:
            if d["asm"] or not d.get("addr") or re.search(r"\binline\b|__inline", d["ret"]):
                continue
            callers.append((fi, d))
    if scope is not None:
        keep = set((fi["path"], d["name"]) for fi, d in callers if fi["path"] in scope)
        for key, lst in callers_of.items():
            cd = ix.defs[key]
            if cd["file"] in scope:
                keep.update((f["path"], dd["name"]) for f, dd, _c in lst)
        callers = [(fi, d) for fi, d in callers if (fi["path"], d["name"]) in keep]
    for fi, d in callers:
        calls = find_calls(d["body"])
        if not calls:
            continue
        bytarget = collections.defaultdict(list)
        for c in calls:
            cd = ix.resolve(fi, c["name"])
            if cd is not None and cd.get("addr"):
                bytarget[cd["addr"] & ~1].append((c, cd))
                continue
            sym = fi["h"]["syms"].get(c["name"])
            a = sym[0] if sym else (addr_of_name(c["name"]) if ADDR_NAME.match(c["name"]) else None)
            if a is not None:
                bytarget[a & ~1].append((c, None))
        if not bytarget:
            continue
        tk = thunks.get((fi["path"], d["name"]))
        sites = None
        for taddr, cl in bytarget.items():
            if tk and (tk["target"] & ~1) == taddr:
                continue
            cd = cl[0][1]
            if cd is not None and cd["var"]:
                continue
            hint = None
            if cd is None:
                sym = fi["h"]["syms"].get(cl[0][0]["name"])
                if sym:
                    hint = sym[1] == "thumb"
            creads = sc.reads(cd["region"] if cd else d["region"], taddr, thumb=hint, strict=True)
            if not creads:
                continue
            declared = cd["words"] if cd is not None and cd["n"] is not None else 0
            if sites is None:
                sites = sc.all_call_sites(d) or {}
            ss = sites.get(taddr, [])
            if not ss:
                continue
            cl_sorted = sorted(cl, key=lambda x: x[0]["pos"])
            paired = len(ss) == len(cl_sorted)
            for n_c, (c, _cd) in enumerate(cl_sorted):
                if cd is not None:
                    lay = cd["layout"]
                    supplied = sum(w for _f, w in lay[:c["k"]]) + max(0, c["k"] - len(lay))
                else:
                    supplied = c["k"]
                for r in sorted(creads):
                    w = int(r[1:])
                    if w < supplied or w < declared:
                        continue                  # passed, or a declared parameter (main scan)
                    use = [ss[n_c]] if paired else ss
                    opr = {r: frozenset().union(*[st[2].get(r, frozenset()) for st in use])}
                    kind, conf, detail = classify(ix, d, [r], opr, False)
                    if not paired and len(ss) > 1:
                        detail += " [union over %d bl sites]" % len(ss)
                    detail += "; callee's original code reads %s, the C call passes %d" % (r, c["k"])
                    if cd is None:
                        detail += "; callee not matched"
                    elif cd["n"] is None:
                        detail += "; callee definition is unprototyped ()"
                    else:
                        detail += "; callee definition too short (%s declares %d params%s)" % (
                            cd["name"], cd["n"], ", void" if cd["n"] == 0 else "")
                    if cd is not None and c["name"] != cd["name"]:
                        detail += "; defined as %s (resolved by address)" % cd["name"]
                    und = sc.undecidable_at(cd["region"] if cd else d["region"], taddr)
                    if und is not None:
                        detail += "; undecidable: the callee jumps to 0x%08X, outside the image" % und
                        conf = "low"
                    detail += " " + BROAD_TAG
                    out.append(dict(caller_file=fi["path"], caller_func=d["name"], callee=c["name"],
                                    callee_def=cd["name"] if cd else c["name"],
                                    callee_def_file=cd["file"] if cd else "-", kind=kind, detail=detail,
                                    confidence=conf, region=d["region"], area=area_of(fi["path"]),
                                    sdk=is_sdk(fi["path"]) or bool(cd and is_sdk(cd["file"])), arg=w, reg=r,
                                    pos=c["pos"]))
    return out


def scan(ix, files=None):
    """Rows for the whole tree, or only those touching the given repo-relative files."""
    sc = Scanner(ix)
    scope = set(files) if files else None
    rows = []
    callers_of = collections.defaultdict(list)
    addr_taken = collections.Counter()
    for fi in ix.files:
        for d in fi["defs"]:
            if d["asm"]:
                continue
            for c in find_calls(d["body"]):
                cd = ix.resolve(fi, c["name"])
                if cd:
                    callers_of[(cd["region"], cd["name"])].append((fi, d, c))
            for m in re.finditer(r"\b((?:func|sub|ov\d+_func)_[0-9A-Fa-f]{8}|[A-Z][A-Za-z0-9_]*)\b(?!\s*\()", d["body"]):
                cd = ix.resolve(fi, m.group(1))
                if cd:
                    addr_taken[(cd["region"], cd["name"])] += 1
        s = fi["stripped"]
        for d in fi["defs"]:
            s = s.replace(d["body"], "")
        for m in re.finditer(r"=[^;]*", s):
            for nm in re.findall(r"\b[A-Za-z_]\w*\b", m.group(0)):
                cd = ix.resolve(fi, nm)
                if cd:
                    addr_taken[(cd["region"], cd["name"])] += 1

    th = find_thunks(ix, sc, scope)
    for t in th.values():
        rows.append(t["row"])
    reads_cache = {}

    def callee_reads(cd):
        k = (cd["region"], cd["name"])
        if k not in reads_cache:
            reads_cache[k] = sc.reads(cd["region"], cd["addr"]) if cd.get("addr") else None
        return reads_cache[k]

    for key, lst in callers_of.items():
        cd = ix.defs[key]
        if cd["n"] is None or cd["var"]:
            continue
        per = collections.defaultdict(list)
        for fi, d, c in lst:
            per[(fi["path"], d["name"])].append((fi, d, c))
        for (cpath, cname), cl in per.items():
            if scope is not None and cpath not in scope and cd["file"] not in scope:
                continue
            fi, d = cl[0][0], cl[0][1]
            short = [x for x in cl if x[2]["k"] < cd["n"]]
            if not short:
                continue
            tk = th.get((cpath, cname))
            if tk and cd.get("addr") and (tk["target"] & ~1) == (cd["addr"] & ~1):
                continue                          # reported once, as a thunk row
            R = callee_reads(cd)
            sites = sc.sites_for(fi, d, cd["addr"]) if cd.get("addr") else None
            cl_sorted = sorted(cl, key=lambda x: x[2]["pos"])
            mapping = {}
            if sites is not None and len(sites) == len(cl_sorted):
                for x, st in zip(cl_sorted, sites):
                    mapping[id(x)] = [st]
            for x in short:
                c = x[2]
                proto = fi["protos"].get(c["name"])
                local_def = any(dd["name"] == c["name"] for dd in fi["defs"])
                ss = mapping.get(id(x), sites or [])
                for i in range(c["k"], cd["n"]):
                    used = callee_uses(cd, i)
                    pn = cd["pnames"][i] if i < len(cd["pnames"]) else None
                    first, nw = cd["layout"][i]
                    proto_txt = ("proto %s params" % ("()" if proto["n"] is None else proto["n"])) if proto \
                        else ("local def" if local_def else "no proto")
                    proto_short = proto is not None and proto["n"] is not None and proto["n"] < cd["n"]
                    regs = ["r%d" % w for w in range(first, min(first + nw, 4))]
                    if not regs:
                        kind, conf = ("c" if proto_short else "a"), "low"
                        detail = "arg%d (stack slot) not passed; callee param '%s' %s" % (i, pn, "used" if used else "UNUSED")
                    elif not ss:
                        kind, conf = ("c" if proto_short else "a"), "low"
                        detail = "%s not passed; no bl site found in original (inlined/veneer/extent unknown)" % ":".join(regs)
                    else:
                        opr = {r: frozenset().union(*[st[2].get(r, frozenset()) for st in ss]) for r in regs}
                        kind, conf, detail = classify(ix, d, regs, opr, proto_short)
                        if len(ss) > 1 and id(x) not in mapping:
                            detail += " [union over %d bl sites]" % len(ss)
                        if first + nw > 4:
                            detail += " [param continues on the stack]"
                    if nw > 1:
                        detail += "; param %d takes %d words" % (i, nw)
                    if cd["size_unknown"] is not None and cd["size_unknown"] < i:
                        detail += "; size of param %d unknown, assumed one word" % cd["size_unknown"]
                        if conf == "high":
                            conf = "med"
                    if regs and R is not None:
                        # the callee's own original bytes decide, not its C
                        hit = [r for r in regs if r in R]
                        if not hit:
                            detail = "callee's original code never reads %s (phantom parameter %d%s, not a caller " \
                                     "bug; was %s/%s): %s" % (":".join(regs), i, (" '%s'" % pn) if pn else "",
                                                             kind, conf, detail)
                            kind, conf = "phantom", "high"
                        else:
                            detail += "; callee's original code reads %s" % ":".join(hit)
                    elif not used:
                        detail += "; callee does NOT use param %d%s" % (i, (" '%s'" % pn) if pn else " (unnamed)")
                        conf = {"high": "med", "med": "low"}.get(conf, conf)
                    else:
                        detail += "; callee uses param '%s'" % pn
                    und = sc.undecidable_at(cd["region"], cd["addr"]) if cd.get("addr") and regs else None
                    if und is not None and kind != "phantom":
                        detail += "; undecidable: the callee jumps to 0x%08X, outside the image" % und
                        conf = "low"
                    detail += "; passed %d of %d (%s)" % (c["k"], cd["n"], proto_txt)
                    if proto and proto["void"] and not cd["void"]:
                        detail += "; caller declares callee void, def returns %s" % cd["ret"]
                    if c["name"] != cd["name"]:
                        detail += "; defined as %s (resolved by address)" % cd["name"]
                    rows.append(dict(caller_file=cpath, caller_func=cname, callee=c["name"], callee_def=cd["name"],
                                     callee_def_file=cd["file"], kind=kind, detail=detail, confidence=conf,
                                     region=d["region"], area=area_of(cpath),
                                     sdk=is_sdk(cpath) or is_sdk(cd["file"]), arg=i, reg=regs[0] if regs else None,
                                     pos=c["pos"]))

    for key, lst in callers_of.items():
        cd = ix.defs[key]
        if cd["n"] is None or cd["var"] or cd["n"] == 0:
            continue
        if scope is not None and cd["file"] not in scope:
            continue
        kmax = max(c["k"] for _f, _d, c in lst)
        if kmax >= cd["n"]:
            continue
        extra = list(range(kmax, cd["n"]))
        R = callee_reads(cd)

        def param_read(i):
            if R is None:
                return callee_uses(cd, i)
            first, nw = cd["layout"][i]
            regs = ["r%d" % w for w in range(first, min(first + nw, 4))]
            return any(r in R for r in regs) if regs else callee_uses(cd, i)
        word = ("read", "never read by the original code") if R is not None else ("used", "unused")
        use = ["param %d '%s' %s" % (i, cd["pnames"][i], word[0] if param_read(i) else word[1]) for i in extra]
        ncallers = len(set((f["path"], d["name"]) for f, d, _c in lst))
        at = addr_taken.get(key, 0)
        anyused = any(param_read(i) for i in extra)
        conf = "low" if at else ("high" if not anyused else "med")
        detail = "def declares %d params, matched callers pass at most %d (%d call sites in %d callers); %s" % (
            cd["n"], kmax, len(lst), ncallers, ", ".join(use))
        if at:
            detail += "; address taken %d times (may be a callback, pointer callers can pass more)" % at
        detail += "; unmatched asm callers not checked"
        rows.append(dict(caller_file="*", caller_func="*", callee=cd["name"], callee_def=cd["name"], callee_def_file=cd["file"],
                         kind="reverse", detail=detail, confidence=conf, region=cd["region"],
                         area=area_of(cd["file"]), sdk=is_sdk(cd["file"]), arg=kmax, reg=None, pos=0))

    # the broader check: every call, whatever the callee's definition says
    rows.extend(broad_rows(ix, sc, scope, th, callers_of))

    # definitions whose original code never reads some declared register parameter
    for fi in ix.files:
        if scope is not None and fi["path"] not in scope:
            continue
        for cd in fi["defs"]:
            if cd["asm"] or not cd.get("addr") or not cd["n"] or cd["var"] \
                    or re.search(r"\binline\b|__inline", cd["ret"]) or ix.defs.get((cd["region"], cd["name"])) is not cd:
                continue
            R = callee_reads(cd)
            if R is None:
                continue
            unread = []
            for i, (first, nw) in enumerate(cd["layout"]):
                regs = ["r%d" % w for w in range(first, min(first + nw, 4))]
                if regs and not any(r in R for r in regs):
                    unread.append((i, regs))
            if not unread:
                continue
            last_read = max([i for i, (first, nw) in enumerate(cd["layout"])
                             if any("r%d" % w in R for w in range(first, min(first + nw, 4)))] or [-1])
            names = ["param %d '%s' (%s)" % (i, cd["pnames"][i] if i < len(cd["pnames"]) else None, ":".join(regs))
                     for i, regs in unread]
            at = addr_taken.get((cd["region"], cd["name"]), 0)
            detail = "original code never reads %s" % ", ".join(names)
            trailing = [i for i, _r in unread if i > last_read]
            if trailing and len(trailing) == len(unread):
                detail += "; all trailing, the definition can drop them"
            else:
                detail += "; an unread parameter before a read one stays as a placeholder"
            if at:
                detail += "; address taken %d times (a callback signature may need them)" % at
            rows.append(dict(caller_file="*", caller_func="*", callee=cd["name"], callee_def=cd["name"],
                             callee_def_file=cd["file"], kind="reverse", detail=detail,
                             confidence="med" if at else "high", region=cd["region"], area=area_of(cd["file"]),
                             sdk=is_sdk(cd["file"]), arg=unread[0][0], reg=None, pos=1))

    # a callee that ignores the parameter by name but forwards the register itself
    fwd = set((r["caller_file"], r["caller_func"], r["arg"]) for r in rows if r["kind"] == "a")
    for r in rows:
        if r["kind"] != "reverse" and "does NOT use" in r["detail"] and (r["callee_def_file"], r["callee_def"], r["arg"]) in fwd:
            r["detail"] += "; but callee forwards it implicitly to its own callee (chain)"
            r["confidence"] = {"low": "med", "med": "high"}.get(r["confidence"], r["confidence"])
    rows.sort(key=lambda r: (r["sdk"], r["kind"] == "reverse", r["caller_file"], r["pos"], r["callee"], r["arg"]))
    return rows


# ---------------------------------------------------------------------------
# output
# ---------------------------------------------------------------------------

def write_tsv(rows, fh):
    fh.write("\t".join(COLUMNS) + "\n")
    for r in rows:
        fh.write("\t".join(str(r[k]) for k in COLUMNS) + "\n")


GATE_KINDS = ("a", "b", "set", "thunk")
KINDS = ["a", "b", "set", "thunk", "c", "phantom", "reverse"]


def print_report(rows, fh):
    for r in rows:
        if r["kind"] == "reverse":
            fh.write("%-7s %-4s %s: %s  %s\n" % (r["kind"], r["confidence"], r["callee_def_file"], r["callee"], r["detail"]))
        else:
            fh.write("%-7s %-4s %s: %s -> %s  %s\n" % (r["kind"], r["confidence"], r["caller_file"], r["caller_func"],
                                                     r["callee"], r["detail"]))
    fh.write("\n%d row(s), %d high-confidence %s\n" % (len(rows), len(gate_rows(rows)), "/".join(GATE_KINDS)))


def print_summary(rows, fh):
    confs = ["high", "med", "low"]
    kinds = KINDS + sorted(set(r["kind"] for r in rows) - set(KINDS))
    cnt = collections.Counter((r["kind"], r["confidence"]) for r in rows)
    fh.write("%-8s %6s %6s %6s %7s\n" % ("kind", "high", "med", "low", "total"))
    for k in kinds:
        fh.write("%-8s %6d %6d %6d %7d\n" % (k, cnt[(k, "high")], cnt[(k, "med")], cnt[(k, "low")],
                                             sum(cnt[(k, c)] for c in confs)))
    fh.write("%-8s %6d %6d %6d %7d\n\n" % ("all", sum(cnt[(k, "high")] for k in kinds),
                                           sum(cnt[(k, "med")] for k in kinds),
                                           sum(cnt[(k, "low")] for k in kinds), len(rows)))
    areas = sorted(set(r["area"] for r in rows))
    byarea = collections.Counter((r["area"], r["kind"]) for r in rows)
    hiarea = collections.Counter(r["area"] for r in gate_rows(rows))
    fh.write("%-10s" % "region" + "".join("%9s" % k for k in kinds) + "%10s\n" % "gate")
    for a in areas:
        fh.write("%-10s" % a + "".join("%9d" % byarea[(a, k)] for k in kinds) + "%10d\n" % hiarea[a])


def gate_rows(rows):
    """High-confidence rows that are bugs in the caller's C: a, b, set, thunk."""
    return [r for r in rows if r["kind"] in GATE_KINDS and r["confidence"] == "high"]


def norm_path(p):
    a = os.path.abspath(p if os.path.isabs(p) else os.path.join(os.getcwd(), p))
    if not os.path.exists(a):
        a2 = os.path.abspath(os.path.join(ROOT, p))
        if os.path.exists(a2):
            a = a2
    return os.path.relpath(a, ROOT).replace("\\", "/")


# ---------------------------------------------------------------------------
# selftest
# ---------------------------------------------------------------------------

def _thumb_bl(at, target):
    off = target - (at + 4)
    hi = 0xF000 | ((off >> 12) & 0x7FF)
    lo = 0xF800 | ((off >> 1) & 0x7FF)
    return hi.to_bytes(2, "little") + lo.to_bytes(2, "little")


def _thumb_fn(base, parts):
    """Assemble a Thumb function from halfwords and ('bl', target) items."""
    out = b""
    for p in parts:
        if isinstance(p, tuple):
            out += _thumb_bl(base + len(out), p[1])
        else:
            out += p.to_bytes(2, "little")
    return out


def _site_state(code, base, target):
    insns = list(md(True).disasm(code, base))
    IN = analyze(insns)
    for i, ins in enumerate(insns):
        if ins.mnemonic == "bl" and branch_target(ins) == target:
            return IN[i]
    return None


SELFTEST_PIN = "c7981a15574318a0e3902edb2b0a1f92395ace69"
# the parent of 2f3e94b38, which named the r0 that seven overlay callers passed
# to func_020315D4 (defined as sub_020315D4, so only an address lookup finds it)
SELFTEST_PIN_ADDR = "47c17a6ebf82db2cb7a86fe617b3afbd8a307335"
# 967be270c, the commit that added this tool: func_02062F90 still called
# func_02062D4C(p) and func_021A3D50's callers still passed two of four
SELFTEST_PIN_KINDS = "967be270c6cc4ec55e2fee77b99794a03e9eacc5"
# 3e0a7c135: ov217 func_021C11DC, ov043 func_021F42A8 and ov019 func_0217FE44
# before OV's lanes named the values they pass
SELFTEST_PIN_BROAD = "3e0a7c135467390473f1ca7b0e1b7c42eda3ff12"


def _git_show(rev, path):
    import shutil
    import subprocess
    git = shutil.which("git")
    if not git:
        return None
    r = subprocess.run([git, "show", "%s:%s" % (rev, path)], cwd=ROOT, capture_output=True)
    if r.returncode != 0:
        return None
    return r.stdout.decode("utf-8", "replace")


def git_snapshot(rev):
    """{path: text} for every .c under src/matched at commit rev, or None
    without git.  One `git ls-tree` and one `git cat-file --batch`."""
    import shutil
    import subprocess
    git = shutil.which("git")
    if not git:
        return None
    r = subprocess.run([git, "ls-tree", "-r", "--name-only", rev, "--", MATCHED], cwd=ROOT, capture_output=True)
    if r.returncode != 0:
        return None
    paths = [p for p in r.stdout.decode("utf-8", "replace").splitlines() if p.endswith(".c")]
    req = "".join("%s:%s\n" % (rev, p) for p in paths).encode("utf-8")
    r = subprocess.run([git, "cat-file", "--batch"], cwd=ROOT, input=req, capture_output=True)
    if r.returncode != 0:
        return None
    out, buf, pos = {}, r.stdout, 0
    for p in paths:
        eol = buf.index(b"\n", pos)
        head = buf[pos:eol].split()
        if len(head) < 3 or head[1] != b"blob":
            return None
        size = int(head[2])
        out[p] = buf[eol + 1:eol + 1 + size].decode("utf-8", "replace")
        pos = eol + 1 + size + 1
    return out


_SNAPSHOTS = {}


def _pinned_index(rev):
    """An Index of src/matched exactly as it was at rev (cached), or None."""
    if rev not in _SNAPSHOTS:
        snap = git_snapshot(rev)
        _SNAPSHOTS[rev] = Index(snapshot=snap) if snap else None
    return _SNAPSHOTS[rev]


def selftest():
    res = []
    base, A, B = 0x02000000, 0x02000100, 0x02000200

    # adds r5, r1, #0 / bl A / adds r1, r5, #0 / bl B: r1 at B is the incoming r1
    code = _thumb_fn(base, [0xB530, 0x1C0D, ("bl", A), 0x1C29, ("bl", B), 0xBD30])
    st = _site_state(code, base, B)
    res.append((st is not None and st["r1"] == {("entry", "r1")} and st["r0"] == {("ret", base + 4, A)},
                "a callee-saved copy of the incoming r1 traces back to entry r1"))

    # bl A / adds r4, r0, #0 / bl B' / adds r0, r4, #0 / bl B: r0 at B is A's return, not a fresh write
    B2 = 0x02000300
    code = _thumb_fn(base, [0xB510, ("bl", A), 0x1C04, ("bl", B2), 0x1C20, ("bl", B), 0xBD10])
    st = _site_state(code, base, B)
    res.append((st is not None and st["r0"] == {("ret", base + 2, A)},
                "a callee-saved copy of an earlier return traces back to that call"))

    # push / sub sp,#8 / str r1,[sp,#4] / bl A / ldr r1,[sp,#4] / bl B: r1 is the incoming r1
    code = _thumb_fn(base, [0xB500, 0xB082, 0x9101, ("bl", A), 0x9901, ("bl", B), 0xB002, 0xBD00])
    st = _site_state(code, base, B)
    res.append((st is not None and st["r1"] == {("entry", "r1")},
                "a stack spill reload traces back to entry r1"))

    # same, but the stack address escapes to A at sp+0: the slot is dropped at the call
    code = _thumb_fn(base, [0xB500, 0xB082, 0x9101, 0xA800, ("bl", A), 0x9901, ("bl", B), 0xB002, 0xBD00])
    st = _site_state(code, base, B)
    res.append((st is not None and all(o[0] == "ins" for o in st["r1"]),
                "a spill slot at or above an escaped stack address is dropped at a call"))

    # register layout of 64-bit and struct-by-value parameters
    _s, defs, _p, _t = parse_file("typedef unsigned long long u64;\n"
                                  "typedef struct { unsigned int x; unsigned short y; } S;\n"
                                  "void f(void *p, u64 k, int c) { }\n"
                                  "void g(S s, int a) { }\n"
                                  "void h(struct Q *q, S *s, long long v) { }\n")
    lay = {d["name"]: d["layout"] for d in defs}
    res.append((lay.get("f") == [(0, 1), (1, 2), (3, 1)], "a u64 parameter takes two consecutive registers (r1:r2)"))
    res.append((lay.get("g") == [(0, 2), (2, 1)], "an 8-byte struct by value takes two registers"))
    res.append((lay.get("h") == [(0, 1), (1, 1), (2, 2)], "pointers take one register, long long two"))

    # the real tree.  Every tree case runs on the WHOLE of src/matched as it was
    # at a pinned commit (git_snapshot), callers and callees alike: the lanes fix
    # these very sites, and a fix to either side in the working tree must not
    # move a case.  The original bytes they are checked against never change.
    f1 = "src/matched/ov/ov021_func_021C2EDC.c"
    f2 = "src/matched/ov/ov018_func_0217D890.c"
    f3 = "src/matched/ov/ov171_func_021DC8A8.c"
    pins = {}
    for rev in (SELFTEST_PIN, SELFTEST_PIN_ADDR, SELFTEST_PIN_KINDS, SELFTEST_PIN_BROAD):
        try:
            pins[rev] = _pinned_index(rev)
        except OSError as exc:
            res.append((False, "index the tree at %s [%s]" % (rev[:9], exc)))
            return res
        if pins[rev] is None:
            res.append((True, "skip: src/matched not readable at %s (no git?), tree cases not run" % rev[:9]))
            return res

    rows = scan(pins[SELFTEST_PIN], [f1])
    if not any(r["kind"] != "reverse" and "no bl site" not in r["detail"] for r in rows):
        res.append((True, "skip: original bytes unavailable (no extract/), tree cases not run"))
        return res
    hit = [r for r in rows if r["caller_func"] == "func_021C2EDC" and r["callee"] == "func_021C2F50"]
    res.append((len(hit) == 1 and hit[0]["kind"] == "a" and hit[0]["confidence"] == "high"
                and hit[0]["reg"] == "r1" and "does not declare" in hit[0]["detail"],
                "func_021C2EDC passes its undeclared incoming r1 to func_021C2F50 (a, high)"))
    hit = [r for r in rows if r["caller_func"] == "func_021C2EDC" and r["callee"] in ("func_021C2EBC", "func_0206E62C")]
    res.append((not hit, "func_021C2EDC's calls that name every argument give no row"))
    res.append((len(gate_rows([r for r in rows if r["caller_file"] == f1])) >= 1,
                "--check on %s fails" % f1))

    rows = scan(pins[SELFTEST_PIN_ADDR], [f3])
    hit = [r for r in rows if r["caller_func"] == "func_021DC8A8" and r["callee"] == "func_020315D4"]
    res.append((len(hit) == 1 and hit[0]["kind"] == "a" and hit[0]["confidence"] == "high"
                and hit[0]["reg"] == "r0" and hit[0]["callee_def"] == "sub_020315D4",
                "func_021DC8A8's func_020315D4() resolves by address to sub_020315D4 (a, high)"))

    # phantom rows, the unread-parameter reverse row, set rows through `bx ip`, thunks
    ix = pins[SELFTEST_PIN_KINDS]
    f4 = "src/matched/arm9/func_02062F90.c"
    f5 = "src/matched/ov/ov021_func_021A3FC0.c"
    f6 = "src/matched/ov/func_021A3D50.c"
    f7 = "src/matched/arm9/func_0200A350.c"
    rows = scan(ix, [f2, f4, f5, f6, f7])
    # (func_0200523C -> func_02005B24 was the first b fixture; func_02005B24 never reads r0, so it is phantom)
    hit = [r for r in rows if r["caller_func"] == "func_0217D890" and r["callee"] == "func_020409B4"]
    res.append((len(hit) == 2 and all(r["kind"] == "b" and r["confidence"] == "high" and r["reg"] == "r0"
                                      and "sub_02045730" in r["detail"] for r in hit),
                "func_0217D890 chains sub_02045730's return into func_020409B4, twice (b, high)"))
    hit = [r for r in rows if r["caller_func"] == "func_02062F90" and r["callee"] == "func_02062D4C"]
    res.append((len(hit) == 1 and hit[0]["kind"] == "set" and hit[0]["confidence"] == "high" and hit[0]["reg"] == "r1"
                and "mov r1, #0" in hit[0]["detail"],
                "func_02062F90's `ldr ip, =func_02062D4C; bx ip` passes the shared `mov r1, #0` (set, high)"))
    hit = [r for r in rows if r["caller_func"] == "func_021A3FC0" and r["callee"] == "func_021A3D50"]
    res.append((sorted((r["reg"], r["kind"]) for r in hit) == [("r2", "phantom"), ("r3", "phantom")],
                "func_021A3FC0 -> func_021A3D50: r2 and r3 are phantom (the callee never reads c, d)"))
    hit = [r for r in rows if r["kind"] == "reverse" and r["callee"] == "func_021A3D50"
           and r["detail"].startswith("original code never reads")]
    res.append((len(hit) == 1 and hit[0]["confidence"] == "high" and "'c' (r2)" in hit[0]["detail"]
                and "'d' (r3)" in hit[0]["detail"],
                "func_021A3D50 gets a reverse/high row naming c (r2) and d (r3) as unread"))
    hit = [r for r in rows if r["caller_func"] == "func_0200A350"]
    res.append((len(hit) == 1 and hit[0]["kind"] == "thunk" and hit[0]["confidence"] == "high"
                and "reads r0;" in hit[0]["detail"] and "returns a value" in hit[0]["detail"],
                "func_0200A350 is a thunk: forwards r0-r2 by tail call, func_0200A3FC reads r0 and returns a value"))

    # callee-side reads (the fixing lanes' findings), the ISA at every level of a
    # follow, and outgoing stack arguments; definitions from the same pinned tree
    sc = Scanner(ix)
    for name, region, want, why in (
            ("func_0216D3CC", "ov010", {"r0"}, "a1 is overwritten (movs r1, #1) before any read"),
            ("func_021A3D50", "ov021", {"r0", "r1"}, "c and d are never read"),
            ("func_021ABEA0", "ov021", {"r0", "r1"}, "really 2 parameters, read through its forward to func_021ABF2C"),
            ("func_02158F58", "ov010", {"r0"}, "a1 is overwritten (ldr r1, [r4, #0x10]) before any read")):
        got = sc.reads(region, addr_of_name(name))
        res.append((got == want, "%s reads %s: %s%s" % (name, ", ".join(sorted(want)), why,
                                                        "" if got == want else " [got %s]" % got)))
    loc = sc.locate(0x020307B0, "arm9", thumb_hint=True)
    res.append((loc == ("arm9", False),
                "sub_020307B0 is ARM even when reached with a Thumb hint (its isa: line wins) [got %s]" % (loc,)))
    got = sc.reads("arm9", 0x02028604)
    res.append((got == {"r0"}, "func_02028604 reads only r0 (its blx into ARM sub_020307B0 decodes as ARM) [got %s]"
                % (sorted(got) if got is not None else None)))
    got = sc.reads("ov021", 0x0218E260)
    res.append((got == {"r0", "r1"}, "func_0218E260 reads b: it stores r1 to [sp] as func_0204944C's fifth argument "
                "[got %s]" % (sorted(got) if got is not None else None)))

    # round 4, the fixing lanes' false positives (strict reads: what the code is
    # proved to read): switch tables are data, complementary conditional writes
    # are one write, a pushed register is read only through its own slot
    for name, region, want, why in (
            ("func_0200B078", "arm9", {"r0", "r1"}, "Thumb switch: the halfword table after `add pc, r1` is data"),
            ("func_021DA390", "ov175", {"r0"}, "Thumb switch table, not `movs r2, r3`"),
            ("func_021ED814", "ov093", {"r0"}, "Thumb switch table (entries 0x0008 / 0x0010 are not movs)"),
            ("func_021F9260", "ov094", {"r0", "r1"}, "Thumb switch table"),
            ("func_0204047C", "arm9", {"r0", "r1"}, "ARM `addls pc, pc, r0, lsl #2` reaches only its table's cases"),
            ("sub_02043094", "arm9", {"r0", "r1", "r2"}, "ARM switch: r3 is loaded before every use"),
            ("MI_CpuCopy8", "arm9", {"r0", "r1", "r2"}, "`ldrhne r3` / `ldrheq r3` write r3 on both paths"),
            ("FX_Atan2Idx", "arm9", {"r0", "r1"}, "`movgt r2` + `bgt`, `movlt r2` + `blt`: r2 written before use"),
            ("MIi_CpuCopy16", "arm9", {"r0", "r1", "r2"}, "`strhlt r3` reads the r3 `ldrhlt` wrote"),
            ("sub_020452E8", "arm9", {"r0"}, "`smulbbeq r2` / `lslne r2`: one write"),
            ("func_0206DB80", "arm9", set(), "`ldrne r2; cmpne r2; popeq`: past popeq, r2 was written"),
            ("func_021B630C", "ov101", {"r0", "r1"}, "`push {r0-r3}` with only &value taken: r2, r3 unread"),
            ("sub_0204B454", "arm9", {"r0", "r1", "r2"}, "`push {r3, lr}` padding slot reused as a local: no r3"),
            ("func_021D57A8", "ov093", {"r0", "r1", "r2"}, "r3 pushed as alignment padding is not a read"),
            ("func_021B9F90", "ov099", {"r0", "r1", "r2"}, "struct temp in the padding slot: no r3"),
            ("func_0203F1FC", "arm9", {"r0", "r1"}, "ARM, r3 written on both paths before use")):
        a = {"MI_CpuCopy8": 0x02082D44, "FX_Atan2Idx": 0x0207CFB8, "MIi_CpuCopy16": 0x02082A60}.get(name) \
            or addr_of_name(name)
        got = sc.reads(region, a, strict=True)
        res.append((got == want, "%s reads %s: %s%s" % (name, ", ".join(sorted(want)) or "nothing", why,
                                                        "" if got == want else " [got %s]" % sorted(got))))
    und = sc.undecidable_at("ov172", 0x021B6724)
    res.append((und == 0x0272FCE0, "ov172 func_021B6724's `ldr pc` veneer into TWL 0x0272FCE0 is undecidable [got %s]"
                % (None if und is None else "0x%08X" % und)))

    # the broader check
    f8 = "src/matched/ov/ov217_func_021C11DC.c"
    f9 = "src/matched/ov/ov043_func_021F42A8.c"
    f10 = "src/matched/ov/ov019_func_0217FE44.c"
    rows = scan(pins[SELFTEST_PIN_BROAD], [f8, f9, f10])

    def one(caller, callee, reg):
        return [r for r in rows if r["caller_func"] == caller and r["callee"] == callee and r["reg"] == reg]
    hit = one("func_021C11DC", "func_021C1AC0", "r1")
    res.append((len(hit) == 1 and hit[0]["kind"] == "a" and hit[0]["confidence"] == "high"
                and BROAD_TAG in hit[0]["detail"] and "definition too short" in hit[0]["detail"],
                "ov217 func_021C11DC forwards r1 to func_021C1AC0, whose definition is too short (broader check)"))
    hit = one("func_021F42A8", "func_02188D2C", "r0") + one("func_021F42A8", "func_0218EC5C", "r0")
    res.append((len(hit) == 2 and all(r["kind"] == "b" and r["confidence"] == "high" and BROAD_TAG in r["detail"]
                                      for r in hit),
                "ov043 func_021F42A8 passes results to unmatched func_02188D2C and func_0218EC5C (b, broader check)"))
    hit = one("func_0217FE44", "func_021A3074", "r0")
    res.append((len(hit) == 1 and hit[0]["kind"] == "b" and hit[0]["confidence"] == "high"
                and "02188CB4" in hit[0]["detail"],
                "ov019 func_0217FE44 chains func_02188CB4's result into func_021A3074 (b, high)"))
    return res


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("cmd", nargs="?", default="scan", choices=("scan", "selftest"))
    ap.add_argument("-o", "--output", help="write the rows as TSV to this file")
    ap.add_argument("--file", action="append", nargs="+", default=[],
                    help="only call sites in these files and calls to the definitions they contain")
    ap.add_argument("--summary", action="store_true", help="counts per kind, confidence and region")
    ap.add_argument("--check", action="store_true", help="exit 1 if any high-confidence a, b, set or thunk row exists")
    args = ap.parse_args(argv)

    if args.cmd == "selftest":
        res = selftest()
        for ok, name in res:
            print("  %-4s %s" % ("ok" if ok else "FAIL", name))
        bad = sum(1 for ok, _ in res if not ok)
        print("\n%d case(s), %d failure(s)" % (len(res), bad))
        return 1 if bad else 0

    files = [norm_path(p) for grp in args.file for p in grp]
    for f in files:
        if not f.startswith(MATCHED + "/") or not os.path.exists(os.path.join(ROOT, f)):
            print("error: %s is not a file under %s" % (f, MATCHED), file=sys.stderr)
            return 2
    ix = Index()
    rows = scan(ix, files or None)
    if args.output:
        with open(args.output, "w", encoding="utf-8", newline="\n") as fh:
            write_tsv(rows, fh)
    if args.summary:
        print_summary(rows, sys.stdout)
    elif args.check:
        bad = gate_rows(rows)
        for r in bad:
            print("%s: %s -> %s  %s" % (r["caller_file"], r["caller_func"], r["callee"], r["detail"]))
        print("%d high-confidence a/b/set/thunk row(s)" % len(bad))
        return 1 if bad else 0
    elif not args.output:
        print_report(rows, sys.stdout)
    if args.check:
        return 1 if gate_rows(rows) else 0
    return 0


if __name__ == "__main__":
    sys.exit(main())
