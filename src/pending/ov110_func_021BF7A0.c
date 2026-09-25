/*
 * function: func_021BF7A0
 * address:  0x021BF7A0
 * packet:   pkt_ov110_021BF7A0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021BEDE0          -> unresolved: 021BEDE0 (arm, from name) has no witness outside 021BF7A0..021BF7AC; 12 overlays overlap this address (ov016, ov021, ov093, ov099, ov110, ov114, ov172, ov203, ov204, ov208, ov210, ov217), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021BEDE0(void *);
void func_021BF7A0(u8 *p) { func_021BEDE0(p + 0x54); }
