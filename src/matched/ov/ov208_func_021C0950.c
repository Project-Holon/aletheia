/*
 * function: func_021C0950
 * address:  0x021C0950
 * packet:   pkt_ov208_021C0950
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FB44  0x0203FB44  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0203FB44(int id, u16 a, u16 b);

void func_021C0950(void *unused, u8 *p)
{
    u32 v = *(u32 *)(p + 0x68);
    func_0203FB44(7, (u16)v, (u16)(v >> 16));
}
