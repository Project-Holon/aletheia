/*
 * function: func_021BB978
 * address:  0x021BB978
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
 *   func_021BB998  0x021BB998  thumb  ov217
 *

 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +0010 ABS32 func_021BB998          -> unresolved: 021BB998 (thumb, from header) has no witness outside 021BB978..021BB98C; 16 overlays overlap this address (ov016, ov021, ov070, ov072, ov088, ov091, ov093, ov099, ov109, ov110, ov114, ov172, ov206, ov217, ov223, ov225), none resolvable without a region hint on the symbols: line
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

extern void func_021BB998();
void func_021BB978(u8 *a0, u32 a1)
{
    *(u32*)(((u8*)a0) + 28) = a1;
    *(u32*)(((u8*)a0) + 36) = 0;
    *(u32*)(((u8*)a0) + 344) = 0;
    func_021BB998((u32)a0, 344, 0);
}

