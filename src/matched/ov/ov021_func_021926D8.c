/*
 * function: func_021926D8
 * address:  0x021926D8
 * packet:   pkt_ov021_021926D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm  arm9
 *   func_0203630C  0x0203630C  arm  arm9
 *   func_02045334  0x02045334  arm  arm9
 *   func_02045770  0x02045770  arm  arm9
 *   func_021928F8  0x021928F8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct U {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 sub[2];
} U;

extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u32 func_02045770(u32 a);
extern void func_021928F8(u32 *sub, u32 a, u32 b);
extern void func_02045334(u32 a);

int func_021926D8(U *u)
{
    u32 v = func_020362DC();
    func_0203630C();
    if (v & 3)
        return 1;
    func_021928F8(u->sub, func_02045770(u->f00), u->f0c);
    func_02045334(u->f00);
    return 0;
}
