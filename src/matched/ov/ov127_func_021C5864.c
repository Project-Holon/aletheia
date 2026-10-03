/*
 * function: func_021C5864
 * address:  0x021C5864
 * packet:   pkt_021C5864
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5944  0x021C5944  thumb
 *   func_021C42C4  0x021C42C4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C5944(u8 *p, int n, int a);
extern void func_021C42C4(u8 *p);

void func_021C5864(u8 *p, int b)
{
    func_021C5944(p, 0, b);
    func_021C42C4(*(void **)(p + 4));
}
