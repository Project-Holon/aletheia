/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: sub_0204B92C, sub_0204B944
 * address:  0x0204B92C
 * packet:   pkt_0204B84C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A setter/getter pair for one bit of the flag word at +0x60 of a widely
 * passed object (bit 25).  The unlabelled getter at 0x0204B944 saves no lr,
 * so disasm.py never labels it; it is only visible by sweeping addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B92C.c \
 *       --addr 0x0204B92C --arm
 */

typedef unsigned int u32;

struct Obj {
    u32 unk_00[24];
    u32 unk_60_0 : 25;
    u32 unk_60_25 : 1;
    u32 unk_60_26 : 6;
};

void sub_0204B92C(struct Obj *p, u32 v)
{
    p->unk_60_25 = v;
}

u32 sub_0204B944(struct Obj *p)
{
    return p->unk_60_25;
}
