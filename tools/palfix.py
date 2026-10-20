#!/usr/bin/env python3
"""palfix.py: PalAnmSlot -> PaletteFade.

PALANM_Create allocates one 0x120-byte PaletteFade (14 PaletteFadeWork of 0x14 bytes plus
flags). The slot functions index its work[] array (rawBuf = defaultWork, workBuf = transWork).

Stage 1 (already applied to palanm.c/h): the slot functions take PaletteFade *; palanm.h keeps
`#define PalAnmSlot PaletteFade` so files not yet converted still compile.
Stage 2 (--core2): PALANM_Create/Delete take and return PaletteFade *, PALANM_BlendChannel*
take PaletteFade *, PALANM_GetDefaultWork/GetTransWork take PaletteFade * and return u16 *.
Callers then lose their (PaletteFadeWork *) and (char *) casts.
--final removes the transitional macro (run when no PalAnmSlot remains).

  python tools/palfix.py FILE... [--apply]      callers, stage 1 (drop PalAnmSlot casts, fwd decls, retype fields)
  python tools/palfix.py --core2 [--apply]      stage 2 in palanm.c/h
  python tools/palfix.py --all [--apply]        stage 2 core and stage 2 callers (every file naming PalAnmSlot,
                                                 plus the files listed in STAGE2_CALLERS)
  python tools/palfix.py --final [--apply]      drop the macro
Dry run unless --apply.
"""
import os, re, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__))).replace(os.sep, "/") + "/"
SLOT = r"struct\s+PalAnmSlot"
NL = chr(10)
MACRO = (NL + "/* Transitional: callers still holding the old slot-array name (removed once tools/palfix.py has run on them). */"
         + NL + "#define PalAnmSlot PaletteFade" + NL)
STAGE2_CALLERS = [
    "src/game/ov094/btlv_gauge.c",
    "src/game/ov094/btlv_input.c",
    "src/game/ov100/ircbattlematch.c",
]
STAGE2 = [
    ("void *PALANM_Create(u32 heapId)", "PaletteFade *PALANM_Create(u32 heapId)"),
    ("u32 PALANM_Delete(void *ctx)", "u32 PALANM_Delete(PaletteFade *ctx)"),
    ("    void *ctx = GFL_HEAP_Alloc((u16)heapId, 0x120,", "    PaletteFade *ctx = GFL_HEAP_Alloc((u16)heapId, sizeof(PaletteFade),"),
    ("MI_CpuFill8(ctx, 0, 0x120);", "MI_CpuFill8(ctx, 0, sizeof(PaletteFade));"),
    ("void PALANM_BlendChannel(PaletteFadeWork *p,", "void PALANM_BlendChannel(PaletteFade *p,"),
    ("void PALANM_BlendChannelMask(PaletteFadeWork *p,", "void PALANM_BlendChannelMask(PaletteFade *p,"),
    ("p[idx].defaultWork", "p->work[idx].defaultWork"),
    ("p[idx].transWork", "p->work[idx].transWork"),
    ("int PALANM_GetDefaultWork(char *p, int i)", "u16 *PALANM_GetDefaultWork(PaletteFade *p, int i)"),
    ("int PALANM_GetTransWork(char *p, int i)", "u16 *PALANM_GetTransWork(PaletteFade *p, int i)"),
    ("return *(int *)(p + i * 0x14);", "return p->work[i].defaultWork;"),
    ("return *(int *)(p + i * 0x14 + 4);", "return p->work[i].transWork;"),
]

# Stage 2 hand edits that no pattern covers: (old, new) per file; a missing old text is reported.
STAGE2_HAND = {
    "src/game/ov100/ircbattlematch.c": [("    int transWork;", "    u16 *transWork;")],
    "src/game/ov021/ircbattlemenu.c": [
        ("    PaletteFadeWork *fade;", "    PaletteFade *fade;"),
        ("buf = (u16 *)PALANM_GetTransWork(fade, bank);", "buf = PALANM_GetTransWork(fade, bank);"),
    ],
    "src/game/ov136/mailsys.c": [
        ("extern void PALANM_RequestFade(struct PaletteFade *p, int a, int b, int c, int d, int e, int f, u32 g);" + NL, ""),
        ("extern u32 PALANM_GetFadeRequestBits(const struct PaletteFade *p);" + NL, ""),
        ("extern void PALANM_BlendChannel(struct PaletteFade *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);" + NL,
         "#include " + chr(34) + "../arm9/palanm.h" + chr(34) + NL),
    ],
    "src/game/ov137/guru2_main.c": [
        ("PALANM_BlendChannelMask(((u32)p->palAnm),", "PALANM_BlendChannelMask(p->palAnm,"),
        ("PALANM_Delete((void *)p->palAnm)", "PALANM_Delete(p->palAnm)"),
    ],
}


def rd(p):
    return open(ROOT + p, encoding="utf-8", newline="").read()


def wr(p, s):
    open(ROOT + p, "w", encoding="utf-8", newline="").write(s)


