/*
 * function: func_021BD57C
 * address:  0x021BD57C
 * packet:   pkt_021BD57C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the word at +8 with a zero second argument.
 *
 * symbols:
 *   func_02043B5C  0x02043B5C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02043B5C(u32 v, u32 a);

void func_021BD57C(u8 *p)
{
    func_02043B5C(*(u32 *)(p + 8), 0);
}
