/*
 * function: func_021C11A4
 * address:  0x021C11A4
 * packet:   pkt_ov093_021C11A4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C0C34  0x021C0C34  thumb  ov093
 *   func_021C11F0  0x021C11F0  thumb  ov093
 *   func_021C18D4  0x021C18D4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021C0C34(u8 *d);
extern u32 func_021C11F0(u8 *p, u32 b, u32 c, u8 *d, u32 a, u32 e, u32 f, u32 g);
extern void func_021C18D4(u8 *p, u8 *a, u8 *q, u32 v);

u32 func_021C11A4(u8 *p, u32 a, u32 b, u32 c, u8 *d, u32 e, u32 f, u32 g)
{
    u32 r;
    if ((u8)func_021C0C34(d) != 0) {
        r = func_021C11F0(p, b, c, d, a, e, f, g);
        func_021C18D4(p, (u8 *)b, (u8 *)a, r);
        return r;
    }
    return 0;
}
