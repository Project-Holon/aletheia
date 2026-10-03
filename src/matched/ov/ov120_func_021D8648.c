/*
 * function: func_021D8648
 * address:  0x021D8648
 * packet:   pkt_021D8648
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02028148  0x02028148  thumb
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02028148(u8 *p);
extern void func_02041B6C(u32 bit);

void func_021D8648(u8 *p)
{
    func_02028148(*(void **)(p + 0xc4));
    func_02041B6C(5);
    *(u32 *)(p + 0xc4) = 0;
}
