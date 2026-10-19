#!/usr/bin/env python3
"""Count or list placeholder names left in src/game: struct fields, parameters and locals
named by offset or position instead of by meaning.

  fields:  struct members named fXX, fieldXX, field_0xXX, unkXX, unk_XX, xXX (hex offset)
  params:  parameters of function definitions named aN, argN, paramN, pN
  proto:   the same in prototypes (extern declarations); counted apart
  locals:  locals named aN, argN, paramN, vN, tmpN, varN, localN

Comments are ignored. `pad` members are not counted: padding that nothing reads is a
legitimate name. Hits on the ACCEPTED rows (original or domain names that
match a pattern) are reported apart.

    python tools/placeholdernames.py                 summary per region and total
    python tools/placeholdernames.py --list PATH...  every hit (file:line kind name); PATH is
                                                     a file or a directory under src/game
"""
import argparse
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GAME = os.path.join(ROOT, "src", "game")

FIELD = re.compile(r"^\s+(?:const\s+|volatile\s+|struct\s+|unsigned\s+|signed\s+)*[A-Za-z_]\w*[\s\*]+\**"
                   # an offset spelling: a digit in it, upper-case hex, or at most two hex
                   # characters (fC, fa); a lower-case word such as `fade` is a real name
                   r"((?:f|x)(?:[0-9A-Fa-f]*[0-9][0-9A-Fa-f]*|[0-9A-F]{1,4}|[0-9A-Fa-f]{1,2})(?![0-9A-Za-z_])"
                   r"|(?:field_?(?:0x)?|unk_?(?:0x)?)[0-9A-Fa-f]{1,4})\s*(?:\[[^\]]*\]\s*)*(?::\s*\d+\s*)?;")
PARAM = re.compile(r"\b((?:a|arg|param|p)[0-9])\s*(?=[,\[]|$)")
LOCAL = re.compile(r"^\s+(?:const\s+|volatile\s+|register\s+|struct\s+|unsigned\s+|signed\s+)*[A-Za-z_]\w*[\s\*]+\**"
                   r"((?:a|arg|param|v|tmp|var|local)[0-9]+)\s*(?:\[[^\]]*\]\s*)*(?:=|;|,)")


# Names the patterns flag that are the original or the domain's own names. Each row is
# (file, name, reason); a hit on an accepted row is reported apart, not counted.
ACCEPTED = [
    ("src/game/arm9/fldmmdl_save.c", "param0 param1 param2", "mirror the Mmdl param0..2 fields (the game's own names)"),
    ("src/game/ov010/fldmmdl_types.h", "param0 param1 param2", "MmdlHeader/Mmdl param0..2, the move model's script parameters"),
    ("src/game/ov010/script_work.c", "param0 param1 param2 param3", "SCRIPT_PARAM0..3, the script variables 0x8000..0x8003"),
    ("src/game/ov114/dwci_nd_types.h", "param1 param2 param3", "DWC Nd SDK field names"),
    ("src/game/arm9/nns_g3d_sbc.c", "param0 param1", "the TEXIMAGE_PARAM words of the SBC command"),
    ("src/game/arm9/nns_g2d_font.c", "x0 x1 xe", "glyph rectangle coordinates (x0, x1 and the end x)"),
    ("src/game/arm9/nns_g2d_renderer_core.c", "v0 v1", "texture coordinates u0/v0 and u1/v1"),
    ("src/game/arm9/touchpanel_shared_types.h", "x30", "calibration point coordinate, pairs with y30"),
    ("src/game/arm9/tp.c", "x0 tmp32", "SDK TPCalibrateParam field and the SDK's own local"),
    ("src/game/ov009/gsplatformsocket.c", "fd", "POSIX pollfd member"),
    ("src/game/ov009/soc.c", "fd", "POSIX pollfd member"),
    ("src/game/ov016/aoss.c", "fd", "POSIX pollfd member"),
    ("src/game/ov016/graphics.c", "x1 x2", "rectangle coordinates"),
    ("src/game/ov172/camera_system.c", "x0 x1", "rectangle coordinates"),
    ("src/game/ov172/ctvt_draw.c", "x2", "line end coordinate"),
    ("src/game/ov172/ctvt_types.h", "x0 x1", "rectangle coordinates"),
    ("src/game/ov172/draw_system.c", "x0 x1", "rectangle coordinates"),
    ("src/game/ov172/jpegdec.c", "tmp0 tmp10", "libjpeg's own names in the IDCT"),
    ("src/game/ov172/jpegenc.c", "a0 a1 a2 a3 a4 a5 a6 a7 c0 c1 c2 c3 c4 c5 c6 c7", "butterfly stage temporaries of the forward DCT"),
]
_ACC = {(f, n) for f, names, _ in ACCEPTED for n in names.split()}


