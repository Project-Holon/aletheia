/*
 * function: func_021BE318
 * address:  0x021BE318
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Rebuilds the +0x1dc record from the +0x1d8 source, retiring the old one first.
 *
 * symbols:
 *   func_021BE34C  0x021BE34C  thumb  ov172
 *   func_0202EE8C  0x0202EE8C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BE34C(void *p);
extern u32  func_0202EE8C(u32 a, int b, int c, int d, u16 e);

void func_021BE318(char *a0, int a1)
{
    if (*(u32 *)(a0 + 0x1dc) != 0)
        func_021BE34C(a0);

    *(u32 *)(a0 + 0x1dc) =
        func_0202EE8C(*(u32 *)(a0 + 0x1d8), a1, 0xf, 0x10, *(u16 *)a0);
}
