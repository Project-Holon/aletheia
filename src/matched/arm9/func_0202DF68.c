/*
 * unit:     no
 * function: func_0202DF68
 * address:  0x0202DF68
 * packet:   pkt_0202DF68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the four handles of the pms_draw sub-object at +0x10 of its
 * owner: the three VRAM-bank queries of unit_0202DE9C are taken first
 * (off the engine word at +4), a 0x2b resource set is opened on the
 * caller's heap, and ENV_SetResourceSet / func_0204A6C8 / func_0204AF28
 * fill +8, +0xc and +0x10 before the set is closed again.
 *
 * The screen-size argument to ENV_SetResourceSet is `(u16)(a1 << 5)`, the
 * unequal shift pair lsls #0x15 / lsrs #0x10 -- a narrowing cast folded
 * with the shift, not an 11-bit bitfield.
 *
 * symbols:
 *   sub_0202DE9C       0x0202DE9C  thumb
 *   sub_0202DEE0       0x0202DEE0  thumb
 *   sub_0202DF24       0x0202DF24  thumb
 *   func_020490F4      0x020490F4  arm
 *   ENV_SetResourceSet 0x0204AC18  arm
 *   func_0204A6C8      0x0204A6C8  arm
 *   func_0204AF28      0x0204AF28  arm
 *   func_02049238      0x02049238  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32   sub_0202DE9C(u32 engine);
extern u32   sub_0202DEE0(u32 engine);
extern u32   sub_0202DF24(u32 engine);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32   ENV_SetResourceSet(void *h, u32 a1, u32 engine, u16 a3,
                                u32 s0, u32 s1, u32 s2);
extern u32   func_0204A6C8(void *h, u32 a1, u32 a2, u32 engine, u32 s0);
extern u32   func_0204AF28(void *h, u32 a1, u32 a2, u32 a3);
extern void  func_02049238(void *h);

void func_0202DF68(u32 *o, u32 a1, u32 heap)
{
    u32 b0;
    u32 b1;
    u32 b2;
    void *h;

    b0 = sub_0202DE9C(o[1]);
    b1 = sub_0202DEE0(o[1]);
    b2 = sub_0202DF24(o[1]);
    h = func_020490F4(0x2b, heap);
    o[2] = ENV_SetResourceSet(h, 1, o[1], (u16)(a1 << 5), 0, 5, heap);
    o[3] = func_0204A6C8(h, b2, 0, o[1], heap);
    o[4] = func_0204AF28(h, b0, b1, heap);
    func_02049238(h);
}
