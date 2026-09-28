/*
 * function: func_021C2A18
 * address:  0x021C2A18
 * packet:   pkt_ov217_021C09D8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 14-byte ov217 leaf in a .word run; target of the veneer at
 * 0x021C29F8 and the bottom of the func_021BA31C blocker chain.  Store order
 * in the source is +0x14, +0x18, +0x1c, +0x12.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void func_021C2A18(u8 *p, u32 b, u16 c)
{
    *(u32 *)(p + 0x14) = 1;
    *(u32 *)(p + 0x18) = b;
    *(u32 *)(p + 0x1c) = 0;
    *(u16 *)(p + 0x12) = c;
}
