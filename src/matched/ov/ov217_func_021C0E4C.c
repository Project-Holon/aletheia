/*
 * function: func_021C0E4C
 * address:  0x021C0E4C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer to func_021C0EA4.
 *
 * symbols:
 *   func_021C0EA4  0x021C0EA4  thumb  ov217

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C0EA4(char *p, int v);
void func_021C0E4C(u32 a0, u32 a1)
{
    func_021C0EA4((char *)a0, (int)a1);
}

