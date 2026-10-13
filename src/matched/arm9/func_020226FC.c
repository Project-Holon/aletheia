/*
 * unit:     no
 * address:  0x020226FC
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WIPE_SUB_PatternFadeIn
 *
 * symbols:
 *   WIPE_SUB_FadeStart  0x020229A4  thumb
 *   WIPE_SUB_FadeMain  0x02022A44  thumb
 *
 * Same shape as WIPE_SUB_PatternFadeOut in src/matched/unit_020226A0.c, and kept in
 * its own file for the same reason: its calls to WIPE_SUB_FadeStart and
 * WIPE_SUB_FadeMain have to stay outside that unit's compared range to attest
 * its calls, and vice versa.  Sets the flag pair at +0x28 and +0x2c to
 * (0, 1) instead of (1, 1) and calls WIPE_SUB_FadeStart(p, 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternFadeIn.c \
 *       --func WIPE_SUB_PatternFadeIn --addr 0x020226FC --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u8  pad00[0xC];
    u32 unk0C;
    u8  pad10[0x28 - 0x10];
    u32 unk28;
    u32 unk2C;
};

struct Task;
extern void WIPE_SUB_FadeStart(struct Task *t, u32 dir);
extern u32 WIPE_SUB_FadeMain(struct Task *t);

u32 WIPE_SUB_PatternFadeIn(struct Obj *p)
{
    if (p->unk0C == 0) {
        p->unk28 = 0;
        p->unk2C = 1;
        WIPE_SUB_FadeStart((struct Task *)p, 0);
        return 0;
    }
    return WIPE_SUB_FadeMain((struct Task *)p);
}
