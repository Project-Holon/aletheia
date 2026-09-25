/*
 * function: func_021BABF4
 * address:  0x021BABF4
 * packet:   pkt_ov110_021BABF4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021BC6E0          -> unresolved: 021BC6E0 (arm, from name) has no witness outside 021BABF4..021BAC00; 16 overlays overlap this address (ov016, ov021, ov088, ov091, ov093, ov099, ov110, ov114, ov172, ov208, ov209, ov210, ov211, ov216, ov217, ov223), none resolvable without a region hint on the symbols: line
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void func_021BC6E0(u32);
void func_021BABF4(u8 *p) { func_021BC6E0(*(u32 *)(p + 0x54)); }
