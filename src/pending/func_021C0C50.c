/*
 * function: func_021C0C50
 * address:  0x021C0C50
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
 *   func_021C0C50  0x021C0C50  thumb  ov217
 *

 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +0008 ABS32 func_02021540          -> unresolved: 02021540 (arm, from name) has no witness outside 021C0C50..021C0C5C
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

extern void func_02021540();
void func_021C0C50(u8 *a0)
{
    func_02021540(*(u32*)(((u8*)a0) + 40));
}

