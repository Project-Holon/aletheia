/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02014274
 * packet:   pkt_02013ED8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZONEDATA_ExitDirToDir, ZONEDATA_DirToExitDir, ZONEDATA_GetEventWorkSize, ZONEDATA_InitEventWork
 *
 * symbols:
 *   sub_02082BCC  0x02082BCC  arm
 *
 * alias: ZONEDATA_ExitDirToDir and ZONEDATA_DirToExitDir are two dense switches over a small
 * id (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md): the
 * range each `cmp`/`bhi` accepts has one slot with no case of its own,
 * which lands on the same body as the function's default arm
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md); the id that
 * hits it is not a real case, it is written as the default.
 *
 * ZONEDATA_GetEventWorkSize is a bare constant getter, hiding the same way the tail
 * calls elsewhere in this packet do: no prologue, so disasm.py's sweep
 * never labels it. ZONEDATA_InitEventWork is a tail call to the ARM function
 * sub_02082BCC forwarding its own argument and two more constants; the
 * same target is reached by an ordinary `blx` from unit_02014368.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014274.c \
 *       --addr 0x02014274 --thumb
 */

typedef unsigned int u32;

extern u32 sub_02082BCC(u32 a, u32 b, u32 c);

u32 ZONEDATA_ExitDirToDir(u32 idx)
{
    switch (idx) {
    case 1: return 0;
    case 2: return 1;
    case 3: return 2;
    case 4: return 3;
    default: return 1;
    }
}

u32 ZONEDATA_DirToExitDir(u32 idx)
{
    switch (idx) {
    case 0: return 1;
    case 1: return 2;
    case 2: return 3;
    case 3: return 4;
    default: return 2;
    }
}

u32 ZONEDATA_GetEventWorkSize(void)
{
    return 0x3EA;
}

u32 ZONEDATA_InitEventWork(u32 a)
{
    return sub_02082BCC(a, 0, 0x3EA);
}
