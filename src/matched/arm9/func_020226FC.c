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
 * function: func_020226FC
 *
 * symbols:
 *   func_020229A4  0x020229A4  thumb
 *   func_02022A44  0x02022A44  thumb
 *
 * Same shape as func_020226E0 in src/matched/unit_020226A0.c, and kept in
 * its own file for the same reason: its calls to func_020229A4 and
 * func_02022A44 have to stay outside that unit's compared range to attest
 * its calls, and vice versa.  Sets the flag pair at +0x28 and +0x2c to
 * (0, 1) instead of (1, 1) and calls func_020229A4(p, 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020226FC.c \
 *       --func func_020226FC --addr 0x020226FC --cc 1.1p1 --thumb
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
extern void func_020229A4(struct Task *t, u32 dir);
extern u32 func_02022A44(struct Task *t);

u32 func_020226FC(struct Obj *p)
{
    if (p->unk0C == 0) {
        p->unk28 = 0;
        p->unk2C = 1;
        func_020229A4((struct Task *)p, 0);
        return 0;
    }
    return func_02022A44((struct Task *)p);
}
