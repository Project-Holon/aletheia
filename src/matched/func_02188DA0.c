/*
 * function: func_02188DA0
 * address:  0x02188DA0
 * packet:   pkt_02188DA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with a fixed data pointer argument.
 *
 * symbols:
 *   func_0203FC28  0x0203FC28  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0203FC28(u32 p);

void func_02188DA0(void)
{
    func_0203FC28(0x021D35F4);
}
