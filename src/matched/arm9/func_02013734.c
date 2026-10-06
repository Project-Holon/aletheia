/*
 * function: func_02013734
 * address:  0x02013734
 * packet:   pkt_020136E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020134F4  0x020134F4  thumb
 *   func_02013284  0x02013284  thumb
 *
 * The three-slot setup that takes a single word argument block: the shared
 * halfword is the first word of that block (its low half, copied into the
 * outgoing stack slot of the first call) and the fourth word of the object
 * is the outer value both other calls carry.  Only three sub-blocks here,
 * so the trailing byte is 3.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013734.c \
 *       --func func_02013734 --addr 0x02013734 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj02013734 {
    u8  pad00[0x22];
    u8  f22;            /* +0x22 */
};

extern void func_020134F4(struct Obj02013734 *o, u32 a1, u32 n, u32 a2, u32 a3);
extern void func_02013284(u8 *o, u32 *a1, u32 n, u32 *dst, u32 v, u32 h);

void func_02013734(struct Obj02013734 *o, u32 a1, u32 a2, u32 a3, u32 a4,
                   u32 a5, u32 a6)
{
    func_020134F4(o, a1, 1, a2, a6);
    func_02013284((u8 *)o, (u32 *)a1, 2, (u32 *)((u8 *)o + 0x2c), a3, a6);
    func_02013284((u8 *)o, (u32 *)a1, 1, (u32 *)((u8 *)o + 0x28), a4, a6);
    func_02013284((u8 *)o, (u32 *)a1, 3, (u32 *)((u8 *)o + 0x30), a5, a6);
    *((u8 *)o + 0x22) = 3;
}
