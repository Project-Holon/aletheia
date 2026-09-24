/*
 * function: func_021BAB58
 * address:  0x021BAB58
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
 *   func_021BAB50  0x021BAB50  thumb  ov217
 *

 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +0008 ABS32 func_021BAB50          -> unresolved: 021BAB50 (thumb, from header) has no witness outside 021BAB58..021BAB68; 22 overlays overlap this address (ov016, ov021, ov068, ov070, ov071, ov072, ov088, ov091, ov093, ov099, ov100, ov110, ov114, ov172, ov181, ov206, ov213, ov214, ov217, ov218, ov223, ov225), none resolvable without a region hint on the symbols: line
 *   +000C ABS32 func_02005654          -> unresolved: 02005654 (arm, from name) has no witness outside 021BAB58..021BAB68
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

extern void func_02005654();
extern void func_021BAB50();
void func_021BAB58(void)
{
    func_02005654(func_021BAB50, 0);
}

