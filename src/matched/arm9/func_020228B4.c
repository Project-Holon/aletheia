/*
 * unit:     no
 * address:  0x020228B4
 * packet:   pkt_0202271C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WIPE_SUB_PatternBoxSlideOut
 *
 * symbols:
 *   WIPE_SetBackColor  0x020222A8  thumb
 *   WIPE_SUB_BoxStart  0x02023464  thumb
 *   WIPE_SUB_BoxMain  0x020234C0  thumb
 *
 * Same shape as src/matched/WIPE_SUB_PatternBoxOpenOut.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (1, 0) and stashes the constant 0x0209F5EC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_PatternBoxSlideOut.c \
 *       --func WIPE_SUB_PatternBoxSlideOut --addr 0x020228B4 --cc 1.1p1 --thumb
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

void WIPE_SUB_PatternBoxSlideOut(struct Obj *p)
{
    if (p->unk0C == 0) {
        WIPE_SetBackColor(p->unk24);
        WIPE_SUB_BoxStart((struct Task *)p, (u8 *)0x0209F5EC);
        p->unk28 = 1;
        p->unk2C = 0;
        return;
    }
    WIPE_SUB_BoxMain((struct Task *)p);
}
