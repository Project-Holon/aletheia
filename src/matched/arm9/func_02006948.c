/*
 * function: PM_VOICE_Stop
 * address:  0x02006948
 * packet:   pkt_02006948
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * promoted: from src/pending 2026-09-19, no C change: blockers 0x02072A88
 *           (src/matched/func_02072A88.c, ../1.2/sp2) and 0x02072BDC
 *           (src/matched/func_02072BDC.c, ../2.0/sp2) are filed and
 *           0x02072D20 was already a manifest entry, so all seven sites
 *           resolve through the `matched` class.  EXACT* not EXACT: the
 *           follower at 0x0200697A carries no label, nothing else differs.
 * blocker:  (resolved)
 *
 * symbols:
 *   func_02072BDC  0x02072BDC  arm
 *   func_02072D20  0x02072D20  arm
 *   func_02072A88  0x02072A88  arm
 *   PM_VOICE_ResetParams  0x020067A4  thumb
 *
 * Tear down one voice: three calls on the object's object pointer at +0x14,
 * the same three on the second one at +0x18 when +0x2C is 1, then clear the
 * first word and re-initialise.  The +0x14 load is repeated before each call
 * because the callees are extern and may write it back, so the source reads
 * the field again rather than caching it in a local.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PM_VOICE_Stop.c \
 *       --func PM_VOICE_Stop --addr 0x02006948 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Sub02006948 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
};

extern void func_02072BDC(u32 a);
extern void func_02072D20(u32 a);
extern void func_02072A88(u32 *a);
struct Sub02006544Entry;
extern void PM_VOICE_ResetParams(struct Sub02006544Entry *p);

void PM_VOICE_Stop(struct Sub02006948 *p)
{
    func_02072BDC(p->unk14);
    func_02072D20(p->unk14);
    func_02072A88((u32 *)p->unk14);
    if (p->unk2C == 1) {
        func_02072BDC(p->unk18);
        func_02072D20(p->unk18);
        func_02072A88((u32 *)p->unk18);
    }
    p->unk00 = 0;
    PM_VOICE_ResetParams((struct Sub02006544Entry *)p);
}
