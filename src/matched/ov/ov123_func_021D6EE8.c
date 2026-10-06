/*
 * function: func_021D6EE8
 * address:  0x021D6EE8
 * packet:   pkt_021D6EE8
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *   func_021D6EE0  0x021D6EE0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_020221A4(void);
extern void func_021D6EE0(u8 *p, u32 v, int unused);

void func_021D6EE8(char *p)
{
    if (func_020221A4() != 0)
        func_021D6EE0((u8 *)p, 0, 0x157);
}
