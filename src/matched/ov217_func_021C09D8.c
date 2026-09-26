/*
 * function: func_021C09D8
 * address:  0x021C09D8
 * packet:   pkt_ov217_021C09D8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 4-byte tail-call veneer in a .word run; pool 0x021C09DC names
 * func_021C0D38.  Top of the func_021BA31C blocker chain.
 *
 * symbols:
 *   func_021C0D38  0x021C0D38  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021C0D38(u8 *p, u32 i);

void func_021C09D8(u8 *p, u32 i)
{
    func_021C0D38(p, i);
}
