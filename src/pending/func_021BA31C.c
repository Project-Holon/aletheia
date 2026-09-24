/*
 * function: func_021BA31C
 * address:  0x021BA31C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   func_021C09D8  0x021C09D8  thumb  ov217
 *

 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +0008 ABS32 func_021C09D8          -> unresolved: 021C09D8 (thumb, from header) has no witness outside 021BA31C..021BA328; 12 overlays overlap this address (ov016, ov021, ov093, ov099, ov110, ov114, ov172, ov203, ov204, ov208, ov210, ov217), none resolvable without a region hint on the symbols: line
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021C09D8();
void func_021BA31C(u8 *a0)
{
    func_021C09D8(*(u32*)(((u8*)a0)), 0);
}