def accepted(rel, name):
    return (rel, name) in _ACC


def strip_comments(text):
    """Comments blanked, newlines kept, so line numbers stay right."""
    return re.sub(r"/\*.*?\*/|//[^\n]*", lambda m: re.sub(r"[^\n]", " ", m.group(0)), text, flags=re.S)


NL = chr(10)
DECL = re.compile(r"\b[A-Za-z_]\w*\s*\(((?:[^;{}()]|\([^;{}()]*\))*)\)\s*(?=[{;])", re.S)


def scan(path):
    text = strip_comments(open(path, encoding="latin1").read())
    hits = []
    # brace depth at every line start, so a top-level declaration can be told from a call
    depth_at = []
    depth = 0
    for line in text.split(NL):
        depth_at.append(depth)
        depth = max(0, depth + line.count("{") - line.count("}"))
    starts = [0]
    for i, ch in enumerate(text):
        if ch == NL:
            starts.append(i + 1)
    import bisect
    for s in DECL.finditer(text):
        no = bisect.bisect_right(starts, s.start())
        if depth_at[no - 1] != 0:
            continue
        kind = "param" if text[s.end():s.end() + 1] == "{" or text[s.end():].lstrip()[:1] == "{" else "proto"
        for p in PARAM.finditer(s.group(1)):
            hits.append((no, kind, p.group(1)))
    for no, line in enumerate(text.split(NL), 1):
        if depth_at[no - 1] > 0:
            m = FIELD.match(line)
            if m:
                hits.append((no, "field", m.group(1)))
                continue
            m = LOCAL.match(line)
            if m:
                hits.append((no, "local", m.group(1)))
    return hits


def files_under(paths):
    for p in paths:
        p = os.path.join(ROOT, p) if not os.path.isabs(p) else p
        if os.path.isfile(p):
            yield p
            continue
        for d, _, fs in os.walk(p):
            for f in sorted(fs):
                if f.endswith((".c", ".h")):
                    yield os.path.join(d, f)


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--list", nargs="+", metavar="PATH")
    a = ap.parse_args()
    if a.list:
        for f in files_under(a.list):
            rel = os.path.relpath(f, ROOT).replace(os.sep, "/")
            for no, kind, name in scan(f):
                print("%s:%d\t%s\t%s" % (rel, no, kind, name))
        return
    per = {}
    nacc = 0
    for f in files_under([GAME]):
        region = os.path.relpath(f, GAME).replace(os.sep, "/").split("/")[0]
        rel = os.path.relpath(f, ROOT).replace(os.sep, "/")
        c = per.setdefault(region, {"field": 0, "param": 0, "local": 0, "proto": 0})
        for _, kind, name in scan(f):
            if accepted(rel, name):
                nacc += 1
                continue
            c[kind] += 1
    tot = {"field": 0, "param": 0, "local": 0, "proto": 0}
    for r in sorted(per, key=lambda r: -sum(per[r].values())):
        c = per[r]
        if sum(c.values()):
            print("%-22s fields %5d  params %5d  locals %5d  prototype params %5d" % (r, c["field"], c["param"], c["local"], c["proto"]))
        for k in tot:
            tot[k] += c[k]
    print("placeholder names: fields %d, params %d, locals %d, total %d (plus %d prototype params)"
          % (tot["field"], tot["param"], tot["local"], tot["field"] + tot["param"] + tot["local"], tot["proto"]))
    print("accepted (original or domain names, ACCEPTED in this tool): %d" % nacc)


if __name__ == "__main__":
    main()
