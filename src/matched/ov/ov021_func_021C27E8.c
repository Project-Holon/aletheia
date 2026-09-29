/*
 * function: func_021C27E8
 * address:  0x021C27E8
 * packet:   pkt_ov021_021C27E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: tail call on the word at +0x68.  (Not the ov099
 * function at the same address in src/matched/ov/func_021C27E8.c.)
 *
 * symbols:
 *   func_02043534  0x02043534  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_02043534(u32 a);

void func_021C27E8(u8 *p)
{
    func_02043534(*(u32 *)(p + 0x68));
}
