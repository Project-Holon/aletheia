/*
 * unit:     no
 * address:  0x02022830
 * packet:   pkt_0202271C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02022830
 *
 * symbols:
 *   func_020222A8  0x020222A8  thumb
 *   func_02023464  0x02023464  thumb
 *   func_020234C0  0x020234C0  thumb
 *
 * Same shape as src/matched/func_02022804.c; kept in its own file for the
 * same reason (the sibling calls to the shared helpers have to stay
 * outside the compared range to attest them).  Sets the flag pair to
 * (0, 0) instead of (1, 0), and stashes the constant 0x0209F628.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022830.c \
 *       --func func_02022830 --addr 0x02022830 --cc 1.1p1 --thumb
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

void func_02022830(struct Obj *p)
{
    if (p->unk0C == 0) {
        func_020222A8(p->unk24);
        func_02023464(p, 0x0209F628);
        p->unk28 = 0;
        p->unk2C = 0;
        return;
    }
    func_020234C0(p);
}
