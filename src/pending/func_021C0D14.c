/*
 * function: func_021C0D14
 * address:  0x021C0D14
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
 *   func_021C29E8  0x021C29E8  thumb  ov217
 *   func_021C3F50  0x021C3F50  arm  ov217
 *

 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +0014 ABS32 func_021C3F50          -> unresolved: 021C3F50 (arm, from header) has no witness outside 021C0D14..021C0D2C; 10 overlays overlap this address (ov016, ov021, ov093, ov111, ov114, ov127, ov136, ov172, ov208, ov217), none resolvable without a region hint on the symbols: line
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

extern void func_021C29E8();
extern void func_021C3F50();
void func_021C0D14(u8 *a0)
{
    func_021C29E8(*(u32*)(((u8*)a0) + 44), *(u32*)(((u8*)func_021C3F50)), *(u32*)(((u8*)func_021C3F50) + 4), *(u8*)(((u8*)func_021C3F50) + 8));
}

