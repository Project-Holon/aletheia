/*
 * function: func_021C6D90
 * address:  0x021C6D90
 * packet:   pkt_ov021_021C6D90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C6E94  0x021C6E94  thumb  ov021
 *   func_021C6EA8  0x021C6EA8  thumb  ov021
 *   func_021C6EDC  0x021C6EDC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021C6E94(u8 *p, u8 i);
extern void func_021C6EA8(u8 *p, u8 i);
extern void func_021C6EDC(u8 *p, u8 i);

void func_021C6D90(u8 *p)
{
    int i;

    for (i = 0; i < p[0]; i++)
        func_021C6E94(p, i);
    for (i = 0; i < p[0]; i++)
        func_021C6EA8(p, i);
    for (i = 0; i < p[0]; i++)
        func_021C6EDC(p, i);
}
