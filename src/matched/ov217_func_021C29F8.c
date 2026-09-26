/*
 * function: func_021C29F8
 * address:  0x021C29F8
 * packet:   pkt_ov217_021C09D8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
  * status:   EXACT
 *
 * Unlabelled 4-byte tail-call veneer in a .word run; pool 0x021C29FC names
 * func_021C2A18. Middle of the func_021BA31C blocker chain.
 *
 * symbols:
 *   func_021C2A18  0x021C2A18  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021C2A18(u8 *p, u32 b, u16 c);

void func_021C29F8(u8 *p, u32 b, u16 c)
{
    func_021C2A18(p, b, c);
}
