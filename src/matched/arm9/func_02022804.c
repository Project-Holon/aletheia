/*
 * unit:     no
 * address:  0x02022804
 * packet:   pkt_0202271C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WIPE_SUB_PatternBoxOpenOut
 *
 * symbols:
 *   WIPE_SetBackColor  0x020222A8  thumb
 *   WIPE_SUB_BoxStart  0x02023464  thumb
 *   WIPE_SUB_BoxMain  0x020234C0  thumb
 *
 * One of a run of near-identical setup functions on one object
 * (WIPE_SUB_PatternBoxOpenOut, WIPE_SUB_PatternBoxOpenIn, WIPE_SUB_PatternCircleOut, WIPE_SUB_PatternCircleIn,
 * WIPE_SUB_PatternBoxSlideOut, WIPE_SUB_PatternBoxSlideIn, each its own file so that the sibling
 * calls to the shared helpers stay outside the compared range and keep
 * attesting them; see docs/MATCHING.md, "the label class").
 *
 * Checks a delegate pointer at +0xc: when set, the whole call forwards to
 * WIPE_SUB_BoxMain and returns.  That arm has to be written as the
 * fall-through (the guard on the complement, `== 0`, with the delegate
 * call left unconditional after it): the mirror phrasing, guarding
 * `!= 0` with the delegate inside the guarded block, lays the blocks out
 * in the opposite order and does not reproduce.  The fall-through calls
 * WIPE_SetBackColor with the object's id field at +0x24, then WIPE_SUB_BoxStart
 * with the object pointer and a second, unattested pool constant
 * (0x0209F61C, written as a plain integer literal since nothing in this
 * function's own range names it as a symbol), and finally sets the pair
 * of flag words at +0x28 (to 1) and +0x2c (to 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternBoxOpenOut.c \
 *       --func WIPE_SUB_PatternBoxOpenOut --addr 0x02022804 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u8  pad00[0xC];
    u32 unk0C;
    u8  pad10[0x24 - 0x10];
    u16 unk24;
    u8  pad26[2];
    u32 unk28;
    u32 unk2C;
};

extern void WIPE_SetBackColor(u32 a);
struct Task;
extern void WIPE_SUB_BoxStart(struct Task *t, u8 *cfg);
extern u32 WIPE_SUB_BoxMain(struct Task *t);

void WIPE_SUB_PatternBoxOpenOut(struct Obj *p)
{
    if (p->unk0C == 0) {
        WIPE_SetBackColor(p->unk24);
        WIPE_SUB_BoxStart((struct Task *)p, (u8 *)0x0209F61C);
        p->unk28 = 1;
        p->unk2C = 0;
        return;
    }
    WIPE_SUB_BoxMain((struct Task *)p);
}
