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
 * function: func_02022804
 *
 * symbols:
 *   func_020222A8  0x020222A8  thumb
 *   func_02023464  0x02023464  thumb
 *   func_020234C0  0x020234C0  thumb
 *
 * One of a run of near-identical setup functions on one object
 * (func_02022804, func_02022830, func_0202285C, func_02022888,
 * func_020228B4, func_020228E0, each its own file so that the sibling
 * calls to the shared helpers stay outside the compared range and keep
 * attesting them; see docs/MATCHING.md, "the label class").
 *
 * Checks a delegate pointer at +0xc: when set, the whole call forwards to
 * func_020234C0 and returns.  That arm has to be written as the
 * fall-through (the guard on the complement, `== 0`, with the delegate
 * call left unconditional after it): the mirror phrasing, guarding
 * `!= 0` with the delegate inside the guarded block, lays the blocks out
 * in the opposite order and does not reproduce.  The fall-through calls
 * func_020222A8 with the object's id field at +0x24, then func_02023464
 * with the object pointer and a second, unattested pool constant
 * (0x0209F61C, written as a plain integer literal since nothing in this
 * function's own range names it as a symbol), and finally sets the pair
 * of flag words at +0x28 (to 1) and +0x2c (to 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022804.c \
 *       --func func_02022804 --addr 0x02022804 --cc 1.1p1 --thumb
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

extern void func_020222A8(u32 a);
extern void func_02023464(struct Obj *p, u32 arg);
extern void func_020234C0(struct Obj *p);

void func_02022804(struct Obj *p)
{
    if (p->unk0C == 0) {
        func_020222A8(p->unk24);
        func_02023464(p, 0x0209F61C);
        p->unk28 = 1;
        p->unk2C = 0;
        return;
    }
    func_020234C0(p);
}
