/*
 * function: func_021D5AB0
 * address:  0x021D5AB0
 * packet:   pkt_021D5AB0
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D97CC  0x021D97CC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021D97CC(int, void *);

void func_021D5AB0(u8 *p, int x)
{
    func_021D97CC(x, *(void **)(p + 0x2c));
}
