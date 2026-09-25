/*
 * function: func_021D9FFC
 * address:  0x021D9FFC
 * packet:   pkt_021D9FFC
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F73C  0x0201F73C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0201F73C(void *, int, int, int);

void func_021D9FFC(u8 *p, int a, int b)
{
    func_0201F73C(*(void **)(p + 0x10), 0, a, b);
}
