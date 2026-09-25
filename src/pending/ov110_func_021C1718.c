/*
 * function: func_021C1718
 * address:  0x021C1718
 * packet:   pkt_ov110_021C1718
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021C1848          -> unresolved: 021C1848 (arm, from name) has no witness outside 021C1718..021C1724; 10 overlays overlap this address (ov016, ov021, ov093, ov099, ov110, ov114, ov172, ov203, ov208, ov217), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021C1848(void *);
void func_021C1718(u8 *p) { func_021C1848(p + 4); }
