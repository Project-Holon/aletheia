/*
 * function: func_021BBAD0
 * address:  0x021BBAD0
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
 *   func_021BC574  0x021BC574  thumb  ov217
 *

 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +0008 ABS32 func_021BC574          -> unresolved: 021BC574 (thumb, from header) has no witness outside 021BBAD0..021BBADC; 16 overlays overlap this address (ov016, ov021, ov088, ov091, ov093, ov099, ov110, ov114, ov172, ov208, ov209, ov210, ov211, ov216, ov217, ov223), none resolvable without a region hint on the symbols: line
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

extern void func_021BC574();
void func_021BBAD0(u32 a0)
{
    func_021BC574(a0, 0);
}

