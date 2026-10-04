/*
 * function: func_021C29E8
 * address:  0x021C29E8
 * packet:   pkt_ov217_021C29E8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C2DE0  0x021C2DE0  thumb  ov217
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_021C2DE0(char *p, unsigned short *dst, unsigned short *src, int count);

void func_021C29E8(void *p, u32 b, u32 c, u32 d)
{
    func_021C2DE0(p, (short unsigned int *)b, (short unsigned int *)c, d);
}