def core(stage2=False, final=False):
    c = rd("src/game/arm9/palanm.c")
    h = rd("src/game/arm9/palanm.h")
    c = c.replace("struct PalAnmSlot;" + NL + "#include", "#include", 1)
    c = re.sub(r"struct PalAnmSlot \{.*?\};\n\n", "", c, count=1, flags=re.S)
    c = re.sub(r"\(struct PalAnmSlot \*\)palSlots", "palSlots", c)
    c = c.replace("struct PalAnmSlot *palSlots", "PaletteFade *fade")
    c = c.replace("palSlots[slotIdx].rawBuf", "fade->work[slotIdx].defaultWork")
    c = c.replace("palSlots[slotIdx].workBuf", "fade->work[slotIdx].transWork")
    c = c.replace("palSlots[slotIdx].size", "fade->work[slotIdx].size")
    c = c.replace("palSlots", "fade")
    h = h.replace("struct PalAnmSlot;" + NL, "")
    h = h.replace("struct PalAnmSlot *palSlots", "PaletteFade *fade")
    if stage2:
        for a, b in STAGE2:
            c = c.replace(a, b)
            h = h.replace(a, b)
        h = h.replace("PALANM_Delete(void *ctx)", "PALANM_Delete(PaletteFade *ctx)")
        h = h.replace("void *PALANM_Create(", "PaletteFade *PALANM_Create(")
    if final:
        h = h.replace(MACRO, "")
    elif MACRO not in h:
        end = "/* END mkheaders: generated region */" + NL
        h = h.replace(end, end + MACRO, 1)
    wr("src/game/arm9/palanm.c", c)
    wr("src/game/arm9/palanm.h", h)


def halve_offsets(s):
    """PALANM_Get*Work(...) + BYTES: the result is now u16 *, so the byte offset becomes halfwords."""
    out, pos = [], 0
    for m in re.finditer(r"PALANM_Get(?:Default|Trans)Work\(", s):
        if m.start() < pos:
            continue
        k, depth = m.end(), 1
        while depth and k < len(s):
            depth += {"(": 1, ")": -1}.get(s[k], 0)
            k += 1
        n = re.match(r"\s*\+\s*(0x[0-9a-fA-F]+|\d+)", s[k:])
        if not n or int(n.group(1), 0) % 2:
            continue
        end = k + n.end()
        head = s[pos:m.start()]
        expr = s[m.start():k] + " + " + hex(int(n.group(1), 0) // 2)
        if head.endswith("(u16 *)(") and s[end:end + 1] == ")":
            head, end = head[:-len("(u16 *)(")], end + 1
        out.append(head + expr)
        pos = end
    out.append(s[pos:])
    return "".join(out)


def caller(p, stage2=False):
    s = rd(p)
    o = s
    # *(struct PalAnmSlot * *)&EXPR -> EXPR
    s = re.sub(r"\*\(" + SLOT + r"\s*\*\s*\*\)&", "", s)
    # (struct PalAnmSlot *) cast: drop it
    s = re.sub(r"\(" + SLOT + r"\s*\*\)", "", s)
    s = re.sub(r"^" + SLOT + r";\n", "", s, flags=re.M)
    s = re.sub(SLOT + r"\s*\*", "struct PaletteFade *", s)
    if stage2:
        s = re.sub(r"(PALANM_Blend\w+\()\((?:struct )?PaletteFadeWork \*\)", r"\g<1>", s)
        s = re.sub(r"(PALANM_Get(?:Default|Trans)Work\()\(char \*\)", r"\g<1>", s)
        s = halve_offsets(s)
        for a, b in STAGE2_HAND.get(p, []):
            if a in s:
                s = s.replace(a, b)
            else:
                print("  hand edit not found in " + p + ": " + a[:60])
    s = re.sub(r"(PALANM_\w+Slot\w*)\(\(([\w>.\-]+)\),", r"\g<1>(\g<2>,", s)
    return o, s


def main():
    a = sys.argv[1:]
    apply = "--apply" in a
    stage2 = "--core2" in a or "--all" in a or "--final" in a
    final = "--final" in a
    files = [x for x in a if not x.startswith("--")]
    if stage2 or "--core" in a:
        if apply:
            core(stage2, final)
        print("core", "applied" if apply else "(dry)")
    if "--all" in a:
        out = subprocess.run(["git", "grep", "-lE", "PalAnmSlot|PALANM_(Blend(Channel|ChannelMask)|GetDefaultWork|GetTransWork|Create|Delete)[(]", "--", "src/game"], cwd=ROOT,
                             capture_output=True, text=True).stdout.split()
        files = sorted(set(f for f in out if not f.startswith("src/game/arm9/palanm.") and f.endswith((".c", ".h"))) | set(STAGE2_CALLERS) | set(STAGE2_HAND))
    for f in files:
        o, s = caller(f, stage2)
        print(f, "changed" if o != s else "same")
        if apply and o != s:
            wr(f, s)


main()
