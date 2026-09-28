/*
 * function: func_02188BD8
 * address:  0x02188BD8
 * packet:   pkt_02188BD8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets the two words at +0xC0 and +0xC4 of its argument to 2 and 4.  A leaf
 * with no lr-saving prologue that nothing in ov021 branches to (its caller
 * is sub_02014488 in arm9), so the listing emits it as data words after
 * pool_02188BD4.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void func_02188BD8(u8 *obj)
{
    *(u32 *)(obj + 0xc0) = 2;
    *(u32 *)(obj + 0xc4) = 4;
}
