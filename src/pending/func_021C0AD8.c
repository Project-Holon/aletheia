/*
 * function: func_021C0AD8
 * address:  0x021C0AD8
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
 *   func_021C3F64  0x021C3F64  arm  ov217
 *   func_021C3F9C  0x021C3F9C  arm  ov217
 *

 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +000C ABS32 func_021C3F64          -> unresolved: 021C3F64 (arm, from header) has no witness outside 021C0AD8..021C0AF0; 10 overlays overlap this address (ov016, ov021, ov093, ov111, ov114, ov127, ov136, ov172, ov208, ov217), none resolvable without a region hint on the symbols: line
 *   +0010 ABS32 func_021C3F9C          -> unresolved: 021C3F9C (arm, from header) has no witness outside 021C0AD8..021C0AF0; 10 overlays overlap this address (ov016, ov021, ov093, ov111, ov114, ov127, ov136, ov172, ov208, ov217), none resolvable without a region hint on the symbols: line
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

extern void func_0204A48C();
extern void func_021C3F64();
extern void func_021C3F9C();
void func_021C0AD8(u32 a0)
{
    func_0204A48C(func_021C3F64, func_021C3F9C, *(u16*)(((u8*)a0 + 0)));
}

